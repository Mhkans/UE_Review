// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RV_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE5_REVIEW_API ARV_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ARV_PlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;


private:
	void Input_Move(const struct FInputActionValue& InputValue);
	void Input_Turn(const struct FInputActionValue& InputValue);
	void Input_Attack(const struct FInputActionValue& InputValue);
	void Input_Jump(const struct FInputActionValue& InputValue);
protected:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputMappingContext> _InputMappingContext;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> _MoveAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> _TurnAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> _AttackAction;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> _JumpAction;

};
