// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBulletsBehaviour.h"
#include "ShotGunBullets.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AShotGunBullets : public AMyBulletsBehaviour
{
	GENERATED_BODY()
	AShotGunBullets();
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
};
