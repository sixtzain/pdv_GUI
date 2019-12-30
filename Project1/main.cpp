#include "winfuncs.h"
#include "login_screen.h"
#include "intro_screen.h"
#include <iostream>

using namespace std;

bool begining()
{
	if (!checkInstallation())
	{
		//setInstallReg();
		intro_screen^ intross = gcnew intro_screen;
		Application::Run(intross);
		
		if (!checkInstallation()) { return true; }
	}
	else { return true; }

	return true;
}

int __stdcall WinMain()
{
	if (begining())
	{
		login_screen^ windowskk = gcnew login_screen;
		Application::Run(windowskk);
	}
	//intro_screen^ registerKK = gcnew intro_screen;
	//Application::Run(registerKK);
	
	return 0;
}