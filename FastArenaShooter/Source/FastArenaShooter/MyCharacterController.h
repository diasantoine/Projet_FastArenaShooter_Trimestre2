// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacterController.generated.h"

USTRUCT()
struct FdataStruct
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _groundSpeed = 1;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _maxSpeed = 5000;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _height = 1;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _jumpWindow = 0.5f;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _minimumAngleForBunny = 30.0f;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _weight = 1;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _airAcceleration = 1.2f;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _airSpeed = 200;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _timeBeforeDecceleration = 0.5f;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _deceleration = 0.5f;
	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	float _timeBeforeBunnyStop = 2.0f;
};

UCLASS()
class FASTARENASHOOTER_API AMyCharacterController : public ACharacter
{
	GENERATED_BODY()

	DECLARE_DELEGATE_OneParam(_typeOfFire, bool);

public:
	// Sets default values for this character's properties
	AMyCharacterController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ForwardPlayer(float _value);
	void RightPlayer(float _value);
	void YawRotation(float _value);
	void PitchRotation(float _value);
	void JumpPlayer();
	void JumpWindow();
	void StopBunnyHop();
	void VectorForwardContainer();
	void MovementPlayer();
	void AccelerationVelocity();
	void ResetAccelerationVelocity();
	void ShootWeapon(bool _specialFire);

	UPROPERTY(EditDefaultsOnly,Category = "Stat Character")
	FdataStruct _fDataStruct;

private:
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	void InputPlayer();

	float _decelerationVelocity = 0;
	float _bunnyVelocity = 0;
	FVector _oldForwardVector;

	FTimerHandle ManagerTime;
	FTimerHandle ManagerTimeJump;
	FTimerHandle ManagerTimeDotRotation;
	bool _jumpButtonPressed = false;
	bool _onBunny = false;
};
