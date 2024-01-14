// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	FVector startLocation = FVector(0, 0, 0);
	UPROPERTY(VisibleAnywhere)
	double distanceTravelled = 0;
	UPROPERTY(EditAnywhere)
	int speed = 10;
	UPROPERTY(EditAnywhere)
	FVector moveVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere)
	int maxDistance = 500;
	bool ShouldPlatformRotate = false;
	bool ShouldPlatformMove = true;
	bool ShouldPlatformReturn() const;
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	float GetDistanceTravelled() const;
};
