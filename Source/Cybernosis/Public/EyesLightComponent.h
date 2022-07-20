// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/SpotLightComponent.h"
#include "EyesLightComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CYBERNOSIS_API UEyesLightComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UEyesLightComponent();
	void SetupLightFlare(const FTransform& LightFlareTransform, const FLinearColor& Color,float OuterConeAngle,float Intensity);
	void SetupFirstEyeLight(const FTransform& FirstEyeLightTransform, const FLinearColor& Color, float OuterConeAngle, float Intensity);
	void SetupSecondEyeLight(const FTransform& SecondEyeLightTransform, const FLinearColor& Color, float OuterConeAngle, float Intensity);

protected:
	virtual void BeginPlay() override;	
private:
	UPROPERTY(EditAnywhere)
	USpotLightComponent* LightFlare;

	UPROPERTY(EditAnywhere)
	USpotLightComponent* FirstEyeLight;

	UPROPERTY(EditAnywhere)
	USpotLightComponent* SecondEyeLight;
};
