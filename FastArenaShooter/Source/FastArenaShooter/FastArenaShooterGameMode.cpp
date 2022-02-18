// Copyright Epic Games, Inc. All Rights Reserved.

#include "FastArenaShooterGameMode.h"
#include "FastArenaShooterHUD.h"
#include "FastArenaShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFastArenaShooterGameMode::AFastArenaShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFastArenaShooterHUD::StaticClass();
}
