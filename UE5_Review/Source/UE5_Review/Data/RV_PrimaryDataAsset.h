// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "RV_PrimaryDataAsset.generated.h"

/**
 * 
 */
USTRUCT()
struct FAssetEntry {
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	FName AssetName;
	UPROPERTY(EditDefaultsOnly)
	FSoftObjectPath AssetPath;
	UPROPERTY(EditDefaultsOnly)
	TArray<FName> AssetLables;
};

USTRUCT()
struct FAssetSet {
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FAssetEntry> AssetEntries;
};
UCLASS()
class UE5_REVIEW_API URV_PrimaryDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	//FSoftObjectPath GetAssetPathByName(const FName& AssetName);
	//const FAssetSet& GetAssetSetByLabel(const FName& label);
private:
	UPROPERTY(EditDefaultsOnly)
	TMap<FName, FAssetSet> AssetGroupNameToSet;
	
};
