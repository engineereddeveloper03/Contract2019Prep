// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDWidget.h"

UHUDWidget::UHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void UHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// binding events to bound objects
	ExampleButton->OnClicked.AddDynamic(this, &UHUDWidget::OnButtonClicked); 
}

bool UHUDWidget::Initialize()
{
	bool orig = Super::Initialize();

	return orig;
}

void UHUDWidget::OnButtonClicked()
{
	ExampleButton->SetBackgroundColor(FLinearColor::Blue);
}

TSharedRef<SWidget> UHUDWidget::RebuildWidget()
{
	TSharedRef<SWidget> Widget = Super::RebuildWidget();
	return Widget;
}
