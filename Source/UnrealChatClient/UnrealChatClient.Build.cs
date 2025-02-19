// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UnrealChatClient : ModuleRules
{
	public UnrealChatClient(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"EnhancedInput",
            "SocketIOClient",
			"SIOJson",
			"SocketIOLib",
			});
	}
}
