// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "SmartObjectState.h"
#include "SmartObject.generated.h"

class AStoryManager;

UENUM(BlueprintType)
enum class ESmartObjectTypeEnum : uint8
{
	SOTE_Ball			UMETA(DisplayName = "Ball"),
	SOTE_Bear			UMETA(DisplayName = "Bear"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVENARRATIVE_API USmartObject : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USmartObject();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


	UFUNCTION(BlueprintCallable, Category = Planning)
	FString GetObjectID();
	
	//// Type of object for setting fields and location in global state
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
	ESmartObjectTypeEnum objectType;

	// state of this object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		FString objectName;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		TArray<float> objectStateValues;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		bool isPartOfGoal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
		TArray<float> goalStateValues;


	// state of this object
	UPROPERTY()
		USmartObjectState* objectState;
	UPROPERTY()
		USmartObjectState* goalState;

private:
	UPROPERTY()
	AStoryManager* storyManager;



	// Number instance of this type of object
	UPROPERTY()
		int32 objectIndex;

		
	
};
