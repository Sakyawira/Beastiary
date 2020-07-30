// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Recipe.generated.h"

UENUM(BlueprintType)
enum class Ingredient : uint8 {
	Apple = 0 UMETA(DisplayName = "Apple"),
	Banana = 1  UMETA(DisplayName = "Banana"),
	Cherry = 2     UMETA(DisplayName = "Cherry"),
	Dicks = 3  UMETA(DisplayName = "Dicks")
};

USTRUCT(BlueprintType)
struct FRecipe
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FoodName = "NoFood";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<Ingredient> Ingredients;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* PotionMesh = nullptr;
};

UCLASS(Blueprintable)
class BEASTIARY_API ARecipeHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARecipeHandler();

	// Check whether the needed ingredients for a recipe are available
	UFUNCTION(BlueprintCallable)
	bool containsAll(TArray<Ingredient> _neededIngredients, TArray<Ingredient> _availableIngredients);

	// Check if any of the recipe in the array of recipes can be made
	UFUNCTION(BlueprintCallable)
	FRecipe haveRecipe(TArray<FRecipe> _recipes, TArray<Ingredient> _availableIngredients);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRecipe> Recipes;

};
