
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SphereBase.generated.h"

UCLASS()
class SPHEREGAME_API ASphereBase : public APawn
{
	GENERATED_BODY()

public:
	ASphereBase();
public:
	//UPROPERTY(VisibleAnywhere, Category = "RootCollisionComponent")
	//class USphereComponent * RootCollisionComponent;
	UPROPERTY(VisibleAnywhere, Category = "SphereMesh")
	class UStaticMeshComponent * SphereMesh;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent * CameraBoomComp;

	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent * CameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IsInput")
	bool IsInput;

	FVector AngularVector;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float SphereSpeed;	//Sphere移动速度

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float MaxSpeed;	//Sphere移动速度

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed")
		float MinSpeed;	//Sphere移动速度
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float val);
	void MoveRight(float val);

	void SpeedUp();
	void SpeedLow();
	
};
