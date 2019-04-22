// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ProgressBar.h"
#include "TextBlock.h"
#include "MyNewBlueprintFunctionLibrary.h"
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
	TMap<FString, class UWidgetAnimation*> FindWidgetAnimation;

	UWidgetBlueprintGeneratedClass* WidgetClass;

	virtual void NativeConstruct() override;

	AContract2019PrepCharacter* MyCharacter;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UProgressBar* HealthBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UProgressBar* MagicBar;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UTextBlock* HealthText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UTextBlock* MagicText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animations")
	UWidgetAnimation* FlashAnim;

	UFUNCTION()
	void playDamageAnim();

	// Event Handlers
	UFUNCTION()
	void UpdateHealthBar();

	UFUNCTION()
	void UpdateHealthText();

	UFUNCTION()
	float UpdateMagicBar();

	UFUNCTION()
	FText UpdateMagicText();

	UFUNCTION()
	void UpdateMagic();

	UFUNCTION()
	void UpdateMagicEnd();
};
