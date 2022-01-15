# GameWithDiscord
 An UE4 project that integrates Discord's GameSDK as a new module.
 
## How to download
#### If you want the entire project, clone the repository or download it as a ZIP.
 
#### If you only want the GameSDK module, follow these steps:
 1. Download the repository as a ZIP file.
 2. Copy paste the module `Discord_GameSDK` located in `GameWithDiscord/Source/` into `YourProjectName/Source`.
 3. Open `yourProjectName/Source/yourProjectName.Target.cs` and replace `ExtraModuleNames.AddRange( new string[] { "yourProjectName" } );` with this: `		ExtraModuleNames.AddRange( new string[] { "yourProjectName", "Discord_GameSDK" } );`
 4. Open `yourProjectName/Source/yourProjectNameEditor.Target.cs` and replace `ExtraModuleNames.AddRange( new string[] { "yourProjectName" } );` with this: `		ExtraModuleNames.AddRange( new string[] { "yourProjectName", "Discord_GameSDK" } );`
 5. Open `yourProjectName/Source/yourProjectName/yourProjectName.Build.cs` and add this:

```cs
  //Include Discord GameSDK library files
		PublicIncludePaths.Add(@"D:\Repos\ParkourFPS\Source\DiscordSDK\discord-files");
		PublicAdditionalLibraries.Add(@"D:\Repos\ParkourFPS\Binaries\Win64\discord_game_sdk.dll.lib");

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
```
 Note: when you package the project, it won't put the DLLs in the right folder. I haven't had the time to make this yet.
 For now you'll have to put the DLLs and other files in the `WindowsNoEditor` folder, or make the code for this yourself.

#### You're good to go! Good luck and have fun!
 If you're having trouble with this, please take a look at how it's done in the example project.
