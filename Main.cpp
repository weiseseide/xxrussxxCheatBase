#include "stdafx.h"
#include "Colors.h"
#include "Font.h"
#include "Menu.h"
#include "Addresses.h"
#include "Structs.h"
#include "Cheats.h"
#include "licence.h"
#pragma message("xXRusSXx Base!!")
using namespace std;

MenuBase *XR;
ID3DXFont *pFont;

DWORD Menu_BorderColor;
DWORD Menu_BackGroundColor;
bool Create = false;
/****Folders****/
int Folder1  = 0, Folder2 = 0, Folder3 = 0, Folder4 = 0, Folder5 = 0, Folder6 = 0, Folder7 = 0, Folder8 = 0, Folder9 = 0, Folder10 = 0, Folder11 = 0, Folder12 = 0, Folder13 = 0, Folder14 = 0, Folder15 = 0, Folder16 = 0;


/****Menu****/
char* chFolderOnOff[] = { ">","<" };
char* chOnOff[] = {"OFF","ON"};
char* chBorderColor[] = { "SkyBlue", "White", "Green", "Blue", "Orange", "Purple", "Black", "White"};
char* chColor[] = {"OFF", "Red", "Green", "Blue", "Orange", "Purple", "Pink", "Black"};
char* chSuperJump[] = {"OFF", "Scalare", "1000", "2000", "3000", "4000"};
char* chSpeed[]   = {"OFF", "100x", "200x", "300x", "400x", "500x"};
char* chFillMode[] = {"OFF", "WireFrame", "Point"};
char* chPremium[] = {"OFF", "Bronze", "Silver", "Gold", "Platin"}; 
char* chClass[] = {"OFF","Engeneer", "Medic", "Sniper", "Assault", "Heavy Trooper"};
char* chWeapons[] = { "OFF", "DA_M7 [0]", "DA_KNUCKLE [1]", "DA_STILETTO [2]", "DA_SWORD [3]", "DA_KNUCKLE_2 [4]", "DA_SQUEAKY_HAMMER [5]", "DA_STILETTO_JP [6]", "DA_SWORD_JP [7]", "DB_COLT [8]", "DB_DESERT_EG [9]", "DB_MP5K [10]", "DB_MAGNUM [11]", "DB_GLOCK [12]", "DB_BERETTA_D [13]", "DB_THROWING_KNIFE [14]", "DB_MICRO_UZI [15]", "DB_BERETTA_M93R [16]", "DB_MP5K_GOLD [17]", "DB_MP5K_SW [18]", "DC_AK47 [19]", "DC_K2 [20]", "DC_M4A1 [21]", "DC_FAMAS [22]", "DC_L85A1 [23]", "DC_XM8 [24]", "DC_TYPE89 [25]", "DC_SIG550 [26]", "DC_TAR_21 [27]", "DC_M16A4 [28]", "DC_AN94 [29]", "DC_HK416 [30]", "DC_M16A4_Silver [31]", "DC_AK47_SW [32]", "DC_M4A1_GOLD [33]", "DD_G36C [34]", "DD_G36C_D [35]", "DD_AKS74U [36]", "DE_G36 [37]", "DE_G36_D [38]", "DF_MP5 [39]", "DF_P90 [40]", "DF_UZI [41]", "DF_TMP9 [42]", "DF_K1 [43]", "DF_MP7A1 [44]", "DF_SCORPION_D [45]", "DF_Spectre_M4 [46]", "DF_MAC10 [47]", "DF_UMP45 [48]", "DF_CX4STORM [49]", "DF_P90_Silver [50]", "DF_K1_GOLD [51]", "DF_CX4STORM_SW [52]", "DG_PSG_1 [53]", "DG_BARRETT_M82 [54]", "DG_AUG [55]", "DG_SSG [56]", "DG_M24 [57]", "DG_DRAGUNOV_SVD [58]", "DG_AI_AW [59]", "DG_AW50F [60]", "DG_M21 [61]", "DG_WA2000 [62]", "DG_SR25 [63]", "DG_M40A1 [64]", "DG_AI_AW_GOLD [65]", "DG_PSG_1_SW [66]", "DG_SSG_Silver [67]", "DH_M60 [68]", "DH_M249 [69]", "DI_WINCHESTER_1300 [70]", "DI_M4SUPER90 [71]", "DJ_PZF_3 [72]", "DJ_M136AT_4 [73]", "DJ_RPG_7 [74]", "DJ_JAVELIN [75]", "DJ_RPG_7_GOLD [76]", "DJ_RPG_7_SW [77]", "DK_STINGER [78]", "DK_SG [79]", "DL_TMA_1A [80]", "DL_HA_SUPPLY [81]", "DM_K400_GRENADE [82]", "DN_K400_GRENADE_ASSULT [83]", "DN_SACRIFICE [84]", "DO_SMOKE_G [85]", "DO_FLASH_BANG_1 [86]", "DO_FLASH_BANG_2 [87]", "DU_DROP_C4 [88]", "DU_SWITCH_C4 [89]", "DP_PDA [90]", "DP_SWITCH_C4 [91]", "DP_C4 [92]", "DP_HACKING_TOOL [93]", "DQ_MEDIC_KIT_1 [94]", "DQ_MEDIC_KIT_2 [95]", "DQ_MEDIC_KIT_3 [96]", "DR_SPANNER [97]", "DR_PIPE_WRENCH [98]", "DS_ADRENALINE [99]", "DS_PARACHUTE [100]", "DS_STAMINA [101]", "DS_HP_KIT [102]", "DS_DETECTOR [103]", "DS_TELESCOPE [104]", "DS_FLASH_MINE [105]", "DT_MG3 [106]", "DT_M134 [107]", "DT_MK1S [108]", "DT_HK69 [109]", "DT_HK69_Silver [110]", "DU_AMMO_BOX [111]", "DU_M14 [112]", "DU_TEARGAS [113]", "DV_MEDIC_BOX [114]", "DW_K203 [115]", "DW_TELESCOPE [116]", "DW_SILENCER [117]", "DU_NIPPERS [118]", "DZ_HA_SUPPLY [119]", "D0_DRUM_PIECE [120]", "D1_SLOT_CHG_6TH [121]", "D2_SNOWBALL [122]", "D5_SCORPION_D_8TH [123]", "D5_G36C_D_8TH [124]", "D6_TMP9_8TH [125]", "D6_MP7A1_8TH [126]", "D7_AI_AW_8TH [127]", "D7_BARRETT_M82_8TH [128]", "D8_M60_8TH [129]", "D8_G36_8TH [130]", "D9_M249_8TH [131]", "D9_M134_8TH [132]", "DC_XM8_RED [133]", "DF_SCORPION_D_RED [134]", "DT_MK1S_RED [135]", "DG_BARRETT_M82_CAMO [136]", "DT_HK69_CAMO [137]", "DC_AK47_EX [138]", "DA_SQUEAKY_HAMMER2 [139]", "AW_STRIKE [140]", "AW_LUMBER [141]", "AW_HOOK [142]", "AW_SHAFT [143]", "AW_CRUSH [144]", "AW_SUICIDAL [145]", "AW_INFECT [146]", "DC_FAMAS_BR [147]", "DC_FAMAS_DE [148]", "DC_FAMAS_FR [149]", "DC_FAMAS_IT [150]", "DC_FAMAS_MX [151]", "DC_FAMAS_NL [152]", "DC_FAMAS_PT [153]", "DC_FAMAS_ES [154]", "DC_FAMAS_UK [155]", "DC_FAMAS_US [156]", "DC_FAMAS_KR [157]", "DC_FAMAS_JP [158]", "DC_FAMAS_EN [159]", "DM_K400_SB_GRENADE [160]", "DN_K400_SB_ASSAULT [161]", "DN_T_GRENADE [162]", "DP_CLAYMORE_A [163]", "AW_CRASH [164]", "DB_GLOCK17C [165]", "DG_PSG_1_20B [166]", "DG_BARRETT_M82_NERVE [167]", "DF_BIZON [168]", "DG_TAC_15 [169]", "D2_S_Water_Balloon [170]", "D2_B_Water_Balloon [171]", "DG_DRAGUNOV_SVD_RED [172]", "DJ_M202A1 [173]", "DC_GALIL_AR [174]", "DI_SPAS_12 [175]", "DG_AR-7 [176]", "DN_K400_P_ASSULT [177]", "DN_K400_P_GRENADE [178]", "DB_M500 [179]", "DG_NTW_20 [180]", "DJ_FGM_172_Predator [181]", "DF_Flame_BIZON [182]", "DJ_PZF_3_DUAL [183]", "DJ_M202A1_DUAL [184]", "DA_Blallistic_Knife [185]", "DA_Gurkha [186]", "DJ_MORTAR [187]", "DJ_CRUISEMISSILE [188]", "DJ_STRIKEBOMB [189]", "AW_SUICIDAL2 [190]", "DC_FAMAS_AU [191]", "DC_FAMAS_BE [192]", "DC_FAMAS_EE [193]", "DC_FAMAS_GR [194]", "DC_FAMAS_HU [195]", "DC_FAMAS_IN [196]", "DC_FAMAS_IE [197]", "DC_FAMAS_PL [198]", "DC_FAMAS_SA [199]", "DC_FAMAS_SI [200]", "DC_FAMAS_CH [201]", "DC_FAMAS_AT [202]", "DC_FAMAS_CA [203]", "DC_FAMAS_FI [204]", "DC_FAMAS_IL [205]", "DC_FAMAS_NO [206]", "DC_FAMAS_RO [207]", "DC_FAMAS_SE [208]", "DC_FAMAS_TR [209]", "DC_FAMAS_AE [210]", "DC_FAMAS_GOLD [211]", "DC_Famas_G2_SD [212]", "DC_Famas_G2_TR [213]", "DF_MP7A1_Snow_Camo [214]", "DC_FAMAS_Snow_Camo [215]", "DU_IMPACT_WRENCH [216]", "DC_T65 [217]", "D2_BIG_SNOWBALL [218]", "DC_XM8_CAMO [219]", "DJ_M202A1_CAMO [220]", "DG_WA2000_CAMO [221]", "DC_M16A4_PINK [222]", "DF_K1_PINK [223]", "DJ_RPG_7_PINK [224]", "DG_AI_AW_PINK [225]", "DN_K400_C_GRENADE [226]", "DN_K400_C_ASSULT [227]", "DG_AR_7 [228]", "DG_AR_7_CAMO [229]", "DB_MAG_7 [230]", "DA_Shovel [231]", "DB_USP [232]", "DA_SW_MP1BD [233]", "DJ_M72LAW [234]", "DJ_9K32_Strela_2 [235]", "DB_APS [236]", "DI_KSG_11 [237]", "DA_Claw_knife [238]", "AW_Claw_knife [239]", "DT_MG3_Box [240]", "DM_K400_Water [241]", "DN_K400_Water [242]", "DF_MP7A1_Cheetah [243]", "DG_AW50F_CAMO [244]", "DC_FAMAS_IND [245]", "DC_FAMAS_RED [246]", "DB_DESERT_EG_GOLD [247]", "DJ_M72LAW_CAMO [248]", "DC_T65k2 [249]", "DF_T77 [250]", "DF_T77_D [251]", "AW_Tonfa [252]", "AW_Tonfa2 [253]", "AW_Grenade [254]", "AW_M240H [255]", "DU_M93_Hornet_Mine [256]", "DH_M240B [257]", "DH_M240B_Foregrip [258]", "DH_M240B_Tactical [259]", "DT_EX_41_Luncher [260]", "DB_SR_2_Veresk_Dot [261]", "DB_SR_2_Veresk_Dual [262]", "DB_SR_2_Veresk [263]", "IF_CRUSH [264]", "IF_PIPE [265]", "DF_SCORPION_D_GOLD [266]", "DI_SPAS_12_CAMO [267]", "DH_M60_TUR [268]", "DC_AK47_Dual [269]", "DC_FAMAS_NavyCamo [270]", "DG_PSG_1_NavyCamo [271]", "DF_MP7A1_NavyCamo [272]", "DC_XM8_NavyCamo [273]", "DG_AW50F_NavyCamo [274]", "DC_T65K2_CAMO [275]", "DF_UMP45_CAMO [276]", "DC_TAR_21_GOLD [277]", "DC_TAR_21_RED [278]", "AW_JUMP_ATTACK [279]", "DH_Degtyaryov [280]", "DC_HK_G11 [281]", "DF_K1_Snow_Camo [282]", "DG_DRAGUNOV_SVD_SC [283]", "DC_M4A1_Snow_Camo [284]", "DC_AK47_TUBE [285]", "AW_JUMP_BREAKER [286]", "DA_BIGHEAD_HAMMER [287]", "DB_dumpling [288]", "DD_G36C_D_Dragon [289]", "DI_SPAS_12_Dragon [290]", "DG_SR25_Dragon [291]", "DK_STINGER_Dragon [292]", "DS_AIRDROP [293]", "DJ_FIRESUPPORT [294]", "DJ_MK777 [295]", "DG_DSR1 [296]", "AW_SHOVEL [297]", "AW_M16SWING [298]", "DG_DSR1_camo [299]", "DA_BROKEN_REVOLVER [300]", "DF_VECTOR [301]", "DF_VECTOR_BLACK [302]", "DJ_AT4 [303]", "DC_AK47_RB [304]", "DD_G36C_RB [305]", "DG_AW50F_RB [306]", "DC_SCAR_L [307]", "DC_SCAR_L_Black [308]", "DC_SCAR_L_Camo [309]", "DN_WEB_GRENADE [310]", "IF_M16SWING [311]", "IF_SUICIDAL [312]", "DG_M95_Barrett [313]", "DI_X_12 [314]", "AW_Gauntlet [315]", "DA_Gauntlet [316]", "AW_ROADSIGN [317]", "AW_KITCHENKNIFE [318]", "AW_TOOTH [319]", "DF_PP91KEDR [320]", "DF_PP91KEDR_DUAL [321]", "DN_T_CAPSULE [322]", "DJ_QLB06 [323]", "DI_KSG [324]", "DI_KSG_Camo [325]", "DT_PKM [326]", "DT_PKM_Camo [327]", "DG_VSS [328]", "DG_VSS_Red [329]", "DF_PP2000 [330]", "DF_PP2000_Red [331]", "DB_M500_Stick [332]", "DI_M4SUPER90_Stick [333]", "DN_K400_GIFT [334]", "DN_K400_A_GIFT [335]", "DF_Chicago_Typewriter [336]", "DG_M1891 [337]", "DJ_RPG_7_WINTER [338]", "DC_HK416_WINTER [339]", "DG_NTW_20_WINTER [340]", "DA_Flowers [341]", "D8_M60 [342]", "D9_M134 [343]", "D5_G36C_D [344]", "D7_AI_AW [345]", "D9_M249 [346]", "D8_Famas [347]", "DF_K1_ESL [348]", "DC_AK47_ESL [349]", "DG_AUG_ESL [350]", "DB_MP5K_ESL [351]", "DJ_RPG7_ESL [352]", "DF_FMG9_Dual [353]", "DB_FMG9_Desert [354]", "DE_SCAR_H [355]", "DE_SCAR_H_Blue [356]", "DA_LongSword [357]", "DA_LongSword_Snake [358]", "DG_CHEYTAC_M200 [359]", "DG_CHEYTAC_M200_Camo [360]", "DL_SPIKESTRIP [361]", "DB_BERETTA_M92 [362]", "DJ_CARLGUSTAV [363]", "DE_TYPE11 [364]", "DF_MP7A1_BLUE [365]", "DF_SCORPION_D_BLUE [366]", "DG_PSG_1_BLUE [367]", "DJ_M72LAW_BLUE [368]", "DC_FAMAS_BLUE [369]", "DG_CHEYTAC_M200_Red [370]", "DE_TYPE95 [371]", "DE_TYPE95_Camo [372]", "DE_TYPE95_Red [373]", "DF_MP7A1_RED [374]", "DJ_M72LAW_RED [375]", "DF_SCORPION_D_NavyCamo [376]", "DJ_M72LAW_NavyCamo [377]", "DN_WOODSTICK_BOMB [378]", "DC_M4A1_Hanbok [379]", "DF_K1_Hanbok [380]", "DG_M95_Barrett_Hanbok [381]", "DJ_MK777_Hanbok [382]", "DF_F1 [383]", "DF_F1_Desert [384]", "DI_USAS12 [385]", "DI_USAS12_Luxury [386]", "DA_FacaWotan [387]", "DB_PT92 [388]", "DE_MD97 [389]", "DJ_M72LAW_PINK [390]", "DC_FAMAS_PINK [391]", "DF_MP7A1_PINK [392]", "DF_SCORPION_D_PINK [393]", "DG_PSG_1_PINK [394]", "DB_FMG9 [395]", "DG_CHEYTAC_M200_Hex [396]", "DH_Negev [397]", "DH_Negev_Camo [398]", "DF_L34A1 [399]", "DF_L34A1_Orange [400]", "DG_Gepard [401]", "DG_AS50 [402]", "DJ_GRENADE_BOW [403]", "DE_AK47TC [404]", "DE_AK47TC_TIGER [405]", "DF_MP7TC [406]", "DF_MP7TC_SNOW [407]", "DG_DSR1TC [408]", "DG_DSR1TC_LEAF [409]", "DC_AK47_PINK [410]", "DB_LugerP08 [411]", "DC_Springfield_M1903A3 [412]", "DG_TOKAREV_SVT40 [413]", "DD_G36GT [414]", "DD_G36GT_EAGLE [415]" };
char* chAimKey[] = {"None","RMouse","Alt"};
char* chAimBone[] = {"Breast","Head"};
char* chAimDistance[] = {"OFF","100","1000","10000"}; 
char* chESPHealth[]	= {"OFF","BOX"};
char* chLine []	= {"OFF","CrossHair","Player"};
char* chGameMode[] = {"OFF", "CQC", "BG", "AI"};

