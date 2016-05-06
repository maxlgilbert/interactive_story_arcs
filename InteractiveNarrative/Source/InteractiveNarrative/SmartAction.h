// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SmartGlobalState.h"
#include "SmartAction.generated.h"

UCLASS()
class INTERACTIVENARRATIVE_API ASmartAction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASmartAction();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Planning
	UFUNCTION(BlueprintCallable, Category = Planning)
	TArray<FStateNode > GenerateNeighbors(const FStateNode &parentNode);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		FString actionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		FString objectType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		TArray<float> preCondition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		TArray<float> transitionState;


	// Simulation

private:

	UPROPERTY()
		AStoryManager* storyManager;

	
	
};
