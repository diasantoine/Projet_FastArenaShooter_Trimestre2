// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetMunition.h"

#include "Components/Image.h"

void UUserWidgetMunition::NativeConstruct()
{
}

void UUserWidgetMunition::MunitionChanged(TypeOfWeapon WhichWeapon,int MunitionLeft, int MaxMunition)
{
	switch (WhichWeapon)
	{
	case Riffle:
		default:
		_riffleMunitionImage->Brush.ImageSize.Y =_sizeRiffleImage.Y * MunitionLeft / MaxMunition;
		break;
	case Shotgun:
		_shotGunMunitionImage->Brush.ImageSize.Y = _sizeShotGunImage.Y * MunitionLeft / MaxMunition;
		break;
	case RocketLauncher:
		_rocketLauncherMunitionImage->Brush.ImageSize.Y = _sizeRocketLauncherImage.Y * MunitionLeft / MaxMunition;
		//_rocketLauncherMunitionImage->GetDesiredSize().Set(_sizeRocketLauncherImage.X * (MunitionLeft / MaxMunition),_sizeRocketLauncherImage.Y * (MunitionLeft / MaxMunition));
		break;
	}
}

