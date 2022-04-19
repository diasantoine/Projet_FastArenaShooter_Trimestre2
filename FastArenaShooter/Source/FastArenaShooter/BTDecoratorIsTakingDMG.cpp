// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecoratorIsTakingDMG.h"

#include "AIController.h"
#include "FAS_IACharacter.h"


bool UBTDecoratorIsTakingDMG::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	//Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(OwnerComp.GetAIOwner()->GetPawn());
	//AFASCharacter* _player = Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (IA != nullptr)
	{
		if (IA->_onATakingDMG)
		{
			return true;
		}
	}
	return false;
}
void UBTDecoratorIsTakingDMG::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}


void UBTDecoratorIsTakingDMG::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTDecoratorIsTakingDMG::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}