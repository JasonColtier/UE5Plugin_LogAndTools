// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "BlueprintQueue.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class LOGANDTOOLS_API UBlueprintQueue : public UObject
{
	GENERATED_BODY()

private:
	TQueue<UObject*> ObjectsQueue;

public:
	
	/**
	 * adds and object in last position
	 * @param ObjectToQueue 
	 */
	UFUNCTION(BlueprintCallable,Category = "Queue")
	bool Enqueue(UObject* ObjectToQueue);
	
	UFUNCTION(BlueprintCallable, Category = "Queue")
	bool Dequeue(UObject*& DequeuedObject);
	
	UFUNCTION(BlueprintCallable, Category = "Queue")
	void Empty();
	
	UFUNCTION(BlueprintPure, Category = "Queue")
	bool IsEmpty();
	
	UFUNCTION(BlueprintCallable, Category = "Queue")
	bool Peek(UObject*& Object);
	
	UFUNCTION(BlueprintCallable, Category = "Queue")
	bool Pop();
};
