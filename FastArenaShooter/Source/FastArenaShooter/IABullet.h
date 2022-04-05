// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBullet.h"
#include "MyWeaponBehaviour.h"
#include "IABullet.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AIABullet : public ABaseBullet
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
public:
	AIABullet();
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Bullet Data")
	FdataWeapon _dataBullet;
};
