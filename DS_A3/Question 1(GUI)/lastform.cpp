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
using namespace L226198A3;

System::Void L226198A3::lastform::lastform_Load(System::Object^ sender, System::EventArgs^ e)
{

	StreamReader^ read = gcnew StreamReader("Random.txt");
	winner->Text = read->ReadLine();
	read->Close();
	StreamWriter^ edit = gcnew StreamWriter("Random.txt", false);
	edit->WriteLine(" ");
	edit->Close();
}
System::Void L226198A3::lastform::End_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	Application::Exit();
}
