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
	GetCharacterMovement()->MaxWalkSpeed = _fDataStruct._groundSpeed;
	GetCharacterMovement()->JumpZVelocity = _fDataStruct._height;
	GetCharacterMovement()->GravityScale *= _fDataStruct._weight;
	GetCharacterMovement()->BrakingFrictionFactor = _fDataStruct._deceleration;
}

// Called every frame
void AMyCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovementPlayer();
	// if (GetCharacterMovement()->IsMovingOnGround())
	// {
	// 	if (GetCharacterMovement()->Velocity == FVector(0,0,0))
	// 	{
	// 		if (!GetWorldTimerManager().TimerExists(ManagerTime))
	// 		{
	// 			GetWorldTimerManager().SetTimer(ManagerTime,this,&AMyCharacterController::ResetAccelerationVelocity,_fDataStruct._timeBeforeDecceleration
	// 				,true,_fDataStruct._timeBeforeDecceleration);
	// 		}
	// 	}
	// }
	// else
	// {
	// 	if (GetWorldTimerManager().TimerExists(ManagerTime))
	// 	{
	// 		GetWorldTimerManager().ClearTimer(ManagerTime);
	// 	}
	// }

	// if (_onBunny)
	// {
	// 	if (GetInputAxisValue("Right") == 0)
	// 	{
	// 		_onBunny = false;
	// 	}
	// }
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

	// if (!GetWorldTimerManager().TimerExists(ManagerTimeDotRotation))
	// {
	// 	GetWorldTimerManager().SetTimer(ManagerTimeDotRotation,this,&AMyCharacterController::StopBunnyHop,_timeBeforeBunnyStop,
	// 		false,_timeBeforeBunnyStop);
	// }	
}

void AMyCharacterController::ForwardPlayer(float _value)
{
	//AddMovementInput(GetActorForwardVector(),_value);
	// else
	// {
	// 	float _normVelocity = GetCharacterMovement()->Velocity.Size();
	// 	GetCharacterMovement()->Velocity.X = _normVelocity * GetActorForwardVector().X;
	// 	GetCharacterMovement()->Velocity.Y = _normVelocity * GetActorForwardVector().Y;
	// }
	//GetCharacterMovement()->Velocity.X = GetActorForwardVector().X * _value * GetCharacterMovement()->MaxWalkSpeed;
	//MovementPlayer();
	//GetCharacterMovement()->Velocity += GetActorForwardVector();
}

void AMyCharacterController::RightPlayer(float _value)
{
	//AddMovementInput(GetActorRightVector(),_value);
	// else
	// {
	// 	float _normVelocity = GetCharacterMovement()->Velocity.Size();
	// 	GetCharacterMovement()->Velocity.X = _normVelocity * GetActorRightVector().X * _value;
	// 	GetCharacterMovement()->Velocity.Y = _normVelocity * GetActorRightVector().Y * _value;
	// }
	//MovementPlayer();
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
}

