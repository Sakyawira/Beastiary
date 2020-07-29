// Fill out your copyright notice in the Description page of Project Settings.


#include "Recipe.h"

// Sets default values
ARecipe::ARecipe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

bool ARecipe::containsAll(TArray<Ingredient2> _neededIngredients, TArray<Ingredient2> _availableIngredients)
{
	int len = _neededIngredients.Num();
	for (int i = 0; i < len; i++) 
	{
		if (_availableIngredients.Find(_neededIngredients[i]) == false)
		{
			return false;
		}
	}
	return true;
}

// Called when the game starts or when spawned
void ARecipe::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARecipe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

