// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBulletsBehaviour.h"
#include "MyBulletsForFirstWeapon.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AMyBulletsForFirstWeapon : public AMyBulletsBehaviour
{
	GENERATED_BODY()
public:
	AMyBulletsForFirstWeapon();
};
