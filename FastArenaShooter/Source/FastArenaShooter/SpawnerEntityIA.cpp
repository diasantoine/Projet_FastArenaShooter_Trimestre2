// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerEntityIA.h"

// Sets default values
ASpawnerEntityIA::ASpawnerEntityIA()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawnerEntityIA::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnerEntityIA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (FWaweIA WaweIA : _waweIA)
	{
		for (auto IAParameter : WaweIA._waweParameter)
		{
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
			for (AActor* Spawner :IAParameter.Value._spawner)
			{
				GetWorld()->SpawnActor<AFAS_IACharacter>(IAParameter.Key,Spawner->GetActorLocation(),FRotator(0,0,0),ActorSpawnParams);
			}
		}
	}
}

