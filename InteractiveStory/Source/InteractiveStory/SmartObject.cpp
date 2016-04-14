// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveStory.h"
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
	
	objectState = SmartObjectState();

	// ...
	
}
// Called when the object is destoryed
void USmartObject::BeginDestroy()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void USmartObject::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