/****Functions****/
//Menu Functions
int iBorderColor = 0, Credits = 0, Exit = 0;

/***EXTERN&OBJECTS***/
extern CCheats CheatTools;
extern CPlayer Player;
extern CServer Server;
extern CWeapon Weapon;
extern CFast   Fast;

extern int var[17];

CLocal* p_Local;
//D3D Functions
extern int PlayerChams, PlayerChamsColorA, PlayerChamsColorB, VehicleChams, VehicleChamsColorA, VehicleChamsColorB, WallHack, NoFog, FillMode, Fullbright, Crosshair;

extern void OPKThread();
extern void NoClipCheat();
extern void D3DCheats( LPDIRECT3DDEVICE9 pDevice, DWORD p0, DWORD p1, DWORD p2, DWORD p3, DWORD p4, DWORD p5 );

void _stdcall DrawItems()
{
	XR->AddFolder("| Menu Settings |" ,chFolderOnOff ,&Folder1 ,2 ,MENUFOLDER ,"Contains all global menu settings");
	if ( Folder1 )
	{
		XR->AddItem("  BorderColor" ,chBorderColor ,&iBorderColor ,6 ,MENUITEM ,"Changes Border Color");
		XR->AddItem("  ShowCredits" ,chOnOff       ,&Credits      ,2 ,MENUITEM ,"Show People who helped me");
		XR->AddItem("  ExitWarRock" ,chOnOff       ,&Exit         ,2 ,MENUITEM ,"Close WarRock Process");
	}

	XR->AddFolder("| Direct3D/Ambient |" ,chFolderOnOff ,&Folder2 ,2 ,MENUFOLDER ,"D3DRelated/Ambient things are in here");
	if ( Folder2 )
	{
		XR->AddCategory("  PlayerChams" ,chOnOff ,&PlayerChams ,2 ,"WallHack Players with Colors");
		if(PlayerChams)
		{
			XR->AddItem("  - FrontColor",chColor ,&PlayerChamsColorA ,8 ,MENUITEM ,"Sets color of Players in front of walls");
			XR->AddItem("  - BackColor" ,chColor ,&PlayerChamsColorB ,8 ,MENUITEM ,"Sets color of Players behind walls");
		}
		XR->AddCategory("  VehicleChams" ,chOnOff ,&VehicleChams ,2 ,"WallHack Vehicle with Colors");
		if(VehicleChams)
		{
			XR->AddItem("  - FrontColor",chColor ,&VehicleChamsColorA ,8 ,MENUITEM ,"Sets color of Vehicle in front of walls");
			XR->AddItem("  - BackColor" ,chColor ,&VehicleChamsColorB ,8 ,MENUITEM ,"Sets color of Vehicle behind walls");
		}
		XR->AddItem("  WallHack"   ,chOnOff    ,&WallHack    ,2 ,MENUITEM ,"See players through walls");
		XR->AddItem("  NoFog"      ,chOnOff    ,&NoFog       ,2 ,MENUITEM ,"No Fog");
		XR->AddItem("  FullBright" ,chOnOff    ,&Fullbright  ,2 ,MENUITEM ,"Full bright");
		XR->AddItem("  FillMode"   ,chFillMode ,&FillMode    ,3 ,MENUITEM ,"Fill in of Objects");
		XR->AddItem("  Crosshair"  ,chColor    ,&Crosshair   ,5 ,MENUITEM ,"Small Crosshair");
	} 

	XR->AddFolder("| Player |" ,chFolderOnOff ,&Folder4 ,2 ,MENUFOLDER ,"Player related things");
	if ( Folder4 )
	{
		XR->AddItem("  SuperJump"      ,chSuperJump ,&Player.m_iSuperJump      ,6 ,MENUITEM ,"Super Jump with CTRL/STRG");
		XR->AddItem("  NoFallDamage"   ,chOnOff     ,&Player.m_iNoFallDamage   ,2 ,MENUITEM ,"No damage by falling down a high height");
		XR->AddItem("  Speed"          ,chSpeed     ,&Player.m_iSpeed          ,6 ,MENUITEM ,"Speed of moving");
		XR->AddItem("  NoBounds"       ,chOnOff     ,&Player.m_iNoBounds       ,2 ,MENUITEM ,"No out of Map");
		XR->AddItem("  OPK"            ,chOnOff     ,&Player.m_iOPK            ,2 ,MENUITEM ,"One Position Kill");
		XR->AddItem("  SVP"            ,chOnOff     ,&Player.m_iSVP            ,2 ,MENUITEM ,"Sniper Ventage Position");
		XR->AddItem("  NoSpawnWait"    ,chOnOff     ,&Player.m_iNoSpawnWait    ,2 ,MENUITEM ,"No Respawn Countdown");
		XR->AddItem("  Invisible"      ,chOnOff     ,&Player.m_iInvisible      ,2 ,MENUITEM ,"Not visible for other Players");
		XR->AddItem("  WalkUnderWater" ,chOnOff     ,&Player.m_iWalkUnderWater ,2 ,MENUITEM ,"Walk under Water");
		XR->AddItem("  StaminaRefill"  ,chOnOff     ,&Player.m_iStaminaRefill  ,2 ,MENUITEM ,"Fast Stamina refill");
		XR->AddItem("  Selfkill"       ,chOnOff     ,&Player.m_iSelfkill       ,2 ,MENUITEM ,"Instant die");
		XR->AddItem("  BeSilent"       ,chOnOff     ,&Player.m_iSilentWalk     ,2 ,MENUITEM ,"Youre not doing sounds like walking/reloading");
		XR->AddItem("  DeadSpinner"    ,chOnOff     ,&Player.m_iDeadSpinner    ,2 ,MENUITEM ,"When you die the body makes crazy moves");
		XR->AddItem("  NoClip(Fly)"    ,chOnOff     ,&Player.m_iNoClip         ,2 ,MENUITEM ,"A fly mode");
	}

	XR->AddFolder("| Weapon |" ,chFolderOnOff ,&Folder5 ,2 ,MENUFOLDER ,"Server related things");
	if ( Folder5 )
	{
		XR->AddItem("  NoRecoil"          ,chOnOff  ,&Weapon.m_iNoRecoil        ,2  ,MENUITEM ,"No recoil while shooting");
		XR->AddItem("  NoSpread"          ,chOnOff  ,&Weapon.m_iNoSpread        ,2  ,MENUITEM ,"No spreading while shooting");
		XR->AddItem("  NoReload"          ,chOnOff  ,&Weapon.m_iNoReload        ,2  ,MENUITEM ,"No Weapon reload");
		XR->AddItem("  UnlAmmo"           ,chOnOff  ,&Weapon.m_iUnlimitedAmmo   ,2  ,MENUITEM ,"Unlimited Ammo");
		XR->AddItem("  NoDelay/Rapidfire" ,chOnOff  ,&Weapon.m_iNoDelay         ,2  ,MENUITEM ,"Shoot very fast");
		XR->AddItem("  Scope"             ,chOnOff  ,&Weapon.m_iScope           ,2  ,MENUITEM ,"Scope with every item");
		XR->AddItem("  ShotAs"            ,chWeapons,&Weapon.m_iShotAs          ,417,MENUITEM ,"Shot as choosen weapon");
		XR->AddItem("  FastLockOn"        ,chOnOff  ,&Weapon.m_iFastLockOn      ,2  ,MENUITEM ,"Fast locking on enemys targets");
		XR->AddItem("  PlantAnyWhere"     ,chOnOff  ,&Weapon.m_iPlantAnyWhere   ,2  ,MENUITEM ,"Plant Bomb any where(CQC)");
		XR->AddItem("  DefuseAnyWhere"    ,chOnOff  ,&Weapon.m_iDefuseAnyWhere  ,2  ,MENUITEM ,"Defuse Bomb any where(CQC)");
		XR->AddItem("  QuickDefuse"       ,chOnOff  ,&Weapon.m_iQuickDefuse     ,2  ,MENUITEM ,"Fast bomb defusing(CQC)");
		XR->AddItem("  QuickPlant"        ,chOnOff  ,&Weapon.m_iQuickPlant      ,2  ,MENUITEM ,"Fast bomb planting(CQC)");
		XR->AddItem("  Breaklimit"        ,chOnOff  ,&Weapon.m_iBreaklimit      ,2  ,MENUITEM ,"Weapons dont overheat");
		XR->AddItem("  NoWeaponGravity"   ,chOnOff  ,&Weapon.m_iNoWeaponGravity ,2  ,MENUITEM ,"No Weapon weight/gravity");
		XR->AddItem("  HideWeapon"        ,chOnOff  ,&Weapon.m_iHideWeapon      ,2  ,MENUITEM ,"Hides your weapon(just for you)");
		XR->AddItem("  ColorShot"         ,chOnOff  ,&Weapon.m_iColorShot       ,2  ,MENUITEM ,"Shot colord patrons");
		XR->AddItem("  Artillery"         ,chOnOff  ,&Weapon.m_iArtillery       ,2  ,MENUITEM ,"Take DS_TELESCOPE [104]in 8Slot");
	}

	XR->AddFolder("| Weapon Binder |",chFolderOnOff,&Folder7,2,MENUFOLDER,"Visual weapon Hack allowing\nyou to put any weapon in any slo\nMay cause crashes");
    if ( Folder7 )
    {
		XR->AddCategory("  Player Class",chClass, &var[1],6,"Select class weapon to fill weapons slots from");
		if( var[1] )
		{
			XR->AddItem("  Slot 1",chWeapons,&var[2],417,MENUITEM,"Select weapon for slot 1");
			XR->AddItem("  Slot 2",chWeapons,&var[3],417,MENUITEM,"Select weapon for slot 2");
			XR->AddItem("  Slot 3",chWeapons,&var[4],417,MENUITEM,"Select weapon for slot 3");
			XR->AddItem("  Slot 4",chWeapons,&var[5],417,MENUITEM,"Select weapon for slot 4");
			XR->AddItem("  Slot 5",chWeapons,&var[6],417,MENUITEM,"Select weapon for slot 5");
			XR->AddItem("  Slot 6",chWeapons,&var[7],417,MENUITEM,"Select weapon for slot 6");
			XR->AddItem("  Slot 7",chWeapons,&var[8],417,MENUITEM,"Select weapon for slot 7");
			XR->AddItem("  Slot 8",chWeapons,&var[9],417,MENUITEM,"Select weapon for slot 8"); 
		}
	}

	XR->AddFolder("| Server |" ,chFolderOnOff ,&Folder6 ,2 ,MENUFOLDER ,"Server related things");
	if ( Folder6 )
	{
		XR->AddItem("  Premium"     ,chPremium  ,&Server.m_iPremium  ,5 ,MENUITEM ,"Visual Premium");
		XR->AddItem("  Dinar"       ,chOnOff    ,&Server.m_iDinar    ,2 ,MENUITEM ,"Visual Dinar");
		XR->AddItem("  Level"       ,chOnOff    ,&Server.m_iLevel    ,2 ,MENUITEM ,"Visual Level");
		XR->AddItem("  UnlockSlots" ,chOnOff    ,&Server.m_iSlot     ,2 ,MENUITEM ,"Unlock all Item Slots");
		XR->AddItem("  GameMode"    ,chGameMode ,&Server.m_iGameMode  ,4  ,MENUITEM ,"Choose Mode Type(CQC/BG/AI)");
	}

	XR->AddFolder("| Fast |" ,chFolderOnOff ,&Folder8 ,2 ,MENUFOLDER ,"Fast related things");
	if ( Folder8 )
	{
		XR->AddItem("  FastHealth" ,chOnOff ,&Fast.m_iFastHealth ,2 ,MENUITEM ,"Fast counting by Health-station");
		XR->AddItem("  FastAmmo"   ,chOnOff ,&Fast.m_iFastAmmo   ,2 ,MENUITEM ,"Fast counting by Ammo-station");
		XR->AddItem("  FastFlag"   ,chOnOff ,&Fast.m_iFastFlag   ,2 ,MENUITEM ,"Fast counting by Conquer");
	}

	XR->AddFolder("| Zombie |" ,chFolderOnOff ,&Folder10 ,2 ,MENUFOLDER ,"Zombie related things");
	if ( Folder10 )
	{
		XR->AddItem("  ZombieGod" ,chOnOff ,&Player.m_iInvisible ,2 ,MENUITEM ,"Zombies cant kill you");
		XR->AddItem("  ZombieOPK" ,chOnOff ,&Player.m_iZOPK      ,2 ,MENUITEM ,"All Zombies in front of you");
	}
	bool InitBoxes = true;
}

