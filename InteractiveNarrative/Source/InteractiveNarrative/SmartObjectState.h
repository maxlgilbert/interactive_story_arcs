// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "SmartObjectState.generated.h"

/**
 * 
 */
UCLASS()
class INTERACTIVENARRATIVE_API USmartObjectState : public UObject
{
	GENERATED_BODY()

public:
	// Float between 0 and 1, planner will round to nearest bool
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
	TArray<float> objectState;
	
	
	
	
};
