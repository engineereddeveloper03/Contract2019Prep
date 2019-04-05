// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Contract2019PrepGameMode.h"
#include "Contract2019PrepCharacter.h"
#include "UObject/ConstructorHelpers.h"

AContract2019PrepGameMode::AContract2019PrepGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
