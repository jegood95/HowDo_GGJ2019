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
	
	TArray<AActor*> foundPanels;
	// get panels in world
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APanel::StaticClass(), foundPanels);
	for (AActor* Panel : foundPanels)
	{
		// get panel from world
		Panels.Add(static_cast<APanel*>(Panel));
		// TODO: finish
	}
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (APanel* Panel : Panels)
	{
		// check for a completed panel
		/*if (Panel->IsAllSlotsPassed())*/
		// TODO report that a panel has passed
	}
}

