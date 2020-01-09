#pragma once
#using <mscorlib.dll>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

#include "FileHandler.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class login_screen :
	public Form
{
public:
	login_screen();
	int* getResponsiveLocation(int x_size, int y_size);

	unsigned int MAX_HEIGHT_WINDOW = 780;
	unsigned int MAX_WIDTH_WINDOW = 640;
private:
	PictureBox^ logo;
	Label^		u_label;
	Label^		p_label;
	TextBox^	user;
	TextBox^	password;
	CheckBox^	unlock_password;
	Button^		login_btn;
	void showPassword(Object^ Sender, EventArgs^ e);
	void logUser(Object^ Sender, EventArgs^ e);
	void MarshalString(String^ s, std::string& os);
};