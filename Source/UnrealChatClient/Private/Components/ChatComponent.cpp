// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/ChatComponent.h"
#include "SIOJsonObject.h"
#include "SIOJsonValue.h"
#include "ISIOJson.h"

// Sets default values for this component's properties
UChatComponent::UChatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UChatComponent::SendMessage(FString Message)
{

	//Parse the Message Command here then dissect it into something to send.
	USIOJsonObject* Packet = NewObject<USIOJsonObject>();
	Packet->SetStringField("message", Message);
	Emit("on_message", USIOJsonValue::ConstructJsonValueObject(Packet, nullptr));
}

void UChatComponent::OnMessageReceived(USIOJsonValue* PacketReceived)
{
	if (PacketReceived) {
		FString MessageRecv = PacketReceived->AsObject()->GetStringField("message");
		MessageReceived.Broadcast(MessageRecv);
	}
}

void UChatComponent::OnUserConnected(USIOJsonValue* PacketReceived)
{
	if (PacketReceived) {
		USIOJsonObject* Packet = PacketReceived->AsObject();
		
	}
}


// Called when the game starts
void UChatComponent::BeginPlay()
{
	Super::BeginPlay();

	//Setup Event Functions here
	BindEventToFunction("OnMessageReceived", "OnMessageReceived", this);
	BindEventToFunction("OnUserConnected", "OnUserConnected", this);



	//Connect to the Chat Server after the events have been bound.
	Connect(URLParams.AddressAndPort);
	if (bIsConnected) {
		MessageReceived.Broadcast("CONNECTED to Phoenix-Chat");
	}
	else {
		MessageReceived.Broadcast("UNABLE to CONNECT to Phoenix-Chat");
	}
}
