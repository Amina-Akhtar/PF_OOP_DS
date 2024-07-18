//#include"teacher's courses.h"
//#include<iostream>
//#include<string>
//using namespace std;
//courses::courses()
//{
//	id = 0;
//	title = " ";
//	teacherid = 0;
//}
//void courses::getdata(int tid)
//{
//	cout << "Enter the course id (XXXX): ";
//	cin >> id;
//	while (id < 999 || id>10000)
//	{
//		cout << "Please enter a valid id (XXXX):";
//		cin >>id;
//	}
//	cout << "Enter the course name: ";
//	cin.ignore();
//	getline(cin,title);
//	teacherid = tid;
//}
//void courses::information()
//{
//	cout << id << "\t\t" << title << "\t\t" << teacherid << endl;
//}
//teachers::teachers()
//{
//	tid = 0;
//	name = " ";
//	list = nullptr;
//}
//void teachers::addcourse(teachers teach[10],int check,int number)
//{
//	teach[check].list = new courses[number];
//	cout << "Enter the teacher id (XXXX): ";
//	cin >> teach[check].tid;
//	while (teach[check].tid < 999 || teach[check].tid>10000)
//	{
//		cout << "Please enter a valid id (XXXX):";
//		cin >> teach[check].tid;
//	}
//	cout << "Enter the teacher name: ";
//	cin.ignore();
//	getline(cin, teach[check].name);
//	int done= teach[check].tid;
//	cout << "----------------------------------------" << endl;
//	for (int i = 0; i < number;i++)
//	{
//		teach[check].list[i].getdata(done);
//	}
//}
//void teachers::display(teachers teach[10], int count,int number)
//{
//	for (int i = 0; i < count; i++)
//	{
//		cout << "Teacher ID:\t" << teach[i].tid << endl;
//		cout << "Teacher name:\t" << teach[i].name << endl;
//		cout << "------------------------" << endl;
//		cout << "COURSE ID\tCOURSE NAME\tTEACHER ID" << endl;
//		for (int j = 0; j < number; j++)
//		{
//			teach[i].list[j].information();
//		}
//		cout << "----------------------------------------" << endl;
//	}
//}
//teachers::~teachers()
//{
//	delete[]list;
//}
//void menu()
//{
//	cout << "------------MENU-----------" << endl;
//	cout << "1. Add a new course " << endl;
//	cout << "2. Display all the courses " << endl;
//	cout << "3.Exit the program " << endl;
//	cout << "----------------------------------------" << endl;
//}
//int main()
//{
//	int choice,check=0,number;
//	teachers teach[10], hint;
//	for (int i = 0; i < 10; i++)
//	{
//		menu();
//		cout << "Enter you choice: ";
//		cin >> choice;
//		cout << "----------------------------------------" << endl;
//		while (choice < 0 || choice>3)
//		{
//			cout << "Please enter a valid choice:";
//			cin >> choice;
//		}
//		if (choice == 1)
//		{
//			cout << "Enter the number of courses teacher can teach:";
//			cin >> number;
//			while (number <= 0)
//			{
//				cout << "Invalid number entered!";
//				cin >> number;
//			}
//			hint.addcourse(teach, check,number);
//			check++;
//			system("CLS");
//		}
//		else if (choice == 2)
//		{
//			if (check == 0)
//			{
//				cout << "No data available to be displayed!" << endl;
//			}
//			else
//			{
//				hint.display(teach, check,number );
//			}
//		}
//		else if (choice == 3)
//		{
//			system("CLS");
//			cout << "----------------------------------------" << endl;
//			cout << "The program has been terminated!" << endl;
//			cout << "----------------------------------------" << endl;
//			return 0;
//		}
//	}
//	return 0;
//}