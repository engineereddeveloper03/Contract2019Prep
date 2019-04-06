// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Contract2019PrepGameMode.h"
#include "Contract2019PrepCharacter.h"
#include "Kismet/GameplayStatics.h"
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

void AContract2019PrepGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AContract2019PrepCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AContract2019PrepGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MyCharacter)
	{
		if (FMath::IsNearlyZero(MyCharacter->GetHealth(), 0.001f))
		{
			SetCurrentState(EGamePlayState::EGameOver);
		}
	}
}

EGamePlayState AContract2019PrepGameMode::GetCurrentState() const
{
	return CurrentState;
}

void AContract2019PrepGameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AContract2019PrepGameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
		case EGamePlayState::EPlaying:
			// do nothing
			break;
		case EGamePlayState::EGameOver:
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
			break;
		case EGamePlayState::EUnknown:
			// do nothing
			break;
		default:
			break;
	}
}
