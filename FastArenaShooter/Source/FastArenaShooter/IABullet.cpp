// Fill out your copyright notice in the Description page of Project Settings.


#include "IABullet.h"

#include "FASCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AIABullet::AIABullet()
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AIABullet::OnHit);// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}
void AIABullet::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovement->InitialSpeed = _dataBullet._speed;
	ProjectileMovement->Velocity += (GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	ProjectileMovement->MaxSpeed =  _dataBullet._speed;
	ProjectileMovement->Velocity = ProjectileMovement->Velocity.GetSafeNormal() * _dataBullet._speed;
}


void AIABullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if (OtherComp != nullptr)
	{
		if (OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		}
		if ((OtherActor != nullptr) && (OtherActor != this))
		{
			AFASCharacter* _containerIA = Cast<AFASCharacter>(OtherActor);
			if (_containerIA != nullptr)
			{
				_containerIA->DamagePlayer(_dataBullet._dmg,GetOwner(),_dataBullet._impactPower,false);
			}
		}
		Destroy();
	}
}
