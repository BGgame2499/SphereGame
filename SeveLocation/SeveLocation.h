
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeveLocation.generated.h"

UCLASS()
class SPHEREGAME_API ASeveLocation : public AActor	//玩家重生位置
{
	GENERATED_BODY()

public:

	ASeveLocation();

public:
	//组件成员
	UPROPERTY(VisibleAnywhere, Category = "SaveMesh")
		class UStaticMeshComponent * SaveMeshComp;

	UPROPERTY(VisibleAnywhere, Category = "HitBox")
		class UBoxComponent * HitBoxComp;

public:

	UFUNCTION()
	   virtual void OnOverlapBegin_HitBox(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "SetGameModeCurrentStart")
		bool SetGameModeCurrentStart(FVector Location);
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
