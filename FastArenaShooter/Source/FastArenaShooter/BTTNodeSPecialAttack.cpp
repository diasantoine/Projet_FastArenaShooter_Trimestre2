// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTNodeSPecialAttack.h"

#include "AIRangeMob.h"
#include "AITankMob.h"
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
	AAIRangeMob* AIRangeMob = Cast<AAIRangeMob>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	AAITankMob* AITankMob =  Cast<AAITankMob>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	if (AIRangeMob != nullptr && _player != nullptr)
	{
		AIRangeMob->_isMoving = false;
		AIRangeMob->_onAttackSpecial = true;
		AIRangeMob->IASpecialAttack(_player);
		return EBTNodeResult::Succeeded;
	}
	if (AITankMob != nullptr && _player != nullptr)
	{
		AITankMob->_isMoving = false;
		AITankMob->_onAttackSpecial = true;
		AITankMob->IASpecialAttack(_player);
		return EBTNodeResult::Succeeded;
	}
	if (IA != nullptr && _player != nullptr)
	{
		IA->_onAttackSpecial = true;
		IA->_isMoving = false;
		IA->IASpecialAttack(_player);
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