void MenuBase::MenuDetails(float x, float y, LPDIRECT3DDEVICE9 pDevice, ...)
{	
	// Header
	DrawBox(pDevice,(x - 8),y,Mxofs+40,Mmax*Mysize+52,Menu_BackGroundColor);
	DrawRectangle((x - 8),(y + 0),Mxofs+40,22,1,Menu_BorderColor,pDevice);
	DrawRectangle((x - 8),(y + 0),Mxofs+40,Mmax*Mysize+32,1,Menu_BorderColor,pDevice);
	// Under Box
	DrawRectangle((x - 8),(y + 0),Mxofs+40,Mmax*Mysize+52,1,Menu_BorderColor,pDevice);
	DrawBox(pDevice,250,y,Mxofs+80,81,Menu_BackGroundColor);
	DrawRectangle(250,12,Mxofs+80,22,1,Menu_BorderColor,pDevice);
	DrawRectangle(250,12,Mxofs+80,81,1,Menu_BorderColor,pDevice);			
}

HRESULT   __stdcall nReset    (  LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters );
typedef HRESULT ( APIENTRY* Reset_t ) (  LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters );
Reset_t     pReset;

HRESULT   __stdcall nPresent   (  LPDIRECT3DDEVICE9 pDevice,CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion );
typedef HRESULT ( APIENTRY* Present_t )(  LPDIRECT3DDEVICE9 pDevice,CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion );
Present_t   pPresent;

