// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Gun.generated.h"

UCLASS()
class HAMMERBASH_API AGun : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;


	UFUNCTION(BlueprintCallable,category = "Gun")
		void Reload();

	UFUNCTION(BlueprintCallable, category = "Gun")
		void Shoot();

	UFUNCTION(BlueprintCallable, category = "Gun")
		uint8 GetAmmo();

	UFUNCTION(BlueprintCallable, category = "Gun")
		int32 GetCurrentReserves();

	UFUNCTION(BlueprintCallable, category = "Gun")
		int32 GetMaxReserves();

	UFUNCTION(BlueprintCallable, category = "Gun")
		uint8 GetMagazineSize();

	UFUNCTION(BlueprintCallable, category = "Gun")
		void StopFiring();

	UFUNCTION(BlueprintImplementableEvent)
		void ShootAnimations();

	UFUNCTION(BlueprintImplementableEvent)
		void ReloadAnimations();

	UFUNCTION(BlueprintImplementableEvent)
		void ShootPhysics();


private:

	UPROPERTY(EditDefaultsOnly)
		uint8 damage = 0;

	UPROPERTY()
		uint8 CurrentAmmo;

	UPROPERTY(EditDefaultsOnly)
		int8 MagazineSize = 0;

	UPROPERTY()
		int32 CurrentReserves;

	UPROPERTY(EditDefaultsOnly)
		uint32 MaxReserves = 0;

	UPROPERTY(EditDefaultsOnly)
		float ReloadSpeed;

	UPROPERTY(EditDefaultsOnly)
		float FireRate;

	UPROPERTY(EditDefaultsOnly)
		bool IsFullAuto = false;

	bool CanFire = true;

	void EnableFire();

	bool ContinueFiring = false;

	bool reloading = false;

	void FinishReload();

	FTimerHandle EnableFireTimerHandler;
	FTimerHandle ReloadTimerHandler;

};
