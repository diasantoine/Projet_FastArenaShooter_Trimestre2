// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBullet.h"
#include "MyWeaponBehaviour.h"
#include "Rocket.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API ARocket : public ABaseBullet
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
public:
	ARocket();
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Bullet Data")
	FdataWeapon _dataBullet;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Bullet Data")
	float _minimumDistanceForOptimalImpact = 100.f;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Bullet Data")
	float _actualSpeed;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Bullet Data")
	float _maxSpeed;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Bullet Data")
	float _rangeExplosion;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Bullet Data")
	float _explosionImpact;
};
