// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FastArenaShooterHUD.generated.h"

UCLASS()
class AFastArenaShooterHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFastArenaShooterHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

