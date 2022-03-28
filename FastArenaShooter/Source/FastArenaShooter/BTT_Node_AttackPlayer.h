// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Node_AttackPlayer.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API UBTT_Node_AttackPlayer : public UBTTaskNode
{
	GENERATED_BODY()
protected:
	virtual void OnNodeCreated() override;
	virtual void OnGameplayTaskInitialized(UGameplayTask& Task) override;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;
	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
};
