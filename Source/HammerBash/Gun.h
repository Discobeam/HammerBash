// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class HAMMERBASH_API AGun : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	AGun();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input

	UFUNCTION(BlueprintCallable, category = "Gun")
		void Reload();

	UFUNCTION(BlueprintCallable,Server , WithValidation, Reliable, category = "Gun")
		void Shoot();

	UFUNCTION(BlueprintCallable, category = "Gun")
		int32 GetAmmo();

	UFUNCTION(BlueprintCallable, category = "Gun")
		int32 GetCurrentReserves();

	UFUNCTION(BlueprintCallable, category = "Gun")
		int32 GetMaxReserves();

	UFUNCTION(BlueprintCallable, category = "Gun")
		int32 GetMagazineSize();

	UFUNCTION(BlueprintCallable, category = "Gun")
		void SetupCameraPosition(FVector CameraPosition, FRotator CameraRotation);

	UFUNCTION(BlueprintCallable, category = "Gun")
		void SetupGun(int32 NewAmmo ,int32 NewReserves);

	UFUNCTION(BlueprintCallable, category = "Gun")
		void StopFiring();

	UFUNCTION(BlueprintImplementableEvent)
		void ShootAnimations();

	UFUNCTION(BlueprintImplementableEvent)
		void ReloadAnimations();

	UFUNCTION(BlueprintImplementableEvent)
		void ShootPhysics(FVector CameraPosition, FRotator CameraRotation, int32 damage);

	UPROPERTY(BlueprintReadWrite, category = "Gun")
		bool IsEquiped = false;

	UPROPERTY(EditDefaultsOnly)
		int32 MaxReserves = 0;

private:

	UPROPERTY(EditDefaultsOnly)
		int32 damage = 0;

	UPROPERTY()
		int32 CurrentAmmo;

	UPROPERTY(EditDefaultsOnly)
		int32 MagazineSize = 0;

	UPROPERTY()
		int32 CurrentReserves;

	UPROPERTY(EditDefaultsOnly)
		float ReloadSpeed;

	UPROPERTY(EditDefaultsOnly)
		float FireRate;

	UPROPERTY(EditDefaultsOnly)
		bool IsFullAuto = false;


	FVector CurrentCameraPosition;

	FRotator CurrentCameraRotation;

	bool CanFire = true;

	void EnableFire();

	bool ContinueFiring = false;

	bool reloading = false;

	void FinishReload();

	FTimerHandle EnableFireTimerHandler;
	FTimerHandle ReloadTimerHandler;

};
