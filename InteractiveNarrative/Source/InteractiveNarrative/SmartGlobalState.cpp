// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveNarrative.h"
#include "SmartGlobalState.h"
//
//
//USmartGlobalState::USmartGlobalState()
//{
//	//this->
//}
//FORCEINLINE USmartGlobalState::USmartGlobalState(const USmartGlobalState& inCopy)
//{
//	//this->
//}

//bool USmartGlobalState::operator==(const USmartGlobalState& other) const
//{
//	int32 distanceToState = 0;
//	TArray<FString> objectKeys;
//	this->globalState.GetKeys(objectKeys);
//	for (int32 i = 0; i < objectKeys.Num(); i++)
//	{
//		if (other.globalState.Contains(objectKeys[i]))
//		{
//			USmartObjectState* objectState = this->globalState[objectKeys[i]];
//			TArray<float> firstValues = this->globalState[objectKeys[i]]->objectState;
//			TArray<float> secondValues = other.globalState[objectKeys[i]]->objectState;
//			for (int32 k = 0; k < firstValues.Num(); k++)
//			{
//				if (firstValues[k] != secondValues[k])
//				{
//					return false;
//				}
//			}
//		}
//	}
//	return true;
//}
//
//

//
//bool USmartGlobalState::operator>(const USmartGlobalState& other) const
//{
//	return ! (*this < other || *this == other);
//}



//bool USmartGlobalState::operator==(USmartGlobalState* other) const
//{
//	int32 distanceToState = 0;
//	TArray<FString> objectKeys;
//	this->globalState.GetKeys(objectKeys);
//	for (int32 i = 0; i < objectKeys.Num(); i++)
//	{
//		if (other->globalState.Contains(objectKeys[i]))
//		{
//			USmartObjectState* objectState = this->globalState[objectKeys[i]];
//			TArray<float> firstValues = this->globalState[objectKeys[i]]->objectState;
//			TArray<float> secondValues = other->globalState[objectKeys[i]]->objectState;
//			for (int32 k = 0; k < firstValues.Num(); k++)
//			{
//				if (firstValues[k] != secondValues[k])
//				{
//					return false;
//				}
//			}
//		}
//	}
//	return true;
//}
//
//
//bool USmartGlobalState::operator<(USmartGlobalState* other) const
//{
//	float distanceToGoalThis = this->getDistanceToState(this->goalState);
//	float distanceToGoalOther = other->getDistanceToState(other->goalState);
//	return this->distance + distanceToGoalThis < other->distance + distanceToGoalOther;
//}
//
//bool USmartGlobalState::operator==(USmartGlobalState other)
//{
//	int32 distanceToState = 0;
//	TArray<FString> objectKeys;
//	this->globalState.GetKeys(objectKeys);
//	for (int32 i = 0; i < objectKeys.Num(); i++)
//	{
//		if (other.globalState.Contains(objectKeys[i]))
//		{
//			USmartObjectState* objectState = this->globalState[objectKeys[i]];
//			TArray<float> firstValues = this->globalState[objectKeys[i]]->objectState;
//			TArray<float> secondValues = other.globalState[objectKeys[i]]->objectState;
//			for (int32 k = 0; k < firstValues.Num(); k++)
//			{
//				if (firstValues[k] != secondValues[k])
//				{
//					return false;
//				}
//			}
//		}
//	}
//	return true;
//}
//
//
//bool USmartGlobalState::operator<(USmartGlobalState other)
//{
//	float distanceToGoalThis = this->getDistanceToState(this->goalState);
//	float distanceToGoalOther = other.getDistanceToState(other.goalState);
//	return this->distance + distanceToGoalThis < other.distance + distanceToGoalOther;
//}


 FString FStateNode::ToString() const
{
	FString stringReturn = "";
	TArray<FString> stringKeys;
	globalState.GetKeys(stringKeys);
	for (int32 i = 0; i < stringKeys.Num(); i++)
	{
		stringReturn += stringKeys[i];
		for (int32 j = 0; j < globalState[stringKeys[i]]->objectState.Num(); j++)
		{
			stringReturn += " " + FString::SanitizeFloat(globalState[stringKeys[i]]->objectState[j]);
		}
		stringReturn += "\n";
	}
	return stringReturn;
}

int32 FStateNode::getDistanceToState(const USmartGlobalState* other)  const
{
	int32 distanceToState = 0;
	TArray<FString> objectKeys;
	this->globalState.GetKeys(objectKeys);
	for (int32 i = 0; i < objectKeys.Num(); i++)
	{
		if (other->globalStateNode.globalState.Contains(objectKeys[i]))
		{
			USmartObjectState* objectState = this->globalState[objectKeys[i]];
			TArray<float> firstValues = this->globalState[objectKeys[i]]->objectState;
			TArray<float> secondValues = other->globalStateNode.globalState[objectKeys[i]]->objectState;
			for (int32 k = 0; k < firstValues.Num(); k++)
			{
				if (fabs(firstValues[k] - secondValues[k])>.0001)
				{
					distanceToState++;
				}
			}
		}
	}
	return distanceToState;
}

FStateNode FStateNode::copyGlobalState() const
{
	FStateNode newState = FStateNode();
	newState.distance = this->distance;
	newState.goalState = this->goalState;
	newState.globalState = TMap<FString, USmartObjectState*>();

	// Recreate mpa of object states.
	TArray<FString> objectKeys;
	this->globalState.GetKeys(objectKeys);
	for (int32 i = 0; i < objectKeys.Num(); i++)
	{
		USmartObjectState *newObjectState = NewObject<USmartObjectState>();
		newObjectState->objectState = this->globalState[objectKeys[i]]->objectState;
		newState.globalState.Add(objectKeys[i], newObjectState);
	}
	return newState;
}

bool FStateNode::isEqual(const FStateNode other)
{
	TArray<FString> objectKeys;
	this->globalState.GetKeys(objectKeys);

	for (int32 i = 0; i < objectKeys.Num(); i++)
	{
		if (other.globalState.Contains(objectKeys[i]))
		{
			USmartObjectState* objectState = this->globalState[objectKeys[i]];
			TArray<float> firstValues = this->globalState[objectKeys[i]]->objectState;
			TArray<float> secondValues = other.globalState[objectKeys[i]]->objectState;
			for (int32 k = 0; k < firstValues.Num(); k++)
			{
				if (secondValues[k] >= 0 && fabs(firstValues[k]- secondValues[k]) > .0001)
				{
					return false;
				}
			}
		}
	}
	return true;
}