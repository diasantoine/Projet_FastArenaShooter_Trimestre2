// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAiController.h"

#include "FAS_IACharacter.h"

void AMyAiController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AFAS_IACharacter* AIEntity = Cast<AFAS_IACharacter>(InPawn);

	if (AIEntity)
	{
		// if (AIEntity->_behaviorTree->BlackboardAsset)
		// {
		// 	Blackboard->InitializeBlackboard(*(AIEntity->_behaviorTree->BlackboardAsset));
		// }
		RunBehaviorTree(AIEntity->_behaviorTree);
	}
}

