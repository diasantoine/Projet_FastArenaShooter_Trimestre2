// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FAS_IACharacter.h"
#include "AITrashMob.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AAITrashMob : public AFAS_IACharacter
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	AAITrashMob();
	virtual bool CanAttack(AFASCharacter* _player)override;
	virtual void AttackPlayer(AFASCharacter* _player)override;
	virtual void DamageIA(int DMG, AActor* Attaquant, float Power)override;
	virtual void IAMoving(AFASCharacter* _player)override;
	virtual void IASpecialAttack(AFASCharacter* _player)override;
	virtual void IAJumpNavMesh(FVector TargetPostion, bool _needToJump)override;

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
