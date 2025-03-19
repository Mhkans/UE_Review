// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RV_BaseCharacter.h"
#include "RV_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class UE5_REVIEW_API ARV_Enemy : public ARV_BaseCharacter
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	ARV_Enemy();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
