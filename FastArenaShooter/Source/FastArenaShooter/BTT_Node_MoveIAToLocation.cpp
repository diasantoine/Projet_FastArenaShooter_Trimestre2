// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Node_MoveIAToLocation.h"

#include "AIRangeMob.h"
#include "AITankMob.h"
#include "FAS_IACharacter.h"
#include "MyAiController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void UBTT_Node_MoveIAToLocation::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	
}

EBTNodeResult::Type UBTT_Node_MoveIAToLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	AFASCharacter* _player = Cast<AFASCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("Player"));
	if (IA != nullptr && _player != nullptr)
	{
		AAIRangeMob* IARange = Cast<AAIRangeMob>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
		AAITankMob* IATankMob = Cast<AAITankMob>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
		if (IARange != nullptr)
		{
			if (!IARange->_onAttackSpecial && !IARange->_onTakingDMG && !IARange->_onDeath)
			{
				IARange->_isMoving = true;
				IARange->IAMoving(_player);
			}
		}else if (IATankMob != nullptr)
		{
			float _distance = FVector::Dist(IATankMob->GetActorLocation(),_player->GetActorLocation());
			if (!IATankMob->_onAttackSpecial && !IATankMob->_onTakingDMG && !IATankMob->_isJumpingNav && _distance > IATankMob->_minimalDistanceForAggro && !IATankMob->_isAggro
				&& !IATankMob->_onDeath)
			{
				IATankMob->_isMoving = true;
				IATankMob->IARandomMove();
			}else if (IATankMob->_isAggro &&!IATankMob->_onAttackSpecial && !IATankMob->_onTakingDMG && !IATankMob->_isJumpingNav)
			{
				IATankMob->_isMoving = true;
				IATankMob->IAMoving(_player);
			}else if (!IATankMob->_onAttackSpecial && !IATankMob->_onTakingDMG && !IATankMob->_isJumpingNav && _distance < IATankMob->_minimalDistanceForAggro && !IATankMob->_isAggro)
			{
				IATankMob->_isMoving = true;
				IATankMob->_isAggro = true;
				IATankMob->IAMoving(_player);
			}
		}
		else if(IA != nullptr)
		{
			if (IA->GetCharacterMovement()->IsMovingOnGround() && !IA->_onAttack && !IA->_isJumpingNav && !IA->_onTakingDMG && !IA->_onAttackSpecial && !IA->_onDeath)
			{
				IA->_isMoving = true;
				IA->IAMoving(_player);
			}
		}
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}

void UBTT_Node_MoveIAToLocation::OnGameplayTaskActivated(UGameplayTask& Task)
{
	
}

void UBTT_Node_MoveIAToLocation::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	
}

