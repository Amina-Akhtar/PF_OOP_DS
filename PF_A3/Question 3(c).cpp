//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int N;
//	cout << " Provide a number you want to build a program against: ";//taking input from user
//	cin >> N;
//	//performing the calculations to display the pattern
//	for (int i = N - 1; i >= 0; i--)
//	{
//		int k = i;
//		while (k)
//		{
//			cout << " ";
//			k--;
//		}
//		if (i == N - 1)
//		{
//			cout << "*\n";
//			continue;
//		}
//		cout << "*";
//
//		k = N - i - 2;
//		while (k)
//		{
//			cout << " ";
//			k--;
//		}
//		cout << "*";
//		k = N - i - 2;
//		while (k)
//		{
//			cout << " ";
//			k--;
//		}
//		cout << "*\n";
//
//	}
//	int i = N;
//	while (i)
//	{
//		int k = N - 1;
//		while (k)
//		{
//			cout << " ";
//			k--;
//		}
//		cout << "*\n";
//		i--;
//	}
//	return 0;
//}