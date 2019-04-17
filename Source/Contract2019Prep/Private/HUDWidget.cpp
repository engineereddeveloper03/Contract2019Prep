// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDWidget.h"

UHUDWidget::UHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	colored = false;
}

void UHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// binding functions to widget events
	ExampleButton->OnClicked.AddDynamic(this, &UHUDWidget::OnButtonClicked);
	ExampleButton->OnClicked.AddDynamic(this, &UHUDWidget::DoubleClick);

	ExampleButton2->OnReleased.AddDynamic(this, &UHUDWidget::toggleMenu);

	PlayButton->OnClicked.AddDynamic(this, &UHUDWidget::StartGame);
}

bool UHUDWidget::Initialize()
{
	bool orig = Super::Initialize();

	return orig;
}

// Description: Toggles the button color from green to blue.
void UHUDWidget::OnButtonClicked()
{
	if (colored)
	{
		ExampleButton->SetBackgroundColor(FLinearColor::Blue);
	}
	else
	{
		ExampleButton->SetBackgroundColor(FLinearColor::Green);
	}

	colored = !colored;
}

// Description: Testing how two functions bound to the same event operate in-game.
//              However, functionality is similar to OnButtonClicked.
void UHUDWidget::DoubleClick()
{
	if (!colored)
	{
		ExampleButton2->SetBackgroundColor(FLinearColor::Red);
	}
	else
	{
		ExampleButton2->SetBackgroundColor(FLinearColor::Gray);
	}
}

// Description: Loads the main level when the Play button is pressed.
void UHUDWidget::StartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), "ThirdPersonExampleMap");
}

// Description: Opens/closes the sub menu for the second button.
void UHUDWidget::toggleMenu()
{
	MenuAnchorB->ToggleOpen(false);
}

TSharedRef<SWidget> UHUDWidget::RebuildWidget()
{
	TSharedRef<SWidget> Widget = Super::RebuildWidget();
	return Widget;
}
