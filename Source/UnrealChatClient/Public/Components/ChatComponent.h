// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SocketIOClientComponent.h"
#include "SocketIONative.h"
#include "ChatComponent.generated.h"


//DECLARE AN EVENT FOR WHEN I GET A MESSAGE BACK

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCHATCLIENT_API UChatComponent : public USocketIOClientComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UChatComponent();

	UFUNCTION(BlueprintCallable, Category="Chat")
	void SendMessage(FString Message);

	UFUNCTION()
	void OnMessageReceived(USIOJsonValue* PacketReceived);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
