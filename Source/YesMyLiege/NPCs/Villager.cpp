// Fill out your copyright notice in the Description page of Project Settings.

#include "Villager.h"
#include "../Buildings/BuildingBase.h"
#include "../Buildings/BuildingHouse.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AVillager::AVillager()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setting initial values of needs
	sleepNeed = 500;
}

// Called when the game starts or when spawned
void AVillager::BeginPlay()
{
	Super::BeginPlay();
	SearchForEmployment();
}

// Called every frame
void AVillager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!isEmployed)
	{
		SearchForEmployment();
	}
	else if (!isBusy)
	{
		SatisfyNeeds();
		if (!hasAlreadyWorked){
			GoToWork();
		}
	}

	ReduceNeeds();
}

// Called to bind functionality to input
void AVillager::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AVillager::SearchForEmployment()
{
	TArray<AActor *> BuildingsToFind;
	if (UWorld *World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABuildingBase::StaticClass(), BuildingsToFind);
	}
	for (AActor *BuildingBaseActor : BuildingsToFind)
	{
		ABuildingBase *BuildingBaseCast = Cast<ABuildingBase>(BuildingBaseActor);
		if (BuildingBaseCast->worker == nullptr && BuildingBaseCast->buildingName != TEXT("House"))
		{
			employment = BuildingBaseCast;
			isEmployed = true;
			BuildingBaseCast->SetWorker(this);
		}
	}
}

void AVillager::SearchForHouse()
{
	TArray<AActor *> BuildingsToFind;
	if (UWorld *World = GetWorld())
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABuildingBase::StaticClass(), BuildingsToFind);
	}
	for (AActor *BuildingBaseActor : BuildingsToFind)
	{
		ABuildingHouse *BuildingHouseCast = Cast<ABuildingHouse>(BuildingBaseActor);
		if (BuildingHouseCast->worker == nullptr && BuildingHouseCast->buildingName == TEXT("House"))
		{
			house = BuildingHouseCast;
			BuildingHouseCast->SetWorker(this);
		}
	}
}

void AVillager::SatisfyNeeds()
{
	if (sleepNeed < 200)
	{
		GoToSatisfySleep();
	}
}

void AVillager::GoToWork_Implementation()
{
	hasAlreadyWorked = true;
}

void AVillager::GoToSatisfySleep_Implementation()
{
}

void AVillager::ReduceNeeds()
{
	if(sleepNeed > 1){
		sleepNeed--;
	}
}