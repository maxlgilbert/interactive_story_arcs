// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "SmartAction.h"
#include "StoryPlanner.generated.h"

USTRUCT(BlueprintType)
struct FSmartEvent {
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY()
	ASmartAction *action;
	int32 targetObjectId;
};

/**
 * 
 */
UCLASS()
class INTERACTIVENARRATIVE_API UStoryPlanner : public UObject
{
	GENERATED_BODY()
public:
	TArray<FSmartEvent> Plan(FStateNode *startState, FStateNode *goalState, TArray<ASmartAction*> actions);
	TArray<FSmartEvent> ReconstructPath(const FStateNode& end);

};
