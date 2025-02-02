// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecoratorCheckIACanAttack.h"

#include "AIController.h"
#include "AITankMob.h"
#include "FAS_IACharacter.h"

bool UBTDecoratorCheckIACanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AFASCharacter* _player = Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (_player != nullptr)
	{
		if	(_player->_numberOfLifeLeft <= 0) return false;
	}
	else
	{
		return false;
	}
	float AngleCosine = FVector::DotProduct(_player->GetActorLocation(), IA->GetActorLocation()) / (_player->GetActorLocation().Size() * IA->GetActorLocation().Size());
	float AngleRadians = FMath::Acos(AngleCosine);
	float angle = FMath::RadiansToDegrees(AngleRadians);
	if (angle <= IA->_iaDataStruct._minimalAngleForAttack  && FVector::Distance(_player->GetActorLocation(),IA->GetActorLocation()) < IA->_iaDataStruct._minimumDistanceForAttack
		&& !IA->_onAttack && !IA->_isJumpingNav && !IA->_onTakingDMG && !IA->_onAttackSpecial && IA->_timeBeforeAbilityBack <= 0 && !IA->_onDeath)
	{
		AAITankMob* AITankMob = Cast<AAITankMob>(OwnerComp.GetAIOwner()->GetPawn());
		if (AITankMob != nullptr)
		{
			AITankMob->_isAggro = true;
		}
		return true;
	}
	return false;
}
void UBTDecoratorCheckIACanAttack::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}


void UBTDecoratorCheckIACanAttack::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTDecoratorCheckIACanAttack::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}


