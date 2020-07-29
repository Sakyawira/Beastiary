// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Recipe.generated.h"

UENUM(BlueprintType)
enum class Ingredient2 : uint8 {
	Apple = 0 UMETA(DisplayName = "Apple"),
	Banana = 1  UMETA(DisplayName = "Banana"),
	Cherry = 2     UMETA(DisplayName = "Cherry"),
	Dicks = 3  UMETA(DisplayName = "Dicks")
};

UCLASS()
class BEASTIARY_API ARecipe : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARecipe();

	bool containsAll(TArray<Ingredient2> _neededIngredients, TArray<Ingredient2> _availableIngredients);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TMap<FString, TArray<Ingredient2>> Recipes;

};
