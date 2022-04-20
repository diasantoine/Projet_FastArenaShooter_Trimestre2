// Fill out your copyright notice in the Description page of Project Settings.


#include "FASCharacter.h"

#include "RiffleWeapon.h"
#include "RocketLauncher.h"
#include "TimerManager.h"
#include "WeaponShotGun.h"
#include "Components/Image.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values

void AFASCharacter::OnConstruction(const FTransform& Transform)
{
	
}


AFASCharacter::AFASCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	GetMesh()->SetOnlyOwnerSee(true);
	GetMesh()->bCastDynamicShadow = false;
	GetMesh()->CastShadow = false;
	GetMesh()->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	GetMesh()->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(false);			// otherwise won't be visible in the multiplayer
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
	FP_Gun->SetupAttachment(RootComponent);
	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));
}

void AFASCharacter::InitialiseWeapon()
{
	for(const auto& Weapon : _weaponTypes)
	{
		if(!weapons.Contains(Weapon.Value))
		{
			AMyWeaponBehaviour* container = GetWorld()->SpawnActor<AMyWeaponBehaviour>(Weapon.Value,GetActorLocation() + FVector(50,0,25),GetActorRotation());
			container->AttachToComponent(FP_Gun,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			container->SetActorHiddenInGame(true);
			weapons.Add(Weapon.Value,container);
		}
	}
}

// Called when the game starts or when spawned
void AFASCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = _fDataStruct._groundSpeed;
	GetCharacterMovement()->JumpZVelocity = _fDataStruct._height;
	GetCharacterMovement()->GravityScale *= _fDataStruct._weight;
	GetCharacterMovement()->BrakingFrictionFactor = _fDataStruct._deceleration;
	InitialiseWeapon();
	TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[_WeaponType];
	weaponBehaviourObject = weapons[weaponBehaviourClass];
	weaponBehaviourObject->SetActorHiddenInGame(false);
	_actualHP = _fDataStruct._hpMax;
	_userWidgetMunition->SwapWeapon(_WeaponType);
	_containerWhichWeapon = _WeaponType;
	_numberOfLifeLeft = _fDataStruct._numberOfLives;
}

// Called every frame
void AFASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	HPRegeneration(DeltaTime);
	CheckPlayerPosition();
	MovementPlayer();
	if (weaponBehaviourObject != nullptr)
	{
		if (weaponBehaviourObject->_justFireRecoil)
		{
			switch (_WeaponType)
			{
			case Riffle:
				KnockBackPlayer(RiffleKnock,weaponBehaviourObject->_dataWeapon._knockPlayerDuration,weaponBehaviourObject->_dataWeapon._recoilPower,
			-UGameplayStatics::GetPlayerCameraManager(GetWorld(),0)->GetActorForwardVector());
				break;
			case Shotgun:
				KnockBackPlayer(ShotgunKnock,weaponBehaviourObject->_dataWeapon._knockPlayerDuration,weaponBehaviourObject->_dataWeapon._recoilPower,
			-UGameplayStatics::GetPlayerCameraManager(GetWorld(),0)->GetActorForwardVector());
				default:
				break;
			case RocketLauncher:
				KnockBackPlayer(RocketLauncherKnock,weaponBehaviourObject->_dataWeapon._knockPlayerDuration,weaponBehaviourObject->_dataWeapon._recoilPower,
			-UGameplayStatics::GetPlayerCameraManager(GetWorld(),0)->GetActorForwardVector());
				break;
			}
		
			weaponBehaviourObject->_justFireRecoil = false;
		}
		weaponBehaviourObject->ActualSpeed = GetCharacterMovement()->Velocity.Size();
		weaponBehaviourObject->MaxSpeed = _fDataStruct._groundSpeed;
	}
	if (_WeaponType == RocketLauncher && _numberOfBunnyMade > 0)
	{
		_numberOfBunnyMade = 0;
	}
	// if (_onRecoil)
	// {
	// 	UE_LOG(LogTemp,Warning,TEXT("%f"), _containerRecoil);
	// }
	
	FP_Gun->SetRelativeRotation(FRotator(0,90,
		UGameplayStatics::GetPlayerCameraManager(GetWorld(),0)->GetCameraRotation().Pitch));//rotate weapon for style
	
	if (_onJumpAuto)
	{
		AutoJumpPlayer();
	}
	
	HudGestion();
}

// Called to bind functionality to input
void AFASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputPlayer();
}


