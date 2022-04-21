// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FAS_IACharacter.h"
#include "AITankMob.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AAITankMob : public AFAS_IACharacter
{
	GENERATED_BODY()
public:
	AAITankMob();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual bool CanAttack(AFASCharacter* _player)override;
	virtual void AttackPlayer(AFASCharacter* _player)override;
	virtual void DamageIA(int DMG, AActor* Attaquant, float Power)override;
	virtual void IAMoving(AFASCharacter* _player)override;
	void IARandomMove();
	void IAChangeRotation(AFASCharacter* _player);
	virtual void IASpecialAttack(AFASCharacter* _player)override;
	virtual void IAJumpNavMesh(FVector TargetPostion, bool _needToJump)override;

	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Dash IA")
	float _dashSpeed = 5000;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Dash IA")
	float _minimalDistanceForAggro = 500.f;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Dash IA")
	FVector _endDashPosition = FVector(0,0,0);
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Dash IA")
	bool _isAggro = false;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Dash IA")
	bool _startRotateTowardPlayer = false;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Dash IA")
	FVector _playerPositionDash;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Dash IA")
	AFASCharacter* Player;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category = "IA")
	TArray<AActor*> _arrayOfRandomPosition;
};
