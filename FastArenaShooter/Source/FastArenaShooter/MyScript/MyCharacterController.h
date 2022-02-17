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
	float _speed;
	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Stat Character")
	float _height;
	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Stat Character")
	float _acceleration;
	
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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MovementPlayer(FVector _direction);

	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Stat Character")
	FdataStruct _fDataStruct;

private:
	virtual void OnConstruction(const FTransform& Transform) override;

};
