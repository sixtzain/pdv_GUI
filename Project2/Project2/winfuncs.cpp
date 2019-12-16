#include "winfuncs.h"
#include "..\logger\logger\logger.h"

#include <Windows.h>
#include <winreg.h>
#include <iostream>
#include <string>

logger	_logger;

bool checkInstallation()
{
	HKEY hk;
	long	n;

	try
	{
		n = RegOpenKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Atilios\\Install"), 1, KEY_QUERY_VALUE, &hk);
		_logger.infoLog(std::to_string(n));
	}
	catch (int e)
	{
		_logger.fatalLog("n value of success: " + std::to_string(n) + " Windows error: " + std::to_string(e));
	}
	

	if (n != 0 || n != ERROR_SUCCESS) 
	{ 
		_logger.fatalLog("n value of success: " + std::to_string(n) + " Windows error: " + std::to_string(GetLastError()));
		return false;
	}
	else 
	{
		_logger.infoLog("PDV already installed, skipping first user set-up...");
		return true; 
	}
}

bool setInstallReg()
{
	HKEY hk;
	long	n;

	try
	{
		n = RegCreateKeyEx(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\Atilios\\Install"), 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hk, NULL);
		_logger.infoLog(std::to_string(n));
	}
	catch (int e)
	{
		_logger.fatalLog("n value of success: " + std::to_string(n) + " Windows error: " + std::to_string(e));
	}

	if (n != 0 || n != ERROR_SUCCESS)
	{
		_logger.fatalLog("n value of success: " + std::to_string(n) + " Windows error: " + std::to_string(GetLastError()));
		return false;
	}
	else 
	{ 
		_logger.infoLog("Installation complete, please press continue to create new Admin user");
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