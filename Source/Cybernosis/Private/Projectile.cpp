// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "PaperSprite.h"
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	CreateAndSetupCollisionComponent();
	CreateAndSetupProjectileComponent();
	CreateAndSetupSpriteComponent();
	

	InitialLifeSpan = 5.0f;
}

void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComponent != nullptr) && OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		Destroy();
	}
}


void AProjectile::CreateAndSetupCollisionComponent()
{
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Component"));
	CollisionComponent->InitSphereRadius(5.0f);
	CollisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComponent->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);

	CollisionComponent->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.0f));
	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	RootComponent = CollisionComponent;
}

void AProjectile::CreateAndSetupProjectileComponent()
{
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	ProjectileMovement->UpdatedComponent = CollisionComponent;
	ProjectileMovement->InitialSpeed = 500.f;
	ProjectileMovement->MaxSpeed = 500.f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->bShouldBounce = true;

}

void AProjectile::CreateAndSetupSpriteComponent()
{
	SpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite Component"));
	SpriteComponent->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UPaperSprite> ProjectileSprite (TEXT("/Game/sprites/Projectile/Projectile"));
	if (ProjectileSprite.Succeeded())
	{
		SpriteComponent->SetSprite(ProjectileSprite.Object);
		SpriteComponent->SetWorldRotation(FRotator(-90.0f, 0.0f, 0.0f));
		SpriteComponent->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
		UE_LOG(LogTemp, Warning, TEXT("Sprite setted!"));
	}
}



