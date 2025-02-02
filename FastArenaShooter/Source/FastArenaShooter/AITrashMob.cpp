// Fill out your copyright notice in the Description page of Project Settings.


#include "AITrashMob.h"

#include "MyAiController.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AAITrashMob::AAITrashMob()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAITrashMob::BeginPlay()
{
	Super::BeginPlay();
	_actualHP = _iaDataStruct._hpMax;
	GetCharacterMovement()->JumpZVelocity = _iaDataStruct._jumpAttackHeight;
	GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
	_IAController = Cast<AMyAiController>(GetController());
}

// Called every frame
void AAITrashMob::Tick(float DeltaTime)
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
		}
		if (_onAttackSpecial)
		{
			_onAttackSpecial = false;
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
	CheckIAPosition();
}


bool AAITrashMob::CanAttack(AFASCharacter* _player)
{
	float AngleCosine = FVector::DotProduct(_player->GetActorLocation(),  GetActorLocation()) / (_player->GetActorLocation().Size() * GetActorLocation().Size());
	float AngleRadians = FMath::Acos(AngleCosine);
	float angle = FMath::RadiansToDegrees(AngleRadians);
	if (angle <= _iaDataStruct._minimalAngleForAttack  &&FVector::Distance(_player->GetActorLocation(),GetActorLocation()) < _iaDataStruct._minimumDistanceForAttack)
	{
		return true;
	}
	return false;
}

void AAITrashMob::AttackPlayer(AFASCharacter* player)
{
	if (player)
	{
		_timeBeforeAbilityBack = _iaDataStruct._cooldownBetweenEachAbility;
		_IAController->StopMovement();
		FaceRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), player->GetActorLocation()));
	}
}

void AAITrashMob::DamageIA(int DMG, AActor* Attaquant, float Power)
{
	_actualHP -= DMG;
	_actualHP = FMath::Clamp(_actualHP,0,_iaDataStruct._hpMax);
	_onTakingDMG = true;
	_onTakingDMGVFX = true;
	if (_actualHP <= 0)
	{
		_IAController->StopMovement();
		_onDeath = true;
	}
}


void AAITrashMob::IAMoving(AFASCharacter* _player)
{
	if (_player != nullptr)
	{
		_IAController->MoveToActor(_player,_iaDataStruct._acceptanceRadius,false);
	}
}

void AAITrashMob::IASpecialAttack(AFASCharacter* _player)
{
	if (_player!= nullptr)
	{
		_timeBeforeSpecialAbilityBack = _iaDataStruct._cooldownBetweenEachSpecialAbility;
		GetCharacterMovement()->Velocity = (_player->GetActorLocation() - GetActorLocation()).GetSafeNormal() * _iaDataStruct._groundSpeed;
		Jump();
	}
}

void AAITrashMob::IAJumpNavMesh(FVector TargetPostion, bool _needToJump)
{
	FVector _direction = GetActorForwardVector() * 250 + GetActorLocation();
	FHitResult out;
	FQuat rot = {0,0,0,0};
	GetWorld()->SweepSingleByChannel(out,GetActorLocation(),_direction,rot,ECC_Visibility,FCollisionShape::MakeSphere(20),FCollisionQueryParams::DefaultQueryParam,
		FCollisionResponseParams::DefaultResponseParam);
	if (out.bBlockingHit || _needToJump)
	{
		AFASCharacter* _canBePlayer = Cast<AFASCharacter>(out.GetActor());
		AFAS_IACharacter* _canBeIA = Cast<AFAS_IACharacter>(out.GetActor());
		if (_canBePlayer == nullptr && _canBeIA != nullptr)
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
		}
	}
}

void AAITrashMob::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherComp != nullptr && _onAttack)
	{
		if ((Other != nullptr) && (Other != this))
		{
			AFASCharacter* _containerPlayer = Cast<AFASCharacter>(Other);
			AFAS_IACharacter* _containerIA = Cast<AFAS_IACharacter>(Other);
			if (_containerPlayer != nullptr)
			{
				_IAController->StopMovement();
				_onPlayerTakingDMG = true;
				_containerPlayer->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit,false);
				_onAttack = false;
			}
		}
	}
}