HRESULT   __stdcall  nDrawIndexedPrimitive    ( LPDIRECT3DDEVICE9 pDevice, DWORD p0, DWORD p1, DWORD p2, DWORD p3, DWORD p4, DWORD p5 );
typedef HRESULT ( APIENTRY* DrawIndexedPrimitive_t ) (  LPDIRECT3DDEVICE9 pDevice, DWORD p0, DWORD p1, DWORD p2, DWORD p3, DWORD p4, DWORD p5 );
DrawIndexedPrimitive_t     pDrawIndexedPrimitive;


HRESULT __stdcall nReset ( LPDIRECT3DDEVICE9 pDevice,D3DPRESENT_PARAMETERS* pPresentationParameters )
{
    _asm PUSHAD;

	pFont->OnLostDevice();
	HRESULT hRet = pReset(pDevice, pPresentationParameters);
	pFont->OnResetDevice();

    _asm POPAD;

    return pReset(pDevice, pPresentationParameters);
}

HRESULT __stdcall nPresent( LPDIRECT3DDEVICE9 pDevice,CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion )
{        
    _asm PUSHAD;

	if (!Create)
	{
		D3DXCreateFontA(pDevice, 14.5,0, FW_BOLD,1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &pFont);
		Create = true;
	}
	
	if (pFont == NULL)
	{
		pFont->OnLostDevice();
	}
	else
	{
		if (XR == NULL)
		{
			XR = new MenuBase("Arial");
		}
		else
		{
			if (XR->Mmax == 0)DrawItems();
			XR->MenuShow(12,12,pFont,pDevice);
			XR->MenuNavigation();
			Menu_BackGroundColor = aBlackTransparent;
			switch ( iBorderColor )
			{
				case 0:{ Menu_BorderColor = aDeepSkyBlue; }break;
				case 1:{ Menu_BorderColor = aBlackTransparent2; }break;
				case 2:{ Menu_BorderColor = aGreen; }break;
				case 3:{ Menu_BorderColor = aBlue; }break;
				case 4:{ Menu_BorderColor = aOrange; }break;
				case 5:{ Menu_BorderColor = aPurple; }break;
			}
		}
	}

	if( Credits == 1 )
	{
		XR->DrawBox(pDevice,(int)250,(int)162,(int)280,(int)95,Menu_BackGroundColor);
	    XR->DrawRectangle((int)250,162,(int)280,(int)25,1,Menu_BorderColor,pDevice);
		XR->DrawRectangle((int)250,192,(int)280,(int)65,1,Menu_BorderColor,pDevice);
	    XR->DrawTextC(390,170,YELLOW,(" Credits/Informations"),pFont);
		XR->DrawTextC(392,210,WHITE,"xXRusSXx Base",pFont); 
		XR->DrawTextC(392,225,WHITE,"Credits: UnknownPK, Exodus, Kazbah, Trademark",pFont);
	}

	if( Exit ==1 )
	{
		if(MessageBoxA(0,"Warning:\n Do you really want to close the game?","Exit Warning",MB_OKCANCEL)==1)
		{
			_exit(0);
		}
		else
		{
			Exit =0;
		}
	}

	DWORD dwCrossHairColor;
	switch ( Crosshair )
	{
	    case 1: dwCrossHairColor = aRed; break;
		case 2: dwCrossHairColor = aGreen; break;
		case 3: dwCrossHairColor = aBlue; break;
		case 4: dwCrossHairColor = aOrange; break;
		case 5: dwCrossHairColor = aPurple; break;
		case 6: dwCrossHairColor = aBlack; break;
		case 7: dwCrossHairColor = aWhite; break;
	}

	if ( Crosshair )
	{
		int PosX = (GetSystemMetrics(0)/2);
		int PosZ = (GetSystemMetrics(1)/2);
		D3DRECT Rect1 = {PosX-10,PosZ,PosX+10,PosZ+1};
		D3DRECT Rect2 = {PosX,PosZ-10,PosX+1,PosZ+10};
		pDevice->Clear(1,&Rect1,D3DCLEAR_TARGET,dwCrossHairColor,0,0); 
		pDevice->Clear(1,&Rect2,D3DCLEAR_TARGET,dwCrossHairColor,0,0);
	}

    _asm POPAD;

    return pPresent (pDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT __stdcall nDrawIndexedPrimitive ( LPDIRECT3DDEVICE9 pDevice, DWORD p0, DWORD p1, DWORD p2, DWORD p3, DWORD p4, DWORD p5 )
{
	_asm PUSHAD;
	
	D3DCheats(pDevice, p0, p1, p2, p3, p4, p5 );

   _asm POPAD;

	return pDrawIndexedPrimitive(pDevice, p0, p1, p2, p3, p4, p5 );
}

DWORD WarRockDevice  (int index)
{
    if ( !ADR_DevicePointer) return 0;
    DWORD dwBla1 = *(DWORD*)ADR_DevicePointer;
    if(!dwBla1) return 0;
        
    DWORD dwBla2 = *(DWORD*)(dwBla1 + ADR_OFS_DevicePTR );
    if(!dwBla2) return 0;
    dwBla2 = *(DWORD*)dwBla2;

    if(!dwBla2) return 0;
    return dwBla2 + ( 4*index );
}


#define  VMTInitialize(name, index)\
        DWORD dw##name##1 = WarRockDevice (index);\
        if(*(DWORD*)dw##name##1 != (DWORD)&n##name && dw##name##1 != NULL)\
{\
         p##name = (name##_t) *(DWORD*)dw##name##1;\
        *(DWORD*)dw##name##1 = (DWORD)&n##name;\
}

int __stdcall InitializateHooks ( void )
{
	bool bValid = false;
    while(true) 
    {
		bValid = WarRockDevice(0) > 0;
        if( bValid )
        {
			VMTInitialize( Reset, 16 );
			VMTInitialize( Present, 17 );
			VMTInitialize( DrawIndexedPrimitive, 82 );
		}
		Sleep(300);
    }
    return (0);
}

void HookCheats()
{
	while(1)
	{
		CheatTools.InGame();
		CheatTools.OutGame();
		CheatTools.Priority();//CreateThread
		Sleep(20);
	}
}
void InitializateByPass()
{
	CheatTools.ByPassHS();
}
//DWORD __stdcall Hackz(void * lpPointer)
//{
// while (true)
// {
//  PlayerHacks();
//  ServerHacks();
//  Sleep(2);
// }
// return 1;
//}
//[18:11:50] Kazbah-Daniel: CreateThread ( 0, 0, &Hackz, 0, 0, 0 ) ;
BOOL WINAPI DllMain(HMODULE hDll, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) 
	{
		//CreateThread(0,0,(LPTHREAD_START_ROUTINE)InitializateByPass,0,0,0);
		CreateThread(0,0,(LPTHREAD_START_ROUTINE)InitializateHooks,0,0,0);
		//CreateThread(0,0,(LPTHREAD_START_ROUTINE)HookCheats,0,0,0);
		//CreateThread(0,0,(LPTHREAD_START_ROUTINE)OPKThread,0,0,0);
		//CreateThread(0,0,(LPTHREAD_START_ROUTINE)NoClipCheat,0,0,0);
		
	}
	return TRUE;
}

