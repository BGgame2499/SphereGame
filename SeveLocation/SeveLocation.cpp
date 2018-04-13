
#include "SeveLocation.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Player/SphereBase.h"
#include "GameMode/SphereGameGameModeBase.h"
#include "Engine.h"

ASeveLocation::ASeveLocation()
{
	PrimaryActorTick.bCanEverTick = true;

	//初始化组件
	SaveMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SaveMesh"));

	HitBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBoxComp->SetupAttachment(SaveMeshComp);
	HitBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ASeveLocation::OnOverlapBegin_HitBox);	//碰撞事件绑定

}

void ASeveLocation::BeginPlay()
{
	Super::BeginPlay();

}

void ASeveLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//HitBox碰撞事件
void ASeveLocation::OnOverlapBegin_HitBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ASphereBase>(OtherActor))	//检查碰撞到的是玩家就将重生坐标更改
	{
		SetGameModeCurrentStart(HitBoxComp->GetComponentLocation());
	}
}

bool ASeveLocation::SetGameModeCurrentStart(FVector Location)
{

	ASphereGameGameModeBase * GameMode = Cast<ASphereGameGameModeBase>(GetWorld()->GetAuthGameMode());
	if (GameMode)
	{
		GameMode->CurrentStart = Location;

		return true;
	}
	return false;
}
