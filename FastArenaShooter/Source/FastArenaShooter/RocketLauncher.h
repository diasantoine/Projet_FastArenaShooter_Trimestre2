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
	virtual void NormalFire(USceneComponent* FP_MuzzleLocation) override;
	virtual void SpecialFire(USceneComponent* FP_MuzzleLocation) override;
};
