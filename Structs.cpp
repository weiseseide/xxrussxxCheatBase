#include "stdafx.h"
#include "Addresses.h"
#include "Structs.h"

CBase* p_Player = (CBase*)ADR_PlayerPointer;
CMatrix* p_Matrix = (CMatrix*)ADR_MatrixPTR;

sCPlayerInfo* GetGlobalInfo( int dwPlayerIndex )
{
	if( dwPlayerIndex > 32 ) return 0;
	return (sCPlayerInfo*)(ADR_BasePTR+(ADR_OFS_GlobalSize*dwPlayerIndex));
}

INT GetLocalInfo()
{
	DWORD *dwServPtr = (DWORD*)ADR_ServerPointer;
	return *(INT*)((*dwServPtr)+ADR_OFS_LocalSize);
}

FLOAT GetDistance(sCPlayer* pLocal, sCPlayer* pGLobal)
{
    FLOAT angle[3];
    angle[0] = pGLobal->ViewX - pLocal->PosX;
    angle[1] = pGLobal->ViewY - pLocal->PosY;
    angle[2] = pGLobal->ViewZ - pLocal->PosZ;
    return sqrt(angle[0]*angle[0]+angle[1]*angle[1]+angle[2]*angle[2]);
}

