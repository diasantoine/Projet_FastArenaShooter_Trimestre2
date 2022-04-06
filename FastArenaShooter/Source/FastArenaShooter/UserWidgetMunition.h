// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyWeaponBehaviour.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetMunition.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API UUserWidgetMunition : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* _riffleMunitionImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* _shotGunMunitionImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* _rocketLauncherMunitionImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* _HPImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* _WeaponTypeImage;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* BarreGunOnRiffleImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* BarreGunOnShotGunImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* BarreGunOnRocketLauncherImage;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* LedRiffleImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* LedShotGunImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* LedRocketLauncherImage;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* RiffleImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* ShotgunImage;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UImage* RocketLauncherImage;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextReloadRiffle;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextReloadShotGun;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextReloadRocketLauncher;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* _WeaponTypeText;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	FVector2D _sizeRiffleImage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	FVector2D _sizeShotGunImage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	FVector2D _sizeRocketLauncherImage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	FVector2D _sizeHPImage;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	float _opacityLow = 0.3f;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	float _opacityHigh= 1;
	
	void MunitionChanged(TypeOfWeapon WhichWeapon,int MunitionLeft, int MaxMunition);
	void HPChange(int HPLeft, int HPMax);
	void SwapWeapon(TypeOfWeapon WhichWeapon);
	
};
