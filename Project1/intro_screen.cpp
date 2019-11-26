#include "intro_screen.h"

intro_screen::intro_screen()
{
	this->Text = L"Bienvenido!!, por favor registra tu usuario";
	this->Size = Drawing::Size(MAX_HEIGHT_WINDOW, MAX_WIDTH_WINDOW);

	int pos_x = getResponsiveLocation(MAX_HEIGHT_WINDOW, MAX_WIDTH_WINDOW)[0];
	int pos_y = getResponsiveLocation(MAX_WIDTH_WINDOW, MAX_WIDTH_WINDOW)[1];

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
	unlock_password->Location = Point(pos_x + 58, pos_y + 48);
	unlock_password->Text = L"Show Password";
	unlock_password->Click += gcnew System::EventHandler(this, &intro_screen::showPassword);
	//Button Settings
	register_btn = gcnew Button;
	register_btn->Location = Point(pos_x + 80, pos_y + 86);
	register_btn->Text = L"Register";
	register_btn->AutoSize = true;
	register_btn->Click += gcnew System::EventHandler(this, &intro_screen::registerUser);
	//Background color
	this->BackColor = Color::Beige;

	//Adding elements to window
	this->Controls->Add(u_label);
	this->Controls->Add(p_label);
	this->Controls->Add(user);
	this->Controls->Add(password);
	this->Controls->Add(unlock_password);
	this->Controls->Add(register_btn);
}

int* intro_screen::getResponsiveLocation(int x_size, int y_size)
{
	int x_resized = x_size * 0.33;
	int y_resized = y_size * 0.33;
	int arr_pos[1];
	arr_pos[0] = x_resized;
	arr_pos[1] = y_resized;
	int *pArr = arr_pos;
	return pArr;
}

void intro_screen::showPassword(Object^ Sender, EventArgs^ e)
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

void intro_screen::registerUser(Object^ Sender, EventArgs^ e)
{

}