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
	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	float _numberWeakUnity = 1;
	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	float _numberBigUnity = 1;
	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	float _numberRangeUnity = 1;

	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	float _cooldownSpawnWeakUnity = 1;
	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	float _cooldownBigUnity = 1;
	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	float _cooldownRangeUnity = 1;

	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	FVector _spawnWeakUnity;
	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	FVector _spawnBigUnity;
	UPROPERTY(EditAnywhere,Category = "Parameter Wawe")
	FVector _spawnRangeUnity;
};
UCLASS()
class FASTARENASHOOTER_API AGameModeFastArenaFPS : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,Category = "Number Of Wawe")
	TArray<FWaweSytem> _arrayWaweSytems;

};