void AFASCharacter::InputPlayer()
{
	this->InputComponent->BindAxis("Forward",this,&AFASCharacter::ForwardPlayer);
	this->InputComponent->BindAxis("Right",this,&AFASCharacter::RightPlayer);
	
	this->InputComponent->BindAxis("Turn", this, &AFASCharacter::YawRotation);
	this->InputComponent->BindAxis("LookUp", this, &AFASCharacter::PitchRotation);
	
	this->InputComponent->BindAction("Jump", IE_Pressed, this,&AFASCharacter::ActivationJumpPlayer);
	this->InputComponent->BindAction("Jump", IE_Released, this,&AFASCharacter::DesactivationJumpPlayer);
	this->InputComponent->BindAction<_typeOfFire>("NormalFire", IE_Pressed, this, &AFASCharacter::ShootWeapon,true);
	this->InputComponent->BindAction<_typeOfFire>("NormalFire", IE_Released, this, &AFASCharacter::StopShootWeapon,true);
	this->InputComponent->BindAction("SpecialFire",IE_Pressed,this,&AFASCharacter::ActivationJumpPlayer);
	this->InputComponent->BindAction("SpecialFire",IE_Released,this,&AFASCharacter::DesactivationJumpPlayer);
	this->InputComponent->BindAxis("WheelMouse",this,&AFASCharacter::ChangeWeapon);
}

void AFASCharacter::PitchRotation(float _value)
{
	APawn::AddControllerPitchInput(_value);
}

void AFASCharacter::YawRotation(float _value)
{
	APawn::AddControllerYawInput(_value);
}

void AFASCharacter::ForwardPlayer(float _value)
{
}

void AFASCharacter::RightPlayer(float _value)
{
}

void AFASCharacter::DamagePlayer(int DMG, AActor* Attaquant, float Power, bool AddImpulse)
{
	_recoveryTime = 0;
	_actualHP -= DMG;
	_actualHP = FMath::Clamp(_actualHP,0,_fDataStruct._hpMax);
	_userWidgetMunition->HPChange(_actualHP,_fDataStruct._hpMax);
	_onTakeDMG = true;
	if (_actualHP <= 0)
	{
		Respawn();
	}
	else
	{
		if (AddImpulse)
		{
			GetCharacterMovement()->AddImpulse(Power * Attaquant->GetActorForwardVector(), true);
		}
	}
}

void AFASCharacter::CheckPlayerPosition()
{
	if (GetActorLocation().X > _maxCoordinateValue.X || GetActorLocation().X < _minCoordinateValue.X)
	{
		Respawn();
	}else if (GetActorLocation().Y > _maxCoordinateValue.Y || GetActorLocation().Y < _minCoordinateValue.Y)
	{
		Respawn();
	}else if (GetActorLocation().Z > _maxCoordinateValue.Z || GetActorLocation().Z < _minCoordinateValue.Z)
	{
		Respawn();
	}
}


void AFASCharacter::Respawn()
{
	_numberOfLifeLeft--;
	if (_numberOfLifeLeft <= 0)
	{
		UE_LOG(LogTemp,Warning,TEXT("TES MORT"));
	}
	_actualHP = _fDataStruct._hpMax;
	_userWidgetMunition->HPChange(_actualHP,_fDataStruct._hpMax);
	_containerVelocityBunny = 0;
	_onBunny = false;
	_keepBunnySpeed = false;
	_forwardSign = 1;
	GetWorldTimerManager().ClearTimer(ManagerTimeDotRotation);
	GetCharacterMovement()->Velocity = {0,0,0};
	SetActorLocation(_respawnPosition);
}

void AFASCharacter::HPRegeneration(float DeltaTime)
{
	if (_actualHP != _fDataStruct._hpMax)
	{
		_recoveryTime += DeltaTime;
		if (_recoveryTime >= _fDataStruct._timeBeforeRecovery)
		{
			_actualHP += _fDataStruct._hpRecovery;
			_userWidgetMunition->HPChange(_actualHP,_fDataStruct._hpMax);
			_recoveryTime = 0;
		}
	}
	else
	{
		_recoveryTime = 0;
	}
}


