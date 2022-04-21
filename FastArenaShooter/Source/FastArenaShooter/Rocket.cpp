// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocket.h"

#include "FAS_IACharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"

ARocket::ARocket()
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &ARocket::OnHit);// set up a notification for when this component hits something blocking

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
void ARocket::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMovement->InitialSpeed = _dataBullet._speed;
	ProjectileMovement->MaxSpeed =  _dataBullet._speed;
	ProjectileMovement->Velocity = ProjectileMovement->Velocity.GetSafeNormal() * _dataBullet._speed;
	_rangeExplosion = FMath::Clamp(_dataBullet._sizeSphereExplosion * _percentageSpeed,_minimalExplosionRange,_dataBullet._sizeSphereExplosion);
	_explosionImpact = _dataBullet._impactPower * _percentageSpeed;
}


void ARocket::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if (OtherComp != nullptr)
	{
		// if (OtherComp->IsSimulatingPhysics())
		// {
		// 	OtherComp->AddImpulseAtLocation(GetVelocity() * _explosionImpact, GetActorLocation());
		// }
		if ((OtherActor != nullptr) && (OtherActor != this))
		{
			AFAS_IACharacter* _containerIA = Cast<AFAS_IACharacter>(OtherActor);
			if (_containerIA != nullptr)
			{
				_containerIA->DamageIA( FMath::Clamp(_dataBullet._dmg * _percentageSpeed,_dataBullet._dmg * _minimalDMGExplosion,_dataBullet._dmg),GetOwner(),_explosionImpact);
			}
		}
		TArray<FHitResult> out;
		FQuat quat = {0,0,0,0};
		GetWorld()->SweepMultiByChannel(out,GetActorLocation(),GetActorLocation(),quat,ECC_Pawn,FCollisionShape::MakeSphere(_rangeExplosion),
			FCollisionQueryParams::DefaultQueryParam,FCollisionResponseParams::DefaultResponseParam);
		for (auto Out : out)
		{
			
			if (Out.GetActor() != nullptr)
			{
				float DistanceModifVar = FMath::Clamp(_minimumDistanceForOptimalImpact/ FVector::Dist(GetActorLocation(),Out.GetActor()->GetActorLocation()),_minimalPower,1.f )
			 * _percentageSpeed;
				float DistanceDmgModifier = FMath::Clamp(_minimumDistanceForOptimalImpact/ FVector::Dist(GetActorLocation(),Out.GetActor()->GetActorLocation()),_minimalDMGExplosion,1.f)
			 * _percentageSpeed;
				AFAS_IACharacter* _containerIA = Cast<AFAS_IACharacter>(Out.GetActor());
				AFASCharacter* _containerCharacter = Cast<AFASCharacter>(Out.GetActor());
				if (_containerIA != nullptr)
				{
					_containerIA->LaunchCharacter((Out.GetActor()->GetActorLocation() - GetActorLocation()).GetSafeNormal() * _explosionImpact * DistanceModifVar,true,true);
					_containerIA->DamageIA(DistanceDmgModifier * _dataBullet._dmg,GetOwner(),_dataBullet._impactPower * DistanceModifVar);
				}else if (_containerCharacter != nullptr)
				{
					_containerCharacter->KnockBackPlayer(RocketLauncherKnock,_dataBullet._knockPlayerDuration * DistanceModifVar,_explosionImpact * DistanceModifVar,
						(Out.GetActor()->GetActorLocation() - GetActorLocation()).GetSafeNormal() * _explosionImpact * DistanceModifVar);
					// _containerCharacter->LaunchCharacter(
					// 	(Out.GetActor()->GetActorLocation() - GetActorLocation()).GetSafeNormal() * _dataBullet._impactPower / FVector::Dist(GetActorLocation(),Out.GetActor()->GetActorLocation()),true,true);
					//_containerCharacter->DamagePlayer(DistanceDmgModifier,GetOwner(),_explosionImpact * DistanceModifVar,true);
				}
			 }//else
			// {
			// 	float DistanceModifVar = FMath::Clamp(_minimumDistanceForOptimalImpact/ FVector::Dist(GetActorLocation(),Out.GetComponent()->GetComponentLocation()),_minimalPower,1.f )
			//  * _percentageSpeed;
			// 	if (Out.GetComponent()->IsSimulatingPhysics())
			// 	{
			// 		Out.GetComponent()->AddImpulseAtLocation(GetVelocity() * _explosionImpact * DistanceModifVar, GetActorLocation());
			// 	}
			// }
		}
		Destroy();
	}
}
