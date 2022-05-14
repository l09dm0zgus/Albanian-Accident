
#include "AlbanianPlayer.h"

AAlbanianPlayer::AAlbanianPlayer()
{
	PrimaryActorTick.bCanEverTick = false;

	CreateAndSetupFlipbookComponent();
	CreateAndSetupSpringArmComponent();
	CreateAndSetupCameraComponent();
	CreateAndSetupMovementComponent();
	CreateAndSetupEyesLightComponent();
	CreateAndSetupHealthComponent();


	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RollActor(90);
}

void AAlbanianPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}



void AAlbanianPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AAlbanianPlayer::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAlbanianPlayer::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AAlbanianPlayer::Turn);
	PlayerInputComponent->BindAction("FirstWeapon", IE_Pressed, this, &AAlbanianPlayer::ChooseFistWeapon);
	PlayerInputComponent->BindAction("SecondWeapon", IE_Pressed, this, &AAlbanianPlayer::ChooseSecondWeapon);
	PlayerInputComponent->BindAction("ThirdWeapon", IE_Pressed, this, &AAlbanianPlayer::ChooseThirdWeapon);
	PlayerInputComponent->BindAxis("ZoomIn", Camera, &UAlbanianPlayerCameraComponent::ZoomIn);
	PlayerInputComponent->BindAxis("ZoomOut", Camera, &UAlbanianPlayerCameraComponent::ZoomOut);
}

void AAlbanianPlayer::MoveForward(float AxisValue)
{
	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->AddInputVector(GetActorForwardVector() * AxisValue);
	}
}

void AAlbanianPlayer::MoveRight(float AxisValue)
{
	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->AddInputVector(GetActorUpVector() * AxisValue);
	}
}

void AAlbanianPlayer::Turn(float AxisValue)
{
	if (MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->Turn(AxisValue);
	}
}

void AAlbanianPlayer::CreateAndSetupSpringArmComponent()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetUsingAbsoluteRotation(true);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;
	
}

void AAlbanianPlayer::CreateAndSetupCameraComponent()
{
	Camera = CreateDefaultSubobject<UAlbanianPlayerCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 25.0f));
}

void AAlbanianPlayer::CreateAndSetupMovementComponent()
{
	MovementComponent = CreateDefaultSubobject<UAlbanianPlayerMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;
}

void AAlbanianPlayer::CreateAndSetupFlipbookComponent()
{
	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	FlipbookComponent->SetLooping(false);
	RootComponent = FlipbookComponent;
}

void AAlbanianPlayer::CreateAndSetupEyesLightComponent()
{
	EyesLightComponent = CreateDefaultSubobject<UEyesLightComponent>(TEXT("PlayerEyesLights"));
	EyesLightComponent->AttachToComponent(FlipbookComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	SetupLightFlare();
	SetupFirstEyeLight();
	SetupSecondEyeLight();
}

void AAlbanianPlayer::CreateAndSetupHealthComponent()
{
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));
}

void AAlbanianPlayer::SetupLightFlare()
{
	FTransform Transform;
	FRotator Rotator;
	Rotator.Roll = -180.0f;
	Rotator.Yaw = 10.0f;
	Rotator.Pitch = 10.0f;
	Transform.SetRotation(Rotator.Quaternion());
	Transform.SetLocation(FVector(-41.0f, -20.0f, -8.5f));
	EyesLightComponent->SetupLightFlare(Transform, FLinearColor(1.0f, 0.0f, 0.0f), 18.0f, 5000.0f);

}

void AAlbanianPlayer::SetupFirstEyeLight()
{
	FTransform Transform;
	FRotator Rotator;
	Rotator.Roll = -70.0f;
	Rotator.Yaw = 90.0f;
	Transform.SetRotation(Rotator.Quaternion());
	Transform.SetLocation(FVector(1.9f, -12.5f, -1.6f));
	EyesLightComponent->SetupFirstEyeLight(Transform, FLinearColor(1.0f, 0.0f, 0.0f), 4.0f, 100000.0f);
}

void AAlbanianPlayer::SetupSecondEyeLight()
{
	FTransform Transform;
	FRotator Rotator;
	Rotator.Roll = -70.0f;
	Rotator.Yaw = 90.0f;
	Transform.SetRotation(Rotator.Quaternion());
	Transform.SetLocation(FVector(2.15f, -12.5, 3.0f));
	EyesLightComponent->SetupSecondEyeLight(Transform, FLinearColor(1.0f, 0.0f, 0.0f), 4.0f, 100000.0f);
}

void AAlbanianPlayer::RollActor(float Angle)
{
	FRotator NewRotation = GetActorRotation();
	NewRotation.Roll = Angle;
	SetActorRotation(NewRotation);
}

void AAlbanianPlayer::ChooseFistWeapon()
{
	FlipbookComponent->SetFlipbook(FistWeaponAnimation);
	FlipbookComponent->Play();
}

void AAlbanianPlayer::ChooseSecondWeapon()
{
	FlipbookComponent->SetFlipbook(SecondWeaponAnimation);
	FlipbookComponent->Play();
}

void AAlbanianPlayer::ChooseThirdWeapon()
{

	FlipbookComponent->SetFlipbook(ThirdWeaponAnimation);
	FlipbookComponent->PlayFromStart();
	FlipbookComponent->ReverseFromEnd();

}

