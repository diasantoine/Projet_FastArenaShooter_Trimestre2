// Fill out your copyright notice in the Description page of Project Settings.


#include "IAWeapon.h"

#include "IABullet.h"
#include "Kismet/GameplayStatics.h"

void AIAWeapon::NormalFire(USceneComponent* FP_MuzzleLocation)
{
	UWorld* const World = GetWorld();
	if (World != nullptr && _numberOfBallLeft > 0)
	{
		int breakWhile = 0;
		int numberOfBallNeededToBeShoot = _dataWeapon._numberOfBallShoot;
		if (_timeBeforeNextShoot <= 0)
		{
			while (numberOfBallNeededToBeShoot > 0 && breakWhile < 100 )//&& _numberOfBallLeft > 0)
				{
					breakWhile++;
					numberOfBallNeededToBeShoot--;
					const FRotator SpawnRotation = GetActorRotation();//GetActorRotation();//GetControlRotation();
					FVector GunOffset = FVector(100.0f, 0.0f, 10.0f);
					const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr) ? FP_MuzzleLocation->GetComponentLocation() : GetActorLocation()) + SpawnRotation.RotateVector(GunOffset);
					FTransform BulletTransform = {SpawnRotation,SpawnLocation};
					BulletTransform.SetScale3D(FVector(_dataWeapon._ballSize,_dataWeapon._ballSize,_dataWeapon._ballSize));
					ABaseBullet* _bulletsShotgun = World->SpawnActorDeferred<ABaseBullet>(_dataWeapon._modelOfBullet,BulletTransform, this,nullptr,
						ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn);
					if (_bulletsShotgun != nullptr)
					{
						AIABullet* _bulletClass = Cast<AIABullet>(_bulletsShotgun);
						if (_bulletClass != nullptr)
						{
							_bulletClass->_dataBullet = _dataWeapon;
						}
						UGameplayStatics::FinishSpawningActor(_bulletsShotgun,BulletTransform);
					}
				}
			_timeBeforeNextShoot = _dataWeapon._cadenceTir;
		}
		//_numberOfBallLeft--;
	}
}

void  AIAWeapon::SpecialFire(USceneComponent* FP_MuzzleLocation)
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
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			World->SpawnActor<ABaseBullet>(_dataWeapon._modelOfBullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
		_numberOfBallLeft--;
	}
}