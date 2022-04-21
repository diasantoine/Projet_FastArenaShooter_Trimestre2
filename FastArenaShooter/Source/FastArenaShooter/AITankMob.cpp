// Fill out your copyright notice in the Description page of Project Settings.


#include "AITankMob.h"

#include "MyAiController.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAITankMob::AAITankMob()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAITankMob::BeginPlay()
{
	Super::BeginPlay();
	_actualHP = _iaDataStruct._hpMax;
	GetCharacterMovement()->JumpZVelocity = _iaDataStruct._jumpAttackHeight;
	GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
	_IAController = Cast<AMyAiController>(GetController());
}

// Called every frame
void AAITankMob::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!GetCharacterMovement()->IsMovingOnGround())
	{
		if (!_isJumpingNav)
		{
			GetCharacterMovement()->Velocity += FVector(0,0,GetWorld()->GetGravityZ()) * DeltaTime;
		}
	}
	else
	{
		if (_isJumpingNav)
		{
			_isJumpingNav = false;
			GetMesh()->SetCollisionProfileName(_IACollision,false);
		//	GetCapsuleComponent()->SetCollisionProfileName(_IACollision,false);
		}
		if (GetCharacterMovement()->JumpZVelocity != _iaDataStruct._jumpAttackHeight)
		{
			GetCharacterMovement()->JumpZVelocity = _iaDataStruct._jumpAttackHeight;
		}
	}
	if (_timeBeforeAbilityBack > 0)
	{
		_timeBeforeAbilityBack -= DeltaTime;
	}
	if (_timeBeforeSpecialAbilityBack > 0)
	{
		_timeBeforeSpecialAbilityBack -= DeltaTime;
	 }
	// if (GetCharacterMovement()->Velocity.Size() < _dashSpeed && _onAttackSpecial)
	// {
	// 	_IAController->StopMovement();
	// 	_onAttackSpecial = false;
	// 	GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
	// }
	CheckIAPosition();
	// if (_endDashPosition != FVector(0,0,0))
	// {
	// 	if (FVector::Dist(_endDashPosition,GetActorLocation()) <= _iaDataStruct._acceptanceRadius)
	// 	{
	// 		_IAController->StopMovement();
	// 		_onAttackSpecial = false;
	// 		GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
	// 		//UE_LOG(LogTemp,Warning,TEXT("%f"),GetCharacterMovement()->Velocity.Size());
	// 		_endDashPosition = FVector(0,0,0);
	// 	}
	// }
}


bool AAITankMob::CanAttack(AFASCharacter* _player)
{
	float AngleCosine = FVector::DotProduct(_player->GetActorLocation(),  GetActorLocation()) / (_player->GetActorLocation().Size() * GetActorLocation().Size());
	float AngleRadians = FMath::Acos(AngleCosine);
	float angle = FMath::RadiansToDegrees(AngleRadians);
	//float angle = FMath::Abs((acosf(FVector::DotProduct(test, GetActorForwardVector()))) * (180 / PI));
	//float angle = FMath::Abs((acosf(FVector::DotProduct(test, GetActorForwardVector()))) * (180 / PI));
//	UE_LOG(LogTemp,Warning,TEXT("%f %f"),angle, FVector::Distance(_player->GetActorLocation(),GetActorLocation()));
	if (angle <= _iaDataStruct._minimalAngleForAttack  &&FVector::Distance(_player->GetActorLocation(),GetActorLocation()) < _iaDataStruct._minimumDistanceForAttack)
	{
		return true;
	}
	return false;
}

void AAITankMob::AttackPlayer(AFASCharacter* player)
{
	if (player != nullptr)
	{
		_IAController->StopMovement();
		_timeBeforeAbilityBack = _iaDataStruct._cooldownBetweenEachAbility;
		//player->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit,false);
	}
}

void AAITankMob::DamageIA(int DMG, AActor* Attaquant, float Power)
{
	_isAggro = true;
	_actualHP -= DMG;
	_actualHP = FMath::Clamp(_actualHP,0,_iaDataStruct._hpMax);
	if (_actualHP <= 0)
	{
		Destroy();
	}
}


