// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBulletsBehaviour.h"
#include "GameFramework/Actor.h"
#include "MyWeaponBehaviour.generated.h"


UENUM()
enum TypeOfWeapon
{
	_riffle,
	_shotgun,
	_rocketLauncher
};

USTRUCT()
struct FdataWeapon
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	TMap<TEnumAsByte<TypeOfWeapon>,AMyBulletsBehaviour*> _modelOfBullet;
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	TMap<TEnumAsByte<TypeOfWeapon>,UStaticMesh*> _modelOfWeapon;
	UPROPERTY(EditDefaultsOnly,Category = "Weapon Parameter")
	AActor* _gunOffset;
};


UCLASS()
class FASTARENASHOOTER_API AMyWeaponBehaviour : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyWeaponBehaviour();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Fire(bool _normalFire);

	virtual void NormalFire();
	virtual void SpecialFire();

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Parameter")
	FdataWeapon _dataWeapon;
	UPROPERTY(EditDefaultsOnly, Category = "Weapon Parameter")
	TEnumAsByte<TypeOfWeapon> _typeOfWeapon;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
