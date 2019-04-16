// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProgressBar.h"
#include "Text.h"
#include "Contract2019PrepCharacter.h"
#include "Kismet\GameplayStatics.h"
#include "HealthUI.generated.h"

/**
 * 
 */
UCLASS()
class CONTRACT2019PREP_API UHealthUI : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	//virtual void BeginPlay() override;

	AContract2019PrepCharacter* MyCharacter;

	UPROPERTY(meta = (BindWidgetOptional))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidgetOptional))
	UProgressBar* MagicBar;

	//UPROPERTY(meta = (BindWidgetOptional))
	//UTextBuffer* HealthText;

	// Event Handlers
	UFUNCTION()
	float UpdateHealthBar();

	UFUNCTION()
	float UpdateMagicBar();
};
