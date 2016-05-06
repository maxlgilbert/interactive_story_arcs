// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SmartGlobalState.h"
#include "StoryManager.generated.h"

class UStoryPlanner;
UCLASS()
class INTERACTIVENARRATIVE_API AStoryManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStoryManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = Planning)
	static AStoryManager* Instance();


	UFUNCTION(BlueprintCallable, Category = Planning)
	int32 AddSmartObject(USmartObject* smartObject);

	UFUNCTION(BlueprintCallable, Category = Planning)
		void AddSmartAction(ASmartAction* smartAction);

	UFUNCTION(BlueprintCallable, Category = Planning)
	void UpdateGlobalState();


	UFUNCTION(BlueprintCallable, Category = Planning)
		void TestGlobalState();

	UFUNCTION(BlueprintCallable, Category = Planning)
		void TestPlan();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		USmartGlobalState* currentGlobalState;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		TArray<USmartObject*> goalObjects;


	UPROPERTY()
		USmartGlobalState* goalState;



private:

	UPROPERTY()
		TArray<USmartObject*> smartObjects;


	UPROPERTY()
		TArray<ASmartAction*> smartActions;

	UPROPERTY()
		TMap<FString,int32> smartObjectIndices;


	UPROPERTY()
		UStoryPlanner* storyPlanner;

	//UPROPERTY()
	static AStoryManager* inst;

	
	
};
