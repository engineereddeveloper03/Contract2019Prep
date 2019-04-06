// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Contract2019PrepHUD.generated.h"

/**
 * 
 */
UCLASS()
class AContract2019PrepHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AContract2019PrepHUD();

	/** Primary draw call for the HUD*/
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Health")
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
	class UUserWidget* CurrentWidget;
};
