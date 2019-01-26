// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Module.h"
#include "Slot.generated.h"

UCLASS()
class HOWDO_API ASlot : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	ASlot();

	// this slot's module
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Panel")
	AModule* Module;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// loads module if slot is available and returns if slot was populated
	UFUNCTION(BlueprintCallable, Category = "Slot")
	bool LoadModule(AModule* ModuleToAdd);

private:
	// does the slot already have a module?
	bool IsOccupied = false;
};
