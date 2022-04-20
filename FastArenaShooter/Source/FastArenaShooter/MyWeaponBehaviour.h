// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBullet.h"
#include "UserWidgetMunition.h"
#include "GameFramework/Actor.h"
#include "MyWeaponBehaviour.generated.h"


UENUM(BlueprintType)
enum TypeOfWeapon
{
	Riffle,
	Shotgun,
	RocketLauncher,
	IA
};

USTRUCT(BlueprintType)
struct FdataWeapon
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	TSubclassOf<ABaseBullet> _modelOfBullet;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _ballSize;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	int _magazineSize;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	FVector _gunOffset;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	int _numberOfBallShoot;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	int _numberOfBallReload;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _dmg;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _speed;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _cadenceTir;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _impactPower;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	bool _continuTir;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _recoilPower;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	float _knockPlayerDuration;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon Parameter")
	float _sizeSphereExplosion = 400;
};


UCLASS()
class FASTARENASHOOTER_API AMyWeaponBehaviour : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AMyWeaponBehaviour();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Fire(bool _normalFire,USceneComponent* FP_MuzzleLocation, float _percentageEffect);
	void StopFire(bool _normalFire);
	virtual void NormalFire(USceneComponent* FP_MuzzleLocation,float _percentageEffect);
	virtual void SpecialFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect);
	void Reload(UUserWidgetMunition* WidgetMunition);

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Parameter")
	FdataWeapon _dataWeapon;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Parameter")
	TEnumAsByte<TypeOfWeapon> _typeOfWeapon;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapon Parameter")
	int _numberOfBallLeft = _dataWeapon._magazineSize;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapon Parameter")
	float _timeBeforeNextShoot = 0;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapon Parameter")
	bool _ContinuFire = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Weapon Parameter")
	bool _justFire = false;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Weapon Parameter")
	bool _justFireRecoil = false;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapon Parameter")
	float MaxSpeed = 0;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapon Parameter")
	float ActualSpeed = 0;

	USceneComponent* FP_MuzzleLocationContinuFire;
};
