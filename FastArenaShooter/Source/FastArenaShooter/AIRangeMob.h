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
	virtual void IASpecialAttack(AFASCharacter* _player)override;
	virtual void IAJumpNavMesh(FVector TargetPostion, bool _needToJump)override;

	void MakeIaMoveInZ();

	
	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly,Category = Mesh)
	USceneComponent* FP_MuzzleLocation;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Character")
	TSubclassOf<AMyWeaponBehaviour> _IAWeapon;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "IA")
	float _modifHeightIA;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "IA")
	float _timeBetweenZChangement = 3.f;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "IA")
	float _heighChangeValueHigh = 2.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "IA")
	float _heighChangeValueLow = 2.f;

private:
	float _heighIA;
	AMyWeaponBehaviour* weaponBehaviourObject;
	FTimerHandle _timeManager;
};
