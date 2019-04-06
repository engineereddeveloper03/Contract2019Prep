// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Contract2019PrepCharacter.h"
#include "Contract2019PrepGameMode.generated.h"

UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AContract2019PrepGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AContract2019PrepGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	AContract2019PrepCharacter* MyCharacter;

	UFUNCTION(BlueprintPure, Category = "Health")
	EGamePlayState GetCurrentState() const;

	void SetCurrentState(EGamePlayState NewState);

private:
	EGamePlayState CurrentState;

	void HandleNewState(EGamePlayState NewState);
};



