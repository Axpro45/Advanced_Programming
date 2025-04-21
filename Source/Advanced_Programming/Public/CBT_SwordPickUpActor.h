// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBT_SwordPickUpActor.generated.h"

class UStaticMeshComponent;

UCLASS()
class ADVANCED_PROGRAMMING_API ACBT_SwordPickUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACBT_SwordPickUpActor();

protected:
	UPROPERTY(EditDefaultsOnly, Category="Sword Pick Up")
	TIsTObjectPtr<UStaticMeshComponent> MeshComponent;
};
