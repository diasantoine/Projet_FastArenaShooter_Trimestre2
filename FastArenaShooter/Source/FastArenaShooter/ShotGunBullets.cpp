// Fill out your copyright notice in the Description page of Project Settings.

#include "ShotGunBullets.h"
#include "FAS_IACharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

AShotGunBullets::AShotGunBullets()
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AShotGunBullets::OnHit);// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
//	FVector _angle = UKismetMathLibrary::RandomUnitVectorInConeInDegrees(this->GetActorForwardVector(),120).GetSafeNormal();
	ProjectileMovement->InitialSpeed = 3000.F;
//	ProjectileMovement->Velocity *= _angle;
	ProjectileMovement->MaxSpeed =  3000.F;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AShotGunBullets::BeginPlay()
{
	Super::BeginPlay();//todo sortir la valeur
	FVector _angle = {FMath::FRandRange(-200,200),FMath::FRandRange(-200,200),FMath::FRandRange(-200,200)};
	//FVector _angle = FMath::VRandCone(ProjectileMovement->Velocity.GetSafeNormal(),60);//UKismetMathLibrary::RandomUnitVectorInConeInRadians(this->GetActorForwardVector(),30);
	ProjectileMovement->InitialSpeed = _dataBullet._speed;
	ProjectileMovement->Velocity += _angle;
	ProjectileMovement->MaxSpeed =  _dataBullet._speed;
}



void AShotGunBullets::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if (OtherComp != nullptr)// && OtherComp->IsSimulatingPhysics())
	{
		if (OtherComp->IsSimulatingPhysics())
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());
		}
		if ((OtherActor != nullptr) && (OtherActor != this))
		{
			AFAS_IACharacter* _containerIA = Cast<AFAS_IACharacter>(OtherActor);
			if (_containerIA != nullptr)
			{
				_containerIA->DamageIA(_dataBullet._dmg,GetOwner(),_dataBullet._impactPower);
			}
		}
		Destroy();
	}
}