// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardData.h"
#include "IABlackboardData.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API UIABlackboardData : public UBlackboardData
{
	GENERATED_BODY()
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
};
