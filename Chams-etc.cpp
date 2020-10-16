#include "stdafx.h"
#include "Colors.h"
#include "Addresses.h"

int PlayerChams = 0, PlayerChamsColorA = 0, PlayerChamsColorB = 0, VehicleChams = 0 , VehicleChamsColorA = 0 , VehicleChamsColorB = 0, WallHack = 0, NoFog = 0, FillMode = 0, Fullbright = 0, Crosshair = 0;
bool Color  = true;
LPDIRECT3DTEXTURE9 Red,Green,Blue,Yellow,Purple,Pink,Orange,Grey,Cyan,Black,White;

typedef HRESULT ( APIENTRY* DrawIndexedPrimitive_t ) (  LPDIRECT3DDEVICE9 pDevice, DWORD p0, DWORD p1, DWORD p2, DWORD p3, DWORD p4, DWORD p5 );
extern DrawIndexedPrimitive_t     pDrawIndexedPrimitive;

HRESULT GenerateTexture(IDirect3DDevice9 *pD3Ddev, IDirect3DTexture9 **ppD3Dtex, DWORD colour32)
{
    if(FAILED(pD3Ddev->CreateTexture(8, 8, 1, 0, D3DFMT_A4R4G4B4, D3DPOOL_MANAGED, ppD3Dtex, NULL)))
        return E_FAIL;
    
    WORD colour16 = ((WORD)((colour32>>28)&0xF)<<12)
	            	|(WORD)(((colour32>>20)&0xF)<<8)
	             	|(WORD)(((colour32>>12)&0xF)<<4)
                 	|(WORD)(((colour32>>4)&0xF)<<0);

    D3DLOCKED_RECT d3dlr;    
    (*ppD3Dtex)->LockRect(0, &d3dlr, 0, 0);
    WORD *pDst16 = (WORD*)d3dlr.pBits;

    for(int xy=0; xy < 8*8; xy++)
        *pDst16++ = colour16;

    (*ppD3Dtex)->UnlockRect(0);

    return S_OK;
}

