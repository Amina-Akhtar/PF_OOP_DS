//#include<iostream>
//#include<iomanip>//managing the spaces
//using namespace std;
//int main()
//{
//	int r, k =1,x=0,s=1,h=0 ;
//	cout << "Enter the number:";//taking input from user
//	cin >> r;
//	
//     displaying the possible pattern and managing the spaces for two and three digit numbers
//	for (int i = 1;i <= r; i++,x++)
//	{
//		for (int s = r,l=1; s >= i; s--,l++)
//		{
//			cout <<setw(3)<<l;
//		}
//		for (int j = 1, k = i - 1; j <= i * 2 - 1; j++)
//		{
//			
//				cout << setw(3)<<" ";
//		
//		}
//		for (int  s = r-x; s >= 1; s--)
//		{
//			cout <<setw(3)<<s;
//		}
//		cout << endl;//moving to the next row
//		
//		
//	}
//	for (int g=2, i = r - 1; i >= 1; i--,g++)
//	{
//		for (int s= r,l=1; s>=i; s--,l++)
//		{
//			cout <<setw(3)<<l;
//		}
//		for (int j = 1, k = i - 1; j <= i * 2 - 1; j++)
//		{
//			
//				cout << setw(3)<<" ";
//		}
//		for (h=h+g ; h >= 1; h--)
//		{
//			cout << setw(3)<<h;
//		}
//		cout << endl;//moving to the next row
//	}
//	return 0;
//}