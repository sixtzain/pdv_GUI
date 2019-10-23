#include "winfuncs.h"
#include <Windows.h>
#include <winreg.h>

bool checkInstallation()
{
	HKEY hk;
	long n = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Atilios\\Install"), 1, KEY_QUERY_VALUE, &hk);

	if (n == ERROR_SUCCESS)
	{
		return true;
	}
	else { return false; }
}

bool checkSpecReg()
{
	return true;
}

bool changeRegValue()
{
	return true;
}