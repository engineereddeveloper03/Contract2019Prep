// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthUI.h"

void UHealthUI::NativeConstruct()
{
	MyCharacter = Cast<AContract2019PrepCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (HealthBar)
	{
		HealthBar->PercentDelegate.BindUFunction(this, "UpdateHealthBar");
		HealthBar->SynchronizeProperties();

		MagicBar->PercentDelegate.BindUFunction(this, "UpdateMagicBar");
		MagicBar->SynchronizeProperties();
	}
}

float UHealthUI::UpdateHealthBar()
{
	return MyCharacter->GetHealth();
}

float UHealthUI::UpdateMagicBar()
{
	return MyCharacter->GetMagic();
}
