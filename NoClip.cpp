#include "stdafx.h"
#include "Structs.h"
#include "Addresses.h"
#include "Cheats.h"
#include <math.h>
#include <d3dx9math.h>

extern CPlayer Player;
extern struct CBase* p_Player;
extern CLocal* p_Local;

bool InitNoClip = false;

D3DXVECTOR3 getPos()
{
	D3DXVECTOR3 Pos;
	Pos.x = *reinterpret_cast<float*>(Player.pPlayer+ADR_OFS_X);
	Pos.y = *reinterpret_cast<float*>(Player.pPlayer+ADR_OFS_Y);
	Pos.z = *reinterpret_cast<float*>(Player.pPlayer+ADR_OFS_Z);
	return Pos;
}

D3DXVECTOR2 getView()
{
 return (D3DXVECTOR2(p_Local->Yaw, p_Local->Pitch));
}

D3DXVECTOR2 getView2()
{
	D3DXVECTOR2 View;
	View.x =  p_Player->pLocal->ViewX;
	View.y = p_Player->pLocal->ViewY;
	return View;
}

void setPos(D3DXVECTOR3 Pos)
{
	*reinterpret_cast<float*>(Player.pPlayer+ADR_OFS_X) = Pos.x;
	*reinterpret_cast<float*>(Player.pPlayer+ADR_OFS_Y) = Pos.y;
	*reinterpret_cast<float*>(Player.pPlayer+ADR_OFS_Z) = Pos.z;
}

void NoClipCheat()
{
	D3DXVECTOR3 vPos;
	D3DXVECTOR2 vView;
	float       fCos;
	float       fSin;
	float       fSpeed = 20.0f;

	if ( InitNoClip == false )
	{
		p_Local = (CLocal*)*(DWORD*)(ADR_VIEWANGELS);
		InitNoClip = true;
	}
	while(1)
	{
		if ( InitNoClip == true && Player.m_iNoClip == 1 && !Player.pPlayer)
		{
			vPos  = getPos();
			vView = getView();
			fCos  = cosf( vView.x );
			fSin  = sinf( vView.x );

			if(GetAsyncKeyState(VK_SPACE))//Hoch
			{
			
				vPos.y += fSpeed;
				break;
			}        

			else if(GetAsyncKeyState(VK_CONTROL))//Runter
			{
			
				vPos.y -= fSpeed;
				break;
			}
                
			else if(GetAsyncKeyState(0x57))//W Vorne
			{
				// ... If foward height inc/dec based on sine of pitch
				vPos.y += sinf(vView.y);
                    
				// ... x adds onto sine, z adds onto cosine
				vPos.x += fSin;
				vPos.z += fCos;
				break;
			}
                
			else if(GetAsyncKeyState(0x53))//S Hinten
			{
				//Zurück
				vPos.y -= sinf(vView.y);
				vPos.x -= fSin;
				vPos.z -= fCos;
				break;
			}

			else if(GetAsyncKeyState(0x41))//A Links
			{
				// ... If Side step adds onto sine/cosine of yaw added with 90 degrees
				vPos.x += sinf( vView.x + M_PI/2 );
				vPos.z += cosf( vView.x + M_PI/2 );
				break;
			}
                
			else if(GetAsyncKeyState(0x44))//D Rechts
			{
				vPos.x += sinf( vView.x - M_PI/2 );
				vPos.z += cosf( vView.x - M_PI/2 );
				break;
			}
			setPos(vPos);
			Sleep(20);
	
		}
		Sleep(20);
	}
}



/*
#define RADTODEG(radian) ((180.0f / M_PI) * (radian))
float CalculateYaw(INT dwIndex)
{
	FLOAT ViewX = p_Player->pGlobal[dwIndex]->ViewX - p_Player->pLocal->ViewX;
	FLOAT ViewZ = p_Player->pGlobal[dwIndex]->ViewZ - p_Player->pLocal->ViewZ;

	return float(RADTODEG(atan2(ViewZ,ViewX))-90);
}
float CalculatePitch(INT dwIndex)
{

	FLOAT AngelX = p_Player->pGlobal[dwIndex]->ViewX - p_Local->PosX;
	FLOAT AngelY = p_Player->pGlobal[dwIndex]->ViewY - p_Local->PosY;
	FLOAT AngelZ = p_Player->pGlobal[dwIndex]->ViewZ - p_Local->PosZ;

    return float( -1 * (atan( AngelY / sqrt( AngelX * AngelX + AngelZ * AngelZ )) * 180 / M_PI ) );
}
p_Local->Pitch = CalculatePitch(GetNearestPlayer());
p_Local->Yaw = CalculateYaw(GetNearestPlayer());

if ( InitNoClip == false )
	{
		p_Local = (CLocal*)*(DWORD*)(ADR_VIEWANGELS);
		InitNoClip = true;
	}
	else if ( InitNoClip == true )
	{
		if ( Player.m_iNoClip )
		{
			NoClipCheat();
			//Gravity = 1;
			//WTW = 1;
		}
	}
*/
