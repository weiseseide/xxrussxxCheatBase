#include "Cheats.h"
#include "Addresses.h"
#include "WeaponBinder.h"
using namespace std;

//Erzeuge Klassen
CPlayer Player;
CServer Server;
CWeapon Weapon;
CFast   Fast;

void CCheats::MEMwrite(void *adr, void *ptr, int size)
{
	DWORD dwback;
	VirtualProtect(adr,size,PAGE_EXECUTE_READWRITE, &dwback);
	memcpy(adr,ptr,size);
	VirtualProtect(adr,size,dwback, &dwback);
}

void CCheats::InGame()
{
	pPlayer = *reinterpret_cast<DWORD *>(ADR_PlayerPointer);
	pServer = *reinterpret_cast<DWORD *>(ADR_ServerPointer);

	if(pPlayer != 0)
	{
		/***************Start-of-Player***************/
		if ( Player.m_iSuperJump > 0 )
        {
			if(GetAsyncKeyState(VK_CONTROL) &0x8000)
			{
				if( Player.m_iSuperJump == 1 )
				{
					*reinterpret_cast<float*>(pPlayer+ADR_OFS_Z) += 75;
				}
				else{
					*reinterpret_cast<float*>(pPlayer+ADR_OFS_Z)  = (Player.m_iSuperJump - 1)*1000 ;
				}
			}
        }

		if ( Player.m_iNoFallDamage == 1 )
        {
			Player.m_iSelfkill = 0;
			*reinterpret_cast<float*>(pPlayer+ADR_OFS_NFD) = -20000;
        }

		if( Player.m_iSpeed )
		{
			*reinterpret_cast<float*>(pPlayer + ADR_OFS_PlayerSpeed) = Player.m_iSpeed*-100;
		}

		if( Player.m_iNoBounds == 1 )
        {
			*reinterpret_cast<int*>(ADR_NoBounds1) = 0;
			*reinterpret_cast<int*>(ADR_NoBounds2) = 0;
			*reinterpret_cast<int*>(ADR_NoBounds3) = 0;
        }

		if ( Player.m_iNoSpawnWait == 1 )
		{
			*reinterpret_cast<int*>(ADR_NoSpawn1) = 1;
			*reinterpret_cast<int*>(ADR_NoSpawn2) = 1;
			*reinterpret_cast<int*>(ADR_NoSpawn3) = 1;
		}

		if ( Player.m_iWalkUnderWater == 1 )
		{
			*reinterpret_cast<int*>(ADR_WUW) = 0;
		}

		if ( Player.m_iStaminaRefill == 1 )
		{
			*reinterpret_cast<int*>(ADR_StaminaRefill) = 1000;
		}

		if( Player.m_iSelfkill == 1 )
		{
			Player.m_iNoFallDamage = 0;
			*reinterpret_cast<int*>(pPlayer+ADR_OFS_NFD) += 999;
		}

		if( Player.m_iSilentWalk == 1 )
		{
			*reinterpret_cast<int*>(ADR_SilentWalk) = 0;
		}
		
		if( Player.m_iDeadSpinner == 1)
		{
			*reinterpret_cast<float*>(ADR_DeadSpinner) = 400.0f;
		}
		else
		{
			*reinterpret_cast<float*>(ADR_DeadSpinner) = 2.0e-2;
		}

		/***************End-of-Player***************/

		/***************Start-of-Weapon***************/

		if ( Weapon.m_iNoRecoil )
		{
			*reinterpret_cast<float*>(pPlayer + ADR_OFS_NoRecoil1) = 0;
			*reinterpret_cast<float*>(pPlayer + ADR_OFS_NoRecoil2) = 0;
			*reinterpret_cast<float*>(pPlayer + ADR_OFS_NoRecoil3) = 0;
		}

		if ( Weapon.m_iNoSpread )
		{
			*reinterpret_cast<float*>(pPlayer + ADR_OFS_NOSPREAD) = 1;
		}
		else
		{
			*reinterpret_cast<float*>(pPlayer + ADR_OFS_NOSPREAD) = 0;
		}

		if( Weapon.m_iNoReload == 1 )
		{
			*reinterpret_cast<float*>(pPlayer+ADR_OFS_NORELOAD) = 1.0F;
		}
		
		if( Weapon.m_iUnlimitedAmmo == 1 && !Weapon.m_bUnlAmmo)
        {
			//oldValueUnlAmmo = *reinterpret_cast<int*>(ADR_UnlAmmo);
			//*reinterpret_cast<DWORD*>(ADR_UnlAmmo) = 0;
            MEMwrite((void *)(ADR_ASM_UnlAmmo),(BYTE *)"\xC3",1);
			Weapon.m_bUnlAmmo = true;
        }
		else if ( Weapon.m_iUnlimitedAmmo == 0 && Weapon.m_bUnlAmmo)
        {
			//*reinterpret_cast<DWORD*>(ADR_UnlAmmo) = oldValueUnlAmmo;
           MEMwrite((void *)(ADR_ASM_UnlAmmo),(BYTE *)"\x56",1);
		   Weapon.m_bUnlAmmo = false;
		}

		if( Weapon.m_iShotAs > 0 )//8 , 72 83
		{
			*reinterpret_cast<int*>(pPlayer+ADR_OFS_Weapon3) = Weapon.m_iShotAs-1;//test
			*reinterpret_cast<int*>(pPlayer+ADR_OFS_Weapon1) = Weapon.m_iShotAs-1;//test
			*reinterpret_cast<int*>(pPlayer+ADR_OFS_Weapon2) = Weapon.m_iShotAs-1;
		}

		if( Weapon.m_iScope == 1 )
		{
			if(GetAsyncKeyState(VK_RBUTTON))
			{
				*reinterpret_cast<int*>(ADR_Scope) = 1;
			}
			else
			{
				*reinterpret_cast<int*>(ADR_Scope) = 5;
			}
		}

		if( Weapon.m_iFastLockOn == 1 )
		{
			*reinterpret_cast<int*>(ADR_FastLockOn) = 1;
		}
				
		if( Weapon.m_iBreaklimit == 1 )
		{
			*reinterpret_cast<int*>(ADR_Breaklimit) += 1000;
		}

		if( Weapon.m_iNoWeaponGravity == 1 )
		{
			*reinterpret_cast<int*>(ADR_WeaponGravity) = 0;
		}
		

		if( Weapon.m_iColorShot == 1 )
		{
			*reinterpret_cast<int*>(ADR_ColorShot) = 3800;
		}
		else
		{
			*reinterpret_cast<int*>(ADR_ColorShot) = 0;
		}

		if( Weapon.m_iHideWeapon == 1 )
		{
			*reinterpret_cast<int*>(ADR_HideWeapon) = 0;
		}

		if( Weapon.m_iArtillery == 1 )
		{
			MEMwrite((void *)ADR_ASM_Artillery0, (void *)"\x90\x90", 2);
			MEMwrite((void *)ADR_ASM_Artillery1, (void *)"\x90\x90", 2);
			MEMwrite((void *)ADR_ASM_Artillery2, (void *)"\x90\x90\x90\x90\x90", 5);
			MEMwrite((void *)ADR_ASM_Artillery3, (void *)"\xEB", 1);
			//MEMwrite((void *)ADR_ASM_Artillery4, (void *)"\xEB", 1); //not rly usefull
			MEMwrite((void *)ADR_ASM_Artillery5, (void *)"\xEB", 1);
			MEMwrite((void *)ADR_ASM_Artillery6, (void *)"\xEB", 1);
			MEMwrite((void *)ADR_ASM_Artillery7, (void *)"\x90\x90\x90\x90\x90\x90", 6);
		}/*
		else if( Weapon.m_iArtillery == 0 )
		{
			MEMwrite((void *)ADR_ASM_Artillery0, (void *)"\x75\x49", 2);
			MEMwrite((void *)ADR_ASM_Artillery1, (void *)"\x75\x12", 2);
			MEMwrite((void *)ADR_ASM_Artillery2, (void *)"\xE9\x49\x02\x00\x00", 5);
			MEMwrite((void *)ADR_ASM_Artillery3, (void *)"\x7A\x72", 2);
			MEMwrite((void *)ADR_ASM_Artillery4, (void *)"\x75\x72", 2); //not rly usefull
			MEMwrite((void *)ADR_ASM_Artillery5, (void *)"\x74", 1);
			MEMwrite((void *)ADR_ASM_Artillery6, (void *)"\x7D\x72", 2);
			MEMwrite((void *)ADR_ASM_Artillery7, (void *)"\x0F\x85\x93\x00\x00\x00", 6);
		}*/
		
		/***************End-of-Weapon***************/
		
		/***************Start-of-Fast***************/

		if( Fast.m_iFastHealth == 1 )
		{
			*reinterpret_cast<float*>(ADR_FastHealth) = 500;
		}

		if( Fast.m_iFastAmmo == 1 )
		{
			*reinterpret_cast<float*>(ADR_FastAmmo) = 500;
		}

		if( Fast.m_iFastFlag == 1 )
		{
			*reinterpret_cast<float*>(ADR_FastFlag) = -50;
		}
		/***************End-of-Fast***************/
	}
}

