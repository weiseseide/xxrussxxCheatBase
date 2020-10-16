#ifndef _STRUCTS_H
#define _STRUCTS_H
#define _USE_MATH_DEFINES

#include <math.h>
#include <d3dx9math.h>
/*
struct sCPlayer
{
    CHAR xXRusSXx1[0xC4CC];//0x00
    BYTE PlayerState;//0xC4CC
    CHAR xXRusSXx2[0x3CDD];//0xC4CD
    FLOAT Pitch;//0x101A8
    CHAR xXRusSXx3[0x18];//0x101AC
    FLOAT Yaw;//0x101C4
    CHAR xXRusSXx4[0xC];//0x101C8
    FLOAT ViewX;//0x101D4
    FLOAT ViewY;//0x101DC
    FLOAT ViewZ;//0x101D8
    CHAR xXRusSXx6[0x124];//0x101DC
    FLOAT PosX;//0x10300
    CHAR xXRusSXx7[0xC];//0x10304
    FLOAT PosY;//0x10310
    CHAR xXRusSXx8[0x4];//0x10314
    FLOAT PosZ;//0x10308
};*/

struct sCPlayer
{
 char ExoduS1[0xC498];
 BYTE index;//0xC498
 char ExoduS3[0x3D10];
 float Pitch;//0x101A8
 char ExoduS4[0x18];
 float Yaw;//0x101C4
 char ExoduS5[0xC];
 float ViewX;//0x101D4
 float ViewY;//0x101D8
 float ViewZ;//0x101DC
 char ExoduS6[0xE];
 WORD Weapon;//0x101EE
 char ExoduS7[0x5A];
 __int32 Status;//0x1024C
 char ExoduS8[0xB0];
 float PosX;//0x10300
 char ExoduS9[0x4];
 float PosZ;//0x10308
 char ExoduS10[0x4];
 float PosY;//0x10310
};

struct CBase
{
	sCPlayer* pLocal; 
	char* xXRusSXx[0x81FD8];
	sCPlayer** pGlobal;
};

struct sCPlayerInfo
{
	char ExoduS0[400];//0x00000
	char ENAME[20];   //0x190
	char ExoduS1[868];//0x1A4
	char IP[20];      //0x508
	char ExoduS2[280];//0x51C
	char NAME[20];    //0x634
	char ExoduS3[824];//0x648
	int  KILLS;       //0x980
	int  DEATHS;      //0x984
	int  FLAGS;       //0x988
	int  HEALTH;      //0x98C
	int  MAXHEALTH;   //0x990
	char ExoduS4[340];//0x994
	BYTE TEAM;        //0xAE8
};

struct CLocal
{
	char xJumpToAdress0[32];//0x00
	float PosX;//0x20
    float PosY;//0x24            
    float PosZ;//0x28
    char xJumpToAdress1[36];//0x2C
    float Pitch;//0x50
    float Yaw;//0x54 
};

struct CMatrix
{
	D3DXMATRIX Project;//0x00
	D3DXMATRIX View;//0x40
};

#endif