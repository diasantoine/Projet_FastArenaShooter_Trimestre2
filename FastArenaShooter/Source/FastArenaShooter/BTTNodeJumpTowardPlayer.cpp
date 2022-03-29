// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNodeJumpTowardPlayer.h"
#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "BehaviorTree/BlackboardComponent.h"



void UBTTNodeJumpTowardPlayer::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTTNodeJumpTowardPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn())->_isMoving = true;
	AFASCharacter* _player = Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	//Cast<AMyAiController>(OwnerComp.GetAIOwner())->StopMovement();
	Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn())->
	IAJump(_player);
	//	Cast<AMyAiController>(OwnerComp.GetAIOwner())->MoveToActor(GetWorld()->GetFirstPlayerController()->GetPawn());
	return EBTNodeResult::Succeeded;
}

void UBTTNodeJumpTowardPlayer::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTTNodeJumpTowardPlayer::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}
