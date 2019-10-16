#using <mscorlib.dll>
#using <System.dll>
#using <System.Drawing.dll>
#using <System.Windows.Forms.dll>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

public ref class SimpleForm : public Form
{
public: 
	SimpleForm();
	int getResponsiveLocation(int actual_size);

	unsigned int MAX_HEIGHT_WINDOW = 780;
	unsigned int MAX_WIDTH_WINDOW = 640;
private:
	Label^	  u_label;
	Label^	  p_label;
	TextBox^  user;
	TextBox^  password;
	CheckBox^ unlock_password;
	Button^   login_btn;
	void showPassword(Object^ Sender, EventArgs^ e);
};

SimpleForm::SimpleForm()
{
	this->Text = L"Hola Pariente Kun - Login para algo inutil xDxDxDDddxxxddXXDxdD";
	this->Size = Drawing::Size(MAX_HEIGHT_WINDOW, MAX_WIDTH_WINDOW);

	int pos_x = getResponsiveLocation(MAX_HEIGHT_WINDOW);
	int pos_y = getResponsiveLocation(MAX_WIDTH_WINDOW);

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
	unlock_password->Click += gcnew System::EventHandler(this, &SimpleForm::showPassword);
	//Button Settings
	login_btn = gcnew Button;
	login_btn->Location = Point(pos_x + 56, pos_y + 92);
	login_btn->Text = L"Login";
	login_btn->AutoSize = true;

	//Adding elements to window
	this->Controls->Add(u_label);
	this->Controls->Add(p_label);
	this->Controls->Add(user);
	this->Controls->Add(password);
	this->Controls->Add(unlock_password);
	this->Controls->Add(login_btn);
}

int __stdcall WinMain()
{
	SimpleForm^ windowsKK = gcnew SimpleForm;
	Application::Run(windowsKK);

	return 0;
}

int SimpleForm::getResponsiveLocation(int actual_size)
{
	int resized = actual_size * 0.33;
	return resized;
}

void SimpleForm::showPassword(Object^ Sender, EventArgs^ e)
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