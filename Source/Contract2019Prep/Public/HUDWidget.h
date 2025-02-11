// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CanvasPanel.h"
#include "CanvasPanelSlot.h"
#include "Button.h"
#include "TextBlock.h"
#include "WidgetTree.h"
#include "MenuAnchor.h"
#include "WidgetSwitcher.h"
#include "Kismet\GameplayStatics.h"
#include "HUDWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CONTRACT2019PREP_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	UHUDWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	virtual TSharedRef<SWidget> RebuildWidget() override;

	// UI Elements
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UButton* ExampleButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UButton* ExampleButton2;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UButton* PerformanceButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UButton* ChangeButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UButton* PlayButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UButton* LanguageButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UMenuAnchor* OptionsAnchor;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UTextBlock* InvalidText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UTextBlock* RetainerText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UWidgetSwitcher* LogoHolder;

	// Event Handlers
	UFUNCTION()
	void OnButtonClicked();

	UFUNCTION()
	void DoubleClick();

	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void toggleMenu();

	UFUNCTION()
	void changeText();

	UFUNCTION()
	void changePage();

	UFUNCTION()
	void toggleLanguage();

	UFUNCTION()
	void SaySomething();

	// Localization Text
	FText text1A;
	FText text1B;
	FText text2A;
	FText text2B;

	// Misc
	bool colored;
	bool textToggled;
	bool englishText;
	int numWidgets;
};
