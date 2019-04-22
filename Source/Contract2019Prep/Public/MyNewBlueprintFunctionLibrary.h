// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyNewBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class CONTRACT2019PREP_API UMyNewBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(Blueprintcallable, Category = "C++ Test")
	static void SayHello();
};