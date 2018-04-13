// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SeveLocation.h"
#include "EndLocation.generated.h"

/**
 * 
 */
UCLASS()
class SPHEREGAME_API AEndLocation : public ASeveLocation
{
	GENERATED_BODY()
	
public:
	
	AEndLocation();

public:
	//ÖØÐ´¸¸ÀàÅö×²º¯Êý
	UFUNCTION()
		virtual void OnOverlapBegin_HitBox(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	UFUNCTION(BlueprintCallable, Category = "SetGameModeIsEnd")
		void SetGameModeIsEnd(bool is);
protected:
	virtual void BeginPlay()override;

public:
	virtual void Tick(float DeltaTime)override;
};
