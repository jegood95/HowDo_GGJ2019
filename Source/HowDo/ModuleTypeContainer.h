// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "ModuleTypeContainer.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class HOWDO_API UModuleTypeContainer : public UDataAsset
{
	GENERATED_BODY()

public:
	UModuleTypeContainer(const FObjectInitializer& ObjectInitializer);

	// array of module classes
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Properties")
	TArray<TSubclassOf<AActor>> ModuleTypes;
};
