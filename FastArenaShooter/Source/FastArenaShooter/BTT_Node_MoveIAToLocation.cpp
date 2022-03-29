// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Node_MoveIAToLocation.h"
#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBTT_Node_MoveIAToLocation::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTT_Node_MoveIAToLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn())->_isMoving = true;
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	if (IA != nullptr)
	{
		if (IA->GetCharacterMovement()->IsMovingOnGround())
		{
			AFASCharacter* _player = Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
			Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn())->IAMoving(_player);
		}
	}
//	Cast<AMyAiController>(OwnerComp.GetAIOwner())->MoveToActor(GetWorld()->GetFirstPlayerController()->GetPawn());
	return EBTNodeResult::Succeeded;
}

void UBTT_Node_MoveIAToLocation::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTT_Node_MoveIAToLocation::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}

