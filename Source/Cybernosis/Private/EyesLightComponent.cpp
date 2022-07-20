
#include "EyesLightComponent.h"
UEyesLightComponent::UEyesLightComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	LightFlare = CreateDefaultSubobject<USpotLightComponent>(TEXT("LightFlare"));
	FirstEyeLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("FirstEyeLight"));
	SecondEyeLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SecondEyeLight"));
	LightFlare->AttachToComponent(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	FirstEyeLight->AttachToComponent(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	SecondEyeLight->AttachToComponent(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}

void UEyesLightComponent::SetupLightFlare(const FTransform& LightFlareTransform, const FLinearColor& Color, float OuterConeAngle, float Intensity)
{
	LightFlare->SetRelativeLocation(LightFlareTransform.GetLocation());
	LightFlare->SetRelativeRotation(LightFlareTransform.GetRotation());
	LightFlare->SetLightColor(Color);
	LightFlare->SetOuterConeAngle(OuterConeAngle);
	LightFlare->SetIntensity(Intensity);
}

void UEyesLightComponent::SetupFirstEyeLight(const FTransform& FirstEyeLightTransform, const FLinearColor& Color, float OuterConeAngle, float Intensity)
{
	FirstEyeLight->SetRelativeLocation(FirstEyeLightTransform.GetLocation());
	FirstEyeLight->SetRelativeRotation(FirstEyeLightTransform.GetRotation());
	FirstEyeLight->SetLightColor(Color);
	FirstEyeLight->SetOuterConeAngle(OuterConeAngle);
	FirstEyeLight->SetIntensity(Intensity);
}

void UEyesLightComponent::SetupSecondEyeLight(const FTransform& SecondEyeLightTransform, const FLinearColor& Color, float OuterConeAngle, float Intensity)
{
	SecondEyeLight->SetRelativeLocation(SecondEyeLightTransform.GetLocation());
	SecondEyeLight->SetRelativeRotation(SecondEyeLightTransform.GetRotation());
	SecondEyeLight->SetLightColor(Color);
	SecondEyeLight->SetOuterConeAngle(OuterConeAngle);
	SecondEyeLight->SetIntensity(Intensity);
}

void UEyesLightComponent::BeginPlay()
{
	Super::BeginPlay();
}


