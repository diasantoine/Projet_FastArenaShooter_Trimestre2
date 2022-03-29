// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Node_AttackPlayer.h"
#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "BehaviorTree/BlackboardComponent.h"

void UBTT_Node_AttackPlayer::OnNodeCreated()
{
	
}

void UBTT_Node_AttackPlayer::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTT_Node_AttackPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto test = OwnerComp.GetAIOwner();
	if (Cast<AFAS_IACharacter>(	OwnerComp.GetAIOwner()->GetPawn()))
	{
		Cast<AFAS_IACharacter>(OwnerComp.GetAIOwner()->GetPawn())->AttackPlayer(
			Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn()));
	}
	
	return EBTNodeResult::Succeeded;
}

void UBTT_Node_AttackPlayer::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTT_Node_AttackPlayer::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}


