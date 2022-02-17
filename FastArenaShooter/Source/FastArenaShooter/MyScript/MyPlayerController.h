// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacterController.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FASTARENASHOOTER_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	DECLARE_DELEGATE_OneParam(_axisValue, FVector);

protected:
	
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditDefaultsOnly,VisibleAnywhere,Category = "Essential Parameter")
	AMyCharacterController* _myCharacterController;
	
private:
	void InputPlayer();
	
};
