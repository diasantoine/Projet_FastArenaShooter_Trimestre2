// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Node_FindPlayerPosition.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


void UBTT_Node_FindPlayerPosition::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTT_Node_FindPlayerPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	OwnerComp.GetBlackboardComponent()->SetValueAsClass(FName("Player"),Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn())->StaticClass());
	OwnerComp.GetBlackboardComponent()->SetValueAsVector(FName("PlayerPosition"),GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
	return EBTNodeResult::Succeeded;
}

void UBTT_Node_FindPlayerPosition::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTT_Node_FindPlayerPosition::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}

