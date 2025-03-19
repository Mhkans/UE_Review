// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RV_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5_REVIEW_API URV_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	URV_AnimInstance(const FObjectInitializer& ObjectInitializer);

	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
protected:
};
