// Copyright (c) 2026 Dmitriy.Tur. Licensed under the MIT License.


#include "AC_EnemyMoveBase.h"

// Sets default values for this component's properties
UAC_EnemyMoveBase::UAC_EnemyMoveBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_EnemyMoveBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAC_EnemyMoveBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

