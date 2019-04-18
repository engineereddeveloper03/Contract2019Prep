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
	UButton* PlayButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UMenuAnchor* MenuAnchorB;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UTextBlock* InvalidText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UTextBlock* RetainerText;

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

	// Misc
	bool colored;
	bool textToggled;
};
