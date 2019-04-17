// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProgressBar.h"
#include "TextBlock.h"
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

	AContract2019PrepCharacter* MyCharacter;

	UPROPERTY(meta = (BindWidgetOptional))
	UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidgetOptional))
	UProgressBar* MagicBar;

	UPROPERTY(meta = (BindWidgetOptional))
	UTextBlock* HealthText;

	UPROPERTY(meta = (BindWidgetOptional))
	UTextBlock* MagicText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UWidgetAnimation* FlashAnim;

	// Event Handlers
	UFUNCTION()
	float UpdateHealthBar();

	UFUNCTION()
	float UpdateMagicBar();

	UFUNCTION()
	FText UpdateHealthText();

	UFUNCTION()
	FText UpdateMagicText();
};
