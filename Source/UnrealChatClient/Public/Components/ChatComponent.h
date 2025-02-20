// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SocketIOClientComponent.h"
#include "SocketIONative.h"
#include "ChatComponent.generated.h"


//DECLARE AN EVENT FOR WHEN I GET A MESSAGE BACK
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMessageReceivedDelegate, FString, MessageRecv);

UENUM(BlueprintType)
enum class EMessageType : uint8 {
	EMT_General,
	EMT_Private,
	EMT_Community,
	EMT_Trade
};

USTRUCT(BlueprintType)
struct FChannelData {
	GENERATED_BODY()

public:
	FString Name;
	FLinearColor ChannelColor;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCHATCLIENT_API UChatComponent : public USocketIOClientComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UChatComponent();

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	int32 MaxNumMessages = 75;

	UFUNCTION(BlueprintCallable, Category="Chat")
	void SendMessage(FString Message);


	//Bound Functions
	UFUNCTION()
	void OnMessageReceived(USIOJsonValue* PacketReceived);

	//Chat Event Delegates
	UPROPERTY(BlueprintAssignable, Category="Chat|Events")
	FOnMessageReceivedDelegate MessageReceived;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
		
};
