// Fill out your copyright notice in the Description page of Project Settings.


#include "AIRangeMob.h"

#include "MyAiController.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AAIRangeMob::AAIRangeMob()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create a gun mesh component
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
	FP_Gun->SetOnlyOwnerSee(false);			// otherwise won't be visible in the multiplayer
	FP_Gun->bCastDynamicShadow = false;
	FP_Gun->CastShadow = false;
	FP_Gun->SetupAttachment(RootComponent);
	FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	FP_MuzzleLocation->SetupAttachment(FP_Gun);
	FP_MuzzleLocation->SetRelativeLocation(FVector(0, 0, -10.6f));
}

// Called when the game starts or when spawned
void AAIRangeMob::BeginPlay()
{
	Super::BeginPlay();
	_actualHP = _iaDataStruct._hpMax;
	GetCharacterMovement()->JumpZVelocity = _iaDataStruct._jumpAttackHeight;
	GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
	AMyWeaponBehaviour* container = GetWorld()->SpawnActor<AMyWeaponBehaviour>(_IAWeapon,GetActorLocation() + FVector(50,0,25),GetActorRotation());
	container->AttachToComponent(FP_Gun,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	weaponBehaviourObject = container;
	_IAController = Cast<AMyAiController>(GetController());
	_modifHeightIA = GetActorLocation().Z;
	_heighIA = _modifHeightIA;
	GetWorldTimerManager().SetTimer(_timeManager,this,&AAIRangeMob::MakeIaMoveInZ,_timeBetweenZChangement,true,0);
}

// Called every frame
void AAIRangeMob::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Player != nullptr)
	{
		FaceRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Player->GetActorLocation()));
	}
	if (_timeBeforeSpecialAbilityBack > 0)
	{
		_timeBeforeSpecialAbilityBack -= DeltaTime;
	}
}


bool AAIRangeMob::CanAttack(AFASCharacter* _player)
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

void AAIRangeMob::AttackPlayer(AFASCharacter* player)
{
	if (player != nullptr)
	{
		_timeBeforeAbilityBack = _iaDataStruct._cooldownBetweenEachAbility;
		player->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit,false);
	}
}

void AAIRangeMob::DamageIA(int DMG, AActor* Attaquant, float Power)
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


void AAIRangeMob::MakeIaMoveInZ()
{
	_modifHeightIA = FMath::FRandRange(_heighIA/_heighChangeValueLow,_heighIA * _heighChangeValueHigh);
}

void AAIRangeMob::IAMoving(AFASCharacter* _player)
{
	if (_player != nullptr)
	{
		if (Player == nullptr)
		{
			Player = _player;
		}
		if (FVector::Dist(GetActorLocation(),{_player->GetActorLocation().X,_player->GetActorLocation().Y,_modifHeightIA}) > _iaDataStruct._acceptanceRadius)
		{
			FVector _direction = FVector(_player->GetActorLocation().X,_player->GetActorLocation().Y,_modifHeightIA) - GetActorLocation();
			GetCharacterMovement()->Velocity = _direction.GetSafeNormal() * _iaDataStruct._groundSpeed;
		}
		else
		{
			GetCharacterMovement()->StopMovementImmediately();
		}
	}
}

void AAIRangeMob::IASpecialAttack(AFASCharacter* _player)
{
	if (_player!= nullptr)
	{
		_IAController->StopMovement();
		if (weaponBehaviourObject != nullptr)
		{
			_timeBeforeSpecialAbilityBack = _iaDataStruct._cooldownBetweenEachSpecialAbility;
			weaponBehaviourObject->Fire(true,FP_MuzzleLocation,GetCharacterMovement()->Velocity.Size()/_iaDataStruct._maxSpeed);
		}
	}
}

void AAIRangeMob::IAJumpNavMesh(FVector TargetPostion, bool _needToJump)
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
			_destinationLocation.Y /=  _iaDataStruct._jumpNavMeshDuration;//todo lancer se code dés qu'on touche un proxy
			_destinationLocation.Z /=  _iaDataStruct._jumpNavMeshDuration;
			ACharacter::LaunchCharacter(_destinationLocation,true,true);
			_isJumpingNav = true;
		}
	}
}