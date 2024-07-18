//#include<iostream>
//#include<cstdlib>
//#include<ctime>
//#include<time.h>
//using namespace std;
//int main()
//{
//	srand(time(0));
//	int lot, sizlot, chk=0;
//	int lottery[1000] = { 0 };
//	int user[1000] = { 0 };
//n:
//	cout << "Enter the size of array which is same for both user and lottery array: ";
//	cin >> sizlot;
//	if (sizlot < 0 || sizlot>1000)
//	{
//		cout << "Invalid size: \n ";
//		goto n;
//	}
//	for (int i = 0; i < sizlot; i++)
//	{
//		lot= rand() % 6 + 4;
//		lottery[i] = lot;
//	}
//	cout << "Enter the elements of user array:" << endl;
//	for (int i = 0; i < sizlot; i++)
//	{
//		cin >> user[i];
//	}
//	cout << "The elements of lottery array are ";
//	for (int i = 0; i < sizlot; i++)
//	{
//		cout << lottery[i]<<" ";
//	}
//	cout << endl;
//	for (int i = 0; i < sizlot; i++)
//	{
//		if (lottery[i] == user[i])
//		{
//			chk++;
//			cout <<"The number "<< lottery[i] << " at index "<<i<< " is matching \n";
//		}
//	}
//	cout << "The number of matching digits is " << chk << " \n";
//	if (chk == sizlot)
//	{
//		cout << "You are the grand prize winner of this lottery!";
//	}
//   return 0;
//}