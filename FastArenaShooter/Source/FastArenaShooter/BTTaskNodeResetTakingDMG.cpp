// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNodeResetTakingDMG.h"

#include "AIRangeMob.h"
#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBTTaskNodeResetTakingDMG::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTTaskNodeResetTakingDMG::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	if (IA != nullptr)
	{
		if (IA->_onTakingDMG)
		{
			IA->_onTakingDMG = false;
		}
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}

void UBTTaskNodeResetTakingDMG::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTTaskNodeResetTakingDMG::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}