void AFASCharacter::MovementPlayer()
{
	FVector VelocityPlayer = GetCharacterMovement()->Velocity;
	float accelVel; // Accelerated velocity in direction of movment
	float InputForward;
	float InputRight;
	FVector AccelDirection;
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
		AccelDirection =  GetActorForwardVector() * InputForward + GetActorRightVector() * InputRight;
	}
	else
	{
		accelVel = _fDataStruct._airAcceleration; // * GetWorld()->GetDeltaSeconds();
		InputForward = InputComponent->GetAxisValue("Forward");
		InputRight = InputComponent->GetAxisValue("Right");//TODO make the direction follow Q or D during jump to create the perfect BUNNY
		if (_onBunny)
		{
			if (_casualBunny)
			{
				AccelDirection = GetActorRightVector();// * InputRight;
			}
			else
			{
				AccelDirection = GetActorRightVector() * InputRight;
			}
		}
		else
		{
			AccelDirection =  GetActorForwardVector() * InputForward + GetActorRightVector() * InputRight;
		}
	}
	if (InputForward == 0 && InputRight == 0 && !_onJumpAuto)
	{
		
		//_containerVelocityBunny = 0;
		//_onBunny = false;
		//_keepBunnySpeed = false;
		StopBunnyHop();
	}
	if (AccelDirection.Size() > 1)
	{
		AccelDirection.Normalize();
	}
	float projVel = FVector::DotProduct(VelocityPlayer, AccelDirection); // Vector projection of Current velocity onto accelDir.

	// If necessary, truncate the accelerated velocity so the vector projection does not exceed max_velocity
	if(projVel + accelVel >_fDataStruct._maxSpeed)
		accelVel = _fDataStruct._maxSpeed - projVel;

	//FVector2D Velocity2D = FVector2D(GetCharacterMovement()->Velocity.X,GetCharacterMovement()->Velocity.Y);
	if (/*_keepBunnySpeed && */ !_onJumpAuto && GetCharacterMovement()->IsMovingOnGround())
	{
		_onBunny = false;
		StopBunnyHop();
		// if (!GetWorldTimerManager().TimerExists(ManagerTimeDotRotation))
		// {
		// 	GetWorldTimerManager().SetTimer(ManagerTimeDotRotation,this,&AFASCharacter::StopBunnyHop,_fDataStruct._timeBeforeBunnyStop,
		// 		false,_fDataStruct._timeBeforeBunnyStop);
		// }	
	}else if (GetWorldTimerManager().TimerExists(ManagerTimeDotRotation))
	{
		GetWorldTimerManager().ClearTimer(ManagerTimeDotRotation);
	}
	
	if (!GetCharacterMovement()->IsMovingOnGround() ||_onBunny)
	{
		_decelerationVelocityGround = 0;
		if (_bunnyVelocity != 0)
		{
			_bunnyVelocity = 0;
		}
		if (InputComponent->GetAxisValue("Right") != 0 && _onBunny || _onBunny && _casualBunny)
		{
			FVector2D Velocity2D = FVector2D( GetCharacterMovement()->Velocity.X,GetCharacterMovement()->Velocity.Y);
			GetCharacterMovement()->Velocity.X = _forwardSign * GetActorForwardVector().X * Velocity2D.Size() + AccelDirection.X * accelVel;
			GetCharacterMovement()->Velocity.Y = _forwardSign * GetActorForwardVector().Y * Velocity2D.Size() + AccelDirection.Y * accelVel;
			_containerVelocityBunny = GetCharacterMovement()->Velocity.Size();
			//UE_LOG(LogTemp,Warning,TEXT("%f"),_containerVelocityBunny)
			if (_WeaponType != Shotgun && GetCharacterMovement()->Velocity.Size() >= _fDataStruct._maxSpeed * _fDataStruct._reloadShotGunPercentagelvl1)
			{
				if (_timeBeforeReloadShotGun >= _fDataStruct._timeBeforeReloadShotGun)
				{
					_timeBeforeReloadShotGun = 0;
					if (GetCharacterMovement()->Velocity.Size() >= _fDataStruct._maxSpeed * _fDataStruct._reloadShotGunPercentagelvl3)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[Shotgun];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						if (_ContainerpercentageSpeedMaxSpeedShotGun != _fDataStruct._percentageSpeedMaxSpeedlvl3)
						{
							_ContainerpercentageSpeedMaxSpeedShotGun = _fDataStruct._percentageSpeedMaxSpeedlvl3;
						}
					}else if (GetCharacterMovement()->Velocity.Size() >= _fDataStruct._maxSpeed * _fDataStruct._reloadShotGunPercentagelvl2)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[Shotgun];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						if (_ContainerpercentageSpeedMaxSpeedShotGun != _fDataStruct._percentageSpeedMaxSpeedlvl2 &&
							_ContainerpercentageSpeedMaxSpeedShotGun != _fDataStruct._percentageSpeedMaxSpeedlvl3)
						{
							_ContainerpercentageSpeedMaxSpeedShotGun = _fDataStruct._percentageSpeedMaxSpeedlvl2;
						}
					}else
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[Shotgun];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						if (_ContainerpercentageSpeedMaxSpeedShotGun != _fDataStruct._percentageSpeedMaxSpeedlvl2 &&
							_ContainerpercentageSpeedMaxSpeedShotGun != _fDataStruct._percentageSpeedMaxSpeedlvl3)
						{
							_ContainerpercentageSpeedMaxSpeedShotGun = _fDataStruct._percentageSpeedMaxSpeedlvl1;
						}
					}
				}else
				{
					_timeBeforeReloadShotGun += GetWorld()->GetDeltaSeconds();
				}
			}else
			{
				if (_timeBeforeReloadShotGun > 0)
				{
					_timeBeforeReloadShotGun = 0;
				}
			}
			if (_onRecoil)
			{
				if (_containerRecoil > 0)
				{
					_containerRecoil -= GetWorld()->GetDeltaSeconds();
				}
				else
				{
					_containerRecoil = 0;
					_onRecoil = false;
				}
			}
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
					//GetCharacterMovement()->Velocity = AccelDirection * FMath::Lerp(_bunnyVelocity,_fDataStruct._airSpeed,_decelerationVelocityGround); //accelVel;
					// GetCharacterMovement()->Velocity.X = AccelDirection.X * FMath::Lerp(_bunnyVelocity,_fDataStruct._airSpeed,_decelerationVelocityGround);// * accelVel;
					// GetCharacterMovement()->Velocity.Y = AccelDirection.Y * FMath::Lerp(_bunnyVelocity,_fDataStruct._airSpeed,_decelerationVelocityGround);
					FVector2D Velocity2D = FVector2D( GetCharacterMovement()->Velocity.X,GetCharacterMovement()->Velocity.Y);
					GetCharacterMovement()->Velocity.X = GetActorForwardVector().X * FMath::Lerp(Velocity2D.Size(),_fDataStruct._airSpeed,_decelerationVelocityGround)
					+ AccelDirection.X;
					GetCharacterMovement()->Velocity.Y = GetActorForwardVector().Y * FMath::Lerp(Velocity2D.Size(),_fDataStruct._airSpeed,_decelerationVelocityGround)
					+ AccelDirection.Y;
				}
				else
				{
					//GetCharacterMovement()->Velocity = AccelDirection * FMath::Lerp(_bunnyVelocity,_fDataStruct._airSpeed,_decelerationVelocityGround); //accelVel;
					FVector2D Velocity2D = FVector2D( GetCharacterMovement()->Velocity.X,GetCharacterMovement()->Velocity.Y);
					GetCharacterMovement()->Velocity.X = AccelDirection.X * FMath::Lerp(Velocity2D.Size(),_fDataStruct._airSpeed,_decelerationVelocityGround);
					GetCharacterMovement()->Velocity.Y = AccelDirection.Y * FMath::Lerp(Velocity2D.Size(),_fDataStruct._airSpeed,_decelerationVelocityGround);
				}
			}
			else
			{
				if (_jumpFollowDirection)
				{
					FVector2D Velocity2D = FVector2D( GetCharacterMovement()->Velocity.X,GetCharacterMovement()->Velocity.Y);
					GetCharacterMovement()->Velocity.X = GetActorForwardVector().X * Velocity2D.Size() + AccelDirection.X;
					GetCharacterMovement()->Velocity.Y = GetActorForwardVector().Y * Velocity2D.Size() + AccelDirection.Y;
					// GetCharacterMovement()->Velocity.X = AccelDirection.X * _fDataStruct._airSpeed;// * accelVel;
					// GetCharacterMovement()->Velocity.Y = AccelDirection.Y * _fDataStruct._airSpeed;
				}
				else
				{
					if (_onRecoil)
					{
						if (_containerRecoil > 0)
						{
							_containerRecoil -= GetWorld()->GetDeltaSeconds();
						}
						else
						{
							_containerRecoil = 0;
							_onRecoil = false;
						}
					}
					else
					{
						if (_containerVelocityBunny == 0)
						{
							GetCharacterMovement()->Velocity.X = AccelDirection.X * _fDataStruct._airSpeed;// * accelVel;
							GetCharacterMovement()->Velocity.Y = AccelDirection.Y * _fDataStruct._airSpeed;
						}
						else
						{
							// GetCharacterMovement()->Velocity.X += accelVel;
							// GetCharacterMovement()->Velocity.Y += accelVel;
							// GetCharacterMovement()->Velocity.X = 1 * _containerVelocityBunny;
							// GetCharacterMovement()->Velocity.Y = AccelDirection.Y * _containerVelocityBunny;
						}
					}
				}
			}
		}
	}
	else
	{
		if (_onRecoil)
		{
			if (_containerRecoil > 0)
			{
				_containerRecoil -= GetWorld()->GetDeltaSeconds();
			}
			else
			{
				_containerRecoil = 0;
				_onRecoil = false;
			}
		}
		else
		{
			if (_keepBunnySpeed)//Todo le bunny se met en false que si je le rate, 
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
				GetCharacterMovement()->Velocity = GetCharacterMovement()->Velocity.GetSafeNormal() * FMath::Lerp(_bunnyVelocity,_fDataStruct._groundSpeed,_decelerationVelocityGround); //accelVel;
				}
			else
			{
				if (_WeaponType != Riffle && GetCharacterMovement()->Velocity.Size() >= _fDataStruct._groundSpeed * _fDataStruct._reloadRifflePercentageMaxGroundSpeedlvl1)
				{
					if (_timeBeforeReloadRiffle > _fDataStruct._timeBeforeReloadRiffle)
					{
						if (GetCharacterMovement()->Velocity.Size() >= _fDataStruct._groundSpeed * _fDataStruct._reloadRifflePercentageMaxGroundSpeedlvl3)
						{
							_timeBeforeReloadRiffle = 0;
							TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[Riffle];
							AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
							weaponBehaviourObjectReload->Reload(_userWidgetMunition);
							if (_ContainerpercentageSpeedMaxSpeedRiffle != _fDataStruct._percentageSpeedMaxSpeedlvl3)
							{
								_ContainerpercentageSpeedMaxSpeedRiffle= _fDataStruct._percentageSpeedMaxSpeedlvl3;
							}
						}else if (GetCharacterMovement()->Velocity.Size() >= _fDataStruct._groundSpeed * _fDataStruct._reloadRifflePercentageMaxGroundSpeedlvl2)
						{
							_timeBeforeReloadRiffle = 0;
							TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[Riffle];
							AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
							weaponBehaviourObjectReload->Reload(_userWidgetMunition);
							if (_ContainerpercentageSpeedMaxSpeedRiffle != _fDataStruct._percentageSpeedMaxSpeedlvl3 &&
								_ContainerpercentageSpeedMaxSpeedRiffle != _fDataStruct._percentageSpeedMaxSpeedlvl2)
							{
								_ContainerpercentageSpeedMaxSpeedRiffle= _fDataStruct._percentageSpeedMaxSpeedlvl2;
							}
						}
						else
						{
							_timeBeforeReloadRiffle = 0;
							TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[Riffle];
							AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
							weaponBehaviourObjectReload->Reload(_userWidgetMunition);
							if (_ContainerpercentageSpeedMaxSpeedRiffle != _fDataStruct._percentageSpeedMaxSpeedlvl3 &&
								_ContainerpercentageSpeedMaxSpeedRiffle != _fDataStruct._percentageSpeedMaxSpeedlvl2)
							{
								_ContainerpercentageSpeedMaxSpeedRiffle= _fDataStruct._percentageSpeedMaxSpeedlvl1;
							}
						}
					}else
					{
						_timeBeforeReloadRiffle += GetWorld()->GetDeltaSeconds();
					}
				}else
				{
					_timeBeforeReloadRiffle = 0;
				}
				if (_bunnyVelocity == 0)
				{
					_bunnyVelocity = GetCharacterMovement()->Velocity.Size();
				}
				//UE_LOG(LogTemp,Warning,TEXT("%f"),_containerVelocityBunny)
				if (_bunnyVelocity != 0)
				{
					_bunnyVelocity = 0;
				}
				_containerVelocityBunny = 0;
				_decelerationVelocityGround = 0;
				GetCharacterMovement()->Velocity = accelVel * AccelDirection;
			}
		}
	}
	GetCharacterMovement()->Velocity = FMath::Clamp(GetCharacterMovement()->Velocity.Size(),0.0f,_fDataStruct._maxSpeed) * GetCharacterMovement()->Velocity.GetSafeNormal();
}

