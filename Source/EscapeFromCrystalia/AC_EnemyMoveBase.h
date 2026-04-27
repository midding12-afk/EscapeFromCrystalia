// Copyright (c) 2026 Dmitriy.Tur. Licensed under the MIT License.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AC_EnemyMoveBase.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEFROMCRYSTALIA_API UAC_EnemyMoveBase : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_EnemyMoveBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MoveSide;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsOnStart = true;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetStartSide(FVector Vector);
		
};
