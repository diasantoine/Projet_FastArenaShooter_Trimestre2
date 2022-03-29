// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBullet.h"
#include "MyWeaponBehaviour.h"
#include "ABulletForRiffle.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API ABulletForRiffle : public ABaseBullet
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
public:
	ABulletForRiffle();
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Bullet Data")
	FdataWeapon _dataBullet;
};
