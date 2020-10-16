#include "stdafx.h"
#include "Addresses.h"
#include "Cheats.h"
#include "licence.h"

CCheats CheatTools;
CLicence Userlicence;

void CCheats::Heartbeat()
{
	while(1)
	{
		
		while(!pServer)
		{
			CheatTools.MEMwrite((void*)(ADR_WarRockCheck2), (BYTE*)"\xC3", 1);		
			CheatTools.MEMwrite((void*)(ADR_WarRockCheck3),(BYTE*)"\xEB", 1); 
			for(int i = 0;i < 1000 && !pServer;i++)
			{
				Sleep(93000);
			}
			CheatTools.MEMwrite((void*)(ADR_WarRockCheck2), (BYTE*)"\x55", 1);
			for(int i = 0;i < 1000 && !pServer;i++)
			{
				Sleep(93000);
			}
		}
	}
		//MEMwrite((void*)(ADR_WarRockCheck3),(BYTE*)"\x74", 1); 
}


WORD __stdcall CCheats::ByPassHS()
{
	#define ADR_HSCallBack1	        0x009B710
	#define ADR_HSCallBack2	        0x000B0B8
	#define NanoCheck1 				0x002E3FA
	#define NanoCheck2				0x0046C5F

	while(!GetModuleHandleA("EhSvc.dll"));
	DWORD ptrEhSvc = (DWORD)GetModuleHandleA("EhSvc.dll");

	if(ptrEhSvc != 0)
	{
		// == EhSvc.dll
		CheatTools.MEMwrite((void*)(ptrEhSvc + ADR_HSCallBack1), (BYTE*)"\xC3", 1); 
	    CheatTools.MEMwrite((void*)(ptrEhSvc + ADR_HSCallBack2), (BYTE*)"\x74", 1);
		CheatTools.MEMwrite((void*)(ptrEhSvc + NanoCheck1),      (BYTE*)"\xB8\x00\x00\x00\x00", 5); 
		CheatTools.MEMwrite((void*)(ptrEhSvc + NanoCheck2),      (BYTE*)"\x03\xD2", 2); 
		Userlicence.checkLicence();
		Heartbeat();
	}
	return true;
}