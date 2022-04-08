// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetMunition.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UUserWidgetMunition::NativeConstruct()
{
}

void UUserWidgetMunition::MunitionChanged(int WhichWeapon,int MunitionLeft, int MaxMunition)
{
	switch (WhichWeapon)
	{
	case 0:
		default:
		_riffleMunitionImage->Brush.ImageSize.X =_sizeRiffleImage.X * MunitionLeft / MaxMunition;
		break;
	case 1:
		_shotGunMunitionImage->Brush.ImageSize.X = _sizeShotGunImage.X * MunitionLeft / MaxMunition;
		//LedShotGunImage->SetOpacity(_opacityHigh);
		break;
	case 2:
		_rocketLauncherMunitionImage->Brush.ImageSize.X = _sizeRocketLauncherImage.X * MunitionLeft / MaxMunition;
		//LedRocketLauncherImage->SetOpacity(_opacityHigh);
		//_rocketLauncherMunitionImage->GetDesiredSize().Set(_sizeRocketLauncherImage.X * (MunitionLeft / MaxMunition),_sizeRocketLauncherImage.Y * (MunitionLeft / MaxMunition));
		break;
	}
}

void UUserWidgetMunition::HPChange(int HPLeft, int HPMax)
{
	_HPImage->Brush.ImageSize.X = _sizeHPImage.X * HPLeft / HPMax;
}

void UUserWidgetMunition::SwapWeapon(int WhichWeapon)
{
	char* t1;
	FText t2;
	switch (WhichWeapon)
	{
	case 0:
	default:
		_WeaponTypeImage->SetColorAndOpacity(FLinearColor::Red);
		_riffleMunitionImage->SetOpacity(_opacityHigh);
		RiffleImage->SetOpacity(_opacityHigh);
		BarreGunOnRiffleImage->SetOpacity(_opacityHigh);
		TextReloadRiffle->SetOpacity(0);

		if (_shotGunMunitionImage->ColorAndOpacity.A > _opacityLow)
		{
			_shotGunMunitionImage->SetOpacity(_opacityLow);
			ShotgunImage->SetOpacity(_opacityLow);
	//		LedShotGunImage->SetOpacity(_opacityLow);
			BarreGunOnShotGunImage->SetOpacity(_opacityLow);
			TextReloadShotGun->SetOpacity(_opacityLow);
		}

		if (_rocketLauncherMunitionImage->ColorAndOpacity.A > _opacityLow)
		{
			_rocketLauncherMunitionImage->SetOpacity(_opacityLow);
			RocketLauncherImage->SetOpacity(_opacityLow);
		//	LedRocketLauncherImage->SetOpacity(_opacityLow);
			BarreGunOnRocketLauncherImage->SetOpacity(_opacityLow);
			TextReloadRocketLauncher->SetOpacity(_opacityLow);
		}
		
		t1 = "Riffle";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		_WeaponTypeText->SetText(t2);
		break;
	case 1:
		_WeaponTypeImage->SetColorAndOpacity(FLinearColor::Green);
		_shotGunMunitionImage->SetOpacity(_opacityHigh);
		ShotgunImage->SetOpacity(_opacityHigh);
		BarreGunOnShotGunImage->SetOpacity(_opacityHigh);
		TextReloadShotGun->SetOpacity(0);

		if (_rocketLauncherMunitionImage->ColorAndOpacity.A > _opacityLow)
		{
			_rocketLauncherMunitionImage->SetOpacity(_opacityLow);
			RocketLauncherImage->SetOpacity(_opacityLow);
		//	LedRocketLauncherImage->SetOpacity(_opacityLow);
			BarreGunOnRocketLauncherImage->SetOpacity(_opacityLow);
			TextReloadRocketLauncher->SetOpacity(_opacityLow);
		}

		if (_riffleMunitionImage->ColorAndOpacity.A > _opacityLow)
		{
			_riffleMunitionImage->SetOpacity(_opacityLow);
			RiffleImage->SetOpacity(_opacityLow);
		//	LedRiffleImage->SetOpacity(_opacityLow);
			BarreGunOnRiffleImage->SetOpacity(_opacityLow);
			TextReloadRiffle->SetOpacity(_opacityLow);
		}
		
		t1 = "ShotGun";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		_WeaponTypeText->SetText(t2);
		break;
	case 2:
		_WeaponTypeImage->SetColorAndOpacity(FLinearColor::Yellow);
		_rocketLauncherMunitionImage->SetOpacity(_opacityHigh);
		RocketLauncherImage->SetOpacity(_opacityHigh);
		BarreGunOnRocketLauncherImage->SetOpacity(_opacityHigh);
		TextReloadRocketLauncher->SetOpacity(0);

		if (_riffleMunitionImage->ColorAndOpacity.A > _opacityLow)
		{
			_riffleMunitionImage->SetOpacity(_opacityLow);
			RiffleImage->SetOpacity(_opacityLow);
		//	LedRiffleImage->SetOpacity(_opacityLow);
			BarreGunOnRiffleImage->SetOpacity(_opacityLow);
			TextReloadRiffle->SetOpacity(_opacityLow);
		}
		if (_shotGunMunitionImage->ColorAndOpacity.A > _opacityLow)
		{
			_shotGunMunitionImage->SetOpacity(_opacityLow);
			ShotgunImage->SetOpacity(_opacityLow);
		//	LedShotGunImage->SetOpacity(_opacityLow);
			BarreGunOnShotGunImage->SetOpacity(_opacityLow);
			TextReloadShotGun->SetOpacity(_opacityLow);
		}
		t1 = "RocketLauncher";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		_WeaponTypeText->SetText(t2);
		break;
	}
}



