#ifndef LogTool_H
#define LogTool_H

// ce fichier déclare des macros pour faire des logs
//use like this :
//#include "LogTool.h"
//TRACE("message log");
//TRACE("message log %s", *string);
//TRACE_WARNING("message log %s", *string);


#include "CoreMinimal.h"
LOGANDTOOLS_API DECLARE_LOG_CATEGORY_EXTERN(CustomLog, Log, All);

#define NETMODE_WORLD (((GEngine == nullptr) || (GetWorld() == nullptr)) ? TEXT("") \
        : (GEngine->GetNetMode(GetWorld()) == NM_Client) ? TEXT("[Client] ") \
        : (GEngine->GetNetMode(GetWorld()) == NM_ListenServer) ? TEXT("[ListenServer] ") \
        : (GEngine->GetNetMode(GetWorld()) == NM_DedicatedServer) ? TEXT("[DedicatedServer] ") \
        : TEXT("[Standalone] "))
        

#define FUNC_NAME    TEXT("")

#define TRACE(Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    if (Msg == "") \
    { \
        UE_LOG(CustomLog, Log, TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *GetNameSafe(this));\
    } \
    else \
    { \
        UE_LOG(CustomLog, Log, TEXT("%s %s %s() : %s"), NETMODE_WORLD,*GetNameSafe(this), FUNC_NAME, *Msg);\
    } \
    CLEAR_WARN_COLOR();\
}

#define TRACE_STATIC(Format, ...) \
{ \
    SET_WARN_COLOR(COLOR_CYAN);\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(CustomLog, Log, TEXT("%s() : %s"), FUNC_NAME, *Msg);\
    CLEAR_WARN_COLOR();\
}

#define TRACE_WARN(Format, ...) \
{ \
    SET_WARN_COLOR( COLOR_YELLOW );\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(CustomLog, Warning, TEXT("%s %s %s() : %s"), NETMODE_WORLD,*GetNameSafe(this), FUNC_NAME, *Msg);\
    CLEAR_WARN_COLOR();\
}

#define TRACE_ERROR(Format, ...) \
{ \
    SET_WARN_COLOR( COLOR_RED );\
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    UE_LOG(CustomLog, Error, TEXT("%s %s %s() : %s"), NETMODE_WORLD,*GetNameSafe(this), FUNC_NAME, *Msg);\
    CLEAR_WARN_COLOR();\
}

#define TRACE_SCREEN(Format, ...) \
{ \
    const FString Msg = FString::Printf(TEXT(Format), ##__VA_ARGS__); \
    if (Msg == "") \
    { \
        TCHAR StdMsg[MAX_SPRINTF] = TEXT(""); \
        FCString::Sprintf(StdMsg, TEXT("%s%s() : %s"), NETMODE_WORLD, FUNC_NAME, *GetNameSafe(this)); \
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, StdMsg); \
        UE_LOG(LogTemp, Warning, TEXT("%s %s %s() : %s"), NETMODE_WORLD,*GetNameSafe(this), FUNC_NAME,, *Msg);\
    } \
    else \
    { \
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White, Msg); \
        UE_LOG(CustomLog, Warning, TEXT("%s %s %s() : %s"), NETMODE_WORLD,*GetNameSafe(this), FUNC_NAME, *Msg);\
    } \
}

#endif
