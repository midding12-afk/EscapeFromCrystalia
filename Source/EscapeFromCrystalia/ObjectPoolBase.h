// Copyright (c) 2026 Dmitriy.Tur. Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectPoolBase.generated.h"

UCLASS(Blueprintable)
class ESCAPEFROMCRYSTALIA_API AObjectPoolBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectPoolBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	AActor* GetNewActor(TSubclassOf<AActor> ActorClass);
	
};
