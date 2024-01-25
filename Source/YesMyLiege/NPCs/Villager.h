// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Villager.generated.h"

class ABuildingBase;
class ABuildingHouse;

UCLASS()
class YESMYLIEGE_API AVillager : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVillager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Properties
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Villager Properties");
	bool isEmployed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Villager Properties");
	ABuildingBase *employment;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Villager Properties");
	ABuildingHouse *house;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Villager Properties");
	bool isBusy;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Villager Properties");
	bool hasAlreadyWorked;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Villager Properties");
	bool villagerTier;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Villager Properties|Villager Needs");
	int32 sleepNeed;

	UFUNCTION(BlueprintNativeEvent)
	void GoToWork();

	UFUNCTION(BlueprintNativeEvent)
	void GoToSatisfySleep();

	void ReduceNeeds();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

private:
	void SearchForEmployment();
	void SearchForHouse();
	void SatisfyNeeds();
};
