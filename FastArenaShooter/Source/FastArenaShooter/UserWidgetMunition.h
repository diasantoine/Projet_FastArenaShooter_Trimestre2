// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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

	void MunitionChanged();
};
