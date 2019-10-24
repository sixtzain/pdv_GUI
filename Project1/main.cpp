#include "winfuncs.h"
#include "login_screen.h"
#include <iostream>

using namespace std;

int __stdcall WinMain()
{
	bool verga;
	if (checkInstallation())
	{
		//login_screen^ windowskk = gcnew login_screen;
		//Application::Run(windowskk);
		cout << "si ppro :v" << endl;
		verga = true;
	}
	else { cout << "Nel prro >:v"; verga = false; }

	return 0;
}
