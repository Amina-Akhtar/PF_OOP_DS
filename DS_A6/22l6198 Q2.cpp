//#include<iostream>
//using namespace std;
//void heapify(int arr[], int n, int i)
//{
//	int smallest = i;
//	int l = 2 * i + 1;
//	int r = 2 * i + 2;
//	if (l < n && arr[l] < arr[smallest])
//	{
//		smallest = l;
//	}
//	if (r < n && arr[r] < arr[smallest])
//	{
//		smallest = r;
//	}
//	if (smallest != i)
//	{
//		swap(arr[i], arr[smallest]);
//		heapify(arr, n, smallest);
//	}
//}
//void printtree(int arr[], int n)
//{
//		int next = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cout << arr[i]<<" ";
//			if (i == next)
//			{
//				cout << endl; 
//				next = 2 * next + 2;
//			}
//
//		}
//	}
//void printarr(int arr[], int n)
//{
//		for (int i = 0; i < n; i++)
//		{
//			cout << arr[i] << " ";
//		}
//}
//int main()
//{
//	int arr[] = { 6,5,3,9,1,2,10,8 };
//	int n = sizeof(arr) / sizeof(int);
//	cout << "Original array:" << endl;
//	printarr(arr, n);
//	for (int i = n / 2 - 1; i >= 0; i--)
//	{
//		heapify(arr, n, i);
//	}
//	cout << "\nHeapify array: " << endl;
//	printarr(arr, n);
//	cout << "\nHeapify tree: " << endl;
//	printtree(arr, n);
//}