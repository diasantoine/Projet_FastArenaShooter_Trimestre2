// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponBehaviour.h"

// Sets default values
AMyWeaponBehaviour::AMyWeaponBehaviour()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_numberOfBallLeft = _dataWeapon._magazineSize;
}



// Called when the game starts or when spawned
void AMyWeaponBehaviour::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyWeaponBehaviour::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyWeaponBehaviour::Fire(bool _normalFire,USceneComponent* FP_MuzzleLocation)
{
	if (_normalFire)
	{
		NormalFire(FP_MuzzleLocation);
	}
	else
	{
		SpecialFire(FP_MuzzleLocation);
	}
}

void AMyWeaponBehaviour::Reload()
{
	switch (_typeOfWeapon)
	{
	case Riffle:
	default:
		_numberOfBallLeft = FMath::Clamp(_numberOfBallLeft++,0,_dataWeapon._magazineSize);
		break;
	case Shotgun:
		_numberOfBallLeft = FMath::Clamp(_numberOfBallLeft++,0,_dataWeapon._magazineSize);
		break;
	case RocketLauncher:
		_numberOfBallLeft = FMath::Clamp(_numberOfBallLeft++,0,_dataWeapon._magazineSize);
		break;
	}
}


void AMyWeaponBehaviour::NormalFire(USceneComponent* FP_MuzzleLocation)
{
	UE_LOG(LogTemp,Warning,TEXT("Normal FIre"));
}

void AMyWeaponBehaviour::SpecialFire(USceneComponent* FP_MuzzleLocation)
{
	UE_LOG(LogTemp,Warning,TEXT("Special FIre"));
}




