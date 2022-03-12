// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBulletsBehaviour.h"
#include "GameFramework/Actor.h"
#include "MyWeaponBehaviour.generated.h"


UENUM()
enum TypeOfWeapon
{
	Riffle,
	Shotgun,
	RocketLauncher
};

USTRUCT()
struct FdataWeapon
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	TSubclassOf<AMyBulletsBehaviour> _modelOfBullet;
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	UStaticMesh* _modelOfWeapon;
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	FVector _gunOffset;
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	float _dmg;
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	float _speed;
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	float _impactPower;
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

	void Fire(bool _normalFire,USceneComponent* FP_MuzzleLocation);

	virtual void NormalFire(USceneComponent* FP_MuzzleLocation);
	virtual void SpecialFire(USceneComponent* FP_MuzzleLocation);

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Parameter")
	FdataWeapon _dataWeapon;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Parameter")
	TEnumAsByte<TypeOfWeapon> _typeOfWeapon;

	virtual void Tick(float DeltaTime) override;
};
