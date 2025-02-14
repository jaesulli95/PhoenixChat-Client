// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealChatClientGameMode.h"
#include "UnrealChatClientCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealChatClientGameMode::AUnrealChatClientGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
