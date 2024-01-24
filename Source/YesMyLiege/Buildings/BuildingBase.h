// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../NPCs/Villager.h"
#include "BuildingBase.generated.h"

enum class BuildResource;

UCLASS()
class YESMYLIEGE_API ABuildingBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuildingBase();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent *Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building Properties");
	TMap<FString, int> buildResources;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building Properties");
	bool isBeingBuilt;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building Properties");
	FString buildingName;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building Properties");
	AVillager *worker;


	
	void SetWorker(AVillager *newWorker);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
