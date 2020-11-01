// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Discord_Subsystem.generated.h"

/**
 * 
 */
UCLASS()
class DISCORD_GAMESDK_API UDiscord_Subsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
	public:
		// Begin USubsystem
		virtual void Initialize(FSubsystemCollectionBase& Collection) override;
		virtual void Deinitialize() override;
		// End USubsystem

		//Event tick delegate
		bool Tick(float DeltaSeconds);
		FDelegateHandle TickDelegateHandle;

		//Discord Functions
		UFUNCTION(BlueprintCallable, Category = "Discord Functions", meta = (ToolTip = "Sets Discord details."))
		static void Set_Details(FString Details);

		UFUNCTION(BlueprintCallable, Category = "Discord Functions", meta = (ToolTip = "Sets Discord state."))
		static void Set_State(FString State);

		UFUNCTION(BlueprintCallable, Category = "Discord Functions", meta = (ToolTip = "Starts the Discord elapsed time timer at the input time."))
		static void Elapsed_Time_Timer(FDateTime Start_time);

		UFUNCTION(BlueprintCallable, Category = "Discord Functions", meta = (ToolTip = "Starts the Discord elapsed time timer at the input time."))
		static void Remaining_Time_Timer(FDateTime Start_time);

		UFUNCTION(BlueprintCallable, Category = "Discord Functions", meta = (ToolTip = "Sets the Discord large image and the tooltip for it."))
		static void Set_Large_Image(FString Large_image_key, FString Large_image_text);

		UFUNCTION(BlueprintCallable, Category = "Discord Functions", meta = (ToolTip = "Sets the Discord small image and the tooltip for it."))
		static void Set_Small_Image(FString Small_image_key, FString Small_image_text);
};
