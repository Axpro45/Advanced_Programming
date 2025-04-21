// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "CBT_SwordPickUpActor.generated.h"



UCLASS(Placeable, Blueprintable)
class ADVANCED_PROGRAMMING_API ACBT_SwordPickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACBT_SwordPickUpActor();
	

protected:
	//making the event begin play function
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category="Sword Pick Up")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditDefaultsOnly, Category="Sword Pick Up")
	USphereComponent* SphereComponent;

private:
	UFUNCTION()
	void SwordEquip();
	
	
	
};
