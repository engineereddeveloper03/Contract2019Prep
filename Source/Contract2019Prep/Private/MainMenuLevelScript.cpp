// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuLevelScript.h"


// Create pre-defined Main Menu widget to level and display to screen.
void AMainMenuLevelScript::BeginPlay()
{
	Player = UGameplayStatics::GetPlayerController(this, 0);

	if (Player)
	{
		MainMenu = CreateWidget<UUserWidget>(Player, MainMenuObject);
	}

	if (MainMenu)
	{
		MainMenu->AddToViewport();
		Player->bShowMouseCursor = true;
	}
}
