// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthUI.h"

void UHealthUI::NativeConstruct()
{
	if (!MyCharacter)
	{
		MyCharacter = Cast<AContract2019PrepCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	}

	if (HealthBar)
	{
		HealthBar->PercentDelegate.BindUFunction(this, "UpdateHealthBar");
		HealthBar->SynchronizeProperties();
	}

	if (MagicBar)
	{
		MagicBar->PercentDelegate.BindUFunction(this, "UpdateMagicBar");
		MagicBar->SynchronizeProperties();
	}

	if (HealthText)
	{
		HealthText->TextDelegate.BindUFunction(this, "UpdateHealthText");
		HealthText->SynchronizeProperties();
	}

	if (MagicText)
	{
		MagicText->TextDelegate.BindUFunction(this, "UpdateMagicText");
		MagicText->SynchronizeProperties();
	}
}

float UHealthUI::UpdateHealthBar()
{
	UE_LOG(LogTemp, Warning, TEXT("Running1"));
	if (MyCharacter)
	{
		return MyCharacter->GetHealth();
	}
	else
	{
		return 1.0f;
	}
}

float UHealthUI::UpdateMagicBar()
{
	//UE_LOG(LogTemp, Warning, TEXT("Running2"));
	if (MyCharacter)
	{
		return MyCharacter->GetMagic();
	}
	else
	{
		return 1.0f;
	}
}

FText UHealthUI::UpdateHealthText()
{
	//UE_LOG(LogTemp, Warning, TEXT("Running3"));
	if (MyCharacter)
	{
		return MyCharacter->GetHealthIntText();
	}
	else
	{
		return FText::FromString("");
	}
}

FText UHealthUI::UpdateMagicText()
{
	//UE_LOG(LogTemp, Warning, TEXT("Running4"));
	if (MyCharacter)
	{
		return MyCharacter->GetMagicIntText();
	}
	else
	{
		return FText::FromString("");
	}
}
