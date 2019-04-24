// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDWidget.h"

UHUDWidget::UHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	colored = false;
	textToggled = false;
	englishText = true;
}

void UHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// binding functions to widget events
	ExampleButton->OnClicked.AddDynamic(this, &UHUDWidget::OnButtonClicked);
	ExampleButton->OnClicked.AddDynamic(this, &UHUDWidget::DoubleClick);

	ExampleButton2->OnReleased.AddDynamic(this, &UHUDWidget::toggleMenu);

	PerformanceButton->OnReleased.AddDynamic(this, &UHUDWidget::changeText);

	ChangeButton->OnReleased.AddDynamic(this, &UHUDWidget::changePage);

	LanguageButton->OnReleased.AddDynamic(this, &UHUDWidget::toggleLanguage);

	PlayButton->OnClicked.AddDynamic(this, &UHUDWidget::StartGame);
	PlayButton->OnHovered.AddDynamic(this, &UHUDWidget::SaySomething);

	// get number of widgets to switch between
	if (LogoHolder)
	{
		numWidgets = LogoHolder->GetNumWidgets();
	}

	// set localization text
	text1A = NSLOCTEXT("UMG", "Text1A", "Hello");
	text1B = NSLOCTEXT("UMG", "Text1B", "Goodbye");
	text2A = NSLOCTEXT("UMG", "Text2A", "Change");
	text2B = NSLOCTEXT("UMG", "Text2B", "Back");
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
	OptionsAnchor->ToggleOpen(false);
}

// Description: Changes the text on the widget toggling them between two types of Strings.
void UHUDWidget::changeText()
{
	if (textToggled)
	{
		InvalidText->SetText(text1A);
		RetainerText->SetText(text2A);
	}
	else
	{
		InvalidText->SetText(text1B);
		RetainerText->SetText(text2B);
	}

	textToggled = !textToggled;
}

// Description: Switches between the available widget pages.
void UHUDWidget::changePage()
{
	int currIndex = LogoHolder->GetActiveWidgetIndex();
	if (currIndex == numWidgets - 1)
	{
		LogoHolder->SetActiveWidgetIndex(0);
	}
	else
	{
		LogoHolder->SetActiveWidgetIndex(currIndex + 1);
	}
}

void UHUDWidget::toggleLanguage()
{
	if (englishText)
	{
		FInternationalization::Get().SetCurrentCulture(TEXT("es"));
	}
	else
	{
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
	}

	englishText = !englishText;
}

void UHUDWidget::SaySomething()
{
	UE_LOG(LogTemp, Warning, TEXT("Hovering"));
}


TSharedRef<SWidget> UHUDWidget::RebuildWidget()
{
	TSharedRef<SWidget> Widget = Super::RebuildWidget();
	return Widget;
}
