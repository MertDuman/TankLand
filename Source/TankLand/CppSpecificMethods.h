// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/EngineTypes.h"
#include "CppSpecificMethods.generated.h"

/**
 * 
 */
UCLASS()
class TANKLAND_API UCppSpecificMethods : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	 * Wrapper function for GetHitResultAtScreenPosition because that function does not exist within the engine.
	 * Since this is a static function it needs a Target object to identify the World it is working with.
	 * Target pin won't be visible and will default to the caller object.
	 */
	UFUNCTION(BlueprintCallable, Category = "Utilities", meta = (WorldContext = "Target", HidePin = "Target", DefaultToSelf = "Target"))
	static bool HitScanAtScreenPosition(UObject* Target, const FVector2D ScreenPosition, const ECollisionChannel TraceChannel, bool bTraceComplex, FHitResult &HitResult);
	
	
};
