// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeFastArenaFPS.generated.h"

/**
 * 
 */
USTRUCT()
struct FWaweSytem
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,VisibleAnywhere,Category = "Parameter Wawe")
	float _numberWeakUnity = 1;
	UPROPERTY(EditAnywhere,VisibleAnywhere,Category = "Parameter Wawe")
	float _numberBigUnity = 1;
	UPROPERTY(EditAnywhere,VisibleAnywhere,Category = "Parameter Wawe")
	float _numberRangeUnity = 1;

	UPROPERTY(EditAnywhere,VisibleAnywhere,Category = "Parameter Wawe")
	float _cooldownSpawnWeakUnity = 1;
	UPROPERTY(EditAnywhere,VisibleAnywhere,Category = "Parameter Wawe")
	float _cooldownBigUnity = 1;
	UPROPERTY(EditAnywhere,VisibleAnywhere,Category = "Parameter Wawe")
	float _cooldownRangeUnity = 1;
	
};
UCLASS()
class FASTARENASHOOTER_API AGameModeFastArenaFPS : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,VisibleAnywhere,Category = "Number Of Wawe")
	TArray<FWaweSytem*> _arrayWaweSytems;

private:
	virtual void OnConstruction(const FTransform& Transform) override;
	
};
