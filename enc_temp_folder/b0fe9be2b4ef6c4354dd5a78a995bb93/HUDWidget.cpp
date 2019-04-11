// Fill out your copyright notice in the Description page of Project Settings.

#include "HUDWidget.h"

UHUDWidget::UHUDWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// build root widget if it doesn't exist
	//if (!RootWidget)
	//{

	//	RootWidget = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootWidget"));

	//	UCanvasPanelSlot* RootWidgetSlot = Cast<UCanvasPanelSlot>(RootWidget->Slot);
	//	if (RootWidgetSlot)
	//	{
	//		RootWidgetSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
	//	}

	//	WidgetTree->RootWidget = RootWidget;
	//}	
}

void UHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	ExampleButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("First Button"));
	RootWidget->AddChildToCanvas(ExampleButton);
	ExampleButton->OnClicked.AddDynamic(this, &UHUDWidget::OnButtonClicked); // binding event
}

bool UHUDWidget::Initialize()
{
	bool orig = Super::Initialize();

	RootWidget = WidgetTree->ConstructWidget<UCanvasPanel>();
	//WidgetTree->RootWidget = RootWidget;

	return orig;
}

void UHUDWidget::OnButtonClicked()
{

}

//TSharedRef<SWidget> UHUDWidget::RebuildWidget()
//{
	//// build root widget if it doesn't exist
	//if (!RootWidget)
	//{
	//	RootWidget = WidgetTree->ConstructWidget<UCanvasPanel>(UCanvasPanel::StaticClass(), TEXT("RootWidget"));

	//	UCanvasPanelSlot* RootWidgetSlot = Cast<UCanvasPanelSlot>(RootWidget->Slot);
	//	if (RootWidgetSlot)
	//	{
	//		RootWidgetSlot->SetAnchors(FAnchors(0.f, 0.f, 1.f, 1.f));
	//	}

	//	WidgetTree->RootWidget = RootWidget;
	//}

	//TSharedRef<SWidget> Widget = Super::RebuildWidget();

	//if (RootWidget && WidgetTree)
	//{
	//	// text box example
	//	TextBox = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("First Textbox"));
	//	RootWidget->AddChild(TextBox);
	//	uint64 MyValue = UINT64_MAX;
	//	TextBox->SetText(FText::FromString("hello there"));
	//	UCanvasPanelSlot* TextboxSlot = Cast<UCanvasPanelSlot>(TextBox->Slot);
	//	if (TextboxSlot)
	//	{
	//		TextboxSlot->SetAutoSize(true);
	//	}

	//	// button
	//	ExampleButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("First Button"));
	//	RootWidget->AddChild(ExampleButton); // add to root panel
	//	ExampleButton->OnClicked.AddDynamic(this, &UHUDWidget::OnButtonClicked); // binding

	//																			 // button
	//	ExampleButton2 = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("First Button"));
	//	RootWidget->AddChild(ExampleButton2); // add to root panel
	//	ExampleButton2->OnClicked.AddDynamic(this, &UHUDWidget::OnButtonClicked); // binding
	//}

	//return Widget;
//}
