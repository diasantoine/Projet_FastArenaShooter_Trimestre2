// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponShotGun.h"


void AWeaponShotGun::NormalFire(USceneComponent* FP_MuzzleLocation)
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("test"));
		const FRotator SpawnRotation = GetActorRotation();//GetControlRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		//	const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(_dataWeapon._gunOffset);
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		FVector GunOffset = FVector(100.0f, 0.0f, 10.0f);
		const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

		//Set Spawn Collision Handling Override
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		// spawn the projectile at the muzzle
		World->SpawnActor<AMyBulletsBehaviour>(_dataWeapon._modelOfBullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
	}
}

void AWeaponShotGun::SpecialFire(USceneComponent* FP_MuzzleLocation)
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("test"));
		const FRotator SpawnRotation = GetActorRotation();//GetControlRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		//	const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(_dataWeapon._gunOffset);
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		FVector GunOffset = FVector(100.0f, 0.0f, 10.0f);
		const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

		//Set Spawn Collision Handling Override
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		// spawn the projectile at the muzzle
		World->SpawnActor<AMyBulletsBehaviour>(_dataWeapon._modelOfBullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
	}
}

