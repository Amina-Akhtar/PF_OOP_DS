//#include<iostream>
//#include<iomanip>//settling the width
//using namespace std;
//int main()
//{
//	int x = 0, r, z = 1, t = 0,u;
//	char n;
//	//taking input from user
//	cout << "enter the number:";
//	cin >> r;
//	
//	cout << "enter the character you want to print:";//taking input charcter to print
//	cin >> n;
//	 u = r - 1;
//	for (int i = 1; i <= r; i++, x = x + 2)
//	{
//		for (int j = 1; j <= r - i; j++)
//		{
//			cout << setw(3)<<" ";
//		}
//		for (int k = 1; k <= r + x; k++)
//		{
//			cout << setw(3) << n;
//		}
//		cout << endl;//moving to the next row
//	}
//	for (int i = 1,w=(u+(u*2))-1; i <= r - 1; i++, z++, w = w - 2)
//	{
//		for (int j = 0; j < z; j++)
//		{
//
//			cout << setw(3) << " ";
//		}
//		for(int k=1; k <=w;k++)
//		{
//			cout << setw(3)<<n;
//			
//		}
//		
//		cout << endl;//moving to the next row
//		
//	}
//
//	return 0;
//}
//
//   