#include "stdafx.h"
#include <fstream>
#include <string>
#include <Urlmon.h>
#pragma comment(lib, "Urlmon.lib")

using namespace std;
class CLicence
{
private:
	string Code;
	ifstream licenceFile;
	string licences[10];
	public:
	void disconnect();
	void checkLicence();
};

