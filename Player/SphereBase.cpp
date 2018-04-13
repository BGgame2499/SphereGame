
#include "SphereBase.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"


ASphereBase::ASphereBase()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereSpeed = 300.0f;
	MinSpeed = SphereSpeed;
	MaxSpeed = 500.0f;
	IsInput = true;

	//RootCollisionComponent = CreateAbstractDefaultSubobject<USphereComponent>(TEXT("RootCollisionComponent"));
	//RootCollisionComponent->SetSimulatePhysics(true);

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere Mesh"));	//Sphere模型
	//SphereMesh->SetupAttachment(RootCollisionComponent);
	SphereMesh->SetSimulatePhysics(true);

	CameraBoomComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));	//摄像机臂初始化
	CameraBoomComp->SetupAttachment(SphereMesh);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));	//摄像机
	CameraComp->SetupAttachment(CameraBoomComp);
}

void ASphereBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASphereBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (IsInput && AngularVector != FVector(0, 0, 0))
	{
		SphereMesh->SetPhysicsAngularVelocity(AngularVector);
	}
}



void ASphereBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)	//按键绑定
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ASphereBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASphereBase::MoveRight);


	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASphereBase::SpeedUp);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ASphereBase::SpeedLow);
}

void ASphereBase::MoveForward(float val)
{
	if (IsInput)
	{
		AngularVector.Y = SphereSpeed * val;
	}
	
}

void ASphereBase::MoveRight(float val)
{
	if (IsInput)
	{
		AngularVector.X = -SphereSpeed * val;
	}
}


void ASphereBase::SpeedUp()
{
	SphereSpeed = MaxSpeed;
}

void ASphereBase::SpeedLow()
{
	SphereSpeed = MinSpeed;
}
