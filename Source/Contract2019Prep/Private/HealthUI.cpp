// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthUI.h"

void UHealthUI::NativeConstruct()
{
	Super::NativeConstruct();

	if (!MyCharacter)
	{
		MyCharacter = Cast<AContract2019PrepCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	}

	if (MyCharacter)
	{
		MyCharacter->OnDamageDealt.AddDynamic(this, &UHealthUI::playDamageAnim);
		MyCharacter->OnHealthChange.AddDynamic(this, &UHealthUI::UpdateHealthText);
		MyCharacter->OnHealthChange.AddDynamic(this, &UHealthUI::UpdateHealthBar);

		// sets current health to UI (if carried over from other levels)
		UpdateHealthBar();
		UpdateHealthText();
	}

	// Find flash animation workaround
	// Reference: https://answers.unrealengine.com/questions/427948/get-widget-animation-in-c.html
	if (!WidgetClass)
	{
		WidgetClass = GetWidgetTreeOwningClass();
	}

	if (WidgetClass)
	{
		FindWidgetAnimation.Empty();

		for (int i = 0; i < WidgetClass->Animations.Num(); i++)
		{
			FString Name = WidgetClass->Animations[i]->GetName();
			FindWidgetAnimation.Add(Name, WidgetClass->Animations[i]);
		}

		if (WidgetClass->Animations[0] != NULL) 
		{
			FlashAnim = WidgetClass->Animations[0];
		}
		else 
		{
			UE_LOG(LogTemp, Warning, TEXT("There are no animations..."));
		}
	}

	if (MagicBar)
	{
		MagicBar->PercentDelegate.BindUFunction(this, "UpdateMagicBar");
		MagicBar->SynchronizeProperties();
	}

	if (MagicText)
	{
		MagicText->TextDelegate.BindUFunction(this, "UpdateMagicText");
		MagicText->SynchronizeProperties();
	}
}

void UHealthUI::playDamageAnim()
{
	if (FlashAnim)
	{
		PlayAnimation(FlashAnim);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No animation found."));
	}
}

void UHealthUI::UpdateHealthBar()
{
	if (HealthBar)
	{
		HealthBar->SetPercent(MyCharacter->GetHealth());
	}
}

float UHealthUI::UpdateMagicBar()
{
	if (MyCharacter)
	{
		return MyCharacter->GetMagic();
	}
	else
	{
		return 1.0f;
	}
}

// Description: Updating health directly when signaled to optimize performance.
void UHealthUI::UpdateHealthText()
{
	if (HealthText)
	{
		HealthText->SetText(MyCharacter->GetHealthIntText());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No health text found."));
	}
}

FText UHealthUI::UpdateMagicText()
{
	if (MyCharacter)
	{
		return MyCharacter->GetMagicIntText();
	}
	else
	{
		return FText::FromString("");
	}
}
