// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyBulletsBehaviour.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

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
protected:
	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
public:	
	// Sets default values for this actor's properties
	AMyBulletsBehaviour();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FBulletParameter _BulletParameter;

	/** called when projectile hits something */
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly,Category = "Bullet Parameter")
	UStaticMesh* _meshOfBullet;
};