void CCheats::OutGame()
{
	if(pServer != 0)
	{
		/***************Start-of-Player***************/
		if( Server.m_iPremium )
		{
            *reinterpret_cast<int*>(pServer+ADR_OFS_Premium1) = Server.m_iPremium;
            *reinterpret_cast<int*>(pServer+ADR_OFS_Premium2) = Server.m_iPremium;
		}

		if( Server.m_iDinar == 1 )
		{
			*reinterpret_cast<long*>(pServer+ADR_OFS_DINAR) = 999999999;
		}

		if( Server.m_iLevel )
		{
			*reinterpret_cast<long*>(pServer+ADR_OFS_LEVEL) = (Server.m_iLevel)*1000;
		}
		
		if ( Server.m_iSlot == 1 )
		{
			*reinterpret_cast<int*>(pServer+ADR_OFS_Slot5) = 1;
			*reinterpret_cast<int*>(pServer+ADR_OFS_Slot6) = 1;
			*reinterpret_cast<int*>(pServer+ADR_OFS_Slot7) = 1;
			*reinterpret_cast<int*>(pServer+ADR_OFS_Slot8) = 1;
		}
		/***************End-of-Server***************/

		/***************Start-of-SerPlayer***************/

		if  ( Player.m_iInvisible == 1 && Player.m_bPatchInvi == false )
		{
			*reinterpret_cast<long*>(pServer+ADR_OFS_Invisible) -= 2;
			Player.m_bPatchInvi = true;
		}

		if ( Player.m_iInvisible == 0 && Player.m_bPatchInvi == true )
		{
			*reinterpret_cast<long*>(pServer+ADR_OFS_Invisible) +=2;
			Player.m_bPatchInvi = false;
		}
		/***************End-of-SerPlayer***************/
	}
}

