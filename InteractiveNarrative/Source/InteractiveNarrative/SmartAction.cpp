// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveNarrative.h"
#include "StoryManager.h"
#include "SmartAction.h"


// Sets default values
ASmartAction::ASmartAction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASmartAction::BeginPlay()
{
	Super::BeginPlay();

	storyManager = AStoryManager::Instance();
	storyManager->AddSmartAction(this);
	
}

// Called every frame
void ASmartAction::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


TArray<FStateNode > ASmartAction::GenerateNeighbors(const FStateNode parentNode)
{
	TArray<FStateNode > neighborStates;
	TArray<FString> objectKeys;
	parentNode.globalState.GetKeys(objectKeys);
	// Get all the objects in the global state.
	for (int32 i = 0; i < objectKeys.Num(); i++)
	{
		// Find the objects of relevant type.
		if (objectKeys[i].Contains(this->objectType))
		{
			TArray<float> firstValues = parentNode.globalState[objectKeys[i]]->objectState;
			bool eligible = true;
			for (int32 k = 0; k < firstValues.Num(); k++)
			{
				// See if object is eligible for action.
				if (preCondition[k] >= 0 && firstValues[k] != preCondition[k])
				{
					eligible = false;
					break;
				}
			}
			// If object is elibigle, apply changes.
			if (eligible)
			{
				// Copy global state of our parent node.
				FStateNode newNode = parentNode.copyGlobalState();
				newNode.parentNode = &parentNode;
				newNode.parentAction = this;
				FString objectIndex = objectKeys[i];
				objectIndex.RemoveFromStart(this->objectType);
				newNode.objectIndex = FCString::Atoi(*objectIndex);
				// Apply the transition changes.
				//int changesMade = 0;
				for (int32 k = 0; k < firstValues.Num(); k++)
				{
					newNode.globalState[objectKeys[i]]->objectState[k] += transitionState[k];
					//changesMade += int(fabs(transitionState[k]));
				}
				newNode.distance += 1;// changesMade;
				neighborStates.Add(newNode);
			}

		}
	}
	return neighborStates;
}
