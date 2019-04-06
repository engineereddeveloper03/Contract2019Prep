// Fill out your copyright notice in the Description page of Project Settings.


#include "Contract2019PrepHUD.h"
#include "Engine/Canvas.h"
#include "Engine/Texture2D.h"
#include "TextureResource.h"
#include "CanvasItem.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AContract2019PrepHUD::AContract2019PrepHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> HealthBarObj(TEXT("/Game/ThirdPerson/UI/HealthUI"));

	HUDWidgetClass = HealthBarObj.Class;
}

void AContract2019PrepHUD::DrawHUD()
{
	Super::DrawHUD();

	// find center of hte Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
}

void AContract2019PrepHUD::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);

		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}
