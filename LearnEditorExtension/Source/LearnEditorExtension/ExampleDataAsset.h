// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ExampleDataAsset.generated.h"

/**
 *
 */
UCLASS()
class LEARNEDITOREXTENSION_API UExampleDataAsset : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, Category = MyCustomAsset)
		FString Description;

	UPROPERTY(VisibleAnywhere, Category = MyCustomAsset)
		bool bIsActive;
};
