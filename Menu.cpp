#include "stdafx.h"
#include "Colors.h"
#include "Font.h"
#include "Menu.h"

using namespace std;

ID3DXFont* pFont1;
int i,val;
DWORD color;
MenuBase* D3DMenu;
CD3DFont* menuFont;

char Text[100];
char Description[500];
char chServer[100];
char chTime[999];
char chUser[100];
char Descrption[500];
char chFps[999];
float FPSfLastTickCount    = 0.0f;
float FPSfCurrentTickCount = 0.0f;
int FPScounter             = 0;

void MenuBase::AddFolder(char *txt, char **opt, int *var, int maxvalue, int typ, char *description)
{
	MENU[Mmax]->typ=MENUFOLDER;
	MENU[Mmax]->txt=txt;
	MENU[Mmax]->opt=opt;
	MENU[Mmax]->var=var;
	MENU[Mmax]->maxvalue=maxvalue;
	MENU[Mmax]->typ=typ;
	MENU[Mmax]->description=description;
	Mmax++;
}

void MenuBase::AddCategory(char *txt, char **opt, int *var, int maxvalue, char *description)
{
	MENU[Mmax]->typ=MENUCAT;
	MENU[Mmax]->txt=txt;
	MENU[Mmax]->opt=opt;
	MENU[Mmax]->var=var;
	MENU[Mmax]->maxvalue=maxvalue;
	MENU[Mmax]->description=description;
	Mmax++;
}

void MenuBase::AddItem(char *txt, char **opt, int *var, int maxvalue,int typ, char *description)
{
	MENU[Mmax]->typ=MENUITEM;
	MENU[Mmax]->txt=txt;
	MENU[Mmax]->opt=opt;
	MENU[Mmax]->var=var;
	MENU[Mmax]->maxvalue=maxvalue;
	MENU[Mmax]->typ=typ;
	MENU[Mmax]->description=description; //
	Mmax++;
}

bool MenuBase::Font()
{
	if (pFont1)
		return false;
	else return true;
}

void MenuBase::AddText(char *txt, char *opt)
{
	MENU[Mmax]->typ=MENUTEXT;
	MENU[Mmax]->txt=txt;
	MENU[Mmax]->opt=(char **)opt;
	MENU[Mmax]->var=0;
	MENU[Mmax]->maxvalue=0;
	Mmax++;
}

void MenuBase::DrawTextR(int x, int y, DWORD color, char *Text, ID3DXFont* pFont1)
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, (int)(x - 0.1), (int)(y + 0.2), (int)(x - 0.1), (int)(y + 0.0) );
	pFont1->DrawTextA(NULL,Text,-1,&rect2, DT_RIGHT|DT_NOCLIP,BLACK );
    pFont1->DrawTextA(NULL,Text,-1,&rect, DT_RIGHT|DT_NOCLIP, color );
}

void MenuBase::DrawTextL(int x, int y, DWORD color,char *text, ID3DXFont*  pFont1)
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, (int)(x - 0.7), (int)(y + 0.5), (int)(x - 0.1), (int)(y + 0.0) );
	pFont1->DrawTextA(0,text,strlen(text),&rect,DT_LEFT|DT_NOCLIP,D3DCOLOR_XRGB(0x00,0x00,0x00));
	pFont1->DrawTextA(0,text,strlen(text),&rect2,DT_LEFT|DT_NOCLIP,color);
}

void MenuBase::DrawTextL2(int x, int y, DWORD color, char *szFormat, char *szFormat2, ID3DXFont*  pFont1)
{
	RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, (int)(x - 0.1), (int)(y + 0.2), (int)(x - 0.1), (int)(y + 0.0) );
	pFont1->DrawTextA(NULL,szFormat,-1,&rect2, DT_LEFT|DT_NOCLIP, BLACK);
    pFont1->DrawTextA(NULL,szFormat,-1,&rect, DT_LEFT|DT_NOCLIP, color);
}

void MenuBase::DrawTextC(int x,int y,DWORD color,char *text, ID3DXFont* pFont1)
{
    RECT rect, rect2;
    SetRect( &rect, x, y, x, y );
	SetRect( &rect2, (int)(x - 0.7), (int)(y + 0.5), (int)(x - 0.1), (int)(y + 0.0) );
	pFont1->DrawTextA(0,text,strlen(text),&rect,DT_CENTER|DT_NOCLIP,D3DCOLOR_XRGB(0x00,0x00,0x00));
	pFont1->DrawTextA(0,text,strlen(text),&rect2,DT_CENTER|DT_NOCLIP,color);
}

