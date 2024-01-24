// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BuildingBase.h"
#include "BuildingHouse.generated.h"

UCLASS()
class YESMYLIEGE_API ABuildingHouse : public ABuildingBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuildingHouse();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
