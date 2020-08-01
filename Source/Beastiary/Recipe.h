// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Recipe.generated.h"

UENUM(BlueprintType)
enum class Ingredient : uint8 {
	Batwing = 0    UMETA(DisplayName = "Batwing"),
	Claw = 1       UMETA(DisplayName = "Claw"),
	Eyeball = 2    UMETA(DisplayName = "Eyeball"),
	Garlic = 3     UMETA(DisplayName = "Garlic"),
	Horn = 4       UMETA(DisplayName = "Horn"),
	Leafyherb = 5  UMETA(DisplayName = "Leafyherb"),
	Mushroom = 6   UMETA(DisplayName = "Mushroom"),
	Scale = 7      UMETA(DisplayName = "Scale"),
	Tail = 8       UMETA(DisplayName = "Tail"), 
	Tentacle = 9   UMETA(DisplayName = "Tentacle")
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDiscovered = false;
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
	FRecipe haveRecipe(UPARAM(ref) TArray<FRecipe>& _recipes, TArray<Ingredient> _availableIngredients);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FRecipe> Recipes;

};
