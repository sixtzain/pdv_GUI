#include "login_screen.h"
#include <iostream>

using namespace std;

int __stdcall WinMain()
{
	login_screen^ windowsKK = gcnew login_screen;
	Application::Run(windowsKK);

	return 0;
}