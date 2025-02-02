// Fill out your copyright notice in the Description page of Project Settings.


#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Navigation/NavLinkProxy.h"

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
	if (angle <= _iaDataStruct._minimalAngleForAttack  &&FVector::Distance(_player->GetActorLocation(),GetActorLocation()) < _iaDataStruct._minimumDistanceForAttack)
	{
		return true;
	}
	return false;
}

void AFAS_IACharacter::AttackPlayer(AFASCharacter* player)
{
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
		}
	}
	_isJumpingNav = false;
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

