// Fill out your copyright notice in the Description page of Project Settings.


#include "Discord_Subsystem.h"
#include "discord-files/discord.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

discord::Core* core{};
discord::Activity* activity{};

void UDiscord_Subsystem::Initialize(FSubsystemCollectionBase& Collection) {
	// Register ticker delegate
	TickDelegateHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UDiscord_Subsystem::Tick));

	//Set global variables
	discord::Result result = discord::Core::Create(760578869500575816, DiscordCreateFlags_NoRequireDiscord, &core);
	activity = new discord::Activity();
}

void UDiscord_Subsystem::Deinitialize() {
	// Unregister ticker delegate
	FTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);

	//Delete global variables' values
	if (core != NULL) {
		delete core;
	}

	if (activity != NULL) {
		delete activity;
	}
}

bool UDiscord_Subsystem::Tick(float DeltaSeconds)
{
	if (core != NULL) {
		core->RunCallbacks();
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("Invalid Discord core variable!"));
	}

	return true;
}

void UDiscord_Subsystem::Set_Details(FString Details) {
	if (core != NULL) {
		activity->SetDetails(StringCast<ANSICHAR>(*Details).Get());
		core->ActivityManager().UpdateActivity(*activity, [](discord::Result result) {

		});
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("Invalid Discord core variable!"));
	}
}

void UDiscord_Subsystem::Set_State(FString State) {
	if (core != NULL) {
		activity->SetState(StringCast<ANSICHAR>(*State).Get());
		core->ActivityManager().UpdateActivity(*activity, [](discord::Result result) {

		});
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("Invalid Discord core variable!"));
	}
}

void UDiscord_Subsystem::Elapsed_Time_Timer(FDateTime Start_time) {
	if (core != NULL) {
		activity->GetTimestamps().SetStart(Start_time.ToUnixTimestamp());
		core->ActivityManager().UpdateActivity(*activity, [](discord::Result result) {

		});
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("Invalid Discord core variable!"));
	}
}

void UDiscord_Subsystem::Remaining_Time_Timer(FDateTime Start_time) {
	if (core != NULL) {
		activity->GetTimestamps().SetEnd(Start_time.ToUnixTimestamp());
		core->ActivityManager().UpdateActivity(*activity, [](discord::Result result) {

		});
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("Invalid Discord core variable!"));
	}
}

void UDiscord_Subsystem::Set_Large_Image(FString Large_image_key, FString Large_image_text) {
	if (core != NULL) {
		activity->GetAssets().SetLargeImage(StringCast<ANSICHAR>(*Large_image_key).Get());
		activity->GetAssets().SetLargeText(StringCast<ANSICHAR>(*Large_image_text).Get());
		core->ActivityManager().UpdateActivity(*activity, [](discord::Result result) {

		});
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("Invalid Discord core variable!"));
	}
}

void UDiscord_Subsystem::Set_Small_Image(FString Small_image_key, FString Small_image_text) {
	if (core != NULL) {
		activity->GetAssets().SetSmallImage(StringCast<ANSICHAR>(*Small_image_key).Get());
		activity->GetAssets().SetSmallText(StringCast<ANSICHAR>(*Small_image_text).Get());
		core->ActivityManager().UpdateActivity(*activity, [](discord::Result result) {

		});
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, TEXT("Invalid Discord core variable!"));
	}
}