// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "SmartObject.h"
#include "SmartGlobalState.generated.h"

class USmartGlobalState;
class ASmartAction;
USTRUCT(BlueprintType)
struct FStateNode {
	GENERATED_USTRUCT_BODY()


		//UFUNCTION(BlueprintCallable, Category = Planning)
		int32 getDistanceToState(const USmartGlobalState* other) const;

	bool isEqual(const FStateNode &other);

	// Copy constructor
	FStateNode copyGlobalState() const;

	//UFUNCTION(BlueprintCallable, Category = Planning)
		FString ToString();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		int32 distance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		USmartGlobalState* goalState;

	// Some collection of object states
	UPROPERTY()
		TMap<FString, USmartObjectState*> globalState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		int32 objectIndex;


	const FStateNode* parentNode;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		ASmartAction* parentAction = nullptr;


};


inline bool operator<(const FStateNode& A, const FStateNode& B)
{

	float distanceToGoalThis = A.getDistanceToState(A.goalState);
	float distanceToGoalOther = B.getDistanceToState(B.goalState);
	return A.distance + distanceToGoalThis < B.distance + distanceToGoalOther;
	return true;
}

/**
 * 
 */
UCLASS()
class INTERACTIVENARRATIVE_API USmartGlobalState : public UObject
{
	GENERATED_BODY()
public:

	// Only UPROPERTY OF THIS CLASS (WRAPPER FOR STRUCT FOR NOW)
	UPROPERTY()
		FStateNode globalStateNode;
	
	
	
	
};