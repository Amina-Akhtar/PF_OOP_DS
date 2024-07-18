#include "mainorm.h"
#include"startform.h"
#include"lastform.h"
#include"classes.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;

System::Void L226198A3::startform::start_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ n = tbn->Text;
	String^ k = tbk->Text;
	int temp_n = Convert::ToInt32(n);
	int temp_k = Convert::ToInt32(k);
	if (tbn->Text->Length == 0 || tbk->Text->Length == 0||temp_n<=1||temp_k<0)
	{
		MessageBox::Show("Please provide the accurate (+ve) details");
	}
	else
	{
		StreamWriter^ write = gcnew StreamWriter("Input.txt");
		write->WriteLine(n);
		write->WriteLine(k);
		write->Close();
		mainorm^ obj = gcnew mainorm();
		obj->Show();
		this->Hide();
	}
}