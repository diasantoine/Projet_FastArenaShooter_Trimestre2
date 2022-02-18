// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyWeaponBehaviour.generated.h"

UCLASS()
class FASTARENASHOOTER_API AMyWeaponBehaviour : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyWeaponBehaviour();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Fire(bool _normalFire);

	virtual void NormalFire();
	virtual void SpecialFire();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
