// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstWeapon.h"

void AMyWeaponBehaviour::OnConstruction(const FTransform& Transform)
{
	
}

void AMyFirstWeapon::NormalFire()
{
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		const FRotator SpawnRotation = GetActorRotation();//GetControlRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(_dataWeapon._gunOffset->GetActorLocation());

		//Set Spawn Collision Handling Override
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		// spawn the projectile at the muzzle
		World->SpawnActor<AMyBulletsBehaviour>(_dataWeapon._modelOfBullet, SpawnLocation, SpawnRotation, ActorSpawnParams);
	}
}


void AMyFirstWeapon::SpecialFire()
{
	
}

