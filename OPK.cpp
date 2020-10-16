#include "stdafx.h"
#include "Structs.h"
#include "Addresses.h"
#include "Cheats.h"

extern struct CBase* p_Player;
extern sCPlayerInfo* GetGlobalInfo( int dwPlayerIndex );
extern CPlayer Player;

void OPKThread()
{
	while(1)
	{
		if ( Player.pPlayer !=0 )
		{
			if ( Player.m_iOPK )
			{
				for(int i = 0; i < 32; i++)
				{
					sCPlayer* pPlayer = p_Player->pGlobal[i];    
					pPlayer->PosX = 20;
					pPlayer->PosY = 20;
					pPlayer->PosZ = 20; 
				}
			}

			if ( Player.m_iZOPK )
			{
				for (int index = 0; index < 32; index++)
				{
					sCPlayerInfo *pInfo = GetGlobalInfo(index);
					sCPlayer* pPlayer = p_Player->pGlobal[index];
					if (pInfo && pPlayer)
					{
						sCPlayerInfo *pLocalInfo = GetGlobalInfo(p_Player->pLocal->index);
						if (pInfo->TEAM != 0)
						{
							if (pInfo->HEALTH > 0)
							{
								pPlayer->PosX = (p_Player->pLocal->PosX + 145);
								pPlayer->PosY = (p_Player->pLocal->PosY);
								pPlayer->PosZ = (p_Player->pLocal->PosZ);
							}
						}
					}
				}
			}

			if ( Player.m_iSVP )
			{
				for(int i = 0; i < 32; i++)
				{
					sCPlayer* pPlayerA = p_Player->pGlobal[i];    
					pPlayerA->PosX=(i*50);
					pPlayerA->PosY=0;
					pPlayerA->PosZ=0;
				}
			}
		}
	}
}