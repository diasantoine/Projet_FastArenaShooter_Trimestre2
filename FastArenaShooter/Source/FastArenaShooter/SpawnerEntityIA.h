// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FAS_IACharacter.h"
#include "GameFramework/Actor.h"
#include "SpawnerEntityIA.generated.h"

USTRUCT(BlueprintType)
struct FIAParameter
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Spawner IA")
	float _cooldownSpawn;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Spawner IA")
	int _numberOfSpawn;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Spawner IA")
	int _numberToSpawn;
};
USTRUCT(BlueprintType)
struct FWaweIA
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Wawe IA")
	TMap<TSubclassOf<AFAS_IACharacter>,FIAParameter> _waweParameter;
};
UCLASS()
class FASTARENASHOOTER_API ASpawnerEntityIA : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerEntityIA();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Spawner IA")
	TArray<FWaweIA> _waweIA;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Spawner IA")
	TSubclassOf<AFAS_IACharacter> _iaToSpawn;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Spawner IA")
	int _index = 0;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "Spawner IA")
	TArray<AActor*> _arrayOfRandomPositionForTank;

	FTimerHandle _timerManager;
	FTimerHandle _timerIARange;
	FTimerHandle _timerIATank;
	FTimerHandle _timerIATrash;
	void RapidSpawnIA();
	void IARangeSpawner();
	void IATankSpawner();
	void IATrashSpawner();
	void ChangeWawe();
};
