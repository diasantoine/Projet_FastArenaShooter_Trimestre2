// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponShotGun.h"
#include "ShotGunBullets.h"
#include "Kismet/GameplayStatics.h"

void AWeaponShotGun::NormalFire(USceneComponent* FP_MuzzleLocation)
{
	UWorld* const World = GetWorld();
	if (World != nullptr && _numberOfBallLeft > 0)
	{
		int breakWhile = 0;
		int numberOfBallNeededToBeShoot = _dataWeapon._numberOfBallShoot;
		while (numberOfBallNeededToBeShoot > 0 && breakWhile < 100 && _numberOfBallLeft > 0)
		{
			breakWhile++;
			numberOfBallNeededToBeShoot--;
			const FRotator SpawnRotation = UGameplayStatics::GetPlayerCameraManager(World,0)->GetCameraRotation();//GetActorRotation();//GetControlRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			//	const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(_dataWeapon._gunOffset);
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			FVector GunOffset = FVector(100.0f, 0.0f, 10.0f);
			//UKismetMathLibrary::RandomUnitVectorInConeInDegrees(,120f);
			const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);

			//Set Spawn Collision Handling Override
			// FActorSpawnParameters ActorSpawnParams;
			// ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

			// spawn the projectile at the muzzle
			FTransform BulletTransform = {SpawnRotation,SpawnLocation};
			BulletTransform.SetScale3D(FVector(_dataWeapon._ballSize,_dataWeapon._ballSize,_dataWeapon._ballSize));
			ABaseBullet* _bulletsShotgun = World->SpawnActorDeferred<ABaseBullet>(_dataWeapon._modelOfBullet,BulletTransform, this,nullptr,
				ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);
			if (_bulletsShotgun != nullptr)
			{
				//_bulletsShotgun->SetActorScale3D(FVector(_dataWeapon._ballSize,_dataWeapon._ballSize,_dataWeapon._ballSize));
				AShotGunBullets* _bulletClass = Cast<AShotGunBullets>(_bulletsShotgun);
				if (_bulletClass != nullptr)
					
				{
					_bulletClass->_dataBullet = _dataWeapon;
				}
				UGameplayStatics::FinishSpawningActor(_bulletsShotgun,BulletTransform);
			}
			// ABaseBullet* _bulletsShotgun = World->SpawnActor<ABaseBullet>(_dataWeapon._modelOfBullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
			// if (_bulletsShotgun != nullptr)
			// {
			// 	_bulletsShotgun->SetActorScale3D(FVector(_dataWeapon._ballSize,_dataWeapon._ballSize,_dataWeapon._ballSize));
			// 	AShotGunBullets* _bulletClass = Cast<AShotGunBullets>(_bulletsShotgun);
			// 	if (_bulletClass != nullptr)
			// 	{
			// 		_bulletClass->_dataBullet._dmg = _dataWeapon._dmg;
			// 		_bulletClass->_dataBullet._speed = _dataWeapon._speed;
			// 		_bulletClass->_dataBullet._impactPower = _dataWeapon._impactPower;
			// 	}
			// }
		}
		_numberOfBallLeft--;
	}
}

void AWeaponShotGun::SpecialFire(USceneComponent* FP_MuzzleLocation)
{
	UWorld* const World = GetWorld();
	if (World != nullptr && _numberOfBallLeft > 0)
	{
		int breakWhile = 0;
		int numberOfBallNeededToBeShoot = _dataWeapon._numberOfBallShoot;
		while (numberOfBallNeededToBeShoot > 0 && breakWhile < 100 && _numberOfBallLeft > 0)
		{
			breakWhile++;
			numberOfBallNeededToBeShoot--;
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
			World->SpawnActor<ABaseBullet>(_dataWeapon._modelOfBullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
		_numberOfBallLeft--;
	}
}

