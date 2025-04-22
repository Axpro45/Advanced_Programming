// Fill out your copyright notice in the Description page of Project Settings.


#include "CBT_SwordPickUpActor.h"
#include "Components/MeshComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"


// Sets default values
ACBT_SwordPickUpActor::ACBT_SwordPickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	


    //Setting Up collider
    ColliderComponent = CreateDefaultSubobject<USphereComponent>("ColliderComponent");
    SetRootComponent(ColliderComponent);
    ColliderComponent->SetGenerateOverlapEvents(true);
    ColliderComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    ColliderComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
    ColliderComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	

    ColliderComponent->OnComponentBeginOverlap.AddDynamic(
        this, &ACBT_SwordPickUpActor::OnBeginOverlapComponentEvent
    );
    //Setting Static Mesh
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
    MeshComponent->SetupAttachment(ColliderComponent);
    MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
    MeshComponent->SetGenerateOverlapEvents(false);



}
void ACBT_SwordPickUpActor::OnBeginOverlapComponentEvent(
    UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult
)
{
	if (!OtherActor->Tags.Contains("Player")) return;

	if (SwordEquiped)return;
	if (const ACharacter* Character = Cast<ACharacter>(OtherActor))
	{
		AttachToComponent(
			Character->GetMesh(),
			FAttachmentTransformRules(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::KeepWorld,
				false
			),
			FName("hand_l")
		);

		
		SwordEquiped = true;
		// Destroy();
	}
	
	
}


void ACBT_SwordPickUpActor::SwordEquip()
{
	//GEngine is the class and the AddOnScreenDebugMessage is Print screen
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green,TEXT("Picked up"));
}

void ACBT_SwordPickUpActor::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("Test C++ begin play"));
	SwordEquip();
}





