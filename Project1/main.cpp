#include "winfuncs.h"
#include "login_screen.h"
#include <iostream>

using namespace std;

int __stdcall WinMain()
{
	if (checkInstallation())
	{
		login_screen^ windowskk = gcnew login_screen;
		Application::Run(windowskk);
	}
	else { cout << "Nel prro >:v"; }

	return 0;
}
