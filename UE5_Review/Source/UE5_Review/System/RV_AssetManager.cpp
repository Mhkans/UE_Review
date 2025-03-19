// Fill out your copyright notice in the Description page of Project Settings.


#include "RV_AssetManager.h"

URV_AssetManager::URV_AssetManager() :Super()
{
}

URV_AssetManager& URV_AssetManager::GetInstance()
{
	auto* singleton = Cast<URV_AssetManager>(GEngine->AssetManager);
	if (singleton) {
		return *singleton;
	}
	return *NewObject<URV_AssetManager>();
}