void DrawBoxM(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR color)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear(1, &rec, D3DCLEAR_TARGET, color, 0, 0);
}

void MenuBase::DrawBox(LPDIRECT3DDEVICE9 pDevice, int x, int y, int w, int h, D3DCOLOR Color)
{
	struct Vertex
	{
		float x,y,z,ht;
		DWORD Color;
	};
	Vertex V[4];
	V[0].Color = V[1].Color = V[2].Color = V[3].Color = Color;
	V[0].z = V[1].z = V[2].z = V[3].z = 0.0f;
	V[0].ht = V[1].ht = V[2].ht = V[3].ht = 0.0f;

	V[0].x = V[1].x = (float)x;
	V[0].y = V[2].y = (float)(y + h);
	V[1].y = V[3].y = (float)y;
	V[2].x = V[3].x = (float)(x + w);
	
	pDevice->SetTexture(0, NULL);
	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,V,sizeof(Vertex));
}

void MenuBase::FillARGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice ) 
{ 

    struct Vertex 
	{
        float x,y,z,ht;
        DWORD Color;
    };

    Vertex V[4];
    V[0].Color = V[1].Color = V[2].Color = V[3].Color = color;
    V[0].z   = V[1].z   = V[2].z   = V[3].z   = 0.0f;
    V[0].ht = V[1].ht = V[2].ht = V[3].ht = 0.0f;

    V[0].x = V[1].x = (float)x;
    V[0].y = V[2].y = (float)(y + h);
    V[1].y = V[3].y = (float)y;
    V[2].x = V[3].x = (float)(x + w);

	pDevice->SetTexture(0, NULL);
	pDevice->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1); 
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,V,sizeof(Vertex));

} 

void DrawBox_s(int x, int y, int w, int h, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
	D3DRECT rec;
	rec.x1 = x;
	rec.x2 = x + w;
	rec.y1 = y;
	rec.y2 = y + h;
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, Color, NULL, NULL);
}

void Rect(int x, int y, int w, int h, int s, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
	DrawBox_s( x, y, w, s, Color, pDevice);
	DrawBox_s(x, y, s, h, Color, pDevice);
	DrawBox_s((x+w), y, s, h, Color, pDevice);
	DrawBox_s(x, (y+h), w+s, s, Color, pDevice);
}

void Checked(int x, int y, LPDIRECT3DDEVICE9 pDevice)
{
	Rect(x-6, y + 26, 1, 1, 1, WHITE, pDevice);
	Rect(x-7, y + 27, 1, 1, 1, WHITE, pDevice);
	Rect(x-8, y + 28, 1, 1, 1, WHITE, pDevice);
	Rect(x-9, y + 29, 1, 1, 1, WHITE, pDevice);
	Rect(x-10, y + 30, 1, 1, 1, WHITE, pDevice);
	Rect(x-11, y + 31, 1, 1, 1, WHITE, pDevice);
	Rect(x-12, y + 32, 1, 1, 1, WHITE, pDevice);
	Rect(x-13, y + 31, 1, 1, 1, WHITE, pDevice);
	Rect(x-14, y + 30, 1, 1, 1, WHITE, pDevice);
	Rect(x-15, y + 29, 1, 1, 1, WHITE, pDevice);
}

void CurrentBar(int x, int y, LPDIRECT3DDEVICE9 pDevice)
{
	Rect(x-7, y + 21, 235, 1, 1, ScrollBarColor1, pDevice);//Oben
	Rect(x-7, y + 22, 235, 1, 1, ScrollBarColor2, pDevice);
	Rect(x-7, y + 23, 235, 1, 1, ScrollBarColor3, pDevice);
	Rect(x-7, y + 24, 235, 1, 1, ScrollBarColor4, pDevice);
	Rect(x-7, y + 25, 235, 1, 1, ScrollBarColor5, pDevice);
	Rect(x-7, y + 26, 235, 1, 1, ScrollBarColor6, pDevice);
	Rect(x-7, y + 27, 235, 1, 1, ScrollBarColor7, pDevice);
	Rect(x-7, y + 28, 235, 1, 1, ScrollBarColor8, pDevice);
	Rect(x-7, y + 29, 235, 1, 1, ScrollBarColor9, pDevice);
	Rect(x-7, y + 30, 235, 1, 1, ScrollBarColor10, pDevice);
	Rect(x-7, y + 31, 235, 1, 1, ScrollBarColor11, pDevice);
	Rect(x-7, y + 32, 235, 1, 1, ScrollBarColor12, pDevice);
}

