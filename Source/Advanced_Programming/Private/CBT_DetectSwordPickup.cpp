// Fill out your copyright notice in the Description page of Project Settings.


#include "CBT_DetectSwordPickup.h"

// Sets default values
ACBT_DetectSwordPickup::ACBT_DetectSwordPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACBT_DetectSwordPickup::BeginPlay()
{
	Super::BeginPlay();
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("SwordPickedup"));
}

// Called every frame
void ACBT_DetectSwordPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

