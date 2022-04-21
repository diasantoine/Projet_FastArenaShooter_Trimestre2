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
		BarreGunOnRiffleImage->Brush.ImageSize.X =_sizeRiffleImage.X * MunitionLeft / MaxMunition;
		break;
	case 1:
		BarreGunOnShotGunImage->Brush.ImageSize.X = _sizeShotGunImage.X * MunitionLeft / MaxMunition;
		//LedShotGunImage->SetOpacity(_opacityHigh);
		break;
	case 2:
		BarreGunOnRocketLauncherImage->Brush.ImageSize.X = _sizeRocketLauncherImage.X * MunitionLeft / MaxMunition;
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
		//_riffleMunitionImage->SetOpacity(_opacityHigh);
		RiffleImage->SetOpacity(_opacityHigh);
		BarreGunOnRiffleImage->SetOpacity(_opacityHigh);
		TextReloadRiffle->SetOpacity(0);

		if (ShotgunImage->ColorAndOpacity.A > 0)
		{
			//_shotGunMunitionImage->SetOpacity(_opacityLow);
			ShotgunImage->SetOpacity(0);
	//		LedShotGunImage->SetOpacity(_opacityLow);
			BarreGunOnShotGunImage->SetOpacity(_opacityLow);
			TextReloadShotGun->SetOpacity(_opacityHigh);
		}

		if (RocketLauncherImage->ColorAndOpacity.A > 0)
		{
			//_rocketLauncherMunitionImage->SetOpacity(_opacityLow);
			RocketLauncherImage->SetOpacity(0);
		//	LedRocketLauncherImage->SetOpacity(_opacityLow);
			BarreGunOnRocketLauncherImage->SetOpacity(_opacityLow);
			TextReloadRocketLauncher->SetOpacity(_opacityHigh);
		}
		
		t1 = "Riffle";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		break;
	case 1:
		//_shotGunMunitionImage->SetOpacity(_opacityHigh);
		ShotgunImage->SetOpacity(_opacityHigh);
		BarreGunOnShotGunImage->SetOpacity(_opacityHigh);
		TextReloadShotGun->SetOpacity(0);

		if (RocketLauncherImage->ColorAndOpacity.A > 0)
		{
			//_rocketLauncherMunitionImage->SetOpacity(_opacityLow);
			RocketLauncherImage->SetOpacity(0);
		//	LedRocketLauncherImage->SetOpacity(_opacityLow);
			BarreGunOnRocketLauncherImage->SetOpacity(_opacityLow);
			TextReloadRocketLauncher->SetOpacity(_opacityHigh);
		}

		if (RiffleImage->ColorAndOpacity.A > 0)
		{
			//_riffleMunitionImage->SetOpacity(_opacityLow);
			RiffleImage->SetOpacity(0);
		//	LedRiffleImage->SetOpacity(_opacityLow);
			BarreGunOnRiffleImage->SetOpacity(_opacityLow);
			TextReloadRiffle->SetOpacity(_opacityHigh);
		}
		
		t1 = "ShotGun";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		break;
	case 2:
		//_rocketLauncherMunitionImage->SetOpacity(_opacityHigh);
		RocketLauncherImage->SetOpacity(_opacityHigh);
		BarreGunOnRocketLauncherImage->SetOpacity(_opacityHigh);
		TextReloadRocketLauncher->SetOpacity(0);

		if (RiffleImage->ColorAndOpacity.A > 0)
		{
			//_riffleMunitionImage->SetOpacity(_opacityLow);
			RiffleImage->SetOpacity(0);
		//	LedRiffleImage->SetOpacity(_opacityLow);
			BarreGunOnRiffleImage->SetOpacity(_opacityLow);
			TextReloadRiffle->SetOpacity(_opacityHigh);
		}
		if (ShotgunImage->ColorAndOpacity.A > 0)
		{
			//_shotGunMunitionImage->SetOpacity(_opacityLow);
			ShotgunImage->SetOpacity(0);
		//	LedShotGunImage->SetOpacity(_opacityLow);
			BarreGunOnShotGunImage->SetOpacity(_opacityLow);
			TextReloadShotGun->SetOpacity(_opacityHigh);
		}
		t1 = "RocketLauncher";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		break;
	}
}