void MenuBase::DrawText( int x, int y, DWORD color, char *szFormat, ... ) 
{ 
    if( !szFormat )return; 

    char logbuf[256] = { 0 }; 
    va_list va_alist; 
    va_start (va_alist, szFormat); 
    _vsnprintf(logbuf, sizeof(logbuf), szFormat, va_alist); 
    va_end (va_alist); 

    RECT font_rect; 
    SetRect( &font_rect, x, y, 0, 0 ); 
    DrawText( (float)x, (float)y, color, logbuf ); 
}

void MenuBase::DrawRectangleS(int x, int y, int w, int h, int s, DWORD Color, LPDIRECT3DDEVICE9 pDevice)
{
	DrawBox(pDevice, x, y, w, s, Color);
	DrawBox(pDevice, x, y, s, h, Color);
	DrawBox(pDevice, (x+w), y, s, h, Color);
	DrawBox(pDevice, x, (y+h), w+s, s, Color);
}

void MenuBase::DrawRectangle( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice ) 
{

	FillARGB( x+3, (y + h - px), w-6, px,	 	BorderColor, pDevice ); //boden
	FillARGB( x, (y+5), px, (h-10),				BorderColor, pDevice ); //links
    FillARGB( (x+5), (y), (w-10), px,			BorderColor, pDevice ); //decke
    FillARGB( (x + w - px ), (y+5), px, (h-10),	BorderColor, pDevice );//rechts
	
	DrawDot((x+4),(y),BorderColor,pDevice);
	DrawDot((x+3),(y),BorderColor,pDevice);
	DrawDot((x+2),(y),BorderColor,pDevice);
	DrawDot((x+2),(y+1),BorderColor,pDevice);
	DrawDot((x+1),(y+1),BorderColor,pDevice);
	DrawDot((x+1),(y+2),BorderColor,pDevice);
	DrawDot((x),(y+2),BorderColor,pDevice);
	DrawDot((x),(y+3),BorderColor,pDevice);
	DrawDot((x),(y+4),BorderColor,pDevice);
	//

	
	DrawDot((x+w-5),(y),BorderColor,pDevice);//oben rechts
	DrawDot((x+w-4),(y),BorderColor,pDevice);	
	DrawDot((x+w-3),(y),BorderColor,pDevice);
    DrawDot((x+w-3),(y+1),BorderColor,pDevice);
	DrawDot((x+w-2),(y+1),BorderColor,pDevice);
	DrawDot((x+w-2),(y+2),BorderColor,pDevice);
	DrawDot((x+w-1),(y+2),BorderColor,pDevice);
	DrawDot((x+w-1),(y+3),BorderColor,pDevice);
	DrawDot((x+w-1),(y+4),BorderColor,pDevice);
	//


	DrawDot((x+w-4),(y+h-1),BorderColor,pDevice);
	DrawDot((x+w-3),(y+h-1),BorderColor,pDevice);
	DrawDot((x+w-3),(y+h-2),BorderColor,pDevice);
	DrawDot((x+w-2),(y+h-2),BorderColor,pDevice);
	DrawDot((x+w-2),(y+h-3),BorderColor,pDevice);
	DrawDot((x+w-1),(y+h-3),BorderColor,pDevice);
	DrawDot((x+w-1),(y+h-5),BorderColor,pDevice);
	DrawDot((x+w-1),(y+h-4),BorderColor,pDevice);
	//

	DrawDot((x+3),(y+h-1),BorderColor,pDevice);
	DrawDot((x+2),(y+h-1),BorderColor,pDevice);
	DrawDot((x+2),(y+h-2),BorderColor,pDevice);
	DrawDot((x+1),(y+h-2),BorderColor,pDevice);
	DrawDot((x+1),(y+h-3),BorderColor,pDevice);
	DrawDot((x+0),(y+h-3),BorderColor,pDevice);
	DrawDot((x),(y+h-4),BorderColor,pDevice);
	DrawDot((x),(y+h-5),BorderColor,pDevice);
}

void Framerate(char *str, char *format)
{
	FPSfCurrentTickCount = clock() * 0.001f;
	FPScounter++;
	if ((FPSfCurrentTickCount - FPSfLastTickCount) > 1.0f)
	{
		FPSfLastTickCount = FPSfCurrentTickCount;
		sprintf(str,format,FPScounter);
		FPScounter = 0;
	}
}

