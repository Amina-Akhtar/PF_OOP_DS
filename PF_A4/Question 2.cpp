//#include<iostream>
//using namespace std;
//int main()
//{
//	long int empld[7] = { 5658845,4520125, 7895122,8777541, 8451277, 1302850, 7580489 };
//	int hour[7] = { 0 };
//	double payrate[7] = { 0 };
//	double wages[7] = { 0 };
//	for (int i = 0; i < 7; i++)
//	{
//		double grosswage = 0;
//		cout << "For employee number " << empld[i] << " :" << endl;
//		cout << "Enter the number of hours worked :";
//	n:
//		cin >> hour[i];
//		if (hour[i] < 0)
//		{
//			cout << "Invalid hours. Please enter hours greater than zero.\n";
//			goto n;
//		}
//		cout << "Enter the employee's pay rate: ";
//		m:
//		cin >> payrate[i];
//		if (payrate[i] < 6.00)
//		{
//			cout << "Invalid payrate. Please enter payrate greater than 6.00.\n";
//			goto m;
//		}
//		grosswage = hour[i] * payrate[i];
//		wages[i] = grosswage;
//		cout << "                                                        " << endl;
//	}
//	cout << "_______________________________________________________\n";
//	for (int i = 0; i < 7; i++)
//	{
//		cout << "The employee " << empld[i] << " has gross wages " << wages[i] <<"."<< endl;
//		cout << "                                                                    \n";
//    }
//}