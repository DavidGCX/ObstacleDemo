// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		FString myString = FString::SanitizeFloat(GetDistanceTravelled() - maxDistance);
		FString myName = GetName();
		UE_LOG(LogTemp, Display, TEXT("Overshoot: %s By %s"), *myString, *myName);
		FVector MoveDirection = moveVelocity.GetSafeNormal();
		startLocation = startLocation + MoveDirection * maxDistance;
		SetActorLocation(startLocation);
		moveVelocity *= -1;
	}
	else
	{
		FVector currentLocation = GetActorLocation();
		currentLocation += moveVelocity * DeltaTime;
		SetActorLocation(currentLocation);
		distanceTravelled = GetDistanceTravelled();
	}
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceTravelled() > maxDistance;
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator currentRotation = GetActorRotation();
	currentRotation.Yaw += speed * DeltaTime;
	SetActorRotation(currentRotation);
}

float AMovingPlatform::GetDistanceTravelled() const
{
	return FVector::Dist(startLocation, GetActorLocation());
}