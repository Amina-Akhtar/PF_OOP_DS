//#include"customer invoice.h"
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//customer::customer()
//{
//	id = 0;
//	name = " ";
//	discount = 0;
//}
//customer::customer(int id,string name,int discount)
//{
//	this->id = id;
//	this->name = name;
//	this->discount = discount;
//}
//void customer::setdata_c(int ide, string nam, int dis)
//{
//	id = ide;
//	name = nam;
//	discount = dis;
//}
//int customer::getID()
//{
//	return id;
//}
//string customer::getname()
//{
//	return name;
//}
//int customer::getdiscount()
//{
//	return discount;
//}
//string customer::tostring()
//{
//	return name + "(" + to_string(id) + ")(" + to_string(discount) + "%)";
//}
//
//invoice::invoice()
//{
//	id = 0;
//    amount=0;
//}
//invoice::invoice(int id, customer cust, double amount)
//{
//	this->id = id;
//	this->cust = cust;
//	this->amount = amount;
//}
//void invoice::setdata_i(int ide, customer c, double amnt)
//{
//	id = ide;
//	amount = amnt;
//	cust = c;
//}
//int invoice::getid()
//{
//	return id;
//}
//customer invoice::getcustomer()
//{
//	return cust;
//}
//double invoice::getamount()
//{
//	return amount;
//}
//int invoice::getcustomerid()
//{
//	return cust.getID();
//}
//string invoice::getcustomername()
//{
//	return cust.getname();
//}
//int invoice::getcustomerdiscount()
//{
//	return cust.getdiscount();
//}
//double invoice::getamountafterdiscount()
//{
//	this->amount = amount-(amount * cust.getdiscount()/ 100);
//	return this->amount;
//}
//string invoice::tostring(customer cust)
//{
//	return "Invoice[ ID= " + to_string(id) +" Customer= " + cust.tostring() + " Amount= " + to_string(amount)+" ]";
//}
//
//void savetofile(customer cust, invoice voice)
//{
//	ofstream write;
//	write.open("customers.txt",ios::app );
//	write << voice.getcustomerid() << " " << voice.getcustomername() << " " << voice.getcustomerdiscount() << endl;
//	write.close();
//	write.open("invoices.txt", ios::app);
//	write << voice.getid() << " " << voice.getamount() <<" " << voice.getcustomerid()<<endl;
//	write.close();
// }
//double** loadfileinvoice(int &check)
//{
//	int id,iid;
//	double amount;
//	string name;
//	ifstream read;
//	read.open("invoices.txt");
//	while (!read.eof())
//	{
//		read >> iid >> amount >> id;
//		check++;
//	}
//	read.close();
//	//because endl has moved to next line so check is 1 number greater
//	check -= 1;
//	read.open("invoices.txt");
//	double** array = new double * [check];
//	for (int i = 0; i < check; i++)
//	{
//		array[i] = new double[3];
//	}
//	for (int i = 0; i < check; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			read >> array[i][j];
//		}
//	}
//	read.close();
//	return array;
//}
//string** loadfilecustomer(int check)
//{
//	ifstream read;
//	read.open("customers.txt");
//	string** data = new string* [check];
//	for (int i = 0; i < check; i++)
//	{
//		data[i] = new string[3];
//	}
//	for (int i = 0; i < check; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			read >> data[i][j];
//		}
//	}
//	return data;
//}
//int main()
//{
//	customer cust;
//	invoice voice;
//	double** array = NULL;
//	string** custom = NULL;
//	int choice = 0, id, iid, amount = 0, discount,check=0;
//	string name;
//	do {
//		cout << "---------------------------" << endl;
//		cout << "          MENU" << endl;
//		cout << "1. Generate invoice" << endl;
//		cout << "2. Load the data from file" << endl;
//		cout << "3.Terminate the program " << endl;
//		cout << "---------------------------" << endl;
//		cout << "Enter your choice:";
//		cin >> choice;
//		while (choice <= 0 || choice > 3)
//		{
//			cout << "Please enter a valid choice!";
//			cin >> choice;
//		}
//	if (choice == 1)
//			{
//				//to generate new invoice
//				cout << "Enter the customer id: ";
//				cin >> id;
//				cout << "Enter the customer name: ";
//				cin.ignore();
//				getline(cin, name);
//				cout << "Enter the discount percentage: ";
//				cin >> discount;
//				while (discount < 0)
//				{
//					cout << "Discount must be greater than 0!";
//					cin >> discount;
//				}
//				iid = rand() % 51;
//				cout << "Enter the amount: ";
//				cin >> amount;
//				while (amount < 0)
//				{
//					cout << "Discount must be greater than 0!";
//					cin >> amount;
//				}
//				cust.setdata_c(id, name, discount);
//				cust.getID();
//				cust.getname();
//				cust.getdiscount();
//				cust.tostring();
//				voice.setdata_i(iid, customer(id, name, discount), amount);
//				voice.getid();
//				voice.getcustomer();
//				voice.getamount();
//				voice.getcustomerid();
//				voice.getcustomername();
//				voice.getcustomerdiscount();
//				voice.getamountafterdiscount();
//				cout << "-----------------------------------------------------------" << endl;
//				cout << voice.tostring(cust) << endl;
//				savetofile(cust, voice);
//				cout << "-----------------------------------------------------------" << endl;
//			}
//		
//			else if (choice == 2)
//			{
//				int hint = 0, identity, count = 0;
//				array = loadfileinvoice(check);
//				custom = loadfilecustomer(check);
//				cout << "-----------------------------------------------------------" << endl;
//				cout << "The data has been loaded successfully!" << endl;
//				cout << "-----------------------------------------------------------" << endl;
//				do
//				{
//					cout << "              MENU" << endl;
//					cout << "1. Search invoice details" << endl;
//					cout << "2. Display all the invoices" << endl;
//					cout << "Enter your choice: ";
//					cin >> hint;
//					if (hint == 1)
//					{
//						cout << "Enter the customer id :";
//						cin >> identity;
//						for (int i = 0; i < check; i++)
//						{
//							if (identity == array[i][2])
//							{
//								count++;
//								cout << "Invoice[ ID= ";
//								for (int j = 0; j < 2; j++)
//								{
//									cout << array[i][j] << " ";
//									if (j == 1)
//										cout << "Amount =";
//								}
//								cout << " ";
//								cout << "Customer ";
//								for (int k = 0; k < 3; k++)
//								{
//									cout << "( " << custom[i][k] << " )";
//								}
//								cout << " ]" << endl;
//							}
//						}
//						cout << "-----------------------------------------------------------" << endl;
//						if (count == 0)
//						{
//							cout << "Sorry! This customer id does not exist." << endl;
//							cout << "-----------------------------------------------------------" << endl;
//						}
//					}
//					else if (hint == 2)
//					{
//						if (check == 0)
//						{
//							cout << "--------------------------------------------------" << endl;
//							cout << "No data is available to be dispalyed!" << endl;
//							cout << "-----------------------------------------------------------" << endl;
//						}
//						else
//						{
//							for (int i = 0; i < check; i++)
//							{
//								cout << "Invoice[ ID= ";
//								for (int j = 0; j < 2; j++)
//								{
//									cout << array[i][j];
//									if (j == 1)
//										cout << " Amount =";
//								}
//								cout << " ";
//								cout << "Customer ";
//								for (int k = 0; k < 3; k++)
//								{
//									cout << "(" << custom[i][k] << ") ";
//								}
//								cout << " ]" << endl;
//							}
//							cout << "-----------------------------------------------------------" << endl;
//						}
//					}
//				} while (hint == 0 || hint == 1 || hint == 2);
//			}
//	} while (choice != 3);
//	if (choice==3)
//	{
//		cout << "--------------------------------" << endl;
//		cout << "The program has been terminated!" << endl;
//		cout << "--------------------------------" << endl;
//		return 0;
//	}
//	for (int i = 0; i < check; i++)
//	{
//		delete[]array[i];
//		array[i] = nullptr;
//	}
//	delete[]array;
//	for (int i = 0; i < check; i++)
//	{
//		delete[]custom[i];
//		custom[i] = nullptr;
//	}
//	delete[]array;
// }