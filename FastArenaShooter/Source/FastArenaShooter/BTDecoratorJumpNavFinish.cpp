// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecoratorJumpNavFinish.h"

#include "AIController.h"
#include "AITankMob.h"
#include "FAS_IACharacter.h"


bool UBTDecoratorJumpNavFinish::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AAITankMob* IATank = Cast<AAITankMob>(OwnerComp.GetAIOwner()->GetPawn());
	if (IATank != nullptr)
	{
		if (!IATank->_onAttackSpecial)
		{
			return true;
		}
		return false;
	}
	if (IA != nullptr)
	{
		if (!IA->_onAttackSpecial)
		{
			return true;
		}
	}
	return false;
}
void UBTDecoratorJumpNavFinish::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}


void UBTDecoratorJumpNavFinish::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTDecoratorJumpNavFinish::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}