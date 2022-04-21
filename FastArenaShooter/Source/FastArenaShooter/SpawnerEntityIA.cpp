// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnerEntityIA.h"

#include "AIRangeMob.h"
#include "AITankMob.h"
#include "AITrashMob.h"

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
	//GetWorldTimerManager().SetTimer(_timerManager,this,&ASpawnerEntityIA::RapidSpawnIA,5,true,0);
	// if (Cast<AAITrashMob>(_iaToSpawn))
	// {
	// 	GetWorldTimerManager().SetTimer(_timerIATrash,this,&ASpawnerEntityIA::IATrashSpawner,_waweIA[0]._waweParameter[_iaToSpawn]._cooldownSpawn,true,
	// 		_waweIA[0]._waweParameter[_iaToSpawn]._cooldownSpawn);
	// }else if (Cast<AAIRangeMob>(_iaToSpawn))
	// {
	// 	GetWorldTimerManager().SetTimer(_timerIARange,this,&ASpawnerEntityIA::IARangeSpawner,_waweIA[0]._waweParameter[_iaToSpawn]._cooldownSpawn,true,
	// 		_waweIA[0]._waweParameter[_iaToSpawn]._cooldownSpawn);
	// }
	// else
	// {
	// 	GetWorldTimerManager().SetTimer(_timerIATank,this,&ASpawnerEntityIA::IATankSpawner,_waweIA[0]._waweParameter[_iaToSpawn]._cooldownSpawn,true,
	// 		_waweIA[0]._waweParameter[_iaToSpawn]._cooldownSpawn);
	// }
}

// Called every frame
void ASpawnerEntityIA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawnerEntityIA::ChangeWawe()
{
	if (_index < _waweIA.Num())
	{
		GetWorldTimerManager().ClearAllTimersForObject(this);
		AAITrashMob* TrashMob = Cast<AAITrashMob>(_iaToSpawn);
		AAIRangeMob* RangeMob = Cast<AAIRangeMob>(_iaToSpawn);
		AAITankMob* TankMob = Cast<AAITankMob>(_iaToSpawn);//TODO les cast ne marchent pas à check ASAP
		if (TrashMob != nullptr)
		{
			GetWorldTimerManager().SetTimer(_timerIATrash,this,&ASpawnerEntityIA::IATrashSpawner,_waweIA[_index]._waweParameter[_iaToSpawn]._cooldownSpawn,true,
				_waweIA[_index]._waweParameter[_iaToSpawn]._cooldownSpawn);
		}else if (RangeMob != nullptr)
		{
			GetWorldTimerManager().SetTimer(_timerIARange,this,&ASpawnerEntityIA::IARangeSpawner,_waweIA[_index]._waweParameter[_iaToSpawn]._cooldownSpawn,true,
				_waweIA[_index]._waweParameter[_iaToSpawn]._cooldownSpawn);
		}
		else if(TankMob != nullptr)
		{
			GetWorldTimerManager().SetTimer(_timerIATank,this,&ASpawnerEntityIA::IATankSpawner,_waweIA[_index]._waweParameter[_iaToSpawn]._cooldownSpawn,true,
				_waweIA[_index]._waweParameter[_iaToSpawn]._cooldownSpawn);
		}
	}
	_index++;
}


void ASpawnerEntityIA::RapidSpawnIA()
{
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AFAS_IACharacter>(_iaToSpawn,GetActorLocation(),FRotator(0,0,0),ActorSpawnParams);
}

void ASpawnerEntityIA::IATrashSpawner()
{
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AAITrashMob>(_iaToSpawn,GetActorLocation(),FRotator(0,0,0),ActorSpawnParams);
	_waweIA[_index]._waweParameter[_iaToSpawn]._numberOfSpawn--;
	if (_waweIA[_index]._waweParameter[_iaToSpawn]._numberOfSpawn <= 0)
	{
		GetWorldTimerManager().ClearTimer(_timerIATrash);
	}
}

void ASpawnerEntityIA::IARangeSpawner()
{
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	GetWorld()->SpawnActor<AAIRangeMob>(_iaToSpawn,GetActorLocation(),FRotator(0,0,0),ActorSpawnParams);
	_waweIA[_index]._waweParameter[_iaToSpawn]._numberOfSpawn--;
	if (_waweIA[_index]._waweParameter[_iaToSpawn]._numberOfSpawn <= 0)
	{
		GetWorldTimerManager().ClearTimer(_timerIARange);
	}
}

void ASpawnerEntityIA::IATankSpawner()
{
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
	AAITankMob* IATank = GetWorld()->SpawnActor<AAITankMob>(_iaToSpawn,GetActorLocation(),FRotator(0,0,0),ActorSpawnParams);
	_waweIA[_index]._waweParameter[_iaToSpawn]._numberOfSpawn--;
	if (IATank != nullptr)
	{
		IATank->_arrayOfRandomPosition = _arrayOfRandomPositionForTank;
	}
	if (_waweIA[_index]._waweParameter[_iaToSpawn]._numberOfSpawn <= 0)
	{
		GetWorldTimerManager().ClearTimer(_timerIATank);
	}
}




