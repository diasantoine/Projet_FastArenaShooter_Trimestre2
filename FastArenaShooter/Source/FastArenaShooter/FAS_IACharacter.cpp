// Fill out your copyright notice in the Description page of Project Settings.


#include "FAS_IACharacter.h"

#include "MyAiController.h"
#include "BehaviorTree/BlackboardData.h"

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
}

// Called every frame
void AFAS_IACharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


// Called to bind functionality to input
void AFAS_IACharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AFAS_IACharacter::CanAttack(AFASCharacter* _player)
{
	float angle = FMath::Abs((acosf(FVector::DotProduct(_player->GetActorForwardVector(), GetActorForwardVector()))) * (180 / PI));
	if (angle <= 90)
	{
		return true;
	}
	return false;
}

void AFAS_IACharacter::AttackPlayer(AFASCharacter* player)
{
	if (CanAttack(player))
	{
		player->DamagePlayer(_iaDataStruct._dmg,this,_iaDataStruct._powerHit);
	}
}





