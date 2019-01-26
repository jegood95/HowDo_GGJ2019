// Fill out your copyright notice in the Description page of Project Settings.

#include "Device.h"


// Sets default values
ADevice::ADevice()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ADevice::BeginPlay()
{
	Super::BeginPlay();
	// check valid number of panels
	if (Panels.Num() != MaxPanels)
		UE_LOG(LogTemp, Error, TEXT("Number of loaded panels does not match expected"));	
}

// Called every frame
void ADevice::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ADevice::IsAllPanelsPassed()
{
	return PassedPanels == MaxPanels;
}

void ADevice::PassPanel()
{
	// increment number of passed panels
	++PassedPanels;
}

