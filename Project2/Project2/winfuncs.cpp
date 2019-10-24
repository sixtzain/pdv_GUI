#include "winfuncs.h"
#include "logger.h"
#include <Windows.h>
#include <winreg.h>

bool checkInstallation()
{
	HKEY hk;
	logger	message;
	long n = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Atilios\\Install"), 1, KEY_QUERY_VALUE, &hk);
	message.infoLog(std::to_string(n));

	if (n != 0 || n != ERROR_SUCCESS) 
	{ 
		message.fatalLog("n value of success: " + std::to_string(n) + "Windows error: " + std::to_string(GetLastError()));
		return false;
	}
	else { return true; }
}

bool setInstallReg()
{
	HKEY hk;
	logger	message;
	long n = RegCreateKey(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Atilios\\Install"), &hk);
	message.infoLog(std::to_string(n));

	if (n != 0 || n != ERROR_SUCCESS)
	{
		message.fatalLog("n value of success: " + std::to_string(n) + "Windows error: " + std::to_string(GetLastError()));
		return false;
	}
	else { return true; }
}

/*To be implemented in future version
bool checkSpecReg()
{
	return true;
}

bool changeRegValue()
{
	return true;
}*/