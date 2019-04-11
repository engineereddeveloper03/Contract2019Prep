// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CanvasPanel.h"
#include "CanvasPanelSlot.h"
#include "Button.h"
#include "TextBlock.h"
#include "WidgetTree.h"
#include "HUDWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CONTRACT2019PREP_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UHUDWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	UCanvasPanel* RootWidget;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	//UTextBlock* TextBox;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	//UButton* ExampleButton;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	//UButton* ExampleButton2;

	virtual bool Initialize() override;

	UFUNCTION()
	void OnButtonClicked();

	UFUNCTION(BlueprintCallable, Category = "Test")
	void changeWidgetColor(UButton* inputButton);

	//virtual TSharedRef<SWidget> RebuildWidget() override;
};