#pragma once
#using <mscorlib.dll>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

#include "FileHandler.h"
//#include "logger.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class intro_screen :
	public Form
{
public:
	intro_screen();
	int* getResponsiveLocation(int x_size, int y_size);

	unsigned int MAX_HEIGHT_WINDOW = 780;
	unsigned int MAX_WIDTH_WINDOW = 640;

private:
	Label^		u_label;
	Label^		p_label;
	TextBox^	user;
	TextBox^	password;
	CheckBox^	unlock_password;
	Button^		register_btn;

	void showPassword(Object^ Sender, EventArgs^ e);
	void registerUser(Object^ Sender, EventArgs^ e);
};