void AAITankMob::IAMoving(AFASCharacter* _player)
{
	if (_player != nullptr)
	{
		_IAController->MoveToActor(_player,_iaDataStruct._acceptanceRadius,false);
		// float AngleCosine = FVector::DotProduct(_player->GetActorLocation(), GetActorLocation()) / (_player->GetActorLocation().Size() * GetActorLocation().Size());
		// float AngleRadians = FMath::Acos(AngleCosine);
		// float angle = FMath::RadiansToDegrees(AngleRadians);
		// if (_player->GetActorLocation().Z < GetActorLocation().Z * 1.6f && angle <= _iaDataStruct._minimalAngleForAttack)
		// {
		// 	IAJumpNavMesh(_player->GetActorLocation(),_isInNeedToJump);
		// }
	}
}

void AAITankMob::IARandomMove()
{
	if (_IAController->GetMoveStatus() != EPathFollowingStatus::Moving)
	{
		if (_arrayOfRandomPosition.Num() > 0)
		{
			int _index = FMath::RandRange(0,_arrayOfRandomPosition.Num()-1);
			_IAController->MoveToActor(_arrayOfRandomPosition[_index],_iaDataStruct._acceptanceRadius,false);
		}
	}
	// float AngleCosine = FVector::DotProduct(_player->GetActorLocation(), GetActorLocation()) / (_player->GetActorLocation().Size() * GetActorLocation().Size());
	// float AngleRadians = FMath::Acos(AngleCosine);
	// float angle = FMath::RadiansToDegrees(AngleRadians);
	// if (_player->GetActorLocation().Z < GetActorLocation().Z * 1.6f && angle <= _iaDataStruct._minimalAngleForAttack)
	// {
	// 	IAJumpNavMesh(_player->GetActorLocation(),_isInNeedToJump);
	// }
}


void AAITankMob::IASpecialAttack(AFASCharacter* _player)
{
	if (_player!= nullptr)
	{
		_timeBeforeSpecialAbilityBack = _iaDataStruct._cooldownBetweenEachSpecialAbility;
		//_IAController->MoveToLocation(_player->GetActorLocation(),-1,false);
		//FAIMoveRequest test = FAIMoveRequest::GoalActor
		GetCharacterMovement()->MaxWalkSpeed = _dashSpeed;
		//GetCharacterMovement()->AddImpulse((_player->GetActorLocation() - GetActorLocation()).GetSafeNormal() * _dashSpeed,true);
		GetCharacterMovement()->Velocity = (_player->GetActorLocation() - GetActorLocation()).GetSafeNormal() * _dashSpeed;
	//	_endDashPosition = _player->GetActorLocation();
		//ACharacter::LaunchCharacter(_direction,true,true);
	}
}

void AAITankMob::IAJumpNavMesh(FVector TargetPostion, bool _needToJump)
{
	FVector _direction = GetActorForwardVector() * 100 + GetActorLocation();
	FHitResult out;
	FQuat rot = {0,0,0,0};
	GetWorld()->SweepSingleByChannel(out,GetActorLocation(),_direction,rot,ECC_Visibility,FCollisionShape::MakeSphere(20),FCollisionQueryParams::DefaultQueryParam,
		FCollisionResponseParams::DefaultResponseParam);
	if (out.bBlockingHit || _needToJump)
	{
		if (!Cast<AFASCharacter>(out.GetActor()) && !Cast<AFAS_IACharacter>(out.GetActor()))
		{
			FVector _destinationLocation;
			_destinationLocation.X = TargetPostion.X - GetActorLocation().X;
			_destinationLocation.Y = TargetPostion.Y - GetActorLocation().Y;
			_destinationLocation.Z = TargetPostion.Z - (GetActorLocation().Z +  FMath::Square(_iaDataStruct._jumpNavMeshDuration) * -0.5 * 982);
			_destinationLocation.X /= _iaDataStruct._jumpNavMeshDuration;
			_destinationLocation.Y /=  _iaDataStruct._jumpNavMeshDuration;
			_destinationLocation.Z /=  _iaDataStruct._jumpNavMeshDuration;
			ACharacter::LaunchCharacter(_destinationLocation,true,true);
			_isJumpingNav = true;
			_isMoving = false;
			GetMesh()->SetCollisionProfileName(_jumpIACollision,false);
			//GetCapsuleComponent()->SetCollisionProfileName(_jumpIACollision,false);
			//Jump();
		}
	}
	// FVector _vectorDirection = TargetPostion - GetActorLocation();
	// _vectorDirection = _vectorDirection.GetSafeNormal();
 //    float _distanceJump = FVector::Dist(TargetPostion,GetActorLocation());
 //    GetCharacterMovement()->Velocity = TargetPostion / 2.500f * 2;
 //    float _jumpSpeed =  GetCharacterMovement()->Velocity.Size();
}