void AMyCharacterController::MovementPlayer()
{
FVector VelocityPlayer = GetCharacterMovement()->Velocity;
	float accelVel; // Accelerated velocity in direction of movment
	float InputForward;
	float InputRight;
	if (GetCharacterMovement()->IsMovingOnGround() && !_onBunny)
	{
		// float speed = VelocityPlayer.Size();
		// if (speed != 0) // To avoid divide by zero errors
		// {
		// 	float drop = speed * 2 * GetWorld()->GetDeltaSeconds();
		// 	VelocityPlayer *= FMath::Max(speed - drop, 0.f) / speed; // Scale the velocity based on friction.
		// }
		accelVel = _fDataStruct._groundSpeed ;//* GetWorld()->GetDeltaSeconds();
		InputForward = InputComponent->GetAxisValue("Forward");
		InputRight = InputComponent->GetAxisValue("Right");
	}
	else
	{
		accelVel = _fDataStruct._airAcceleration; // * GetWorld()->GetDeltaSeconds();
		InputForward = InputComponent->GetAxisValue("Forward");
		InputRight = InputComponent->GetAxisValue("Right");//TODO make the direction follow Q or D during jump to create the perfect BUNNY
	}
	if (InputForward == 0 && InputRight == 0)
	{
		_onBunny = false;
		GetWorldTimerManager().ClearTimer(ManagerTimeDotRotation);
	}
	FVector AccelDirection =  GetActorForwardVector() * InputForward + GetActorRightVector() * InputRight;
	if (AccelDirection.Size() > 1)
	{
		AccelDirection.Normalize();
	}
	float projVel = FVector::DotProduct(VelocityPlayer, AccelDirection); // Vector projection of Current velocity onto accelDir.

	// If necessary, truncate the accelerated velocity so the vector projection does not exceed max_velocity
	if(projVel + accelVel >_fDataStruct._maxSpeed)
		accelVel = _fDataStruct._maxSpeed - projVel;

	//FVector2D Velocity2D = FVector2D(GetCharacterMovement()->Velocity.X,GetCharacterMovement()->Velocity.Y);
	if (_onBunny && GetCharacterMovement()->IsMovingOnGround())
	{
		if (!GetWorldTimerManager().TimerExists(ManagerTimeDotRotation))
		{
			GetWorldTimerManager().SetTimer(ManagerTimeDotRotation,this,&AMyCharacterController::StopBunnyHop,_fDataStruct._timeBeforeBunnyStop,
				false,_fDataStruct._timeBeforeBunnyStop);
		}	
	}else if (GetWorldTimerManager().TimerExists(ManagerTimeDotRotation))
	{
		GetWorldTimerManager().ClearTimer(ManagerTimeDotRotation);
	}
	if (!GetCharacterMovement()->IsMovingOnGround())
	{
		_decelerationVelocityGround = 0;
		if (_bunnyVelocity != 0)
		{
			_bunnyVelocity = 0;
		}
		if (/*InputComponent->GetAxisValue("Right") != 0 && */ _onBunny)
		{
			//UE_LOG(LogTemp,Warning,TEXT("test"))
			FVector2D Velocity2D = FVector2D( GetCharacterMovement()->Velocity.X,GetCharacterMovement()->Velocity.Y);
			GetCharacterMovement()->Velocity.X = GetActorForwardVector().X * Velocity2D.Size() + AccelDirection.X * accelVel;
			GetCharacterMovement()->Velocity.Y = GetActorForwardVector().Y * Velocity2D.Size() + AccelDirection.Y * accelVel;
		}
		else
		{
			if (_decelerationJump)
			{
				if (_bunnyVelocity == 0)
				{
					_bunnyVelocity = GetCharacterMovement()->Velocity.Size();
				}
				_decelerationVelocityGround = _decelerationVelocityGround + GetWorld()->GetDeltaSeconds()/_fDataStruct._timeBeforeBunnyStop;
				if (_jumpFollowDirection)
				{
					GetCharacterMovement()->Velocity = AccelDirection * FMath::Lerp(_bunnyVelocity,_fDataStruct._airSpeed,_decelerationVelocityGround); //accelVel;
					// GetCharacterMovement()->Velocity.X = AccelDirection.X * _fDataStruct._airSpeed;// * accelVel;
					// GetCharacterMovement()->Velocity.Y = AccelDirection.Y * _fDataStruct._airSpeed;
				}
				else
				{
					GetCharacterMovement()->Velocity = AccelDirection * FMath::Lerp(_bunnyVelocity,_fDataStruct._airSpeed,_decelerationVelocityGround); //accelVel;
					// GetCharacterMovement()->Velocity.X = AccelDirection.X * _fDataStruct._airSpeed;// * accelVel;
					// GetCharacterMovement()->Velocity.Y = AccelDirection.Y * _fDataStruct._airSpeed;
				}
			}
			else
			{
				if (_jumpFollowDirection)
				{
					GetCharacterMovement()->Velocity.X = AccelDirection.X * _fDataStruct._airSpeed;// * accelVel;
					GetCharacterMovement()->Velocity.Y = AccelDirection.Y * _fDataStruct._airSpeed;
				}
				else
				{
					GetCharacterMovement()->Velocity.X = AccelDirection.X * _fDataStruct._airSpeed;// * accelVel;
					GetCharacterMovement()->Velocity.Y = AccelDirection.Y * _fDataStruct._airSpeed;
				}
				
			}
		}
	}
	else
	{
		if (_onBunny)
		{
			if (_bunnyVelocity == 0)
			{
				_bunnyVelocity = GetCharacterMovement()->Velocity.Size();
			}
			// float speed = VelocityPlayer.Size();
			// if (speed != 0) // To avoid divide by zero errors
			// {
			// 	float drop = speed * 2 * GetWorld()->GetDeltaSeconds();
			// 	VelocityPlayer *= FMath::Max(speed - drop, 0.f) / speed; // Scale the velocity based on friction.
			// }
			 _decelerationVelocityGround = _decelerationVelocityGround + GetWorld()->GetDeltaSeconds()/_fDataStruct._timeBeforeBunnyStop;
			// float test =VelocityPlayer.Size();
			// UE_LOG(LogTemp,Warning,TEXT("%f"),test)
			GetCharacterMovement()->Velocity = AccelDirection * FMath::Lerp(_bunnyVelocity,_fDataStruct._groundSpeed,_decelerationVelocityGround); //accelVel;
		}
		else
		{
			if (_bunnyVelocity != 0)
			{
				_bunnyVelocity = 0;
			}
			_decelerationVelocityGround = 0;
			GetCharacterMovement()->Velocity = accelVel * AccelDirection;
		}
	}

	// GetCharacterMovement()->Velocity.X = GetActorForwardVector().X * Velocity2D.Size() + AccelDirection.X * accelVel;
	// GetCharacterMovement()->Velocity.Y = GetActorForwardVector().Y * Velocity2D.Size() + AccelDirection.Y * accelVel;


	// FVector ConteneurCameraPositionForward = GetActorForwardVector();
	// FVector ConteneurCameraPositionRight = GetActorRightVector() * InputComponent->GetAxisValue("Right");
	// FVector Vector3_Deplacement_Player =  ConteneurCameraPositionForward + ConteneurCameraPositionRight;
	// GetCharacterMovement()->Velocity *= FVector(GetActorForwardVector().X,1,1);

	
	
	// if (GetCharacterMovement()->IsMovingOnGround())
	// {
	// 	FVector _forwardDirection = GetActorForwardVector() * InputComponent->GetAxisValue("Forward");
	// 	FVector _rightMovement = GetActorRightVector() * InputComponent->GetAxisValue("Right");
	// 	FVector _directionPlayer =  (_forwardDirection + _rightMovement).GetSafeNormal();
	// 	GetCharacterMovement()->Velocity = _directionPlayer * GetCharacterMovement()->MaxWalkSpeed + FVector(0,0,GetCharacterMovement()->Velocity.Z);
	// 	
	// 	// GetCharacterMovement()->Velocity = FVector(InputComponent->GetAxisValue("Forward") * _fDataStruct._groundSpeed 
	// 	// 	, InputComponent->GetAxisValue("Right") * _fDataStruct._groundSpeed,GetCharacterMovement()->Velocity.Z) * rotationVec;
	// }else
	// {
	// 	FVector ConteneurCameraPositionForward = GetActorForwardVector();
	// 	FVector ConteneurCameraPositionRight = GetActorRightVector() * InputComponent->GetAxisValue("Right");
	// 	FVector Vector3_Deplacement_Player =  ConteneurCameraPositionForward + ConteneurCameraPositionRight;
	// 	GetCharacterMovement()->Velocity *= FVector(GetActorForwardVector().X,1,1);
	// 	// GetCharacterMovement()->Velocity = FVector(Vector3_Deplacement_Player.X * GetCharacterMovement()->Velocity.X,
	// 	// 		Vector3_Deplacement_Player.Y +  GetCharacterMovement()->Velocity.Y,GetCharacterMovement()->Velocity.Z);
	// }
	
	// if (_oldForwardVector == FVector(0,0,0))
	// {
	// 	_oldForwardVector = GetActorForwardVector();
	// }
	// float angle = ((acosf(FVector::DotProduct(_oldForwardVector, GetActorForwardVector()))) * (180 / PI));
	// if (//(angle >= _fDataStruct._minimumAngleForBunny &&
	// 	!GetCharacterMovement()->IsMovingOnGround()
	// 	&& InputComponent->GetAxisValue("Right") != 0)// || _onBunny)
	// {
	// 	_onBunny = true;
	// 	UE_LOG(LogTemp,Warning,TEXT("dzdfzf"));
	// 	//Calculate current speed
	// 	FVector horizontalMovement = GetCharacterMovement()->Velocity;
	// 	horizontalMovement.Z = 0.0f;
	// 	float speed = horizontalMovement.Size();
	//
	// 	//Get the rotation of pawn
	// 	FRotator rotation = GetActorRotation();
	// 	FVector rotationVec = rotation.Vector();
	//
	// 	//Apply speed to rotation vector
	// 	rotationVec.X *= speed;
	// 	rotationVec.Y *= speed;
	//
	// 	//Set new movement velocity
	// 	GetCharacterMovement()->Velocity.X = rotationVec.X;
	// 	//GetCharacterMovement()->Velocity.Y = rotationVec.Y;
	// }
	// _oldForwardVector = GetActorForwardVector();
}

