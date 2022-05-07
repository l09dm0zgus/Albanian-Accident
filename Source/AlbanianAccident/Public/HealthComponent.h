// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALBANIANACCIDENT_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetCurrentHealth(float currentHealth);
	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetStartHealth(float startHealth);
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetCurrentHealth();
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetStartHealth();
private:

	UPROPERTY(EditAnywhere, Category = "Health")
	float StartHealth = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Health")
	float CurrentHealth = 100.0f;
};
