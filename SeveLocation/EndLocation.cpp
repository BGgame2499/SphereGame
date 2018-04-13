// Fill out your copyright notice in the Description page of Project Settings.

#include "EndLocation.h"
#include "Engine.h"
#include "GameMode/SphereGameGameModeBase.h"
#include "Player/SphereBase.h"

AEndLocation::AEndLocation()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AEndLocation::BeginPlay()
{
	Super::BeginPlay();
}

void AEndLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEndLocation::OnOverlapBegin_HitBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (Cast<ASphereBase>(OtherActor))
	{
		SetGameModeIsEnd(true);
		SetGameModeCurrentStart(HitBoxComp->GetComponentLocation());
	}
}
void AEndLocation::SetGameModeIsEnd(bool is)	//通知GameMode游戏结束
{
	ASphereGameGameModeBase * GameMode = Cast<ASphereGameGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->IsEnd = is;
	}
}
