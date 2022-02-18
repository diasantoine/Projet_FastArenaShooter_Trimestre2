// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

void AMyPlayerController::InputPlayer()
{
	this->InputComponent->BindAction<_axisValue>("Forward", IE_Pressed, _myCharacterController,&AMyCharacterController::MovementPlayer,
		new FVector(0,0,InputComponent->GetAxisValue("Forward")));
	this->InputComponent->BindAction<_axisValue>("Right", IE_Pressed, _myCharacterController,&AMyCharacterController::MovementPlayer,
	new FVector(InputComponent->GetAxisValue("Right"),0,0));
	this->InputComponent->BindAction<_axisValue>("Jump", IE_Pressed, _myCharacterController,&AMyCharacterController::MovementPlayer,
    	new FVector(0,InputComponent->GetAxisValue("Jump"),0));

	this->InputComponent->BindAction<_typeOfFire>("NormalFire", IE_Pressed, _myCharacterController, &AMyCharacterController::ShootWeapon,false);
	this->InputComponent->BindAction<_typeOfFire>("SpecialFire", IE_Pressed, _myCharacterController, &AMyCharacterController::ShootWeapon,true);
}

void AMyPlayerController::BeginPlay()
{
	InputPlayer();
}
