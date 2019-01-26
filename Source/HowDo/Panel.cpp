// Fill out your copyright notice in the Description page of Project Settings.

#include "Panel.h"

// Sets default values
APanel::APanel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void APanel::BeginPlay()
{
	Super::BeginPlay();
	// check valid number of slots
	if (Slots.Num() != MaxSlots)
		UE_LOG(LogTemp, Error, TEXT("Number of loaded slots does not match expected"));
	
}

// Called every frame
void APanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool APanel::LoadSlots(TArray<AModule*> Modules)
{
	// load slots up to the number available
	for(AModule* Module : Modules)
	{
		if (!AddModule(Module))
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to load Module %s. No available slots."), *(Module->GetName()));
			return false;
		}
	}
	UE_LOG(LogTemp, Display, TEXT("Successfully loaded all slots."));
	return true;
}

bool APanel::AddModule(AModule* Module)
{
	if (UsedSlots != MaxSlots)
	{
		// slot available, so load it w/ the module
		Slots[UsedSlots]->LoadModule(Module);
		++UsedSlots;
		return true;
	}
	// couldn't load slot
	return false;
}

bool APanel::IsAllSlotsPassed()
{
	return PassedSlots == MaxSlots;
}

