// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FAS_IACharacter.h"
#include "AIRangeMob.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AAIRangeMob : public AFAS_IACharacter
{
	GENERATED_BODY()
public:
	AAIRangeMob();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual bool CanAttack(AFASCharacter* _player)override;
	virtual void AttackPlayer(AFASCharacter* _player)override;
	virtual void DamageIA(int DMG, AActor* Attaquant, float Power)override;
	virtual void IAMoving(AFASCharacter* _player)override;
	virtual void IAJumpAttack(AFASCharacter* _player)override;
	virtual void IAJumpNavMesh(FVector TargetPostion, bool _needToJump)override;
	
	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly,Category = Mesh)
	USceneComponent* FP_MuzzleLocation;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Character")
	TSubclassOf<AMyWeaponBehaviour> _IAWeapon;

private:
	AMyWeaponBehaviour* weaponBehaviourObject;
};
