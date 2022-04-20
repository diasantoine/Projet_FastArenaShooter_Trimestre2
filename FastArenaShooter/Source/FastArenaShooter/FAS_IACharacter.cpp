// Fill out your copyright notice in the Description page of Project Settings.


#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/NavLinkProxy.h"

// // Sets default values
// AFAS_IACharacter::AFAS_IACharacter()
// {
//  	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
// 	PrimaryActorTick.bCanEverTick = true;
//
// }
//
// // Called when the game starts or when spawned
// void AFAS_IACharacter::BeginPlay()
// {
// 	Super::BeginPlay();
// 	_actualHP = _iaDataStruct._hpMax;
// 	GetCharacterMovement()->JumpZVelocity = _iaDataStruct._jumpAttackHeight;
// 	GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
// }
//
// // Called every frame
// void AFAS_IACharacter::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
// 	if (!GetCharacterMovement()->IsMovingOnGround())
// 	{
// 		if (!_isJumpingNav)
// 		{
// 			GetCharacterMovement()->Velocity += FVector(0,0,GetWorld()->GetGravityZ()) * DeltaTime;
// 		}
// 	}
// 	else
// 	{
// 		if (_isJumpingNav)
// 		{
// 			_isJumpingNav = false;
// 		}
// 		if (GetCharacterMovement()->JumpZVelocity != _iaDataStruct._jumpAttackHeight)
// 		{
// 			GetCharacterMovement()->JumpZVelocity = _iaDataStruct._jumpAttackHeight;
// 		}
// 	}
// 	// if (_isMoving)
// 	// {
// 	// 	IAMoving(Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()));
// 	// }
// }
//
//

// Called to bind functionality to input
void AFAS_IACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AFAS_IACharacter::CanAttack(AFASCharacter* _player)
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

void AFAS_IACharacter::AttackPlayer(AFASCharacter* player)
{
	// if (CanAttack(player))
	// {
	// 	player->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit);
	// }
	Cast<AMyAiController>(GetController())->StopMovement();
	player->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit,false);
}

void AFAS_IACharacter::DamageIA(int DMG, AActor* Attaquant, float Power)
{
	_actualHP -= DMG;
	_actualHP = FMath::Clamp(_actualHP,0,_iaDataStruct._hpMax);
	if (_actualHP <= 0)
	{
		Destroy();
	}
}


void AFAS_IACharacter::IAMoving(AFASCharacter* _player)
{
	if (_player != nullptr)
	{
		Cast<AMyAiController>(GetController())->MoveToActor(_player,_iaDataStruct._acceptanceRadius,false);
		if (_player->GetActorLocation().Z < GetActorLocation().Z * 1.6f)
		{
			IAJumpNavMesh(_player->GetActorLocation(),_isInNeedToJump);
		}
	}
}

void AFAS_IACharacter::IASpecialAttack(AFASCharacter* _player)
{
	if (_player!= nullptr)
	{
		//Cast<AMyAiController>(GetController())->StopMovement();
		//GetMesh()->SetSimulatePhysics(true);
		Jump();
	}
}

void AFAS_IACharacter::IAJumpNavMesh(FVector TargetPostion, bool _needToJump)
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

void AFAS_IACharacter::CheckIAPosition()
{
	if (GetActorLocation().X > _maxCoordinateValue.X || GetActorLocation().X < _minCoordinateValue.X)
	{
		Destroy();
	}else if (GetActorLocation().Y > _maxCoordinateValue.Y || GetActorLocation().Y < _minCoordinateValue.Y)
	{
		Destroy();
	}else if (GetActorLocation().Z > _maxCoordinateValue.Z || GetActorLocation().Z < _minCoordinateValue.Z)
	{
		Destroy();
	}
}

