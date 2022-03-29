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
	class UTextBlock* _WeaponTypeText;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	FVector2D _sizeRiffleImage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	FVector2D _sizeShotGunImage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	FVector2D _sizeRocketLauncherImage;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Weapon HUD")
	FVector2D _sizeHPImage;
	
	void MunitionChanged(TypeOfWeapon WhichWeapon,int MunitionLeft, int MaxMunition);
	void HPChange(int HPLeft, int HPMax);
	void SwapWeapon(TypeOfWeapon WhichWeapon);
	
};
