// Copyright (c) 2026 Dmitriy.Tur. Licensed under the MIT License.


#include "ObjectPoolBase.h"

// Sets default values
AObjectPoolBase::AObjectPoolBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObjectPoolBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObjectPoolBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

