// Copyright (c) 2026 Dmitriy.Tur. Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "AC_EnemyMoveBase.h"
#include "ObjectPoolBase.h"
#include "Spawner.generated.h"


USTRUCT(BlueprintType)
struct FF_Bonuses : public FTableRowBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Waight", MakeStructureDefaultValue = "0.000000"))
	float Waight;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Bluprint", MakeStructureDefaultValue = nullptr))
	TSubclassOf<AActor> Bluprint;
};


UCLASS()
class ESCAPEFROMCRYSTALIA_API ASpawner : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASpawner();

	FTimerHandle SpawnerTimerHandle;
	FRandomStream MyStream;
	int Score=0;
	int NextBonusAtScore=10;

	UPROPERTY()
	UBoxComponent* SpawnBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyInput")
	TArray<TSubclassOf<AActor>> SpawnedActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyInput")
	TArray<float> SpawnedActorsWaight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyInput")
	UDataTable* SpawnedBonuses;


	int GunCount = 1;
	float FireRate = 1.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


	UPROPERTY()
	AObjectPoolBase* ObjectPoolActor;


public:	
	
	UFUNCTION(BlueprintCallable)
	void SetRandomSeed(FName Seed);

	UFUNCTION(BlueprintCallable)
	void SetScore(int NewScore);

	UFUNCTION()
	void Func_SpawnActor();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	AActor* SpawnActorFromPool(TSubclassOf<AActor> actor);

	UFUNCTION(BlueprintCallable)
	void SetGunCountInfo(int InCount);

	UFUNCTION(BlueprintCallable)
	void SetFireRateInfo(float Infirerate);
};
