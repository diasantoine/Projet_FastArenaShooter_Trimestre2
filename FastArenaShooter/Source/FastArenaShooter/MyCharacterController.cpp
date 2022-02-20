// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterController.h"

#include "TimerManager.h"
#include "Engine/World.h"
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
	GetCharacterMovement()->MaxWalkSpeed = _fDataStruct._speed;
	GetCharacterMovement()->JumpZVelocity = _fDataStruct._height;
	GetCharacterMovement()->GravityScale *= _fDataStruct._weight;
}

// Called every frame
void AMyCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		if (!GetWorldTimerManager().TimerExists(ManagerTime))
		{
			GetWorldTimerManager().SetTimer(ManagerTime,this,&AMyCharacterController::AccelerationVelocity,0.5f,true,0.5f);
		}
		if (!GetWorldTimerManager().TimerExists(ManagerTime))//TODO un moyen d'accélerer, toute les x en déplaçant et + 1 par saut
		{//Todo reset cette accélération si on attend x sc sans bouger
			GetWorldTimerManager().SetTimer(ManagerTime,this,&AMyCharacterController::ResetAccelerationVelocity,0.5f,true,0.5f);
		}
	}
	else
	{
		if (!GetWorldTimerManager().TimerExists(ManagerTime))
		{
			GetWorldTimerManager().SetTimer(ManagerTime,this,&AMyCharacterController::ResetAccelerationVelocity,0.5f,true,0.5f);
		}
	}

}

// Called to bind functionality to input
void AMyCharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputPlayer();
	ResetAccelerationVelocity();
}


void AMyCharacterController::InputPlayer()
{
	this->InputComponent->BindAxis("Forward",this,&AMyCharacterController::ForwardPlayer);
	this->InputComponent->BindAxis("Right",this,&AMyCharacterController::RightPlayer);

	this->InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	this->InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	
	this->InputComponent->BindAction("Jump", IE_Pressed, this,&ACharacter::Jump);
	this->InputComponent->BindAction("Jump", IE_Released, this,&ACharacter::StopJumping);
	this->InputComponent->BindAction<_typeOfFire>("NormalFire", IE_Pressed, this, &AMyCharacterController::ShootWeapon,false);
	this->InputComponent->BindAction<_typeOfFire>("SpecialFire", IE_Pressed, this, &AMyCharacterController::ShootWeapon,true);
}

void AMyCharacterController::ForwardPlayer(float _value)
{
	//MovementPlayer(0);
	AddMovementInput(GetActorForwardVector(),_value);
}

void AMyCharacterController::RightPlayer(float _value)
{
	AddMovementInput(GetActorRightVector(),_value);
	//MovementPlayer(0);
}

void AMyCharacterController::JumpPlayer()
{
	MovementPlayer(1);
}


void AMyCharacterController::MovementPlayer(float _jumpValue)
{
	
}



void AMyCharacterController::AccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed  *= _fDataStruct._accelerationMultiplier;
}

void AMyCharacterController::ResetAccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed = _fDataStruct._speed;
	if (GetWorldTimerManager().TimerExists(ManagerTime))
	{
		GetWorldTimerManager().ClearTimer(ManagerTime);
	}
}

void AMyCharacterController::ShootWeapon(bool _specialFire)
{
	if (_specialFire)
	{
		
	}
	else
	{
		
	}
}





