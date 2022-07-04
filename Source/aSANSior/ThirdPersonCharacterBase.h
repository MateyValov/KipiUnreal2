// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ThirdPersonCharacterBase.generated.h"

UCLASS()
class ASANSIOR_API AThirdPersonCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThirdPersonCharacterBase();

protected:
	// Called when the game starts or when spawned
	UPROPERTY()
	bool isCrouching = false;

	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void setSpawnpoint() { Spawnpoint = GetActorLocation(); }

	UFUNCTION()
		void Respawn() { 
			SetActorLocation(Spawnpoint); 
			SetActorRotation(FQuat(FRotator(0, 0, 0)), ETeleportType::None);
		}

private:
	UPROPERTY()
	FVector Spawnpoint;

protected:
	UFUNCTION()
		void beginCrouch();
	UFUNCTION()
		void endCrouch();


};
