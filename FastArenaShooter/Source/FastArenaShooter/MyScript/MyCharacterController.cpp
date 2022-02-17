// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterController.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values

void AMyCharacterController::OnConstruction(const FTransform& Transform)
{
	
}


AMyCharacterController::AMyCharacterController()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacterController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacterController::MovementPlayer(FVector _direction)
{
	_direction = FVector(_direction.X * GetActorForwardVector().Z * _fDataStruct._speed * _fDataStruct._acceleration,
		_direction.Y * _fDataStruct._height * _fDataStruct._acceleration,
		_direction.Z * GetActorRightVector().X * _fDataStruct._speed * _fDataStruct._acceleration) * GetWorld()->GetDeltaSeconds();
	this->GetCharacterMovement()->AddInputVector(_direction);
}


