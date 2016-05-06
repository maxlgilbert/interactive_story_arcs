// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveNarrative.h"
#include "StoryManager.h"
#include "SmartObject.h"


// Sets default values for this component's properties
USmartObject::USmartObject()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USmartObject::BeginPlay()
{
	Super::BeginPlay();
	storyManager = AStoryManager::Instance();
	this->objectIndex = storyManager->AddSmartObject(this);
	objectState = NewObject<USmartObjectState>(this, "objectState");
	objectState->objectState = objectStateValues;

	if (isPartOfGoal)
	{
		goalState = NewObject<USmartObjectState>(this, "goalState");
		goalState->objectState = goalStateValues;
	}
	
}


// Called every frame
void USmartObject::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
}

FString USmartObject::GetObjectID()
{
	FString objectID = objectName + FString::FromInt(objectIndex);
	return objectID;
}

