// Fill out your copyright notice in the Description page of Project Settings.


#include "SubMenuWidget.h"

USubMenuWidget::USubMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	buttonChanged = false;
}

void USubMenuWidget::NativeConstruct()
{
	ButtonA->OnReleased.AddDynamic(this, &USubMenuWidget::ChangeButtonText);

	// set localization text
	optionTextA = NSLOCTEXT("UMG", "OptionTextA", "InvA");
	optionTextB = NSLOCTEXT("UMG", "OptionTextB", "Option 3");
}

void USubMenuWidget::ChangeButtonText()
{
	if (!buttonChanged)
	{
		TextChange->SetText(optionTextA);
	}
	else
	{
		TextChange->SetText(optionTextB);
	}

	buttonChanged = !buttonChanged;
}
