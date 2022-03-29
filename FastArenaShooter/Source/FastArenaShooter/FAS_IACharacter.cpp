// Fill out your copyright notice in the Description page of Project Settings.


#include "FAS_IACharacter.h"

#include "MyAiController.h"
#include "BehaviorTree/BlackboardData.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AFAS_IACharacter::AFAS_IACharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFAS_IACharacter::BeginPlay()
{
	Super::BeginPlay();
	_actualHP = _iaDataStruct._hpMax;
	GetCharacterMovement()->JumpZVelocity = _iaDataStruct._jumpHeight;
	GetCharacterMovement()->MaxWalkSpeed = _iaDataStruct._maxSpeed;
}

// Called every frame
void AFAS_IACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!GetCharacterMovement()->IsMovingOnGround())
	{
		GetCharacterMovement()->Velocity += FVector(0,0,GetWorld()->GetGravityZ()) * DeltaTime;
	}
	// if (_isMoving)
	// {
	// 	IAMoving(Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()));
	// }
}


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
	UE_LOG(LogTemp,Warning,TEXT("%f %f"),angle, FVector::Distance(_player->GetActorLocation(),GetActorLocation()));
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
	player->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit);
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
	}
}

void AFAS_IACharacter::IAJump(AFASCharacter* _player)
{
	if (_player!= nullptr)
	{
		//Cast<AMyAiController>(GetController())->StopMovement();
		//GetMesh()->SetSimulatePhysics(true);
		Jump();
	}
}







