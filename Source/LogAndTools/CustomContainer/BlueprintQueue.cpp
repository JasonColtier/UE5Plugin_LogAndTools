// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintQueue.h"

bool UBlueprintQueue::Enqueue(UObject* ObjectToQueue)
{
	if (IsValid(ObjectToQueue))
	{
		return ObjectsQueue.Enqueue(ObjectToQueue);
	}
	return false;
}

bool UBlueprintQueue::Dequeue(UObject*& DequeuedObject)
{
	return ObjectsQueue.Dequeue(DequeuedObject);
}

void UBlueprintQueue::Empty()
{
	return ObjectsQueue.Empty();
}

bool UBlueprintQueue::IsEmpty()
{
	return ObjectsQueue.IsEmpty();
}

bool UBlueprintQueue::Peek(UObject*& Object)
{
	return ObjectsQueue.Peek(Object);
}

bool UBlueprintQueue::Pop()
{
	return ObjectsQueue.Pop();
}
