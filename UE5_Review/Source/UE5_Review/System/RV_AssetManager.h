// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "RV_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class UE5_REVIEW_API URV_AssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	URV_AssetManager();
	static URV_AssetManager& GetInstance();
};
