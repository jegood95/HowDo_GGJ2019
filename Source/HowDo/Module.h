// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Module.generated.h"

UCLASS()
class HOWDO_API AModule : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AModule();

	// Has the player completed the module?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Module")
	bool Passed;

	// index of owning panel
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Module")
	int32 PanelIndex;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
