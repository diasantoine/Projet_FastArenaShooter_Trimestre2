// Fill out your copyright notice in the Description page of Project Settings.


#include "RiffleWeapon.h"
#include "ABulletForRiffle.h"
#include "Kismet/GameplayStatics.h"

void ARiffleWeapon::NormalFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect)
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
				UE_LOG(LogTemp,Warning,TEXT("test"));
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
					ABulletForRiffle* _bulletClass = Cast<ABulletForRiffle>(_bulletsShotgun);
					if (_bulletClass != nullptr)
					
					{
						_bulletClass->_dataBullet = _dataWeapon;
						_bulletClass->_dataBullet._speed = FMath::Clamp(_dataWeapon._speed / _percentageEffect,_dataWeapon._speed * 0.1f, _dataWeapon._speed);
					}
					UGameplayStatics::FinishSpawningActor(_bulletsShotgun,BulletTransform);
				}
			}
			_timeBeforeNextShoot = FMath::Clamp(_dataWeapon._cadenceTir / _percentageEffect,_dataWeapon._cadenceTir,_maximumCadenceTir);
			UE_LOG(LogTemp,Warning,TEXT("%f"),_percentageEffect)
			_numberOfBallLeft--;
		}
	}
}


void ARiffleWeapon::SpecialFire(USceneComponent* FP_MuzzleLocation, float _percentageEffect)
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
			const FRotator SpawnRotation = GetActorRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(_dataWeapon._gunOffset);
			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			// spawn the projectile at the muzzle
			World->SpawnActor<ABaseBullet>(_dataWeapon._modelOfBullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
		_numberOfBallLeft--;
	}
}

