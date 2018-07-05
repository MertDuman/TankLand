// Fill out your copyright notice in the Description page of Project Settings.

#include "CppSpecificMethods.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

bool UCppSpecificMethods::HitScanAtScreenPosition(UObject* Target, const FVector2D ScreenPosition, const ECollisionChannel TraceChannel, bool bTraceComplex, FHitResult &HitResult) {
	if (ensure(GEngine)) {
		// Get the world using the context object
		UWorld* World = GEngine->GetWorldFromContextObject(Target);
		if (ensure(World)) {
			APlayerController* Pc = UGameplayStatics::GetPlayerController(World, 0);
			if (ensure(Pc)) {
				return Pc->GetHitResultAtScreenPosition(ScreenPosition, TraceChannel, bTraceComplex, HitResult);
			}
		}
	}
	return false;
}