void AFASCharacter::StopBunnyHop()
{
	// if (_oldForwardVector == FVector(0,0,0))
	// {
	// 	_oldForwardVector = GetActorForwardVector();
	// }
	// _oldForwardVector = GetActorForwardVector();
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		_containerVelocityBunny = 0;
		_onBunny = false;
		_keepBunnySpeed = false;
	}
//	UE_LOG(LogTemp,Warning,TEXT("%f"), _forwardSign);
	//_forwardSign = 1;
	GetWorldTimerManager().ClearTimer(ManagerTimeDotRotation);
}



void AFASCharacter::ActivationJumpPlayer()
{
	_onJumpAuto = true;
}

void AFASCharacter::DesactivationJumpPlayer()
{
	_onJumpAuto = false;
	StopJumping();
}


void AFASCharacter::AutoJumpPlayer()
{
	if(GetCharacterMovement()->IsMovingOnGround())
	{
		Jump();
		// float angle = ((acosf(FVector::DotProduct(_oldForwardVector, GetActorForwardVector()))) * (180 / PI));
		// if (GetInputAxisValue("Right") != 0 && angle >= _fDataStruct._AmountOfMovementForBunny)
		// {
		// 	UE_LOG(LogTemp,Warning,TEXT("%d"),angle);
		// 	AccelerationVelocity();
		// }
		if (InputComponent->GetAxisValue("Right") != 0)
		{
			//float angle = ((acosf(FVector::DotProduct(_oldForwardVector, GetActorForwardVector()))) * (180 / PI));
			if (InputComponent->GetAxisValue("Right") < 0 && InputComponent->GetAxisValue("Turn") <= -_fDataStruct._AmountOfMovementForBunny)
			//if (InputComponent->GetAxisValue("Turn") <= -_fDataStruct._AmountOfMovementForBunny)
			{
				if (_WeaponType != RocketLauncher)
				{
					_numberOfBunnyMade++;
					if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl3)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl3;
					}else if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl2)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl2;
					}else if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl1)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl1;
					}
				}else
				{
					if (_numberOfBunnyMade > 0)
					{
						_numberOfBunnyMade = 0;
					}
				}
				_onBunny = true;
				_keepBunnySpeed = true;
			}else //if (InputComponent->GetAxisValue("Turn") >= _fDataStruct._AmountOfMovementForBunny)
				if (InputComponent->GetAxisValue("Right") > 0 && InputComponent->GetAxisValue("Turn") >= _fDataStruct._AmountOfMovementForBunny)
			{
				if (_WeaponType != RocketLauncher)
				{
					// TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
					// AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
					// weaponBehaviourObjectReload->Reload(_userWidgetMunition);
					_numberOfBunnyMade++;
					if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl3)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl3;
					}else if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl2)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl2;
					}else if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl1)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl1;
					}
				}else
				{
					if (_numberOfBunnyMade > 0)
					{
						_numberOfBunnyMade = 0;
					}
				}
				_onBunny = true;
				_keepBunnySpeed = true;
			}else if  (InputComponent->GetAxisValue("Forward") != 0)
			{
				if (InputComponent->GetAxisValue("Forward") > 0)
				{
					_forwardSign = 1;
				}else
				{
					_forwardSign = -1;
				}
				if (_WeaponType != RocketLauncher)
				{
					_numberOfBunnyMade++;
					if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl3)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl3;
					}else if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl2)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl2;
					}else if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl1)
					{
						TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
						AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
						weaponBehaviourObjectReload->Reload(_userWidgetMunition);
						_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl1;
					}
				}else
				{
					if (_numberOfBunnyMade > 0)
					{
						_numberOfBunnyMade = 0;
					}
				}
				_onBunny = true;
				_keepBunnySpeed = true;
			}
			else
			{
				if (_onBunny)
				{
					_onBunny = false;
				}
			}
		}
		else if (InputComponent->GetAxisValue("Forward") != 0)
		{
			if (InputComponent->GetAxisValue("Forward") > 0)
			{
				_forwardSign = 1;
			}else
			{
				_forwardSign = -1;
			}
			if (_WeaponType != RocketLauncher)
			{
				_numberOfBunnyMade++;
				_numberOfBunnyMade++;
				if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl3)
				{
					TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
					AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
					weaponBehaviourObjectReload->Reload(_userWidgetMunition);
					_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl3;
				}else if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl2)
				{
					TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
					AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
					weaponBehaviourObjectReload->Reload(_userWidgetMunition);
					_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl2;
				}else if (_numberOfBunnyMade >= _fDataStruct._numberOfBunnyForReloadRocketLauncherlvl1)
				{
					TSubclassOf<AMyWeaponBehaviour>& weaponBehaviourClass = _weaponTypes[RocketLauncher];
					AMyWeaponBehaviour* weaponBehaviourObjectReload = weapons[weaponBehaviourClass];
					weaponBehaviourObjectReload->Reload(_userWidgetMunition);
					_ContainerpercentageSpeedMaxSpeedRocketLauncher = _fDataStruct._percentageSpeedMaxSpeedlvl1;
				}
			}else
			{
				if (_numberOfBunnyMade > 0)
				{
					_numberOfBunnyMade = 0;
				}
			}
			_onBunny = true;
			_keepBunnySpeed = true;
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
		if (InputComponent->GetAxisValue("Right") == 0 && InputComponent->GetAxisValue("Forward") == 0)
		{
			if (_onBunny)
			{
				_onBunny = false;
			}
		}
	}
	// else
	// {
	// 	GetWorldTimerManager().SetTimer(ManagerTimeJump,this,&AFASCharacter::JumpWindow,_fDataStruct._jumpWindow,
	// 		false,_fDataStruct._jumpWindow);
	// }
}



