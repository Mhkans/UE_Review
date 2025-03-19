// Fill out your copyright notice in the Description page of Project Settings.


#include "RV_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "RV_Player.h"


ARV_PlayerController::ARV_PlayerController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	

}

void ARV_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (subsystem) {
		subsystem->AddMappingContext(_InputMappingContext, 0);
	}
}

void ARV_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	auto enhancedInputCompnent = Cast<UEnhancedInputComponent>(InputComponent);
	if (enhancedInputCompnent) {
		enhancedInputCompnent->BindAction(_MoveAction, ETriggerEvent::Triggered, this, &ARV_PlayerController::Input_Move);
		enhancedInputCompnent->BindAction(_TurnAction, ETriggerEvent::Triggered, this, &ARV_PlayerController::Input_Turn);
		enhancedInputCompnent->BindAction(_AttackAction, ETriggerEvent::Started, this, &ARV_PlayerController::Input_Attack);
		enhancedInputCompnent->BindAction(_JumpAction, ETriggerEvent::Started, this, &ARV_PlayerController::Input_Jump);
	}
}

void ARV_PlayerController::Input_Move(const FInputActionValue& InputValue)
{
	FVector2D moveVector = InputValue.Get<FVector2D>();
	
	if (moveVector.Length() > 0)
	{
		FVector forWard = GetPawn()->GetActorForwardVector();
		FVector right = GetPawn()->GetActorRightVector();

		GetPawn()->AddMovementInput(right, moveVector.X * 10);
		GetPawn()->AddMovementInput(forWard, moveVector.Y * 10);
	}
}

void ARV_PlayerController::Input_Turn(const FInputActionValue& InputValue)
{
	FVector2D lookVector = InputValue.Get<FVector2D>();

	AddYawInput(lookVector.X);
	AddPitchInput(-lookVector.Y);

}

void ARV_PlayerController::Input_Attack(const FInputActionValue& InputValue)
{
	FVector ActorLocation = GetPawn()->GetActorLocation();
	DrawDebugString(GetWorld(), ActorLocation, TEXT("Attack"), nullptr, FColor::Blue, 5.0f, true);
}

void ARV_PlayerController::Input_Jump(const FInputActionValue& InputValue)
{
	auto player = Cast<ARV_Player>(GetPawn());
	if (player) {
		player->Jump();
	}
	
}
