// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GameWithDiscord : ModuleRules
{
	public GameWithDiscord(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

		//Include Discord GameSDK library files
		PublicIncludePaths.Add(@"D:\Repos\GameWithDiscord\Source\Discord_GameSDK\discord-files"); //Put the absolute path to the discord-files folder between the quotes
		PublicAdditionalLibraries.Add(@"D:\Repos\GameWithDiscord\Binaries\Win64\discord_game_sdk.dll.lib"); //Put the absolute path to the discord_game_sdk.dll.lib file between the quotes

#if PLATFORM_WINDOWS
#if PLATFORM_64BITS
    RuntimeDependencies.Add("Binaries\Win64" + "discord_game_sdk.dll");
#else
    RuntimeDependencies.Add("Binaries\Win64" + "discord_game_sdk.dll");
#endif

#elif PLATFORM_MAC
    RuntimeDependencies.Add("Binaries\Win64" + discord_game_sdk.so);
#endif

#if PLATFORM_LINUX
    RuntimeDependencies.Add("Binaries\Win64" + discord_game_sdk.dylib);
#endif
	}
}
