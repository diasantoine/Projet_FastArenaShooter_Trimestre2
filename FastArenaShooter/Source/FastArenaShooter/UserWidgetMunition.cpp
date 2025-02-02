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
		break;
	case 2:
		BarreGunOnRocketLauncherImage->Brush.ImageSize.X = _sizeRocketLauncherImage.X * MunitionLeft / MaxMunition;
		break;
	}
}

void UUserWidgetMunition::HPChange(int HPLeft, int HPMax)
{
	float _hpPercentage = (float)HPLeft /(float)HPMax;
	_hpPercentage/=2;
	UE_LOG(LogTemp,Warning,TEXT("%f"),_hpPercentage)
	_HPImage->SetOpacity(0.5f - _hpPercentage);
}

void UUserWidgetMunition::SwapWeapon(int WhichWeapon)
{
	char* t1;
	FText t2;
	switch (WhichWeapon)
	{
	case 0:
	default:
		RiffleImage->SetOpacity(_opacityHigh);
		BarreGunOnRiffleImage->SetOpacity(_opacityHigh);
		TextReloadRiffle->SetOpacity(0);

		if (ShotgunImage->ColorAndOpacity.A > 0)
		{
			ShotgunImage->SetOpacity(0);
			BarreGunOnShotGunImage->SetOpacity(_opacityLow);
			TextReloadShotGun->SetOpacity(_opacityHigh);
		}

		if (RocketLauncherImage->ColorAndOpacity.A > 0)
		{
			RocketLauncherImage->SetOpacity(0);
			BarreGunOnRocketLauncherImage->SetOpacity(_opacityLow);
			TextReloadRocketLauncher->SetOpacity(_opacityHigh);
		}
		
		t1 = "Riffle";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		break;
	case 1:
		ShotgunImage->SetOpacity(_opacityHigh);
		BarreGunOnShotGunImage->SetOpacity(_opacityHigh);
		TextReloadShotGun->SetOpacity(0);

		if (RocketLauncherImage->ColorAndOpacity.A > 0)
		{
			RocketLauncherImage->SetOpacity(0);
			BarreGunOnRocketLauncherImage->SetOpacity(_opacityLow);
			TextReloadRocketLauncher->SetOpacity(_opacityHigh);
		}

		if (RiffleImage->ColorAndOpacity.A > 0)
		{
			RiffleImage->SetOpacity(0);
			BarreGunOnRiffleImage->SetOpacity(_opacityLow);
			TextReloadRiffle->SetOpacity(_opacityHigh);
		}
		
		t1 = "ShotGun";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		break;
	case 2:
		RocketLauncherImage->SetOpacity(_opacityHigh);
		BarreGunOnRocketLauncherImage->SetOpacity(_opacityHigh);
		TextReloadRocketLauncher->SetOpacity(0);

		if (RiffleImage->ColorAndOpacity.A > 0)
		{
			RiffleImage->SetOpacity(0);
			BarreGunOnRiffleImage->SetOpacity(_opacityLow);
			TextReloadRiffle->SetOpacity(_opacityHigh);
		}
		if (ShotgunImage->ColorAndOpacity.A > 0)
		{
			ShotgunImage->SetOpacity(0);
			BarreGunOnShotGunImage->SetOpacity(_opacityLow);
			TextReloadShotGun->SetOpacity(_opacityHigh);
		}
		t1 = "RocketLauncher";
		t2 = FText::FromString(ANSI_TO_TCHAR(t1));
		break;
	}
}



