#include"Appointment.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	Appointment *Appoint = new Appointment[20];
	string description,type;
	char unit = ' ';
	int year, month, day, hint = 1,index = 0;
	ofstream write;
	write.open("appointment.txt", ios::out);
	write.close();
	while (hint == 1&&index<20)
	{
			cout << "Enter the type of appointment (o-Onetime,d-Daily,m-Monthly):" << endl;
			cin >> type;
			while ((type != "o" && type != "d" && type != "m") &&( type != "O" && type != "D" && type != "M"))
			{
				cout << "Enter a valid appointment type:";
				cin >> type;
			}
			cout << "Enter the description: ";
			cin.ignore();
			getline(cin, description);
			cout << "Enter a date (YYYY MM DD): " << endl;
			cin >> year;
		             	while (year < 0)
		 				{
							cout << "Invalid year!";
							cin >> year;
						}
						cin >> month;
						while (month<0||month>12)
						{
							cout << "Invalid month!";
							cin >> month;
						}
						cin>> day;
						while (day < 0||day>30)
						{
							cout << "Invalid day!";
							cin >> day;
						}
			if (type == "o")
			{
				Onetime once("Onetime",description, year, month, day);
				Appoint[index++] = once;
				cout << "To save data to file press y:";
				cin >> unit;
				if (unit == 'y' || unit == 'Y')
				{
					write.open("appointment.txt", ios::app);
					write << Appoint[index-1].gettype() << ",";
					write << Appoint[index-1].getdescription() << ",";
					write << Appoint[index-1].getyear() << ",";
					write << Appoint[index - 1].getmonth() << ",";
					write << Appoint[index - 1].getday() << "\n";
					write.close();
					cout << "------------------------------------" << endl;
					cout << "The data has been saved to the file!" << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else if (type == "d")
			{
				Daily daily("Daily",description, year, month, day);
				Appoint[index++] = daily;
				cout << "To save data to file press y:";
				cin >> unit;
				if (unit == 'y' || unit == 'Y')
				{
					write.open("appointment.txt", ios::app);
					write << Appoint[index - 1].gettype() << ",";
					write << Appoint[index - 1].getdescription() << ",";
					write << Appoint[index - 1].getyear() << ",";
					write << Appoint[index - 1].getmonth() << ",";
					write << Appoint[index - 1].getday() << "\n";
					write.close();
					cout << "------------------------------------" << endl;
					cout << "The data has been saved to the file!" << endl;
					cout << "------------------------------------" << endl;
				}
			}
			else if (type == "m")
			{
				Monthly mnth("Monthly",description, year, month, day);
				Appoint[index++] = mnth;
				cout << "To save data to file press y:";
				cin >> unit;
				if (unit == 'y' || unit == 'Y')
				{
					write.open("appointment.txt", ios::app);
					write << Appoint[index - 1].gettype() << ",";
					write << Appoint[index - 1].getdescription() << ",";
					write << Appoint[index - 1].getyear() << ",";
					write << Appoint[index - 1].getmonth() << ",";
					write << Appoint[index - 1].getday() << "\n";
					write.close();
					cout << "------------------------------------" << endl;
					cout << "The data has been saved to the file!" << endl;
					cout << "------------------------------------" << endl;
				}
			}
			cout << "To add another appointment press 1:" << endl;;
		cout << "(Entering other key will load the data from the file) " << endl;
		cin >> hint;
		cout << "--------------------------------------" << endl;
	}
	system("CLS");
	           ifstream get;
				get.open("appointment.txt");
				string temp,des, d, m, y;
				int mine = 0;
				if (get.fail())
				{
					cout << "-----------------------------------------------" << endl;
					cout << "No data can be loaded becuse the file is empty!" << endl;
					cout << "-----------------------------------------------" << endl;
				}
				else
				{
					while (!get.eof())
					{
						getline(get, temp, ',');
						getline(get, des, ',');
						getline(get, y, ',');
						getline(get, m, ',');
						getline(get, m, '\n');
						mine++;
					}
					get.close();
                    int you=mine-1;
					Appointment* data = new Appointment[you];
					get.open("appointment.txt");
					for (int i = 0; i < mine-1; )
					{
						getline(get, temp, ',');
						getline(get, des, ',');
						getline(get, y, ',');
						getline(get, m, ',');
						getline(get, d, '\n');
						if (temp == "Onetime")
						{
							Onetime once(temp, des, stoi(y), stoi(m), stoi(d));
							data[i++] = once;
	
						}
						else if (temp == "Daily")
						{
							Daily daily(temp, des, stoi(y), stoi(m), stoi(d));
							data[i++] = daily;
						}
						else if (temp == "Monthly")
						{
							Monthly month(temp, des, stoi(y), stoi(m), stoi(d));
							data[i++] = month;
						}
					}
					cout << "-----------------------------------------------" << endl;
					cout << "The data loaded from the file is:\n" << endl;
	
					for (int i = 0; i < mine-1; i++)
					{
						cout << i + 1 << ". " << data[i].gettype() << " appointment: ";
						cout << data[i].getdescription() << " ";
						cout << data[i].getyear() << "/";
						cout << data[i].getmonth() << "/";
						cout << data[i].getday() << endl;
					}
					cout << "-----------------------------------------------" << endl;
					//deallocating the memory
					delete[]data;
				}
delete[]Appoint;
}