void AFASCharacter::AccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed  = FMath::Clamp(GetCharacterMovement()->MaxWalkSpeed * _fDataStruct._airAcceleration,_fDataStruct._groundSpeed,
		_fDataStruct._maxSpeed);
	//GetCharacterMovement()->Velocity *= _fDataStruct._airAcceleration;
}

void AFASCharacter::ResetAccelerationVelocity()
{
	GetCharacterMovement()->MaxWalkSpeed = _fDataStruct._groundSpeed;
	if (GetWorldTimerManager().TimerExists(ManagerTime))
	{
		GetWorldTimerManager().ClearTimer(ManagerTime);
	}
}

void AFASCharacter::JumpWindow()
{
	if (GetCharacterMovement()->IsMovingOnGround())
	{
		//AccelerationVelocity();
		Jump(); 
	}
	GetWorldTimerManager().ClearTimer(ManagerTimeJump);
}

void AFASCharacter::ShootWeapon(bool _normalFire)
{
	//InitialiseWeapon();
	if (Cast<ARiffleWeapon>(weaponBehaviourObject))
	{
		weaponBehaviourObject->Fire(_normalFire,FP_MuzzleLocation,_ContainerpercentageSpeedMaxSpeedRiffle);//GetCharacterMovement()->Velocity.Size() / _fDataStruct._groundSpeed);
	}else if(Cast<AWeaponShotGun>(weaponBehaviourObject))
	{
		weaponBehaviourObject->Fire(_normalFire,FP_MuzzleLocation,_ContainerpercentageSpeedMaxSpeedShotGun);//GetCharacterMovement()->Velocity.Size() / _fDataStruct._maxSpeed);
	}else if (Cast<ARocketLauncher>(weaponBehaviourObject))
	{
		weaponBehaviourObject->Fire(_normalFire,FP_MuzzleLocation,_ContainerpercentageSpeedMaxSpeedRocketLauncher);
	}
}

