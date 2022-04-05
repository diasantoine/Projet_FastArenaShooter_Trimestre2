// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Node_AttackPlayer.h"
#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "BehaviorTree/BlackboardComponent.h"


void UBTT_Node_AttackPlayer::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTT_Node_AttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	AFASCharacter* _player = Cast<AFASCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Player"));
	if (IA != nullptr && _player != nullptr)
	{
		IA->_moveBlocked = true;
		Cast<AFAS_IACharacter>(OwnerComp.GetAIOwner()->GetPawn())->AttackPlayer(_player);
		return EBTNodeResult::Succeeded;
	}
	IA->_moveBlocked = false;
	return EBTNodeResult::Failed;
}

void UBTT_Node_AttackPlayer::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTT_Node_AttackPlayer::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}


