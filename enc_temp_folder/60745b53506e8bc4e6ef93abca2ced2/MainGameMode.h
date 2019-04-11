// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Contract2019PrepCharacter.h"
#include "MainGameMode.generated.h"

UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};

/**
 * 
 */
UCLASS()
class CONTRACT2019PREP_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMainGameMode();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	AContract2019PrepCharacter* MyCharacter;

	UFUNCTION(BlueprintPure, Category = "Health")
	EGamePlayState GetCurrentState() const;

	void SetCurrentState(EGamePlayState NewState);

	UPROPERTY(EditAnywhere, Category = "Health")
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
	class UUserWidget* CurrentWidget;

private:
	EGamePlayState CurrentState;

	void HandleNewState(EGamePlayState NewState);
};
