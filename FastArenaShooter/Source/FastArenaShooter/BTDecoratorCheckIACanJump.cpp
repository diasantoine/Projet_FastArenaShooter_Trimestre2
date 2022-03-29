// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecoratorCheckIACanJump.h"

#include "AIController.h"
#include "FAS_IACharacter.h"


bool UBTDecoratorCheckIACanJump::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	//Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AFASCharacter* _player = Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	float AngleCosine = FVector::DotProduct(_player->GetActorLocation(), IA->GetActorLocation()) / (_player->GetActorLocation().Size() * IA->GetActorLocation().Size());
	float AngleRadians = FMath::Acos(AngleCosine);
	float angle = FMath::RadiansToDegrees(AngleRadians);
	//UE_LOG(LogTemp,Warning,TEXT("%f %f"),angle, FVector::Distance(_player->GetActorLocation(),IA->GetActorLocation()));
	if (angle <= IA->_iaDataStruct._minimalAngleForAttack  && FVector::Distance(_player->GetActorLocation(),IA->GetActorLocation()) < IA->_iaDataStruct._minimumDistanceForJump)
	{
		return true;
	}
	return false;
}
void UBTDecoratorCheckIACanJump::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}


void UBTDecoratorCheckIACanJump::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTDecoratorCheckIACanJump::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}