void AFASCharacter::StopShootWeapon(bool _normalFire)
{
	weaponBehaviourObject->StopFire(_normalFire);
}


void AFASCharacter::ChangeWeapon(float _value)
{
	weaponBehaviourObject->SetActorHiddenInGame(true);
	if (_value < 0)
	{
		switch (_WeaponType)
		{
		case Riffle:
			default:
			_ContainerpercentageSpeedMaxSpeedRiffle = 0.f;
			_WeaponType = Shotgun;
			break;
		case Shotgun:
			_ContainerpercentageSpeedMaxSpeedShotGun = 0.f;
			_WeaponType = RocketLauncher;
			break;
		case RocketLauncher:
			_ContainerpercentageSpeedMaxSpeedRocketLauncher = 0.f;
			_WeaponType = Riffle;
		//	UE_LOG(LogTemp,Warning,TEXT("Riffle"));
			break;
		}
		weaponBehaviourObject = weapons[_weaponTypes[_WeaponType]];
		weaponBehaviourObject->SetHidden(false);
		_userWidgetMunition->SwapWeapon(_WeaponType);
	}
	else if(_value > 0)
	{
		switch (_WeaponType)
		{
		case Riffle:
			_ContainerpercentageSpeedMaxSpeedRiffle = 0.f;
			_WeaponType = RocketLauncher;
			break;
		case Shotgun:
		default:
			_ContainerpercentageSpeedMaxSpeedShotGun = 0.f;
			_WeaponType = Riffle;
			break;
		case RocketLauncher:
			_ContainerpercentageSpeedMaxSpeedRocketLauncher = 0.f;
			_WeaponType = Shotgun;
		//	UE_LOG(LogTemp,Warning,TEXT("ShotGun"));
			break;
		}
		weaponBehaviourObject = weapons[_weaponTypes[_WeaponType]];
		weaponBehaviourObject->SetActorHiddenInGame(false);
		_userWidgetMunition->SwapWeapon(_WeaponType);
	}
}

