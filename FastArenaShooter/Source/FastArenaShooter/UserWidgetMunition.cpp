// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetMunition.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

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

void UUserWidgetMunition::HPChange(int HPLeft, int HPMax)
{
	_HPImage->Brush.ImageSize.X = _sizeHPImage.X * HPLeft / HPMax;
}

void UUserWidgetMunition::SwapWeapon(TypeOfWeapon WhichWeapon)
{
	char* t1;
	FText t2;
	switch (WhichWeapon)
	{
	case Riffle:
	default:
		_WeaponTypeImage->SetColorAndOpacity(FLinearColor::Red);
		t1 = "Riffle";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		_WeaponTypeText->SetText(t2);
		break;
	case Shotgun:
		_WeaponTypeImage->SetColorAndOpacity(FLinearColor::Green);
		t1 = "ShotGun";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		_WeaponTypeText->SetText(t2);
		break;
	case RocketLauncher:
		_WeaponTypeImage->SetColorAndOpacity(FLinearColor::Yellow);
		t1 = "RocketLauncher";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		_WeaponTypeText->SetText(t2);
		break;
	}
}



