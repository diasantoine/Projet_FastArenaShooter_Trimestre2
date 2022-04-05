// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FAS_IACharacter.h"
#include "AITankMob.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AAITankMob : public AFAS_IACharacter
{
	GENERATED_BODY()
public:
	AAITankMob();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual bool CanAttack(AFASCharacter* _player)override;
	virtual void AttackPlayer(AFASCharacter* _player)override;
	virtual void DamageIA(int DMG, AActor* Attaquant, float Power)override;
	virtual void IAMoving(AFASCharacter* _player)override;
	virtual void IASpecialAttack(AFASCharacter* _player)override;
	virtual void IAJumpNavMesh(FVector TargetPostion, bool _needToJump)override;

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Dash IA")
	float _dashSpeed = 5000;
};
