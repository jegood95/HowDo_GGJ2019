// Fill out your copyright notice in the Description page of Project Settings.

#include "Slot.h"


// Sets default values
ASlot::ASlot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASlot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ASlot::LoadModule(AModule * ModuleToAdd)
{
	if (!IsOccupied)
	{
		// store reference to the module
		Module = ModuleToAdd;
		// set module's location inside slot
		Module->SetActorLocation(this->GetActorLocation());
		// acknowledge slot is occupied
		IsOccupied = true;
	}
	return IsOccupied;
}

