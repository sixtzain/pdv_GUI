#include "winfuncs.h"
#include "logger.h"
#include <Windows.h>
#include <winreg.h>

bool checkInstallation()
{
	HKEY hk;
	logger	message;
	long	n;

	try
	{
		n = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Atilios\\Install"), 1, KEY_QUERY_VALUE, &hk);
		message.infoLog(std::to_string(n));
	}
	catch (int e)
	{
		message.fatalLog("n value of success: " + std::to_string(n) + " Windows error: " + std::to_string(e));
	}
	

	if (n != 0 || n != ERROR_SUCCESS) 
	{ 
		message.fatalLog("n value of success: " + std::to_string(n) + " Windows error: " + std::to_string(GetLastError()));
		return false;
	}
	else 
	{
		message.infoLog("PDV already installed, skipping first user set-up...");
		return true; 
	}
}

bool setInstallReg()
{
	HKEY hk;
	logger	message;
	long	n;

	try
	{
		n = RegCreateKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Atilios\\Install"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hk, NULL);
		message.infoLog(std::to_string(n));
	}
	catch (int e)
	{
		message.fatalLog("n value of success: " + std::to_string(n) + " Windows error: " + std::to_string(e));
	}

	if (n != 0 || n != ERROR_SUCCESS)
	{
		message.fatalLog("n value of success: " + std::to_string(n) + " Windows error: " + std::to_string(GetLastError()));
		return false;
	}
	else 
	{ 
		message.infoLog("Installation complete, please press continue to create new Admin user");
		return true; 
	}
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