void AAITankMob::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherComp != nullptr)
	{
		if ((Other != nullptr) && (Other != this))
		{
			AFASCharacter* _containerPlayer = Cast<AFASCharacter>(Other);
			AFAS_IACharacter* _containerIA = Cast<AFAS_IACharacter>(Other);
			AAITankMob* _containeIATank = Cast<AAITankMob>(Other);
			ABaseBullet* _containerBullet = Cast<ABaseBullet>(Other);
			if (_onAttack)
			{
				if (_containerPlayer != nullptr)
				{
					_IAController->StopMovement();
					GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
					//_containerPlayer->KnockBackPlayer(RocketLauncher,_iaDataStruct._timeKnockBack,_iaDataStruct._powerHit,(_containerPlayer->GetActorLocation() - GetActorLocation()).GetSafeNormal());
					_containerPlayer->DamagePlayer(_iaDataStruct._dmg,GetOwner(),_iaDataStruct._powerHit,true);
				}else if (_containeIATank != nullptr)
				{
					_IAController->StopMovement();
				}
				else if (_containerIA)
				{
					_IAController->StopMovement();
					OtherComp->AddImpulseAtLocation(GetVelocity() * _iaDataStruct._powerHit, GetActorLocation());
					//_containerIA->DamageIA(_iaDataStruct._dmg,GetOwner(),_iaDataStruct._powerHit,true);
				}
				else if (_containerBullet == nullptr)
				{
					_IAController->StopMovement();
					_onAttackSpecial = false;
					GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
				}
			}else if (_onAttackSpecial)
			{
				if (_containerPlayer != nullptr)
				{
					_IAController->StopMovement();
					_onAttackSpecial = false;
					GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;//TODO check knocback and make one dash at a time
					_containerPlayer->KnockBackPlayer(IATankKnock,_iaDataStruct._timeKnockBack,_iaDataStruct._powerHit,(_containerPlayer->GetActorLocation() - GetActorLocation()).GetSafeNormal());
					_containerPlayer->DamagePlayer(_iaDataStruct._dmg,GetOwner(),_iaDataStruct._powerHit,false);
				}else if (_containeIATank != nullptr)
				{
					_IAController->StopMovement();
				}
				else if (_containerIA)
				{
					//_IAController->StopMovement();
					OtherComp->AddImpulseAtLocation(GetVelocity() * _iaDataStruct._powerHit, GetActorLocation());
					//_containerIA->DamageIA(_iaDataStruct._dmg,GetOwner(),_iaDataStruct._powerHit,true);
				}
				else if (_containerBullet == nullptr)
				{
					UE_LOG(LogTemp,Warning,TEXT("HIIIIIIIIIIIIT"));
					_IAController->StopMovement();
					_onAttackSpecial = false;
					GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
				}
			}
			//else
			// {
			// 	if (OtherComp->IsSimulatingPhysics())
			// 	{
			// 		OtherComp->AddImpulseAtLocation(GetVelocity() * _iaDataStruct._powerHit, GetActorLocation());
			// 	}
			// }
		}//else
		// {
		// 	if (OtherComp->IsSimulatingPhysics())
		// 	{
		// 		OtherComp->AddImpulseAtLocation(GetVelocity() * _iaDataStruct._powerHit, GetActorLocation());
		// 	}
		// }
	}
}







