#include "licence.h"

void CLicence::checkLicence()
{
	HRESULT hResult = URLDownloadToFileW(0,L"http://xxrussxx.square7.ch/xXRusSXxlicence.txt",L"C://licence.txt",0,0);
    string Code = "public";
	switch(hResult)
	{
		case(S_OK): break;
		case(E_OUTOFMEMORY): disconnect(); break;
		case(INET_E_DOWNLOAD_FAILURE): disconnect();
	}

	licenceFile.open("C://licence.txt");
	for(int i = 0; !licenceFile.eof(); i++) 
	{
		getline(licenceFile,licences[i]); 
	}
	licenceFile.close();

	if(licences[0] != Code)
	{
		disconnect();
	}
}

void CLicence::disconnect()
{
	ShellExecuteW(0, L"open",L"http://xxrussxx.square7.ch/index.html",0,0,0);//TODO Website get VIP
	TerminateProcess("warrock.exe",0);
    CloseHandle("warrock.exe");
	ExitProcess(0);
}