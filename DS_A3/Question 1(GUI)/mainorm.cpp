#include "mainorm.h"
#include"startform.h"
#include"lastform.h"
#include"classes.h"
#include<Windows.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace L226198A3;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew startform());
	return 0;
}
System::Void L226198A3::mainorm::mainorm_Load(System::Object^ sender, System::EventArgs^ e)
{
	srand(time(nullptr));
	queue_data<int>^ q = gcnew queue_data<int>();
	StreamReader^ gett = gcnew StreamReader("Input.txt");
	String^ n = gett->ReadLine();
	String^ k = gett->ReadLine();
	gett->Close();
	StreamWriter^ date = gcnew StreamWriter("Input.txt", false);
	date->WriteLine(" ");
	date->Close();
	int num = Convert::ToInt32(n);
	int val = Convert::ToInt32(k);
	for (int i = 1; i <= num; i++)
	{
		q->enqueue(i);
	}
	while (q->front != q->rear)
	{
		q->getwinner(val);
		playersprocess->Text = playersprocess->Text+"Players updated: \r\n";
		num--;
		StreamReader^ red = gcnew StreamReader("Random.txt");
		for (int i = 0; i < num; i++)
		{
			String^ temp = red->ReadLine();
			playersprocess->Text = playersprocess->Text + temp + "\r\t";
		}
		red->Close();
		playersprocess->Text = playersprocess->Text + "\r\n";
	}
}
System::Void L226198A3::mainorm::buttonwin_Click(System::Object^ sender, System::EventArgs^ e)
{
	lastform^ obj = gcnew lastform();
	obj->Show();
	this->Hide();
}
