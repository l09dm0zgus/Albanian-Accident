
#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHealthComponent::SetCurrentHealth(float currentHealth)
{
	this->CurrentHealth = currentHealth;
}

void UHealthComponent::IncreaseCurrentHealth(float Value)
{
	CurrentHealth += Value;
}

void UHealthComponent::DecreaseCurrentHealth(float Value)
{
	CurrentHealth -= Value;
}

void UHealthComponent::SetStartHealth(float startHealth)
{
	this->StartHealth = startHealth;
}

float UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

float UHealthComponent::GetStartHealth()
{
	return StartHealth;
}


