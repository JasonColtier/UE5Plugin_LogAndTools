// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFL_GenericTools.generated.h"

/**
 * 
 */

UENUM()
enum ELogEnum
{
	PI_Debug = 0,
	PI_Warning = 1,
	PI_Error = 2,
};

UCLASS()
class LOGANDTOOLS_API UBPFL_GenericTools : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	
	//un print custom qui rajoute la possibilité de print un warning ou une erreur depuis le BP et d'utiliser 2 strings qui seront concaténées
	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext, Keywords = "log print", AdvancedDisplay = "2", DevelopmentOnly), Category="Utilities|String")
	static void PI_Print(const UObject* WorldContextObject, FString String1, FString String2, ELogEnum LogCategory, bool bPrintToScreen = true, bool bPrintToLog = true, FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0), float Duration = 2.f);

	UFUNCTION(BlueprintCallable, Category = "Irwino")
	static bool IsFirstPawnLocallyControlled(AActor* WorldContext);
};
