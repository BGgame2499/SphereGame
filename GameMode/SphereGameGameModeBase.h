// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SphereGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SPHEREGAME_API ASphereGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ASphereGameGameModeBase();
	virtual void BeginPlay()override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerPawn")
		class ASphereBase * PlayerPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DeathHighly")
		float DeathHighly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DeathNum")
		int32 DeathNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Start")
		FVector CurrentStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "End")
		bool IsEnd;
public:

	virtual void Tick(float DeltaTime)override;
	
	UFUNCTION(BlueprintCallable, Category = "SetPlayerStart")
		void SetPlayerStart(FVector Start);
	
};
