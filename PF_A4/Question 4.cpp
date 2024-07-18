//#include<iostream>
//using namespace std;
//void MIN(int A[], int B[], int M, int N)
//{
//	int C[100] = { 0 };
//	int slong = M + N - 1;
//	int perslong = slong;
//	int countevenA = 0, countoddA = 0;
//	for (int i = 0, k = 0; i < M; i++)
//	{
//		if (A[i] % 2 == 0)
//		{
//			countevenA++;
//			C[k] = A[i];
//			k++;
//		}
//		else if (A[i] % 2 != 0)
//		{
//			countoddA++;
//			C[slong] = A[i];
//			slong--;
//		}
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (B[i] % 2 == 0)
//		{
//			C[countevenA] = B[i];
//			countevenA++;
//		}
//		else if (B[i] % 2 != 0)
//		{
//			C[slong] = B[i];
//			slong--;
//		}
//	}
//     cout << "{ ";
//	for(int i = 0; i <= perslong; i++)
//
//	{
//	cout << C[i];
//	if (i < perslong)
//	{
//		cout << " , ";
//	}
//    }
//	cout << " }";
//}
//int main()
//{
//	int A[100], B[100], M, N;
//	kal:
//	cout << "Enter the size of first array: ";
//	cin >> M;
//	if (M < 0 || M>100)
//	{
//		cout << "Invalid size entered! \n";
//		goto kal;
//	}
//	cout << "Enter the elements of first array:\n";
//	for (int i = 0; i < M; i++)
//	{
//		cin >> A[i];
//	}
//   cal:
//	cout << "Enter the size of second array: ";
//	cin >> N;
//	if (N < 0 || N>100)
//	{
//		cout << "Invalid size entered! \n";
//		goto kal;
//	}
//	cout << "Enter the elements of second array:\n";
//	for (int i = 0; i < N; i++)
//	{
//		cin >> B[i];
//	}
//	MIN(A, B, M, N);
//}