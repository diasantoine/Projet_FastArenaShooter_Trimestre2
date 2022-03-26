// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FASCharacter.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_Node_FindPlayerPosition.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API UBTT_Node_FindPlayerPosition : public UBTTaskNode
{
	GENERATED_BODY()
	
	
protected:
	virtual void OnNodeCreated() override;
	virtual void OnGameplayTaskInitialized(UGameplayTask& Task) override;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void OnGameplayTaskActivated(UGameplayTask& Task) override;
	virtual void OnGameplayTaskDeactivated(UGameplayTask& Task) override;
};
