// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNodeSPecialAttack.h"
#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "BehaviorTree/BlackboardComponent.h"



void UBTTNodeSPecialAttack::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTTNodeSPecialAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn())->_isMoving = true;
	AFASCharacter* _player = Cast<AFASCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Player"));
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	if (IA != nullptr && _player != nullptr)
	{
		IA->_moveBlocked = true;
		Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn())->
		IASpecialAttack(_player);
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
	//Cast<AMyAiController>(OwnerComp.GetAIOwner())->StopMovement();
	//	Cast<AMyAiController>(OwnerComp.GetAIOwner())->MoveToActor(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void UBTTNodeSPecialAttack::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTTNodeSPecialAttack::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}
