// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Button.h"
#include "TextBlock.h"
#include "SubMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class CONTRACT2019PREP_API USubMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	USubMenuWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	// UI Elements
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UButton* ButtonA;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetOptional))
	UTextBlock* TextChange;

	// Event Handlers
	UFUNCTION()
	void ChangeButtonText();

	// misc
	bool buttonChanged;
	FText optionTextA;
	FText optionTextB;
};
