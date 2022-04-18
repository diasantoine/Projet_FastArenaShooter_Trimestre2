// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FASCharacter.h"
#include "MyAiController.h"
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
	float _jumpAttackHeight = 5000;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _jumpNavMeshHeight = 5000;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _jumpNavMeshDuration = 2;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	int _hpMax = 200;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	int _dmg = 200;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _powerHit = 200;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _timeKnockBack = 0.5f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _minimalAngleForAttack = 120;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _minimumDistanceForAttack = 100;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _minimumDistanceForAttackSpecial = 100;
};


UCLASS()
class FASTARENASHOOTER_API AFAS_IACharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	//AFAS_IACharacter();

protected:
	// Called when the game starts or when spawned
	//virtual void BeginPlay() override;

public:	
	// // Called every frame
	// virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "IA")
	UBehaviorTree* _behaviorTree;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Data IA")
	FIAdataStruct _iaDataStruct;
	virtual bool CanAttack(AFASCharacter* _player);
	virtual void AttackPlayer(AFASCharacter* _player);
	virtual void DamageIA(int DMG, AActor* Attaquant, float Power);
	virtual void IAMoving(AFASCharacter* _player);
	virtual void IASpecialAttack(AFASCharacter* _player);
	UFUNCTION(BlueprintCallable,Category = "IA")
	virtual void IAJumpNavMesh(FVector TargetPostion, bool _needToJump);

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "IA")
	bool _isMoving = false;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Data IA")
	int _actualHP;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "IA")
	bool _isJumpingNav;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "IA")
	bool _isInNeedToJump;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "IA")
	AMyAiController* _IAController;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "IA")
	bool _onAbility = false;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "IA")
	FName _IACollision;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "IA")
	FName _jumpIACollision;
};
