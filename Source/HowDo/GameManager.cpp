// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> foundDevices;
	TArray<AActor*> foundPanels;
	// get Devices in world
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADevice::StaticClass(), foundDevices);
	for (AActor* Device : foundDevices)
	{
		Devices.Add(static_cast<ADevice*>(Device));
	}

	// get panels in world
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APanel::StaticClass(), foundPanels);
	for (AActor* Panel : foundPanels)
	{
		Panels.Add(static_cast<APanel*>(Panel));
	}

	// assign random modules to panels
	// TODO
	
	int32 index = 0;
	// for each device's panels, map its Device index
	for(ADevice* Device : Devices)
	{
		for (APanel* Panel : Device->Panels)
		{
			Panel->DeviceIndex = index;
		}
		++index;
	}
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (APanel* Panel : Panels)
	{
		// check for a completed panel
		if (Panel->IsAllSlotsPassed())
			// update total passing panels in its associated Device
			Devices[Panel->DeviceIndex]->PassPanel();
	}

}