void AFASCharacter::KnockBackPlayer(TypeOfKnockback WhichKnock, float _KnockBackDuration, float _knockBackPower, FVector _direction)
{
	switch (WhichKnock)
	{
	case RiffleKnock:
		break;
	case ShotgunKnock:
		_onRecoil = true;
		_containerRecoil = _KnockBackDuration;
		GetCharacterMovement()->AddImpulse(_direction * _knockBackPower,true);
		//GetCharacterMovement()->AddImpulse(-UGameplayStatics::GetPlayerCameraManager(GetWorld(),0)->GetActorForwardVector() * _knockBackPower,true);
		//LaunchCharacter(-UGameplayStatics::GetPlayerCameraManager(GetWorld(),0)->GetActorForwardVector() * weaponBehaviourObject->_dataWeapon._recoilPower,true,true);
		break;
	case RocketLauncherKnock:
		_onRecoil = true;
		_containerRecoil = _KnockBackDuration;
		LaunchCharacter(_direction,true,true);
		//GetCharacterMovement()->AddImpulse(_direction * _knockBackPower,true);
		break;
	case IATrashKnock:
		break;
	case IARangeKnock:
		break;
	case IATankKnock:
		_onRecoil = true;
		_containerRecoil = _KnockBackDuration;
		LaunchCharacter(_direction,true,true);
		break;
	}
}

