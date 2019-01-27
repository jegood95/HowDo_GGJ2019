// Fill out your copyright notice in the Description page of Project Settings.

#include "ModuleTypeContainerFactory.h"

#define LOCTEXT_NAMESPACE "ModuleTypeContainer"

UModuleTypeContainerFactory::UModuleTypeContainerFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UModuleTypeContainer::StaticClass();
}

UObject * UModuleTypeContainerFactory::FactoryCreateNew(UClass * Class, UObject * InParent, FName Name, EObjectFlags Flags, UObject * Context, FFeedbackContext * Warn)
{
	UModuleTypeContainer* NewObjectAsset = NewObject<UModuleTypeContainer>(InParent, Name, Flags | RF_Transactional);
	return NewObjectAsset;
}

#undef LOCTEXT_NAMESPACE


