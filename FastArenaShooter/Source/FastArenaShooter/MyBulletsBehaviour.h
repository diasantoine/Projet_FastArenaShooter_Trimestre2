// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBulletsBehaviour.generated.h"

USTRUCT()
struct FBulletParameter
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,Category = "Bullet Parameter")
	UStaticMesh* _modelOfBullet;
};
UCLASS()
class FASTARENASHOOTER_API AMyBulletsBehaviour : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyBulletsBehaviour();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly,Category = "Bullet Parameter")
	UStaticMesh* _meshOfBullet;

	virtual void OnConstruction(const FTransform& Transform) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FBulletParameter _BulletParameter;
};
