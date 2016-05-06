// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractiveNarrative.h"
#include "StoryPlanner.h"

TArray<FSmartEvent> UStoryPlanner::Plan(FStateNode *startState, FStateNode *goalState, TArray<ASmartAction *> actions)
{
	TArray<FSmartEvent> events;
	TSet<FString> visited;

	TArray< FStateNode> heap = TArray<FStateNode>();
	heap.HeapPush(*startState);

	while (heap.Num() > 0)
	{
		FStateNode currNode = heap.Pop();
		FString currName = currNode.ToString();
		if (!visited.Contains(currName))
		{
			visited.Add(currName);
			if (currNode.isEqual(*goalState))
			{
				return ReconstructPath(currNode);
			}
			for (int32 i = 0; i < actions.Num(); i++)
			{
				TArray<FStateNode> neighbors = actions[i]->GenerateNeighbors(currNode);
				for (int32 j = 0; j < neighbors.Num(); j++)
				{
					heap.HeapPush(neighbors[j]);
				}
			}
		}
	}

	return events;
}

TArray<FSmartEvent> UStoryPlanner::ReconstructPath(const FStateNode& end)
{
	TArray<FSmartEvent> events;
	FStateNode curr = end;
	while (curr.parentAction != nullptr)
	{
		FSmartEvent smartEvent = FSmartEvent();
		smartEvent.action = curr.parentAction;
		smartEvent.targetObjectId = curr.objectIndex;
		events.Add(smartEvent);
		curr = *curr.parentNode;
	}
	TArray<FSmartEvent> orderedEvents;
	for (int32 i = events.Num(); i > 0; i--)
	{
		orderedEvents.Add(events[i - 1]);
	}
	return orderedEvents;
}



