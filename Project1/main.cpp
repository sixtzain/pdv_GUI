#include "winfuncs.h"
#include "login_screen.h"
#include "intro_screen.h"
#include <iostream>

using namespace std;

bool start()
{
	bool success = true;
	if (checkInstallation()) { return success; }
	else if (!setInstallReg())
	{
		success = false;
		return success;
	}
	return success;
}

int __stdcall WinMain()
{
	/*if (start())
	{
		login_screen^ windowskk = gcnew login_screen;
		Application::Run(windowskk);
	}*/
	intro_screen^ registerKK = gcnew intro_screen;
	Application::Run(registerKK);
	
	return 0;
}