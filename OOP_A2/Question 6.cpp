//#include"Appointment.h"
//#include<iostream>
//
//using namespace std;
//int main()
//{
//	// create some appointments
//	Onetime dentist("See the dentist", 2023, 4, 15);
//	Daily gym("Go to the gym", 2023, 4, 8);
//	Monthly rent("Pay rent", 2023, 4, 1);
//	// put them in an array 
//	Appointment* appointments[] = { &dentist, &gym, &rent };
//	// get a date from the user
//	int year, month, day, choice=1;
//	while (choice == 1)
//	{
//		cout << "-----------------------------------" << endl;
//		cout << "Enter a date (YYYY MM DD): "<<endl;
//		cin >> year;
//		while (year < 0)
//		{
//			cout << "Invalid year!";
//			cin >> year;
//		}
//		cin >> month;
//		while (month<0||month>12)
//		{
//			cout << "Invalid month!";
//			cin >> month;
//		}
//		cin>> day;
//		while (day < 0||day>30)
//		{
//			cout << "Invalid day!";
//			cin >> day;
//		}
//		for (int i = 0; i < 3; i++) 
//		{
//			if (appointments[i]->occursOn(year, month, day))
//			{
//				choice = 0;
//				cout << appointments[i]->getdescription() << " ";
//				cout << appointments[i]->getyear() << "/";
//				cout << appointments[i]->getmonth() << "/";
//				cout << appointments[i]->getday() << endl;
//			}
//		}
//		cout << "-----------------------------------" << endl;
//		if (choice == 1)
//		{
//			cout << "No Appointment on this date!" << endl;
//			cout << "-----------------------------------" << endl;
//		}
//
//		cout << "To continue press 1:";
//		cin >> choice;
//	}
//	if (choice != 1)
//	{
//		system("CLS");
//		cout << "-----------------------------------" << endl;
//		cout<<"The program has been terminated"<<endl;
//		cout << "-----------------------------------" << endl;
//		return 0;
//	}
//	//	Complete the main by calling function from array in loop.
//}