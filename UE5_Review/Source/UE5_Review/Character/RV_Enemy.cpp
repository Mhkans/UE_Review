// Fill out your copyright notice in the Description page of Project Settings.


#include "RV_Enemy.h"

ARV_Enemy::ARV_Enemy()
{
}

void ARV_Enemy::BeginPlay()
{
	Super::BeginPlay();
}

void ARV_Enemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
} 

void ARV_Enemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
