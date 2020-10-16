#include "stdafx.h"
#include "Addresses.h"

int var[17];

DWORD *serverptr = (DWORD*)ADR_ServerPointer;

struct t_weap
{
	char unknown[12];
	int  id;
	char lname[32];
	char sname1[32];
	char sname2[32];
	char sname3[32];
	char data[5336];
};
 
struct t_slot
{
	BYTE  enab;      //0 // always 1 :S
	BYTE  type;      //1 // 44 standard weapon?? 48-52
    BYTE  id;        //2 // weaponno 1-101, when bought it is empty??
	BYTE  novaule;
    char  dum1[33];  //4 // empty
    char  sname[16]; //25// short name like DC01 10h
    char  dum2[19];  //35// empty 13h
    DWORD adr_weap;  //48// weapon address of the inventory
    DWORD adr_inv;   //4C// filled when a bought weapon is used
};

struct t_invslot
{
    BYTE  enab;      //0 // always 1 :S
    BYTE  type;      //1 // 44 standard weapon?? 48-52
    BYTE  id;        //2 // weaponno 1-101, when bought it is empty??
	BYTE  novaule;
    char  dum1[33];  //4 // empty
    char  sname[16]; //25// short name like DC01 10h
    char  dum2[19];  //35// empty 13h
    DWORD adr_weap;  //48// weapon address of the inventory
    DWORD adr_inv;   //4C// filled when a bought weapon is used
};

DWORD dwADR_WEAPONBASE                    =       0xB38E30;
DWORD dwOFS_SLOTBASE                      =       0x9E040;
DWORD dwOFS_PLAYERSLOT                    =       0xB8368;



t_weap          *pweap[2003];    // pointers to all inventory weapons
t_slot          *pslot[8];       // 8 slots
t_invslot       *pinvoslot[8];   // 8 slots
 
t_invslot *WPNinvslotadr(int pclass, int slot)
{
    return (t_invslot *)(*serverptr+dwOFS_SLOTBASE+(pclass*0x280)+(slot*0x50));
}

t_slot *WPNslotadr(int pclass, int slot)
{
    return (t_slot *)(*serverptr+dwOFS_SLOTBASE+(pclass*0x280)+(slot*0x50));
}


void WPNput(int pclass, int slot, int weappon)
{
    t_slot   *pslot;
    if (weappon<0 || pweap[weappon] == 0) return;
 
    pslot=WPNslotadr(pclass,slot);
    pslot->adr_weap=(DWORD)pweap[weappon];
    strcpy_s(pslot->sname, pweap[weappon]->lname);
    pslot->id = weappon;   
    pslot->type = 0x44;
    pslot->enab = 1;  
}

void find_weapons(void)
{
    DWORD *p_weapbase, *baseadr;
    t_weap *weap;
 
    for (int i=0; i<2003; i++)pweap[i]=0;
    p_weapbase=(DWORD *)dwADR_WEAPONBASE;
    baseadr=(DWORD*)(*p_weapbase);
 
    for (int b=0;b<2003;b++)
    {
        weap=(t_weap *)(*baseadr);
        if (weap)pweap[b]=weap;
        baseadr++;
    }
}

int WPNget(int pclass, int slot)
{
    t_slot  *pslot;
    pslot=WPNslotadr(pclass,slot);
    return pslot->id;
}