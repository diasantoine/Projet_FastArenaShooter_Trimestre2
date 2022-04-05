// Fill out your copyright notice in the Description page of Project Settings.


#include "AIRangeMob.h"

#include "MyAiController.h"
#include "GameFramework/CharacterMovementComponent.h"

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
	// FP_Gun->SetupAttachment(Mesh1P, TEXT("GripPoint"));
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
}

// Called every frame
void AAIRangeMob::Tick(float DeltaTime)
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
		}
		if (GetCharacterMovement()->JumpZVelocity != _iaDataStruct._jumpAttackHeight)
		{
			GetCharacterMovement()->JumpZVelocity = _iaDataStruct._jumpAttackHeight;
		}
	}
}


bool AAIRangeMob::CanAttack(AFASCharacter* _player)
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

void AAIRangeMob::AttackPlayer(AFASCharacter* player)
{
	// if (CanAttack(player))
	// {
	// 	player->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit);
	// }
	if (player != nullptr)
	{
		_IAController->StopMovement();
		player->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit,false);
	}
	// if (weaponBehaviourObject != nullptr)
	// {
	// 	weaponBehaviourObject->Fire(true,FP_MuzzleLocation);
	// }
}

void AAIRangeMob::DamageIA(int DMG, AActor* Attaquant, float Power)
{
	_actualHP -= DMG;
	_actualHP = FMath::Clamp(_actualHP,0,_iaDataStruct._hpMax);
	if (_actualHP <= 0)
	{
		Destroy();
	}
}


void AAIRangeMob::IAMoving(AFASCharacter* _player)
{
	if (_player != nullptr)
	{
		_IAController->MoveToActor(_player,_iaDataStruct._acceptanceRadius,false);
		if (_player->GetActorLocation().Z < GetActorLocation().Z * 1.6f)
		{
			IAJumpNavMesh(_player->GetActorLocation(),_isInNeedToJump);
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
			weaponBehaviourObject->Fire(true,FP_MuzzleLocation);
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
			_destinationLocation.Y /=  _iaDataStruct._jumpNavMeshDuration;
			_destinationLocation.Z /=  _iaDataStruct._jumpNavMeshDuration;
			ACharacter::LaunchCharacter(_destinationLocation,true,true);
			_isJumpingNav = true;
			//Jump();
		}
	}
	_isJumpingNav = false;
	// FVector _vectorDirection = TargetPostion - GetActorLocation();
	// _vectorDirection = _vectorDirection.GetSafeNormal();
 //    float _distanceJump = FVector::Dist(TargetPostion,GetActorLocation());
 //    GetCharacterMovement()->Velocity = TargetPostion / 2.500f * 2;
 //    float _jumpSpeed =  GetCharacterMovement()->Velocity.Size();
}


