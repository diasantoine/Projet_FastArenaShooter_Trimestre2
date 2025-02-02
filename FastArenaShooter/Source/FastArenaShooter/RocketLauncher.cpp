// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketLauncher.h"

#include "Rocket.h"
#include "Kismet/GameplayStatics.h"

void ARocketLauncher::NormalFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect)
{
	UWorld* const World = GetWorld();
	if (World != nullptr && _numberOfBallLeft > 0)
	{
		int breakWhile = 0;
		int numberOfBallNeededToBeShoot = _dataWeapon._numberOfBallShoot;
		if (_timeBeforeNextShoot <= 0)
		{
			_justFire = true;
			_justFireRecoilAnimation = true;
			while (numberOfBallNeededToBeShoot > 0 && breakWhile < 100 && _numberOfBallLeft > 0)
			{
				breakWhile++;
				numberOfBallNeededToBeShoot--;
				const FRotator SpawnRotation = UGameplayStatics::GetPlayerCameraManager(World,0)->GetCameraRotation();
				FVector GunOffset = FVector(100.0f, 0.0f, 10.0f);
				const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
				// spawn the projectile at the muzzle
				FTransform BulletTransform = {SpawnRotation,SpawnLocation};
				BulletTransform.SetScale3D(FVector(_dataWeapon._ballSize,_dataWeapon._ballSize,_dataWeapon._ballSize));
				ABaseBullet* _bulletsShotgun = World->SpawnActorDeferred<ABaseBullet>(_dataWeapon._modelOfBullet,BulletTransform, this,nullptr,
					ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);
				if (_bulletsShotgun != nullptr)
				{
					ARocket* _bulletClass = Cast<ARocket>(_bulletsShotgun);
					if (_bulletClass != nullptr)
					{
						_bulletClass->_dataBullet = _dataWeapon;
						_bulletClass->_percentageSpeed = FMath::Clamp(_percentageEffect,_minimalPowerExplosion,1.f);
						_bulletClass->_minimalPower = _minimalPowerExplosion;
						_bulletClass->_minimalDMGExplosion = _minimalDMGExplosion;
						_bulletClass->_minimalExplosionRange = _minimalExplosionRange;
					}
					UGameplayStatics::FinishSpawningActor(_bulletsShotgun,BulletTransform);
				}
			}
			_timeBeforeNextShoot = _dataWeapon._cadenceTir;
			_numberOfBallLeft--;
		}
	}
}

void ARocketLauncher::SpecialFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect)
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