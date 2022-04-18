// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyWeaponBehaviour.h"
#include "IAWeapon.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AIAWeapon : public AMyWeaponBehaviour
{
	GENERATED_BODY()
public:
	virtual void NormalFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect) override;
	virtual void SpecialFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect) override;
};
