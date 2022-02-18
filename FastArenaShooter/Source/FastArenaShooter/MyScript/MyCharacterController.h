// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacterController.generated.h"

USTRUCT()
struct FdataStruct
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Stat Character")
	float _speed = 1;
	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Stat Character")
	float _height = 1;
	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Stat Character")
	float _accelerationMultiplier = 1.2f;
	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Stat Character")
	float _acceleration = 1;
	
};

UCLASS()
class FASTARENASHOOTER_API AMyCharacterController : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MovementPlayer(FVector _direction);
	void AccelerationVelocity();
	void ResetAccelerationVelocity();
	void ShootWeapon(bool _specialFire);

	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Stat Character")
	FdataStruct* _fDataStruct;

private:
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

	FTimerHandle ManagerTime;

};