void D3DCheats( LPDIRECT3DDEVICE9 pDevice, DWORD p0, DWORD p1, DWORD p2, DWORD p3, DWORD p4, DWORD p5 )
{
	LPDIRECT3DVERTEXBUFFER9 Stream_Data;
	UINT Offset = 0;
	UINT Stride = 0;

	if ( pDevice->GetStreamSource ( 0, &Stream_Data, &Offset, &Stride ) == D3D_OK )
	Stream_Data->Release();

	DWORD dwOldZEnable = D3DZB_TRUE;
	if( Color == true )
	{
		GenerateTexture(pDevice, &White,  aWhite);
		GenerateTexture(pDevice, &Red,    aRed);
		GenerateTexture(pDevice, &Green,  aGreen);
		GenerateTexture(pDevice, &Blue,   aBlue);
		GenerateTexture(pDevice, &Black,  aBlack);
		GenerateTexture(pDevice, &Purple, aPurple);
		GenerateTexture(pDevice, &Grey,   aGrey);
		GenerateTexture(pDevice, &Yellow, aYellow);
		GenerateTexture(pDevice, &Orange, aOrange);
		GenerateTexture(pDevice, &Cyan,   aCyan);
		GenerateTexture(pDevice, &Pink,   aPink);
		Color = false;
	}

	if( WallHack == 1 )
	{
		if(Stride == 36)
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
		}
		else
		{
			pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
		}
	}

	if( NoFog == 1 )
	{
		pDevice->SetRenderState(D3DRS_FOGENABLE, false);
	}

	if( Fullbright == 1 )
	{
		pDevice->SetRenderState(D3DRS_LIGHTING, false);
	}

	switch (FillMode)
	{
	case(1):
		if (Stride == 32)
		{
			DWORD pPlayer = *reinterpret_cast<DWORD *>(ADR_PlayerPointer);
			if(pPlayer != 0)
			{
				pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
			}
		}
		break;
	case(2):
		if(Stride == 32) 
		{
			DWORD pPlayer = *reinterpret_cast<DWORD *>(ADR_PlayerPointer);
			if(pPlayer != 0)
			{
				pDevice->SetRenderState(D3DRS_FILLMODE,D3DFILL_POINT); 
			}
		}
	}

	if ( PlayerChams == 1 )
	{
		if ( Stride == 36 || Stride == 32 )
		{
			if ( PlayerChamsColorA ) { pDevice->SetRenderState(D3DRS_ZENABLE,0); }
			if ( PlayerChamsColorA == 1 ) { pDevice->SetTexture(NULL,Red); }
			if ( PlayerChamsColorA == 2 ) { pDevice->SetTexture(NULL,Green); }
			if ( PlayerChamsColorA == 3 ) { pDevice->SetTexture(NULL,Blue); }
			if ( PlayerChamsColorA == 4 ) { pDevice->SetTexture(NULL,Orange); }
			if ( PlayerChamsColorA == 5 ) { pDevice->SetTexture(NULL,Purple); }
			if ( PlayerChamsColorA == 6 ) { pDevice->SetTexture(NULL,Pink); }
			if ( PlayerChamsColorA == 7 ) { pDevice->SetTexture(NULL,Black); }
			pDrawIndexedPrimitive(pDevice, p0, p1, p2, p3, p4, p5);

			if ( PlayerChamsColorB ) { pDevice->SetRenderState(D3DRS_ZENABLE,1); }
			if ( PlayerChamsColorB == 1 ) { pDevice->SetTexture(NULL,Red); }
			if ( PlayerChamsColorB == 2 ) { pDevice->SetTexture(NULL,Green); }
			if ( PlayerChamsColorB == 3 ) { pDevice->SetTexture(NULL,Blue); }
			if ( PlayerChamsColorB == 4 ) { pDevice->SetTexture(NULL,Orange); }
			if ( PlayerChamsColorB == 5 ) { pDevice->SetTexture(NULL,Purple); }
			if ( PlayerChamsColorB == 6 ) { pDevice->SetTexture(NULL,Pink); }
			if ( PlayerChamsColorB == 7 ) { pDevice->SetTexture(NULL,Black); }
		}
	}

	if( VehicleChams == 1 )
	{
		if(Stride == 44)
		{
			if( VehicleChamsColorA) pDevice->SetRenderState(D3DRS_LIGHTING,false);
			if( VehicleChamsColorA) pDevice->SetRenderState(D3DRS_ZENABLE,false);
			if( VehicleChamsColorA == 1){pDevice->SetTexture(0, Red);}
			if( VehicleChamsColorA == 2){pDevice->SetTexture(0, Green);}
			if( VehicleChamsColorA == 3){pDevice->SetTexture(0, Blue);}
			if( VehicleChamsColorA == 4){pDevice->SetTexture(0, Orange);}
			if( VehicleChamsColorA == 5){pDevice->SetTexture(0, Purple);}
			if( VehicleChamsColorA == 6){pDevice->SetTexture(0, Pink);}
			if( VehicleChamsColorA == 7){pDevice->SetTexture(0, Black);}
			pDrawIndexedPrimitive(pDevice, p0, p1, p2, p3, p4, p5);

			if( VehicleChamsColorB)pDevice->SetRenderState(D3DRS_LIGHTING,false);
			if( VehicleChamsColorB)pDevice->SetRenderState(D3DRS_ZENABLE,true);
			if( VehicleChamsColorB == 1){pDevice->SetTexture(0, Red);}
			if( VehicleChamsColorB == 2){pDevice->SetTexture(0, Green);}
			if( VehicleChamsColorB == 3){pDevice->SetTexture(0, Blue);}
			if( VehicleChamsColorB == 4){pDevice->SetTexture(0, Orange);}
			if( VehicleChamsColorB == 5){pDevice->SetTexture(0, Purple);}
			if( VehicleChamsColorB == 6){pDevice->SetTexture(0, Pink);}
			if( VehicleChamsColorB == 7){pDevice->SetTexture(0, Black);}
		}	
	}
}