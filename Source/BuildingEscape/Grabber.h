// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	float Reach = 200.f; 

	//ensures no crash will occur if physics handle component is not on object
	//do not know if physics handle will run before grabber
	UPhysicsHandleComponent* PhysicsHandle = nullptr; 
	UInputComponent* InputComponent = nullptr; 

	void Grab();
	void Release();
	void FindPhysicsHandle();
	void SetUpInputComponent();

	//Return the first Actor within reach with a Physics Body 
	FHitResult GetFirstPhysicsBodyInReach() const; 

	//Return the LineTraceEnd 
	FVector GetPlayerReach() const; 

	//Get Players Position in World 
	FVector GetPlayerWorldPos() const;

};
