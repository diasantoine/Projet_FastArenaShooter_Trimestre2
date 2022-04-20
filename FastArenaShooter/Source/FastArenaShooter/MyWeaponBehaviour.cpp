// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponBehaviour.h"

#include "UserWidgetMunition.h"
#include "Components/Image.h"

// Sets default values
AMyWeaponBehaviour::AMyWeaponBehaviour()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}



// Called when the game starts or when spawned
void AMyWeaponBehaviour::BeginPlay()
{
	Super::BeginPlay();
	_numberOfBallLeft = _dataWeapon._magazineSize;
	_timeBeforeNextShoot = 0;
}

// Called every frame
void AMyWeaponBehaviour::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (_timeBeforeNextShoot > 0)
	{
		_timeBeforeNextShoot -= GetWorld()->GetDeltaSeconds();
	}
	if (_ContinuFire)
	{
		if (FP_MuzzleLocationContinuFire != nullptr)
		{
			NormalFire(FP_MuzzleLocationContinuFire,_percentageSpeed);
		}
	}
}

void AMyWeaponBehaviour::Fire(bool _normalFire,USceneComponent* FP_MuzzleLocation, float _percentageEffect)
{
	if (_normalFire)
	{
		if (_dataWeapon._continuTir)
		{
			_ContinuFire = true;
			FP_MuzzleLocationContinuFire = FP_MuzzleLocation;
		}
		else
		{
			_ContinuFire = false;
			FP_MuzzleLocationContinuFire = nullptr;
		}
		NormalFire(FP_MuzzleLocation,_percentageEffect);
	}
	else
	{
		if (_dataWeapon._continuTir)
		{
			_ContinuFire = true;
			FP_MuzzleLocationContinuFire = FP_MuzzleLocation;
		}	else
		{
			_ContinuFire = false;
			FP_MuzzleLocationContinuFire = nullptr;
		}
		SpecialFire(FP_MuzzleLocation,_percentageEffect);
	}
}

void AMyWeaponBehaviour::StopFire(bool _normalFire)
{
	if (_normalFire)
	{
		if (_dataWeapon._continuTir)
		{
			_ContinuFire = false;
		}
	}
	else
	{
		if (_dataWeapon._continuTir)
		{
			_ContinuFire = false;
		}
	}
}


void AMyWeaponBehaviour::Reload(UUserWidgetMunition* WidgetMunition)
{
	switch (_typeOfWeapon)
	{
	case Riffle:
	default:
		WidgetMunition->LedRiffleImage->SetOpacity(WidgetMunition->_opacityHigh);
		_numberOfBallLeft += _dataWeapon._numberOfBallReload;
		_numberOfBallLeft = FMath::Clamp(_numberOfBallLeft,0,_dataWeapon._magazineSize);
		break;
	case Shotgun:
		WidgetMunition->LedShotGunImage->SetOpacity(WidgetMunition->_opacityHigh);
		_numberOfBallLeft += _dataWeapon._numberOfBallReload;
		_numberOfBallLeft = FMath::Clamp(_numberOfBallLeft,0,_dataWeapon._magazineSize);
		break;
	case RocketLauncher:
		WidgetMunition->LedRocketLauncherImage->SetOpacity(WidgetMunition->_opacityHigh);
		_numberOfBallLeft += _dataWeapon._numberOfBallReload;
		_numberOfBallLeft = FMath::Clamp(_numberOfBallLeft,0,_dataWeapon._magazineSize);
		break;
	}
}


void AMyWeaponBehaviour::NormalFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect)
{
	UE_LOG(LogTemp,Warning,TEXT("Normal FIre"));
}

void AMyWeaponBehaviour::SpecialFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect)
{
	UE_LOG(LogTemp,Warning,TEXT("Special FIre"));
}




