// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponShotGun.h"



void AWeaponShotGun::NormalFire(USceneComponent* FP_MuzzleLocation)
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		int breakWhile = 0;
		_numberOfBallLeft = _dataWeapon._magazineSize;
		while (_dataWeapon._numberOfBallShoot && breakWhile < 100 && _numberOfBallLeft > 0)
		{
			breakWhile++;
			_numberOfBallLeft--;
			const FRotator SpawnRotation = GetActorRotation();//GetControlRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			//	const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(_dataWeapon._gunOffset);
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			FVector GunOffset = FVector(100.0f, 0.0f, 10.0f);
			//UKismetMathLibrary::RandomUnitVectorInConeInDegrees(,120f);
			const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// spawn the projectile at the muzzle
			AMyBulletsBehaviour* container = World->SpawnActor<AMyBulletsBehaviour>(_dataWeapon._modelOfBullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
			container->SetActorScale3D(FVector(_dataWeapon._ballSize,_dataWeapon._ballSize,_dataWeapon._ballSize));
		}
	}
}

void AWeaponShotGun::SpecialFire(USceneComponent* FP_MuzzleLocation)
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		int breakWhile = 0;
		_numberOfBallLeft = _dataWeapon._magazineSize;
		while (_dataWeapon._numberOfBallShoot && breakWhile < 100 && _numberOfBallLeft > 0)
		{
			breakWhile++;
			_numberOfBallLeft--;
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
}

