// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonCharacterBase.h"
#include "Engine.h"

// Sets default values
AThirdPersonCharacterBase::AThirdPersonCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AThirdPersonCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	setSpawnpoint();
}

// Called every frame
void AThirdPersonCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AThirdPersonCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	InputComponent->BindAction("Crouch", IE_Pressed, this, &AThirdPersonCharacterBase::beginCrouch);
	InputComponent->BindAction("Crouch", IE_Released, this, &AThirdPersonCharacterBase::endCrouch);

	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AThirdPersonCharacterBase::beginCrouch() {
	isCrouching = true;
	GEngine->AddOnScreenDebugMessage(-1,5.f,FColor::Green,TEXT("klekna"));
}

void AThirdPersonCharacterBase::endCrouch() {
	isCrouching = false;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("stana"));

}