void AMyCharacterController::StopBunnyHop()
{
	// if (_oldForwardVector == FVector(0,0,0))
	// {
	// 	_oldForwardVector = GetActorForwardVector();
	// }
	// _oldForwardVector = GetActorForwardVector();
	_onBunny = false;
	GetWorldTimerManager().ClearTimer(ManagerTimeDotRotation);
}



void AMyCharacterController::JumpPlayer()
{
	if(GetCharacterMovement()->IsMovingOnGround())
	{
		if (InputComponent->GetAxisValue("Right") != 0)
		{
			//float angle = ((acosf(FVector::DotProduct(_oldForwardVector, GetActorForwardVector()))) * (180 / PI));
			if (InputComponent->GetAxisValue("Right") < 0 && InputComponent->GetAxisValue("Turn") <= -0.1f)
			{
				_onBunny = true;
			}else if (InputComponent->GetAxisValue("Right") > 0 && InputComponent->GetAxisValue("Turn") >= 0.1f)
			{
				_onBunny = true;
			}
			else
			{
				if (_onBunny)
				{
					_onBunny = false;
				}
			}
		}
		else
		{
			if (_onBunny)
			{
				_onBunny = false;
			}
		}
		Jump();
		// float angle = ((acosf(FVector::DotProduct(_oldForwardVector, GetActorForwardVector()))) * (180 / PI));
		// if (GetInputAxisValue("Right") != 0 && angle >= _fDataStruct._minimumAngleForBunny)
		// {
		// 	UE_LOG(LogTemp,Warning,TEXT("%d"),angle);
		// 	AccelerationVelocity();
		// }
	}
	else
	{
		GetWorldTimerManager().SetTimer(ManagerTimeJump,this,&AMyCharacterController::JumpWindow,_fDataStruct._jumpWindow,
			false,_fDataStruct._jumpWindow);
	}
}

void AMyCharacterController::AccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed  = FMath::Clamp(GetCharacterMovement()->MaxWalkSpeed * _fDataStruct._airAcceleration,_fDataStruct._groundSpeed,
		_fDataStruct._maxSpeed);
	//GetCharacterMovement()->Velocity *= _fDataStruct._airAcceleration;
}

void AMyCharacterController::ResetAccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed = _fDataStruct._groundSpeed;
	if (GetWorldTimerManager().TimerExists(ManagerTime))
	{
		GetWorldTimerManager().ClearTimer(ManagerTime);
	}
}

void AMyCharacterController::JumpWindow()
{
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		//AccelerationVelocity();
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





