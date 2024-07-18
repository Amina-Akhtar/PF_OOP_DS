//#include<iostream>
//using namespace std;
//int main()
//{
//		int array[100] = { 0 }, N, temp;
//	n:
//		cout << "Enter the size of array: ";
//		cin >> N;
//		if (N < 0||N>100)
//		{
//			cout << "Invalid size! \n";
//			goto n;
//		}
//		cout << "Enter the elements of array: \n";
//		for (int i = 0; i < N; i++)
//		{
//			cin >> array[i];
//		}
//		for (int k = 0; k <= N; k++)
//		{
//			for (int i = 0, j = 1; (i < N && j < N); i++, j++)
//			{
//				if (array[i] > array[j])
//				{
//					temp = array[i];
//					array[i] = array[j];
//					array[j] = temp;
//				}
//			}
//		}
//		for (int i = 0,k=0, j = N - 1;k < N;k++ )
//		{
//			if (k % 2 == 0)
//			{
//				cout << array[i]<<" ";
//				i++;
//			}
//			else if (k % 2 != 0)
//			{
//				cout << array[j]<<" ";
//				j--;
//			}
//		}
//}