// Fill out your copyright notice in the Description page of Project Settings.


#include "MyWeaponBehaviour.h"

// Sets default values
AMyWeaponBehaviour::AMyWeaponBehaviour()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called when the game starts or when spawned
void AMyWeaponBehaviour::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyWeaponBehaviour::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyWeaponBehaviour::Fire(bool _normalFire)
{
	if (_normalFire)
	{
		NormalFire();
	}
	else
	{
		SpecialFire();
	}
}

void AMyWeaponBehaviour::NormalFire()
{
	UE_LOG(LogTemp,Warning,TEXT("Normal FIre"));
}

void AMyWeaponBehaviour::SpecialFire()
{
	UE_LOG(LogTemp,Warning,TEXT("Special FIre"));
}




