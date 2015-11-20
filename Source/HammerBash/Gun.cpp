// Fill out your copyright notice in the Description page of Project Settings.

#include "HammerBash.h"
#include "Gun.h"


// Sets default values
AGun::AGun()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	CurrentAmmo = MagazineSize;
	CurrentReserves = MaxReserves;
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGun::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void  AGun::Reload()
{
	if (!reloading)
	{
		reloading = true;
		ReloadAnimations();
		GetWorldTimerManager().SetTimer(ReloadTimerHandler, this, &AGun::FinishReload, ReloadSpeed, false);
	}
}
void AGun::FinishReload()
{
	reloading = false;
	if (CurrentReserves > MagazineSize - CurrentAmmo) //If their is more ammo avaliable than the amount required to fill the magazine.;
	{
		CurrentReserves -= MagazineSize - CurrentAmmo;  //Fill the magazine and lower the Reserves by the right amount.
		CurrentAmmo = MagazineSize;
	}
	else
	{
		CurrentAmmo += CurrentReserves;	//Else move all the avaliable ammo to the magazine.
		CurrentReserves = 0;
	}

	ReloadAnimations();
}

void AGun::Shoot()
{
	if (CurrentAmmo > 0 && CanFire)
	{
		CurrentAmmo -= 1;

		if (CurrentAmmo == 0)
		{
			Reload();
		}
		ShootPhysics();
		ShootAnimations();
		CanFire = false;
		if (IsFullAuto)
		{				//If the gun is on full auto mode , set the gun to fire again unless the mouse is released.(handled in StopFiring())
			ContinueFiring = true;
		}
		GetWorldTimerManager().SetTimer(EnableFireTimerHandler,this, &AGun::EnableFire, FireRate, false);
	}
}

uint8 AGun::GetAmmo()
{
	return CurrentAmmo;
}

int32 AGun::GetCurrentReserves()
{
	return CurrentReserves;
}

int32 AGun::GetMaxReserves()
{
	return MaxReserves;
}

uint8 AGun::GetMagazineSize()
{
	return MagazineSize;
}
void AGun::EnableFire()
{
	CanFire = true;
	if (ContinueFiring)
	{
		Shoot();
	}
}
void AGun::StopFiring()
{
	ContinueFiring = false;
}



