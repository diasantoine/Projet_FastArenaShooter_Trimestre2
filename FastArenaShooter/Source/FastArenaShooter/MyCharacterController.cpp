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
	InputPlayer();
	ResetAccelerationVelocity();
}


void AMyCharacterController::InputPlayer()
{
	this->InputComponent->BindAxis("Forward",this,&AMyCharacterController::ForwardPlayer);
	this->InputComponent->BindAxis("Right",this,&AMyCharacterController::RightPlayer);
	this->InputComponent->BindAction("Jump", IE_Pressed, this,&AMyCharacterController::JumpPlayer);
	this->InputComponent->BindAction<_typeOfFire>("NormalFire", IE_Pressed, this, &AMyCharacterController::ShootWeapon,false);
	this->InputComponent->BindAction<_typeOfFire>("SpecialFire", IE_Pressed, this, &AMyCharacterController::ShootWeapon,true);
}

void AMyCharacterController::ForwardPlayer(float _value)
{
	MovementPlayer(0);
}

void AMyCharacterController::RightPlayer(float _value)
{
	MovementPlayer(0);
}

void AMyCharacterController::JumpPlayer()
{
	MovementPlayer(1);
}


void AMyCharacterController::MovementPlayer(float _jumpValue)
{
	FVector _direction = FVector(InputComponent->GetAxisValue("Forward"), InputComponent->GetAxisValue("Right"), _jumpValue);
	if (!GetWorldTimerManager().TimerExists(ManagerTime))
	{
		GetWorldTimerManager().SetTimer(ManagerTime,this,&AMyCharacterController::AccelerationVelocity,0.5f,true,0.5f);
	}
	UE_LOG(LogTemp,Warning,TEXT("%d %d %d"), _direction.X, _direction.Y, _direction.Z);
	_direction = FVector(_direction.X * GetActorForwardVector().X * _fDataStruct._speed * _fDataStruct._acceleration,
		_direction.Y * GetActorRightVector().Y * _fDataStruct._speed * _fDataStruct._acceleration,0) * GetWorld()->GetDeltaSeconds();
	if (_jumpValue>0)
	{
		
	}
	AddControllerYawInput(1 * _fDataStruct._speedRotation * GetWorld()->GetDeltaSeconds());
	//this->GetCharacterMovement()->AddInputVector(_direction);
	//FaceRotation(FRotator(GetActorRotation().Pitch,GetActorRotation().Roll,GetActorRotation().Yaw * _fDataStruct._speedRotation), GetWorld()->GetDeltaSeconds());
	AddMovementInput(_direction);
}

void AMyCharacterController::AccelerationVelocity()
{
	_fDataStruct._acceleration *= _fDataStruct._accelerationMultiplier;
}

void AMyCharacterController::ResetAccelerationVelocity()
{
	if (!this->GetCharacterMovement()->IsMovementInProgress() && _fDataStruct._acceleration != 1)
	{
		_fDataStruct._acceleration = 1;
	}
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





