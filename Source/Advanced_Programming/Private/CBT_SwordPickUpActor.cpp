// Fill out your copyright notice in the Description page of Project Settings.


#include "CBT_SwordPickUpActor.h"
#include "Components/MeshComponent.h"

// Sets default values
ACBT_SwordPickUpActor::ACBT_SwordPickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	


	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(MeshComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	MeshComponent->SetGenerateOverlapEvents(false);

}
void ACBT_SwordPickUpActor::SwordEquip()
{
	//GEngine is the class and the AddOnScreenDebugMessage is Print screen
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red,TEXT("Picked up"));
	//on the sword it destroys
	this->Destroy();
}

void ACBT_SwordPickUpActor::BeginPlay()
{
	Super::BeginPlay();

	SwordEquip();
}




