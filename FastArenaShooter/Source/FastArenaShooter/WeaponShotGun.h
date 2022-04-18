// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyWeaponBehaviour.h"
#include "WeaponShotGun.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AWeaponShotGun : public AMyWeaponBehaviour
{
	GENERATED_BODY()
public:
	virtual void NormalFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect) override;
	virtual void SpecialFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect) override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Weapon Parameter")
	int _numberOfBallMinimum = 3;
};
