// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveNarrative.h"
#include "StoryPlanner.h"
#include "StoryManager.h"


AStoryManager* AStoryManager::inst = nullptr;
// Sets default values
AStoryManager::AStoryManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	inst = this;
	smartObjectIndices = TMap<FString, int32>();
	smartObjects = TArray<USmartObject*>();

}

// Called when the game starts or when spawned
void AStoryManager::BeginPlay()
{
	Super::BeginPlay();
	currentGlobalState = NewObject<USmartGlobalState>(this, "globalState");
	goalState = NewObject<USmartGlobalState>(this, "goalState");
	storyPlanner = NewObject<UStoryPlanner>();

	
}

// Called every frame
void AStoryManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

AStoryManager* AStoryManager::Instance()
{
	if (inst)
	{
		return inst;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Story Manager not yet initialized"));
		return nullptr;
	}
}


int32 AStoryManager::AddSmartObject(USmartObject* smartObject)
{
	int32 objectIndex = 0;
	this->smartObjects.Add(smartObject);
	if (smartObjectIndices.Contains(smartObject->objectName))
	{
		objectIndex = smartObjectIndices[smartObject->objectName]+1;
		smartObjectIndices[smartObject->objectName] = objectIndex;
	}
	else
	{
		objectIndex = 1;
		smartObjectIndices.Add(smartObject->objectName, objectIndex);
	}
	UE_LOG(LogTemp, Warning, TEXT("Added object: %s %i"),*smartObject->objectName, objectIndex);
	return objectIndex;
}

void AStoryManager::AddSmartAction(ASmartAction* smartAction)
{
	smartActions.Add(smartAction);
}


void AStoryManager::UpdateGlobalState()
{
	currentGlobalState->globalStateNode.globalState.Empty();
	goalState->globalStateNode.globalState.Empty();
	for (int32 i = 0; i < smartObjects.Num(); i++)
	{
		currentGlobalState->globalStateNode.globalState.Add(smartObjects[i]->GetObjectID(), smartObjects[i]->objectState);
		if (smartObjects[i]->isPartOfGoal)
		{
			goalState->globalStateNode.globalState.Add(smartObjects[i]->GetObjectID(), smartObjects[i]->goalState);
		}
	}
	currentGlobalState->globalStateNode.goalState = goalState;
	goalState->globalStateNode.goalState = goalState;

	UE_LOG(LogTemp, Warning, TEXT("current global state: %s"), *currentGlobalState->globalStateNode.ToString());
	UE_LOG(LogTemp, Warning, TEXT("goal state: %s"), *goalState->globalStateNode.ToString());

}

void AStoryManager::TestGlobalState()
{
	TArray< FStateNode> testGlobalStates = TArray<FStateNode>();
	//USmartGlobalState* curr = currentGlobalState;
	//testGlobalStates.HeapPush(curr,[]( USmartGlobalState* A,  USmartGlobalState* B){
	//	return true;
	//	/*float distanceToGoalThis = A.getDistanceToState(A.goalState);
	//	float distanceToGoalOther = B.getDistanceToState(B.goalState);
	//	return A.distance + distanceToGoalThis < B.distance + distanceToGoalOther;*/
	//});
	testGlobalStates.HeapPush(currentGlobalState->globalStateNode);
	testGlobalStates.HeapPush(goalState->globalStateNode);

	//testGlobalStates.Heap;

	int32 size = testGlobalStates.Num();
	for (int32 i = 0; i < size; i++)
	{
		FStateNode curr;
		testGlobalStates.HeapPop(curr);
		UE_LOG(LogTemp, Warning, TEXT("TEST global state: %s, position %i"), *curr.ToString(), i);
	}
}

void AStoryManager::TestPlan()
{
	UE_LOG(LogTemp, Warning, TEXT("Started planning"));
	TArray<FSmartEvent> eventSequence = storyPlanner->Plan(currentGlobalState->globalStateNode, goalState->globalStateNode, smartActions);

	UE_LOG(LogTemp, Warning, TEXT("Plan length: %i"),eventSequence.Num());

	for (int32 i = 0; i < eventSequence.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Perform action %s on %s %i"), *eventSequence[i].action->actionName, *eventSequence[i].action->objectType, eventSequence[i].targetObjectId);
	}
	
}


