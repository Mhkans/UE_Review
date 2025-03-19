// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "RV_InputData.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT()
struct FRV_InputAction {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag::EmptyTag;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr< UInputAction> inputAction = nullptr;
};
/**
 * 
 */
UCLASS()
class UE5_REVIEW_API URV_InputData : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr< UInputMappingContext> inputMappingContext;
	UPROPERTY(EditDefaultsOnly)
	TArray<FRV_InputAction> inputActions;
};
