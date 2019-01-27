// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ModuleTypeContainer.h"
#include "UnrealEd.h"
#include "ModuleTypeContainerFactory.generated.h"

/**
 * 
 */
UCLASS()
class HOWDO_API UModuleTypeContainerFactory : public UFactory
{
	GENERATED_BODY()
public:
	UModuleTypeContainerFactory(const FObjectInitializer& ObjectInitializer);

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// End of UFactory interface
};
