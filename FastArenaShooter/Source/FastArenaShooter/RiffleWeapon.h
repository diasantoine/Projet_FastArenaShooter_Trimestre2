// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyWeaponBehaviour.h"
#include "RiffleWeapon.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API ARiffleWeapon : public AMyWeaponBehaviour
{
	GENERATED_BODY()
public:
	void NormalFire(USceneComponent* FP_MuzzleLocation)override;
	void SpecialFire(USceneComponent* FP_MuzzleLocation) override;

};
