// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Panel.h"
#include "Device.generated.h"

UCLASS()
class HOWDO_API ADevice : public AActor
{
	GENERATED_BODY()
private:
	// number of passed panels
	int32 PassedPanels;
public:	
	// Sets default values for this actor's properties
	ADevice();

	// max number of panels
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Device")
	int32 MaxPanels;

	// array of panels owned by this device
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Device")
	TArray<APanel*> Panels;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// returns if all panels have passed
	UFUNCTION(BlueprintCallable, Category = "Device")
	bool IsAllPanelsPassed();

	// increments the number of passed panels
	UFUNCTION(Category = "Device")
	void PassPanel();
};
