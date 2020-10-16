#include "stdafx.h"

class CCheats
{
public:
	DWORD pPlayer;
	DWORD pServer;
	void InGame();
	void OutGame();
	void Priority();
	WORD __stdcall ByPassHS();
	void Heartbeat();
	void MEMwrite(void *adr, void *ptr, int size);
	template <typename T>void WriteMEM(void* adr,T Vaule,T *Input = NULL)
	{
		if(Input == 0)
				MEMwrite((void*)adr,(void*)&Vaule,sizeof(T));
		else
				MEMwrite((void*)Input,(void*)adr,sizeof(T));
	}
};

class CPlayer : public CCheats
{
public:
	int m_iSuperJump, m_iNoFallDamage, m_iSpeed, m_iNoBounds, m_iNoSpawnWait, m_iInvisible, m_iWalkUnderWater, m_iOPK, m_iZOPK, m_iSVP, m_iStaminaRefill, m_iSelfkill, m_iSilentWalk, m_iDeadSpinner, m_iNoClip;
	bool m_bPatchInvi;
	CPlayer()
	{
		m_iSuperJump            = 0;
		m_iNoFallDamage			= 0;
		m_iSpeed				= 0;
		m_iNoBounds				= 0;
		m_iNoSpawnWait			= 0;
		m_iInvisible			= 0;
		m_iWalkUnderWater		= 0;
		m_iOPK					= 0;
		m_iZOPK					= 0;
		m_iSVP					= 0;
		m_iStaminaRefill		= 0;
		m_iSelfkill				= 0;
		m_iSilentWalk			= 0;
		m_iDeadSpinner			= 0;
		m_iNoClip               = 0;
	}
};

class CWeapon : CCheats
{
public:
	int  m_iNoRecoil, m_iNoSpread, m_iNoReload, m_iUnlimitedAmmo, m_iShotAs, m_iScope, m_iFastLockOn, m_iPlantAnyWhere, m_iDefuseAnyWhere, m_iQuickDefuse, m_iQuickPlant, m_iBreaklimit, m_iNoWeaponGravity,
		 m_iColorShot, m_iHideWeapon, m_iModeType, m_iNoDelay, m_iArtillery;
	int  m_iOldValueUnlAmmo;
	bool m_bUnlAmmo;
	CWeapon()
	{
		m_iOldValueUnlAmmo      = 0;
		m_iNoRecoil				= 0;
		m_iNoSpread				= 0;
		m_iNoReload				= 0;
		m_iUnlimitedAmmo		= 0;
		m_iShotAs				= 0;
		m_iScope				= 0;
		m_iFastLockOn			= 0;
		m_iPlantAnyWhere		= 0;
		m_iDefuseAnyWhere		= 0;
		m_iQuickDefuse			= 0;
		m_iQuickPlant			= 0;
		m_iBreaklimit			= 0;
		m_iNoWeaponGravity		= 0;
		m_iColorShot			= 0;
		m_iHideWeapon			= 0;
		m_iModeType				= 0;
		m_iNoDelay				= 0;
		m_iArtillery            = 0;
	}
};

class CServer : CCheats
{
public:
	int m_iPremium, m_iDinar, m_iLevel, m_iSlot, m_iGameMode;
	CServer()
	{
		m_iPremium				= 0;
		m_iDinar				= 0;
		m_iLevel				= 0;
		m_iSlot					= 0;
		m_iGameMode             = 0;
	}
};

class CFast : CCheats
{
public:
	int m_iFastHealth, m_iFastAmmo, m_iFastFlag;
	CFast()
	{
		m_iFastHealth			= 0;
		m_iFastAmmo				= 0;
		m_iFastFlag				= 0;
	}
};