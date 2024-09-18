// Fill out your copyright notice in the Description page of Project Settings.


#include "BPFL_GenericTools.h"

#include "Kismet/KismetSystemLibrary.h"

void UBPFL_GenericTools::PI_Print(const UObject* WorldContextObject, FString String1, FString String2, ELogEnum LogCategory, bool bPrintToScreen, bool bPrintToLog, FLinearColor TextColor, float Duration)
{
	FString SourceObjectPrefix = FString::Printf(TEXT("[%s] "), *GetNameSafe(WorldContextObject));
	FText   text               = FText::AsCultureInvariant(String1.Append(String2));
	switch (LogCategory)
	{
	case PI_Debug:
		UKismetSystemLibrary::PrintText(WorldContextObject, text, bPrintToScreen, bPrintToLog, TextColor, Duration);
		break;
	case PI_Warning:
		{
			UKismetSystemLibrary::PrintText(WorldContextObject, text, bPrintToScreen, false, TextColor, Duration);
			const FString FinalLogString = SourceObjectPrefix + *text.ToString();
			UE_LOG(LogBlueprint, Warning, TEXT("%s"), *FinalLogString);
		}

		break;
	case PI_Error:
		UKismetSystemLibrary::PrintText(WorldContextObject, text, bPrintToScreen, false, TextColor, Duration);

		const FString FinalLogString2 = SourceObjectPrefix + *text.ToString();
		UE_LOG(LogBlueprint, Error, TEXT("%s"), *FinalLogString2);
		UE_LOG(LogBlueprint, Error, TEXT("Callstack : \n %s"), *FFrame::GetScriptCallstack());
		break;
	}
}

bool UBPFL_GenericTools::IsFirstPawnLocallyControlled(AActor* WorldContext)
{
	if (!IsValid(WorldContext))
	{
		// TRACE_STATIC("no valid world context");
		return false;
	}

	//fail safe quand on ferme l'editor avec les Destroys
	if (!IsValid(WorldContext->GetWorld()))
		return false;

	//we try to get the local pawn
	ULocalPlayer* LocalPlayer = WorldContext->GetWorld()->GetFirstLocalPlayerFromController();

	if (IsValid(LocalPlayer))
	{
		APlayerController* PlayerController = LocalPlayer->PlayerController;
		if (IsValid(PlayerController))
		{
			APawn* Pawn = PlayerController->GetPawn();
			if (IsValid(Pawn))
			{
				if (Pawn->IsLocallyControlled())
					return true;
			}
			else
			{
				// TRACE_STATIC("no valid pawn")
				return PlayerController->IsLocalPlayerController();
				// return false;
			}
			// TRACE_STATIC("no valid player controller")
		}
	}


	return false;
}
