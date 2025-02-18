// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SocketIOClientComponent.h"
#include "SocketIONative.h"
#include "Chat.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCHATCLIENT_API UChat : public USocketIOClientComponent
{
	GENERATED_BODY()

public:

	UChat();

	UPROPERTY(BlueprintReadOnly, Category="Settings")
	int32 MaxNumberOfMessages = 75;

};
