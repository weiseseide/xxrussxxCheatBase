#include "stdafx.h"

#ifndef _XMENU_H_
#define _XMENU_H_

#ifndef D3DFONT_RIGHT
#define D3DFONT_RIGHT		0x0008
#endif

#define 	MENUMAXITEMS	100
#define 	MENUFOLDER		1
#define 	MENUTEXT		2
#define 	MENUITEM		3
#define		MENUCAT			4


typedef struct
{
	DWORD col_group;
	int typ;
	char *txt;
	char **opt;
	int *var;
	int maxvalue;
	int maxval;
	char *description;
	DWORD color;
}tMENU;

struct QuadVertex 
{ 
    float x,y,z,rhw; 
    DWORD dwColor; 
}; 

struct LineVertex 
{  
    float x,y,z,rhw;  
    D3DCOLOR color; 
    float tu,tv;  
}; 

class MenuBase
{
public:
	MenuBase(char *Title = 0)
	{
		Mtitle=Title;
		Mpos=0;
		Mmax=0;
		Mxofs = 200.0f;
		Mysize = 16.0f;
		Mvisible=1;
		MENU=(tMENU **)malloc(4*MENUMAXITEMS);
		for (int i = 0; i < MENUMAXITEMS; i++)
			MENU[i]=(tMENU *)malloc(sizeof(tMENU));
	}
	
	~MenuBase()
	{
		for (int i=0; i<MENUMAXITEMS; i++) free(MENU[i]);
		free(MENU);
	}
	float Mysize;
	int	Mvisible;
	DWORD col_group;
	int	Mmax;
	float Mxofs;
		DWORD col_title;
	//DWORD col_group;
	DWORD col_group1;
	DWORD col_text;
	DWORD col_off;
	DWORD col_on;
	DWORD ItemC_On;
	DWORD OPTC_On;
	DWORD OPTC_Off;
	DWORD ItemC_Off;
	DWORD col_current;
	tMENU **MENU;;

	/**************************** Menu Stuff ****************************/
	void MenuShow(float x, float y, ID3DXFont* pFont1, LPDIRECT3DDEVICE9 pDevice);
	void MenuDetails(float x, float y, LPDIRECT3DDEVICE9 pDevice, ...);
	void Boarders(LPDIRECT3DDEVICE9 pDevice, ID3DXFont* pFont1);
	void Credits(float x, float y, ID3DXFont* pFont11, LPDIRECT3DDEVICE9 pDevice);
	void Infos(float x, float y, ID3DXFont* pFont1, LPDIRECT3DDEVICE9 pDevice);
	void AddItem(char *txt, char **opt, int *var, int maxvalue, int typ,char *description="None");
	void AddFolder(char *txt, char **opt, int *var, int maxvalue, int typ,char *description="No aviable");
	void AddCategory(char *txt, char **opt, int *var, int maxvalue,char *description="None"); 
	void MenuNavigation(void);
	void AddText(char *txt, char *opt="");
	void Save(char* szSection, char* szKey, int iValue);
	int  Load(char* szSection, char* szKey, int iDefaultValue);
	/**************************** Draw Stuff ****************************/
	void DrawText( int x, int y, DWORD color, char *szFormat, ... );
	void DrawTextR(int x, int y, DWORD color, char *text, ID3DXFont* pFont1);
	void DrawTextL(int x, int y, DWORD color, char *szFormat, ID3DXFont* pFont1);
	void DrawTextL2(int x, int y, DWORD color, char *szFormat, char *szFormat2, ID3DXFont*  pFont1);
	void DrawDot( int x, int y,  D3DCOLOR BorderColor, IDirect3DDevice9* pDevice );
	void DrawLine(int x1, int y1, int x2, int y2, D3DCOLOR col, IDirect3DDevice9* pDevice); 
	void DrawTextC(int x, int y, DWORD color, char *text, ID3DXFont* pFont1);
	void DrawRectangle( int x, int y, int w, int h, int px, D3DCOLOR Color, IDirect3DDevice9* pDevice ); 
	void DrawRectangleS(int x, int y, int w, int h, int s, DWORD Color, LPDIRECT3DDEVICE9 pDevice);
	//void DrawRectangle( int x, int y, int w, int h, int px,int s, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice ); 
	void DrawBorder1( int x, int y, int w, int h, int px, D3DCOLOR Color, IDirect3DDevice9* pDevice ); 
	void DrawBox(LPDIRECT3DDEVICE9 pDevice,int x,int y,int w,int h,D3DCOLOR Color);
	void DrawHealthBox(int x, int y, DWORD m_dColorOut, DWORD m_dColorIn, int m_iHealth, int m_iMaxHealth, IDirect3DDevice9* pDevice);
	void DrawFont (int x,int y,D3DCOLOR Color,char *format, ...);
	void DrawGameTextPixel(int x, int y, DWORD color, char *szFormat, ... );
	void DrawGameTextPixelFlag(int x, int y, DWORD color, DWORD flags, char *szFormat, ...);
	/**************************** Font Stuff ****************************/
	bool Font();
	void FontReset();
	void FontCreate(LPDIRECT3DDEVICE9 pDevice);
	/**************************** Other Stuff ***************************/
	void FillRGB(int x, int y, int w, int h, D3DCOLOR Color, IDirect3DDevice9* pDevice);
	void FillARGB( int x, int y, int w, int h,  D3DCOLOR color, IDirect3DDevice9* pDevice );

private:
	char *Mtitle;
	int max_x, max_y;
	int Mpos;
	int	YPOS;
	int m_x,m_y;
	int m_lm, m_rm;
	int totwidth,totheight;
};

#endif // _XMENU_H_