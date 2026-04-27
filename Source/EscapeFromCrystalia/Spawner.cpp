// Copyright (c) 2026 Dmitriy.Tur. Licensed under the MIT License.


#include "Spawner.h"

// Sets default values
ASpawner::ASpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnerBox"));
	RootComponent = SpawnBox;

	SpawnBox->SetBoxExtent(FVector(100.f, 100.f, 10.f));
}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
 
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AObjectPoolBase::StaticClass(), FoundActors);
	if (!FoundActors.IsEmpty())
		ObjectPoolActor = Cast<AObjectPoolBase>(FoundActors[0]);
	

	
}

void ASpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (GetWorld())
	{
		GetWorldTimerManager().ClearTimer(SpawnerTimerHandle);
	}

	Super::EndPlay(EndPlayReason);
}

void ASpawner::SetRandomSeed(FName Seed)
{
	MyStream.Initialize(Seed);

	if (ObjectPoolActor)
		GetWorldTimerManager().SetTimer(SpawnerTimerHandle, this, &ASpawner::Func_SpawnActor, 1.f, false);
}

void ASpawner::SetScore(int NewScore)
{
	Score = NewScore;
	if (NextBonusAtScore <= Score)
	{
		NextBonusAtScore = MyStream.FRandRange(10., 100. + (GunCount - 1.f) * 10.f + (FireRate - 1.f) * 10.f) + Score;

		if (SpawnedBonuses)
		{
			TArray<FName> AllNames;
			TArray<float> AllWaights;
			TArray < TSubclassOf<AActor>> AllBluprint;

			AllNames.Empty();
			AllWaights.Empty();
			AllBluprint.Empty();

			float sum = 0.f;

			for (auto& It : SpawnedBonuses->GetRowMap())
			{
				AllNames.Add(It.Key);
				float waight = reinterpret_cast<FF_Bonuses*>(It.Value)->Waight;
				AllWaights.Add(waight);
				sum += waight;
				AllBluprint.Add(reinterpret_cast<FF_Bonuses*>(It.Value)->Bluprint);
			}
			
			float res = MyStream.FRandRange(0.0, sum);
			
			for (int i = 0; i < AllWaights.Num(); i++)
			{
				if (res <= AllWaights[i])
				{
					FVector BoxMin = SpawnBox->GetComponentLocation() - SpawnBox->GetScaledBoxExtent();
					FVector BoxMax = SpawnBox->GetComponentLocation() + SpawnBox->GetScaledBoxExtent();

					FVector RandomLocation = FVector(MyStream.FRandRange(BoxMin.X, BoxMax.X), MyStream.FRandRange(BoxMin.Y, BoxMax.Y), 100.f);

					AActor* SpawnedActor = ObjectPoolActor->GetNewActor(AllBluprint[i]);
					SpawnedActor->SetActorLocation(RandomLocation);
					SpawnedActor->SetActorRotation(FRotator(0.f, 180.f, 0.f));// Z - Yaw 

					break;
				}
				else
					res -= AllWaights[i];
			}

			AllNames.Empty();
			AllWaights.Empty();
			AllBluprint.Empty();

		}
	}
}

void ASpawner::Func_SpawnActor()
{
	
	//float kHard = FMath::Pow(1.01f, Score*0.01f);
	float Difficult = FMath::Lerp(10.f, 500.f, Score / TNumericLimits<int32>::Max() * 0.2f) + (GunCount-1.f)*5.f + (FireRate-1.f)*10.f;
	float DelayToNextSpawn = MyStream.FRand() * 10.f / (1.f + Difficult * 0.01);
	
	int arrLength = SpawnedActors.Num();

	if (arrLength == 0)
		return;

	int selectEnemyId = MyStream.RandRange(0, arrLength - 1);

	float TargetWeight = Difficult;

	if (SpawnedActorsWaight[selectEnemyId])
	{
		int countSpawn = FMath::RoundToInt(TargetWeight / SpawnedActorsWaight[selectEnemyId]);

		FVector BoxMin = SpawnBox->GetComponentLocation() - SpawnBox->GetScaledBoxExtent();
		FVector BoxMax = SpawnBox->GetComponentLocation() + SpawnBox->GetScaledBoxExtent();

		FVector MoveSide = MyStream.VRand();

		if (SpawnedActors[selectEnemyId])
		{
			for (int i = 0;i <= countSpawn;i++)
			{
				FVector RandomLocation = FVector(MyStream.FRandRange(BoxMin.X, BoxMax.X), MyStream.FRandRange(BoxMin.Y, BoxMax.Y), 100.f);

				//AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(SpawnedActors[selectEnemyId], RandomLocation, FRotator(0.f, 0.f, 0.f));
				//AActor* SpawnedActor = SpawnActorFromPool(SpawnedActors[selectEnemyId]);
				AActor* SpawnedActor = ObjectPoolActor->GetNewActor(SpawnedActors[selectEnemyId]);
				SpawnedActor->SetActorLocation(RandomLocation);
				SpawnedActor->SetActorRotation(FRotator(0.f, 0.f, 0.f));

				UAC_EnemyMoveBase* MoveComp = SpawnedActor->FindComponentByClass<UAC_EnemyMoveBase>();

				if (MoveComp)
				{
					MoveComp->SetStartSide(MoveSide);
					MoveComp->IsOnStart = true;
				}
			}
		}
	}

	GetWorldTimerManager().SetTimer(SpawnerTimerHandle, this, &ASpawner::Func_SpawnActor, DelayToNextSpawn, false);


}

void ASpawner::SetGunCountInfo(int InCount)
{
	GunCount = InCount;
}

void ASpawner::SetFireRateInfo(float Infirerate)
{
	FireRate = Infirerate;
}
