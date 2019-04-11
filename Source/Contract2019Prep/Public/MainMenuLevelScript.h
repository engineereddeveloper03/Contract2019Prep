// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet\GameplayStatics.h"
#include "Widget.h"
#include "UserWidget.h"
#include "HUDWidget.h"
#include "Engine/LevelScriptActor.h"
#include "MainMenuLevelScript.generated.h"

/**
 * 
 */
UCLASS()
class CONTRACT2019PREP_API AMainMenuLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	APlayerController* Player;

	UUserWidget* MainMenu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Main Menu Widget")
	TSubclassOf<class UUserWidget> MainMenuObject;
};
