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
	UPROPERTY(meta = (BindWidgetOptional))
	UButton* ExampleButton;

	UPROPERTY(meta = (BindWidgetOptional))
	UButton* ExampleButton2;

	UPROPERTY(meta = (BindWidgetOptional))
	UButton* PlayButton;

	UPROPERTY(meta = (BindWidgetOptional))
	UMenuAnchor* MenuAnchorB;

	// Event Handlers
	UFUNCTION()
	void OnButtonClicked();

	UFUNCTION()
	void DoubleClick();

	UFUNCTION()
	void StartGame();

	UFUNCTION()
	void toggleMenu();

	// Misc
	bool colored;
};
