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
	GetCharacterMovement()->BrakingFrictionFactor = _fDataStruct._deceleration;
}

// Called every frame
void AMyCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		if (GetCharacterMovement()->Velocity == FVector(0,0,0))
		{
			if (!GetWorldTimerManager().TimerExists(ManagerTime))
			{
				GetWorldTimerManager().SetTimer(ManagerTime,this,&AMyCharacterController::ResetAccelerationVelocity,_fDataStruct._timeBeforeDecceleration
					,true,_fDataStruct._timeBeforeDecceleration);
			}
		}
	}
	else
	{
		if (GetWorldTimerManager().TimerExists(ManagerTime))
		{
			GetWorldTimerManager().ClearTimer(ManagerTime);
		}
	}

	if (_onBunny && GetInputAxisValue("Right") == 0)
	{
		_onBunny = false;
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

	this->InputComponent->BindAxis("Turn", this, &AMyCharacterController::YawRotation);
	this->InputComponent->BindAxis("LookUp", this, &AMyCharacterController::PitchRotation);
	
	this->InputComponent->BindAction("Jump", IE_Pressed, this,&AMyCharacterController::JumpPlayer);
	this->InputComponent->BindAction("Jump", IE_Released, this,&ACharacter::StopJumping);
	this->InputComponent->BindAction<_typeOfFire>("NormalFire", IE_Pressed, this, &AMyCharacterController::ShootWeapon,false);
	this->InputComponent->BindAction<_typeOfFire>("SpecialFire", IE_Pressed, this, &AMyCharacterController::ShootWeapon,true);
}

void AMyCharacterController::ForwardPlayer(float _value)
{
	AddMovementInput(GetActorForwardVector(),_value);
	//GetCharacterMovement()->Velocity += GetActorForwardVector();
}

void AMyCharacterController::RightPlayer(float _value)
{
	AddMovementInput(GetActorRightVector(),_value);
	//GetCharacterMovement()->Velocity.Y = GetActorRightVector().Y * _value * 200;
}

void AMyCharacterController::PitchRotation(float _value)
{
	//GetCharacterMovement()->Velocity *= GetActorForwardVector();
	APawn::AddControllerPitchInput(_value);
}

void AMyCharacterController::YawRotation(float _value)
{
	APawn::AddControllerYawInput(_value);
	if (!GetWorldTimerManager().TimerExists(ManagerTimeDotRotation))
	{
		GetWorldTimerManager().SetTimer(ManagerTimeDotRotation,this,&AMyCharacterController::JumpVelocityDirection,_timeBeforeCheckingAngleForBunny,
			false,_timeBeforeCheckingAngleForBunny);
	}	
}

void AMyCharacterController::JumpVelocityDirection()
{
	if (_oldForwardVector == FVector(0,0,0))
	{
		_oldForwardVector = GetActorForwardVector();
	}
	float angle = ((acosf(FVector::DotProduct(_oldForwardVector, GetActorForwardVector()))) * (180 / PI));
	if ((angle >= _fDataStruct._minimumAngleForBunny &&
		!GetCharacterMovement()->IsMovingOnGround() && InputComponent->GetAxisValue("Right") != 0) || _onBunny)
	{
		_onBunny = true;
		UE_LOG(LogTemp,Warning,TEXT("dzdfzf"));
		//Calculate current speed
		FVector horizontalMovement = GetCharacterMovement()->Velocity;
		horizontalMovement.Z = 0.0f;
		float speed = horizontalMovement.Size();
	
		//Get the rotation of pawn
		FRotator rotation = GetActorRotation();
		FVector rotationVec = rotation.Vector();
	
		//Apply speed to rotation vector
		rotationVec.X *= speed;
		rotationVec.Y *= speed;
	
		//Set new movement velocity
		GetCharacterMovement()->Velocity.X = rotationVec.X;
		GetCharacterMovement()->Velocity.Y = rotationVec.Y;
	}
	_oldForwardVector = GetActorForwardVector();
}


void AMyCharacterController::JumpPlayer()
{
	if(GetCharacterMovement()->IsMovingOnGround())
	{
		AccelerationVelocity();
		Jump();
	}
	else
	{
		GetWorldTimerManager().SetTimer(ManagerTimeJump,this,&AMyCharacterController::JumpWindow,_fDataStruct._jumpWindow,
			false,_fDataStruct._jumpWindow);
	}
}

void AMyCharacterController::AccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed  = FMath::Clamp(GetCharacterMovement()->MaxWalkSpeed * _fDataStruct._acceleration,_fDataStruct._speed,
		_fDataStruct._maxSpeed);
	//GetCharacterMovement()->Velocity *= _fDataStruct._acceleration;
}

void AMyCharacterController::ResetAccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed = _fDataStruct._speed;
	if (GetWorldTimerManager().TimerExists(ManagerTime))
	{
		GetWorldTimerManager().ClearTimer(ManagerTime);
	}
}

void AMyCharacterController::JumpWindow()
{
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		AccelerationVelocity();
		Jump(); 
	}
	GetWorldTimerManager().ClearTimer(ManagerTimeJump);
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





