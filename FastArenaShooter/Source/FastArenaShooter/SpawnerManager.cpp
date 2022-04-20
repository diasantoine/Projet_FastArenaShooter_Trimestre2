// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerManager.h"

#include "SpawnerEntityIA.h"

// Sets default values
ASpawnerManager::ASpawnerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerManager::BeginPlay()
{
	Super::BeginPlay();
	_containerTimeLeft = _timeBeforeNewWawe;
}

// Called every frame
void ASpawnerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (_containerTimeLeft > 0)
	{
		_containerTimeLeft -= DeltaTime;
	}
	else
	{
		_containerTimeLeft = _timeBeforeNewWawe;
		for (AActor* actor : _arrayOfSpawner)
		{
			ASpawnerEntityIA* spawner = Cast<ASpawnerEntityIA>(actor);
			spawner->ChangeWawe();
		}
	}
}

