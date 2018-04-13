// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereGameGameModeBase.h"
#include "Player/SphereBase.h"
#include "Engine.h"

ASphereGameGameModeBase::ASphereGameGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	DeathHighly = 1400;
	IsEnd = false;

}
void ASphereGameGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ASphereBase * Pawn = Cast<ASphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());	//获取到玩家指针
	if (Pawn)
	{
		PlayerPawn = Pawn;
		CurrentStart = PlayerPawn->GetActorLocation();
	}
}
void ASphereGameGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerPawn)
	{
		if (PlayerPawn->GetActorLocation().Z <= DeathHighly)	//判断玩家是否掉落
		{
			if (!IsEnd) { DeathNum++; }	//只有在游戏未结束时才记录死亡
			SetPlayerStart(CurrentStart);
		}

		if (IsEnd)	//如果游戏已经结束 切断玩家的操作
		{
			PlayerPawn->IsInput = false;
		}

	}

}

void ASphereGameGameModeBase::SetPlayerStart(FVector Start)
{
	PlayerPawn->SetActorLocation(Start);
	PlayerPawn->SphereMesh->SetPhysicsLinearVelocity(FVector(0, 0, 0));		//重新调整位置后让其停止移动和旋转
	PlayerPawn->SphereMesh->SetPhysicsAngularVelocity(FVector(0, 0, 0));
}


