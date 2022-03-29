// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FASCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "FAS_IACharacter.generated.h"



USTRUCT(BlueprintType)
struct FIAdataStruct
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _groundSpeed = 1;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _maxSpeed = 5000;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _acceptanceRadius = 50;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _jumpHeight = 5000;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	int _hpMax = 200;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	int _dmg = 200;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _powerHit = 200;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _minimalAngleForAttack = 120;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _minimumDistanceForAttack = 100;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _minimumDistanceForJump = 100;
};


UCLASS()
class FASTARENASHOOTER_API AFAS_IACharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFAS_IACharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "IA")
	UBehaviorTree* _behaviorTree;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Data IA")
	FIAdataStruct _iaDataStruct;

	bool CanAttack(AFASCharacter* _player);
	void AttackPlayer(AFASCharacter* _player);
	void DamageIA(int DMG, AActor* Attaquant, float Power);
	void IAMoving(AFASCharacter* _player);
	void IAJump(AFASCharacter* _player);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "IA")
	bool _isMoving = false;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Data IA")
	int _actualHP;
};
