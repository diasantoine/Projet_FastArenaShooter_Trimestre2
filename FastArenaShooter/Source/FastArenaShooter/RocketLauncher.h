// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyWeaponBehaviour.h"
#include "RocketLauncher.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API ARocketLauncher : public AMyWeaponBehaviour
{
	GENERATED_BODY()
public:
	virtual void NormalFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect) override;
	virtual void SpecialFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect) override;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _minimalPowerExplosion = 0.3f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _minimalDMGExplosion = 1;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Bullet Data")
	float _minimalExplosionRange = 100.f;
};