void MenuBase::FillRGB(int x, int y, int w, int h, D3DCOLOR Color, IDirect3DDevice9* pDevice)
{
    if ( w < 0 )w = 1;
    if ( h < 0 )h = 1;
    if ( x < 0 )x = 1;
    if ( y < 0 )y = 1;

    D3DRECT rec = {x,y,x + w,y + h};
    pDevice->Clear(1,&rec,D3DCLEAR_TARGET,Color,0,0);
}

void MenuBase::DrawLine(int x1, int y1, int x2, int y2, D3DCOLOR col, IDirect3DDevice9* pDevice) 
{ 
    const DWORD D3D_FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1; 
    LineVertex points[2] =  
    { 
        { (float)x1, (float)y1, 0.0f, 0.0f, col, 1.0f, 1.0f }, 
        { (float)x2, (float)y2, 0.0f, 0.0f, col, 1.0f, 1.0f }, 
    }; 
    //allow for translucency 
    pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE,true ); 
    pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE ); 
    pDevice->SetRenderState( D3DRS_FOGENABLE, false ); 

    pDevice->SetFVF(D3D_FVF); 
    pDevice->SetTexture(0, NULL); 
    pDevice->DrawPrimitiveUP(D3DPT_LINESTRIP, 1, points, sizeof(LineVertex)); 


} 

void MenuBase::DrawGameTextPixelFlag(int x, int y, DWORD color, DWORD flags, char *szFormat, ... )
{
    if( !szFormat )return;

    char logbuf[256] = { 0 };

    va_list va_alist;
    va_start (va_alist, szFormat);
    _vsnprintf_s(logbuf, sizeof(logbuf), szFormat, va_alist);
    va_end (va_alist);

    SIZE Size = {0,0};
    flags = 0;
} 

void MenuBase::DrawDot( int x, int y,  D3DCOLOR Color, IDirect3DDevice9* pDevice ) 
{ 
     FillARGB(x,y,1,1,Color,pDevice); 
} 

void MenuBase::Save(char* szSection, char* szKey, int iValue)
{
	char file[255];
	char szValue[255];
	sprintf_s(szValue, "%d", iValue);
	WritePrivateProfileStringA(szSection,  szKey, szValue, file); 
}

void MenuBase::FontReset()
{
	pFont1->OnLostDevice();
	pFont1->OnResetDevice();
}

void MenuBase::FontCreate(LPDIRECT3DDEVICE9 pDevice)
{
	D3DXCreateFontA(pDevice, 13, 0, FW_BOLD, 1, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,"Arial", &pFont1);
}

void rBox( int x, int y, int w, int h, DWORD Color, LPDIRECT3DDEVICE9 pDevice )
{
	if( !pDevice )
		return;

	const DWORD D3D_FVF = (D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	
	struct Vertex 
	{
		float x,y,z,ht;
		DWORD yourcolor;
	}
	V[4] = 
	{
		{(float)x		,(float)(y+h)	, 0.0f, 0.0f, Color},
		{(float)x		,(float)y		, 0.0f, 0.0f, Color},
		{(float)(x+w)	,(float)(y+h)	, 0.0f, 0.0f, Color},
		{(float)(x+w)	,(float)y		, 0.0f, 0.0f, Color}
	};
	
	pDevice->SetTexture( 0, NULL );
	pDevice->SetRenderState( D3DRS_LIGHTING, FALSE);
	pDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_CCW);
	pDevice->SetRenderState( D3DRS_ALPHABLENDENABLE, TRUE );
	pDevice->SetRenderState( D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA );
	pDevice->SetRenderState( D3DRS_ZENABLE, D3DZB_FALSE );
	pDevice->SetRenderState( D3DRS_FOGENABLE, false );

	pDevice->SetFVF(D3D_FVF);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,V,sizeof(Vertex));
}

void rRect( int x, int y, int w, int h, int px, D3DCOLOR Color1, D3DCOLOR Color2 ,IDirect3DDevice9* pDevice ) 
{ 
	if( !pDevice )
		return;

    rBox( x, (y + h - px), w, px,     Color2, pDevice ); 
    rBox( x, y, px, h,                Color1, pDevice ); 
    rBox( x, y, w, px,                Color1, pDevice ); 
    rBox( (x + w - px), y, px, h,     Color2, pDevice ); 
}

