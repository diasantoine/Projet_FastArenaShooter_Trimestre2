// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Node_FindPlayerPosition.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackboardData.h"

void UBTT_Node_FindPlayerPosition::OnNodeCreated()
{
	
}

void UBTT_Node_FindPlayerPosition::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTT_Node_FindPlayerPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerComp.GetBlackboardComponent()->SetValueAsClass(FName("Player"),_player);
	UE_LOG(LogTemp,Warning,TEXT("%s"),OwnerComp.GetBlackboardComponent()->GetValueAsClass(FName("Player")));
	if (OwnerComp.GetBlackboardComponent()->GetValueAsClass(FName("Player"))->IsChildOf(AFASCharacter::StaticClass()))
	{
		if (_player != nullptr)
		{
			//OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("PlayerPosition"),_player->locati;
		}
		
	}
	return EBTNodeResult::Succeeded;
}

void UBTT_Node_FindPlayerPosition::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTT_Node_FindPlayerPosition::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}

