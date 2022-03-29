// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBullet.h"
#include "MyWeaponBehaviour.h"
#include "ShotGunBullets.generated.h"
/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AShotGunBullets : public ABaseBullet
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
public:
	AShotGunBullets();
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Bullet Data")
	FdataWeapon _dataBullet;
};
