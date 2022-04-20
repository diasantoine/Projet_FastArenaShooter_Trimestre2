// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerManager.generated.h"

UCLASS()
class FASTARENASHOOTER_API ASpawnerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnerManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TArray<AActor*> _arrayOfSpawner;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Spawner IA")
	float _timeBeforeNewWawe = 60.f;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Spawner IA")
	float _containerTimeLeft = 0.f;
};