void AFASCharacter::HudGestion()
{
	if (_userWidgetMunition != nullptr && weapons.Num() > 0)
	{
		for (auto _weapon : weapons)
		{
			_userWidgetMunition->MunitionChanged(_weaponTypes.FindKey(_weapon.Key)->GetValue(),_weapon.Value->_numberOfBallLeft,_weapon.Value->_dataWeapon._magazineSize);
		}
		if (_userWidgetMunition->LedRiffleImage->GetRenderOpacity() > _userWidgetMunition->_opacityLow)
		{
			if (_timeBeforeLedRiffle >= _fDataStruct._timeBeforeLedReset)
			{
				_userWidgetMunition->LedRiffleImage->SetOpacity(_userWidgetMunition->_opacityLow);
				_timeBeforeLedRiffle = 0;
			}
			else
			{
				_timeBeforeLedRiffle += GetWorld()->GetDeltaSeconds();
			}
		}
		if (_userWidgetMunition->LedShotGunImage->GetRenderOpacity() > _userWidgetMunition->_opacityLow)
		{
			if (_timeBeforeLedShotGun >= _fDataStruct._timeBeforeLedReset)
			{
				_userWidgetMunition->LedShotGunImage->SetOpacity(_userWidgetMunition->_opacityLow);
				_timeBeforeLedShotGun = 0;
			}
			else
			{
				_timeBeforeLedShotGun += GetWorld()->GetDeltaSeconds();
			}
		}
		if (_userWidgetMunition->LedRocketLauncherImage->GetRenderOpacity() > _userWidgetMunition->_opacityLow)
		{
			if (_timeBeforeLedRocketLauncher >= _fDataStruct._timeBeforeLedReset)
			{
				_userWidgetMunition->LedRocketLauncherImage->SetOpacity(_userWidgetMunition->_opacityLow);
				_timeBeforeLedRocketLauncher = 0;
			}
			else
			{
				_timeBeforeLedRocketLauncher += GetWorld()->GetDeltaSeconds();
			}
		}
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("HUD null ou weapons vide"));
	}
}






