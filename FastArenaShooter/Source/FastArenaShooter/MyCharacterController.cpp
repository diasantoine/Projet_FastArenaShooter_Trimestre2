// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterController.h"
#include "TimerManager.h"
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
	if (GetCharacterMovement()->IsMovingOnGround() && GetCharacterMovement()->Velocity == FVector(0,0,0))
	{
		UE_LOG(LogTemp,Warning,TEXT("testezez"))
		if (!GetWorldTimerManager().TimerExists(ManagerTime))
		{
			GetWorldTimerManager().SetTimer(ManagerTime,this,&AMyCharacterController::ResetAccelerationVelocity,_fDataStruct._timeBeforeDecceleration
				,true,_fDataStruct._timeBeforeDecceleration);
		}
	}
	else
	{
		if (GetWorldTimerManager().TimerExists(ManagerTime))
		{
			GetWorldTimerManager().ClearTimer(ManagerTime);
		}
	}

}

// Called to bind functionality to input
void AMyCharacterController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputPlayer();
}


void AMyCharacterController::InputPlayer()
{
	this->InputComponent->BindAxis("Forward",this,&AMyCharacterController::ForwardPlayer);
	this->InputComponent->BindAxis("Right",this,&AMyCharacterController::RightPlayer);

	this->InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	this->InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	
	this->InputComponent->BindAction("Jump", IE_Pressed, this,&AMyCharacterController::JumpPlayer);
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
	AccelerationVelocity();
	Jump();
}


void AMyCharacterController::MovementPlayer(float _jumpValue)
{
	
}



void AMyCharacterController::AccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed  *= _fDataStruct._acceleration;
	//GetCharacterMovement()->Velocity *= _fDataStruct._acceleration;
}

void AMyCharacterController::ResetAccelerationVelocity()
{
	UE_LOG(LogTemp,Warning,TEXT("test"))
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





