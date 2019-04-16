// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthUI.h"

void UHealthUI::NativeConstruct()
{
	if (HealthBar)
	{
		HealthBar->PercentDelegate.BindUFunction(this, "UpdateImage");
	}
}

float UHealthUI::UpdateHealthBar()
{
	MyCharacter = Cast<AContract2019PrepCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	return 1;

	//return MyCharacter->GetHealth();
}
