// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "Contract2019PrepHUD.h"
#include "Contract2019PrepCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AMainGameMode::AMainGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<UUserWidget> HealthBar(TEXT("/Game/ThirdPerson/UI/HealthUI"));
	HUDWidgetClass = HealthBar.Class;

	// use our custom HUD class
	HUDClass = AContract2019PrepHUD::StaticClass();

	// add Health Bar UI to viewport
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AContract2019PrepCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AMainGameMode::Tick(float DeltaTime)
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

EGamePlayState AMainGameMode::GetCurrentState() const
{
	return CurrentState;
}

void AMainGameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AMainGameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::EPlaying:
		// do nothing
		break;
	case EGamePlayState::EGameOver:
		UGameplayStatics::OpenLevel(this, "MainMenu");
		break;
	case EGamePlayState::EUnknown:
		// do nothing
		break;
	default:
		break;
	}
}