void MenuBase::MenuShow(float x, float y, ID3DXFont* pFont, LPDIRECT3DDEVICE9 pDevice)
{
	int i,val,cy;
	DWORD ColorQ;
	if (!Mvisible) return;
	max_x=(int)(x+143);
	max_y=(int)(y+totheight);
	cy=(int)y;

	if (Mtitle[0])
	{
		MenuDetails(x, y, pDevice);
		DrawTextC((int)((x+totwidth/3) - 31), (int)cy - 5, col_title, Mtitle, pFont);
		DrawTextC((int)((x + 115) + 1),(int)(y + 5),YELLOW,"xXRusSXx",pFont);
		y+=(Mysize+13);
	}
	for (i = 0; i < Mmax; i++)
	{
	
		val=(MENU[i]->var)?(*MENU[i]->var):0;
		sprintf_s(Text,"%s",MENU[i]->txt);
		if (i == Mpos)
		{
			color=Menu_Current;
			sprintf_s(Text,"%s",MENU[i]->txt);
			sprintf_s( Description , "Description of:  %s  \n \n %s" ,MENU [ i ] ->txt , MENU [ i ] ->description);
			DrawTextC(385, 15, WHITE, Description, pFont);
			//DrawBox(pDevice,228,y-3,10,17,aDeepSkyBlue);
			CurrentBar((int)x+1,(int)y-20,pDevice);
		}
		else if (MENU[i]->typ == MENUFOLDER)
			color=Menu_Folder;
		else if (MENU[i]->typ == MENUTEXT)
			color=Menu_Text;
		else
			color=(val)?Menu_Active:Menu_Inactiv;

		if(val>0)
		{
			Checked((int)(x+13),(int)(y-23),pDevice);
		}
		else
		{
			ColorQ = RED;
		}

		if (MENU[i]->typ == MENUFOLDER)
		{
			DrawTextL((int)(x+11),(int)y,color,Text,pFont);
		}
		else
		{
			DrawTextL((int)(x+11),(int)y,color,Text,pFont);
		}

		if (MENU[i]->opt)
		{
			if (MENU[i]->typ == MENUTEXT)
				DrawTextR((int)(x+Mxofs+14),(int)y,color,(char*)MENU[i]->opt,pFont);
			else
				DrawTextR((int)(x+Mxofs+14),(int)y,color,(char*)MENU[i]->opt[val],pFont);
		}
		y+=Mysize;
	}
	if (chTime)
	{
		struct tm * xTM;
		time_t xTime;
		time (&xTime);
		xTM = localtime(&xTime);
		sprintf_s(chTime,"[ %02i:%02i:%02i ]",xTM->tm_hour,xTM->tm_min,xTM->tm_sec);
	}
	Framerate(chFps,"[ FPS: %i ]");
	DrawTextL((int)(x+40) ,(int)(y+5), WHITE,chFps ,pFont);
	DrawTextL((int)(x+115),(int)(y+5), WHITE, "-"  ,pFont);
	DrawTextL((int)(x+135),(int)(y+5), WHITE,chTime,pFont);
	YPOS=(int)y;
}

void MenuBase::MenuNavigation(void)
{
	if (GetAsyncKeyState(0x2D) &1) Mvisible=(!Mvisible);
	if (!Mvisible)return;
	if (GetAsyncKeyState(0x26) &1)
	{
		if (!GetAsyncKeyState(0x12) &1)
		{
			do
			{
				Mpos--;
				if (Mpos < 0) Mpos=Mmax-1;
			}
			while (MENU[Mpos]->typ == MENUTEXT); 
		}
	}
	else if (GetAsyncKeyState(0x28) &1)
	{
		if (!GetAsyncKeyState(0x12) &1)
		{
			do
			{
				Mpos++;
				if (Mpos == Mmax) Mpos=0;
			}
			while (MENU[Mpos]->typ == MENUTEXT); 
		}
	}
	else if (MENU[Mpos]->var)
	{
		int dir=0;
		//POINT mpos;
		if (GetAsyncKeyState(0x25) &1 && *MENU[Mpos]->var > 0 && !GetAsyncKeyState(0x12)) dir=-1;
		if (GetAsyncKeyState(0x27) &1 && *MENU[Mpos]->var < (MENU[Mpos]->maxvalue-1) && !GetAsyncKeyState(0x12)) dir=1;

		if (dir)
		{
			*MENU[Mpos]->var += dir;
			if (MENU[Mpos]->typ == MENUFOLDER)Mmax=0;
			if (MENU[Mpos]->typ == MENUCAT)Mmax=0;
		}
	}
}