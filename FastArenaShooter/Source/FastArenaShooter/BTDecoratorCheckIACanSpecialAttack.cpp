// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecoratorCheckIACanSpecialAttack.h"
#include "AIController.h"
#include "AIRangeMob.h"
#include "AITankMob.h"
#include "AITrashMob.h"
#include "FAS_IACharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


bool UBTDecoratorCheckIACanSpecialAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	//Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	AFAS_IACharacter* IA = Cast<AFAS_IACharacter>(OwnerComp.GetAIOwner()->GetPawn());
	AFASCharacter* _player = Cast<AFASCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	float AngleCosine = FVector::DotProduct(_player->GetActorLocation(), IA->GetActorLocation()) / (_player->GetActorLocation().Size() * IA->GetActorLocation().Size());
	float AngleRadians = FMath::Acos(AngleCosine);
	float angle = FMath::RadiansToDegrees(AngleRadians);
	AAIRangeMob* IARange = Cast<AAIRangeMob>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	AAITankMob* IATankMob = Cast<AAITankMob>(Cast<AMyAiController>(OwnerComp.GetAIOwner())->GetPawn());
	if (IARange != nullptr)
	{
		float _distance = FVector::Distance(FVector(_player->GetActorLocation().X,_player->GetActorLocation().Y,IA->GetActorLocation().Z),IARange->GetActorLocation());
		if (angle <= IARange->_iaDataStruct._minimalAngleForAttack  && _distance < IARange->_iaDataStruct._minimumDistanceForAttackSpecial
			&& !IARange->_onAttack && !IARange->_onTakingDMG && !IARange->_onAttackSpecial)
		{
			IARange->_isMoving = false;
			IARange->_onAttackSpecial = true;
			return true;
		}
	}else if (IATankMob != nullptr)
	{
		float _distance = FVector::Distance(_player->GetActorLocation(),IA->GetActorLocation());
		if (angle <= IATankMob->_iaDataStruct._minimalAngleForAttack  && _distance < IATankMob->_iaDataStruct._minimumDistanceForAttackSpecial
			&& _distance > IATankMob->_iaDataStruct._minimumDistanceForAttack && IATankMob->GetCharacterMovement()->IsMovingOnGround()
			&& !IATankMob->_onAttack && !IATankMob->_isJumpingNav && !IATankMob->_onTakingDMG && !IATankMob->_onAttackSpecial)
		{
			IATankMob->_isMoving = false;
			IATankMob->_onAttackSpecial = true;
			return true;
		}
	}
	else if(IA != nullptr)
	{
		float _distance = FVector::Distance(_player->GetActorLocation(),IA->GetActorLocation());
		if (angle <= IA->_iaDataStruct._minimalAngleForAttack  && _distance < IA->_iaDataStruct._minimumDistanceForAttackSpecial
			&& _distance > IA->_iaDataStruct._minimumDistanceForAttack && IA->GetCharacterMovement()->IsMovingOnGround()
			&& !IA->_onAttack && !IA->_isJumpingNav && !IA->_onTakingDMG && !IA->_onAttackSpecial)
		{
			return true;
		}
	}
	return false;
}
void UBTDecoratorCheckIACanSpecialAttack::OnGameplayTaskInitialized(UGameplayTask& Task)
{
	Super::OnGameplayTaskInitialized(Task);
}


void UBTDecoratorCheckIACanSpecialAttack::OnGameplayTaskActivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskActivated(Task);
}

void UBTDecoratorCheckIACanSpecialAttack::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}