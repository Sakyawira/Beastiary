// Fill out your copyright notice in the Description page of Project Settings.


#include "Recipe.h"

// Sets default values
ARecipeHandler::ARecipeHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ARecipeHandler::containsAll(TArray<Ingredient> _neededIngredients, TArray<Ingredient> _availableIngredients)
{
	int len = _neededIngredients.Num();
	if (_availableIngredients.Num() != _neededIngredients.Num()) 
	{
		return false;
	}

	_availableIngredients.Sort([](const Ingredient& LHS, const Ingredient& RHS) { return LHS > RHS; });
	_neededIngredients.Sort([](const Ingredient& LHS, const Ingredient& RHS) { return LHS > RHS; });

	for (int i = 0; i < len; i++) 
	{
		/*if (_availableIngredients.Find(_neededIngredients[i]) == INDEX_NONE )*/
		if (_availableIngredients[i] != _neededIngredients[i])
		{
			return false;
		}
	}
	return true;
}

FRecipe ARecipeHandler::haveRecipe(UPARAM(ref) TArray<FRecipe>& _recipes, TArray<Ingredient> _availableIngredients)
{
	for (auto& recipe : _recipes)
	{
		if (containsAll(recipe.Ingredients, _availableIngredients))
		{
			recipe.IsDiscovered = true;
			return recipe;
		}
	}
	return FRecipe();
}

// Called when the game starts or when spawned
void ARecipeHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARecipeHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

