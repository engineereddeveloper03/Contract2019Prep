// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNewBlueprintFunctionLibrary.h"

void UMyNewBlueprintFunctionLibrary::SayHello()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Hello World!"));
	}
}