void CCheats::Priority()//ToDo
{
	//Stuff with higher priority
	if(pServer != 0)
	{
		find_weapons();
		if (var[2] > 0){ WPNget( var[1]-1,0); WPNput( var[1]-1,0, var[2]-1);}
		if (var[3] > 0){ WPNget( var[1]-1,1); WPNput( var[1]-1,1, var[3]-1);}
		if (var[4] > 0){ WPNget( var[1]-1,2); WPNput( var[1]-1,2, var[4]-1);}
		if (var[5] > 0){ WPNget( var[1]-1,3); WPNput( var[1]-1,3, var[5]-1);}
		if (var[6] > 0){ WPNget( var[1]-1,4); WPNput( var[1]-1,4, var[6]-1);}
		if (var[7] > 0){ WPNget( var[1]-1,5); WPNput( var[1]-1,5, var[7]-1);}
		if (var[8] > 0){ WPNget( var[1]-1,6); WPNput( var[1]-1,6, var[8]-1);}
		if (var[9] > 0){ WPNget( var[1]-1,7); WPNput( var[1]-1,7, var[9]-1);}
	}

	if(pPlayer != 0)
	{
		if( Weapon.m_iNoDelay == 1 )
		{
			*reinterpret_cast<int*>(ADR_OFS_NODELAY) |= (1 << 10);
		}

		if( Weapon.m_iPlantAnyWhere == 1 )
		{
			*reinterpret_cast<int*>(ADR_PlantAnyWhere) = 1;
		}
		
		if( Weapon.m_iDefuseAnyWhere == 1 )
		{
			*reinterpret_cast<int*>(ADR_DefuseAnyWhere) = 1;
		}

		if( Weapon.m_iQuickPlant == 1 )
		{
			*reinterpret_cast<int*>(ADR_QuickPlant) = 100;
		}

		if( Server.m_iGameMode > 0 )
		{
			*reinterpret_cast<int*>(ADR_GameMode) = Server.m_iGameMode;
		}
	}
}