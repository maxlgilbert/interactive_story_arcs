// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "SmartObjectState.h"
#include "SmartObject.generated.h"

UENUM(BlueprintType)
enum class ESmartObjectTypeEnum : uint8
{
	SOTE_Ball			UMETA(DisplayName = "Ball"),
	SOTE_Bear			UMETA(DisplayName = "Bear"),
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTIVESTORY_API USmartObject : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USmartObject();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called when the object is destroyed
	virtual void BeginDestroy() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


	// Type of object for setting fields and location in global state
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Planning)
	ESmartObjectTypeEnum objectType;

	// Number instance of this type of object
	UPROPERTY()
	int32 objectIndex;

private:

	SmartObjectState objectState;

		
	
};
