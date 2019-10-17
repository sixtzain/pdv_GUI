#include "login_screen.h"

login_screen::login_screen()
{
	this->Text = L"Hola Pariente Kun - Login para algo inutil xDxDxDDddxxxddXXDxdD";
	this->Size = Drawing::Size(MAX_HEIGHT_WINDOW, MAX_WIDTH_WINDOW);

	int pos_x = getResponsiveLocation(MAX_HEIGHT_WINDOW, MAX_WIDTH_WINDOW)[0];
	int pos_y = getResponsiveLocation(MAX_WIDTH_WINDOW, MAX_WIDTH_WINDOW)[1];

	//logo Settings
	logo = gcnew PictureBox;
	logo->Location = Point(50, 80);
	logo->BorderStyle = BorderStyle::FixedSingle;
	logo->Image = Image::FromFile("img\\face_logo.png");
	logo->Size = Drawing::Size(418, 418);
	//User Label Settings
	u_label = gcnew Label;
	u_label->Location = Point(pos_x, pos_y);
	u_label->AutoSize = true;
	u_label->Text = L"User:";
	//Password Label Settings
	p_label = gcnew Label;
	p_label->Location = Point(pos_x, pos_y + 24);
	p_label->AutoSize = true;
	p_label->Text = L"Password:";
	//User TextBox Settings
	user = gcnew TextBox;
	user->Location = Point(pos_x + 57, pos_y);
	user->Size = Drawing::Size(132, 22);
	//Password TextBox Settings
	password = gcnew TextBox;
	password->Location = Point(pos_x + 56, pos_y + 24);
	password->Size = Drawing::Size(132, 22);
	password->UseSystemPasswordChar = true;
	//CheckBox Settings
	unlock_password = gcnew CheckBox;
	unlock_password->Location = Point(pos_x + 56, pos_y + 48);
	unlock_password->Text = L"Show Password";
	unlock_password->Click += gcnew System::EventHandler(this, &login_screen::showPassword);
	//Button Settings
	login_btn = gcnew Button;
	login_btn->Location = Point(pos_x + 56, pos_y + 92);
	login_btn->Text = L"Login";
	login_btn->AutoSize = true;
	login_btn->Click += gcnew System::EventHandler(this, &login_screen::logUser);

	//Adding elements to window
	this->Controls->Add(logo);
	this->Controls->Add(u_label);
	this->Controls->Add(p_label);
	this->Controls->Add(user);
	this->Controls->Add(password);
	this->Controls->Add(unlock_password);
	this->Controls->Add(login_btn);
}

int* login_screen::getResponsiveLocation(int x_size, int y_size)
{
	int x_resized = x_size * 0.66;
	int y_resized = y_size * 0.33;
	int arr_pos[1];
	arr_pos[0] = x_resized;
	arr_pos[1] = y_resized;
	int *pArr = arr_pos;
	return pArr;
}

void login_screen::showPassword(Object^ Sender, EventArgs^ e)
{
	if (unlock_password->Checked)
	{
		password->UseSystemPasswordChar = false;
	}
	else if (!unlock_password->Checked)
	{
		password->UseSystemPasswordChar = true;
	}
	else { return; }
}

void login_screen::logUser(Object^ Sender, EventArgs^ e)
{

}
