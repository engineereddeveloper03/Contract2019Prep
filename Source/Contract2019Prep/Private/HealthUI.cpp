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

		MyCharacter->OnMagicChangeStart.AddDynamic(this, &UHealthUI::UpdateMagic);
		MyCharacter->OnMagicChangeEnd.AddDynamic(this, &UHealthUI::UpdateMagicEnd);

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

// Description: Updating health directly when signaled to optimize performance.
void UHealthUI::UpdateHealthText()
{
	if (HealthText)
	{
		HealthText->SetText(MyCharacter->GetHealthIntText());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No health text widget found."));
	}
}

// Description: Binds the text and magic bar when update is called so UI updates properly.
void UHealthUI::UpdateMagic()
{
	// bind MagicText
	if (MagicText)
	{
		MagicText->TextDelegate.BindUFunction(this, "UpdateMagicText");
		MagicText->SynchronizeProperties();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No magic text widget found."));
	}

	// bind MagicBar
	if (MagicText)
	{
		MagicBar->PercentDelegate.BindUFunction(this, "UpdateMagicBar");
		MagicBar->SynchronizeProperties();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No magic bar widget found."));
	}
}

// Description: Removes binding from text and magic bar when update is complete.
void UHealthUI::UpdateMagicEnd()
{
	// reset magic text
	if (MagicText)
	{
		MagicText->TextDelegate.Clear();
		MagicText->SetText(MyCharacter->GetMagicIntText());
		MagicText->SynchronizeProperties();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No magic text widget found."));
	}

	// reset magic bar
	if (MagicText)
	{
		MagicBar->PercentDelegate.Clear();
		MagicBar->SetPercent(MyCharacter->GetMagic());
		MagicBar->SynchronizeProperties();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No magic bar widget found."));
	}
}
