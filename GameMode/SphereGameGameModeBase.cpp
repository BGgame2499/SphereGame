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

	ASphereBase * Pawn = Cast<ASphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());	//��ȡ�����ָ��
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
		if (PlayerPawn->GetActorLocation().Z <= DeathHighly)	//�ж�����Ƿ����
		{
			if (!IsEnd) { DeathNum++; }	//ֻ������Ϸδ����ʱ�ż�¼����
			SetPlayerStart(CurrentStart);
		}

		if (IsEnd)	//�����Ϸ�Ѿ����� �ж���ҵĲ���
		{
			PlayerPawn->IsInput = false;
		}

	}

}

void ASphereGameGameModeBase::SetPlayerStart(FVector Start)
{
	PlayerPawn->SetActorLocation(Start);
	PlayerPawn->SphereMesh->SetPhysicsLinearVelocity(FVector(0, 0, 0));		//���µ���λ�ú�����ֹͣ�ƶ�����ת
	PlayerPawn->SphereMesh->SetPhysicsAngularVelocity(FVector(0, 0, 0));
}


