// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "HowDoGameMode.h"
#include "HowDoHUD.h"
#include "HowDoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHowDoGameMode::AHowDoGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AHowDoHUD::StaticClass();
}
