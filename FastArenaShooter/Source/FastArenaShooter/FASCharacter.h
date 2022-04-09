// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyWeaponBehaviour.h"
#include "UserWidgetMunition.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "FASCharacter.generated.h"

USTRUCT(BlueprintType)
struct FdataStruct
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _groundSpeed = 800;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _maxSpeed = 1800;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _height = 600;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _jumpWindow = 0.25f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _AmountOfMovementForBunny = 0.05f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _weight = 1.5f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _airAcceleration = 80.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _airSpeed = 800;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _timeBeforeDecceleration = 0.5f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _deceleration = 0.5f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _timeBeforeBunnyStop = 0.5f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	int _hpMax = 200;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _timeBeforeRecovery = 2.0f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	int _hpRecovery = 5;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _reloadShotGunPercentageMaxBunnySpeed = 0.75f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _reloadRifflePercentageMaxGroundSpeed = 0.75f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	float _timeBeforeLedReset = 1.f;
};

UCLASS()
class FASTARENASHOOTER_API AFASCharacter : public ACharacter
{
	GENERATED_BODY()
	DECLARE_DELEGATE_OneParam(_typeOfFire, bool);
public:
	// Sets default values for this character's properties
	AFASCharacter();
	void InitialiseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ForwardPlayer(float _value);
	void RightPlayer(float _value);
	void YawRotation(float _value);
	void PitchRotation(float _value);
	void ActivationJumpPlayer();
	void DesactivationJumpPlayer();
	void AutoJumpPlayer();
	void JumpWindow();
	void StopBunnyHop();
	void MovementPlayer();
	void AccelerationVelocity();
	void ResetAccelerationVelocity();
	void ShootWeapon(bool _normalFire);
	void StopShootWeapon(bool _normalFire);
	void RecoilWeapon(TypeOfWeapon WhichWeapon);
	void ChangeWeapon(float _value);
	void HudGestion();
	void DamagePlayer(int DMG, AActor* Attaquant, float Power, bool AddImpulse);
	void HPRegeneration(float DeltaTime);
	void CheckPlayerPosition();
	void Respawn();

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	FdataStruct _fDataStruct;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	bool _decelerationJump = false;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Stat Character")
	bool _jumpFollowDirection = false;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Character")
	TMap<TEnumAsByte<TypeOfWeapon>,TSubclassOf<AMyWeaponBehaviour>> _weaponTypes;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Weapon Character")
	TEnumAsByte<TypeOfWeapon> _WeaponType;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = "Weapon Character")
	TMap<TSubclassOf<AMyWeaponBehaviour>, AMyWeaponBehaviour*> weapons;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category = "Weapon Character")
	USceneComponent* _socketWeapon;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Weapon Character")
	UUserWidgetMunition* _userWidgetMunition;

	// /** Pawn mesh: 1st person view (arms; seen only by self) */
	// UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	// USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly,Category = Mesh)
	USceneComponent* FP_MuzzleLocation;

	/** Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun) */
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = Mesh)
	USkeletalMeshComponent* VR_Gun;

	/** Location on VR gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly,BlueprintReadOnly, Category = Mesh)
	USceneComponent* VR_MuzzleLocation;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Stat Character")
	FVector _maxCoordinateValue;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Stat Character")
	FVector _minCoordinateValue;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "Stat Character")
	FVector _respawnPosition;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Stat Character")
	int _actualHP;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = "Stat Character")
	float _recoveryTime;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Stat Character")
	bool _casualBunny = false;

private:
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;
	void InputPlayer();
	
	float _decelerationVelocityGround = 0;
	float _decelerationVelocityAir = 0;
	float _bunnyVelocity = 0;
	float _containerVelocityBunny = 0;
	FVector _oldForwardVector;

	FTimerHandle ManagerTime;
	FTimerHandle ManagerTimeJump;
	FTimerHandle ManagerTimeDotRotation;
	bool _jumpButtonPressed = false;
	bool _onBunny = false;
	bool _onJumpAuto = false;
	bool _keepBunnySpeed = false;
	AMyWeaponBehaviour* weaponBehaviourObject;

	float _forwardSign = 1;

	float _timeBeforeLedRiffle;
	float _timeBeforeLedShotGun;
	float _timeBeforeLedRocketLauncher;
};
