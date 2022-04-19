// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTTaskNodeResetAttackVar.h"

#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "BehaviorTree/BlackboardComponent.h"


void UBTTTaskNodeResetAttackVar::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTTTaskNodeResetAttackVar::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	AFASCharacter* _player = Cast<AFASCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Player"));
	if (IA != nullptr && _player != nullptr)
	{
		IA->_onAttack = false;
		IA->_onAttackSpecial = false;
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}

void UBTTTaskNodeResetAttackVar::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTTTaskNodeResetAttackVar::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}