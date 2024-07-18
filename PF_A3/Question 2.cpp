//#include <iostream>
//using namespace std;
//int main()
//{
//	condition:
//		long  int ch, x,k, r = 0, f = 1, xf = 1, n = 0, per = 0, rf = 1, comm = 0, comd = 0;
//		//displaying menu for output
//		cout << "For factorial press 1:\n";
//		cout << "For permutation press 2:\n";
//		cout << "For * combinaion press 3:\n";
//		cout << "For / combinaion press 4:\n";
//		cout << "To exit the program press 5\n";
//		cout << "Enter your choice\n";
//		cin >> ch;
//		cout << "_____________________________________________\n";
//		
//
//		if (ch == 1)
//		{
//			cout << "Enter the  positive number:\n";//taking input from user
//			cin >> n;
//			if (n == 0)
//				f = 1;
//			else if (n < 0)
//			{
//				cout << "Not possible!";
//				return 0;
//			}
//			else {
//				while (n >= 1)
//				{
//					f = f * n;
//					n--;
//				}
//			}
//			cout << "The factorial is " << f << endl;
//		}
//		if (ch == 2 || ch == 3 || ch == 4)
//		{
//			cout << "Enter the  positive number:\n";
//			cin >> n;
//			cout << "Enter the number of ways : \n";
//			cin >> r;
//			x = n - r;
//			if (x == 0) xf = 1;
//			if (r == 0)  rf = 1;
//			if (n == 0) f = 1;
//			else if (x < 0) {
//				cout << "Not possible!";
//				return 0;
//			}
//			else if (r < 0)
//			{
//				cout << "Not possible!";
//				return 0;
//			}
//			else if (n < 0)
//			{
//				cout << "Not possible!";
//				return 0;
//			}
//			//performing calculations
//			else
//			{
//				while (x >= 1)
//				{
//					xf = xf * x;
//					x--;
//				}
//				while (r >= 1) {
//					rf = rf * r;
//					r--;
//				}
//				while (n >= 1)
//				{
//					f = f * n;
//					n--;
//				}
//			}
//			per = f / xf;
//			comm = f / (xf * rf);
//			comd = per / rf;
//			//displaying output
//			if (ch == 2)
//				cout << "The permutation is " << per << endl;
//			if (ch == 3)
//				cout << "The * combination is " << comm << endl;
//			if (ch == 4)
//				cout << "The / combination is " << comd << endl;
//		}
//		if (ch == 5)
//		{
//			system("pause");
//		}
//	
// cout<<"__________________________________________________"<<endl;
// cout << "Press 0 to continue and 1 to terminate the program" << endl;// asking the choice to continue or terminate the program
// cin >> k;
// if (k == 0)
//	 goto condition;
// else if (k == 1)
//	 return 0;
//return 0;
//}