// Copyright Epic Games, Inc. All Rights Reserved.

#include "BeastiaryGameMode.h"
#include "BeastiaryPlayerController.h"
#include "BeastiaryCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABeastiaryGameMode::ABeastiaryGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABeastiaryPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}