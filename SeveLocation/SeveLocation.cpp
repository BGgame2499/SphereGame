
#include "SeveLocation.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Player/SphereBase.h"
#include "GameMode/SphereGameGameModeBase.h"
#include "Engine.h"

ASeveLocation::ASeveLocation()
{
	PrimaryActorTick.bCanEverTick = true;

	//��ʼ�����
	SaveMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SaveMesh"));

	HitBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("HitBox"));
	HitBoxComp->SetupAttachment(SaveMeshComp);
	HitBoxComp->OnComponentBeginOverlap.AddDynamic(this, &ASeveLocation::OnOverlapBegin_HitBox);	//��ײ�¼���

}

void ASeveLocation::BeginPlay()
{
	Super::BeginPlay();

}

void ASeveLocation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//HitBox��ײ�¼�
void ASeveLocation::OnOverlapBegin_HitBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ASphereBase>(OtherActor))	//�����ײ��������Ҿͽ������������
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
