// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Slot.h"
#include "Panel.generated.h"

UCLASS()
class HOWDO_API APanel : public AActor
{
	GENERATED_BODY()

private:
	// number of currently used slots
	int32 UsedSlots = 0;
	
	// number of passed slots
	int32 PassedSlots = 0;
private:
	// adds the given slot if an empty
	// attachment point exists
	bool AddModule(AModule* Module);
public:	
	// Sets default values for this actor's properties
	APanel();

	// panel index in manager
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Panel")
	int32 DeviceIndex;
	
	// max number of available slots
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Panel")
	int32 MaxSlots;
	
	// pointer to slots in this panel
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Panel")
	TArray<ASlot*> Slots;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Load available slots; return if slots were successfully loaded
	UFUNCTION(BlueprintCallable, Category = "Panel")
	bool LoadSlots(TArray<AModule*> Modules);

	// return if all slots have passed
	bool IsAllSlotsPassed();
};
