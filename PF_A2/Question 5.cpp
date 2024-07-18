//#include<iostream>
//using namespace std;
//int main()
//{
//	int t_amnt, d_lmt, amnt,r_amnt,x,y,z,a,b,c;//declaring and initializing variadles
//	cout << "Enter the total amount in your ATM account:" << endl;
//	cin >> t_amnt;
//	cout << "Enter your maximum daily withdrawal limit:" << endl;
//	cin >> d_lmt;
//	cout << "Enter the amount you want to withdraw:" << endl;
//	cin >> amnt;
//	if ((amnt >= t_amnt) || (amnt > d_lmt))
//	{
//		cout << "Sorry! invalid amount" << endl;//handling invalid amount
//		return 0;
//	}
//		if (amnt % 500 == 0)
//		{
//			r_amnt = amnt - 500;
//			x = r_amnt / 5000;//calculating 5000 notes
//			y = r_amnt % 5000;//calculating remaining amount
//			z = y / 1000;//calculating 1000 notes
//			a = y % 1000;//calculating remaining amount
//			b = a / 500;//calculating 500 notes
//			c = ++b;//total 500 notes
//			cout << "Currency notes of 5000:" << x << endl;//displaying 5000 notes
//			cout << "Currency notes of 1000:" << z << endl;//displaying 1000 notes
//			cout << "Currency notes of 500:" <<c << endl;//displaying 500 notes
//		}
//		else
//		{
//			cout << "Invalid amount ,Sorry!" << endl;//handling invalid amount
//			return 0;
//		}
//}