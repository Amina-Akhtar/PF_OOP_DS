//#include<iostream>
//using namespace std;
//void input(int** array,int rows,int columns)
//{
//	cout << "Enter the elements of the array" << endl;
//
//	for (int i = 0; i < rows; i++)
//	{
//		cout << "Row " << i+1 << " :" << endl;
//		for (int j = 0; j < columns; j++)
//		{
//			cin >> array[i][j];
//		}
//	}
//}
//
//int *calculate(int** array, int rows, int columns,int *temp)
//{
//	
//	for (int i = 0,k=0,hint=0; i < rows; i++,hint=0)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (array[i][j] > 0)
//			{
//				hint++;
//			}
//		}
//		temp[k++] = hint;
//	}
//	return temp;
//}
//
//void store_result(int** array, int rows, int columns, int** resultant)
//{
//	int count = 0;
//	
//	for (int i = 0, k = 0; i < rows; i++,count++,k=0)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (array[i][j] > 0)
//			{
//				resultant[count][k++] = array[i][j];
//			}
//		}
//		
//		resultant[count][k] = -1;
//	}
//}
//
//void output(int** resultant, int rows, int columns,int *temp)
//{
//	cout<< "_________________________________________________________________\n";
//	cout << "The resultant array :" << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < temp[i]; j++)
//		{
//			cout << resultant[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//int calculate_sum(int** resultant, int rows, int sum)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; resultant[i][j] != -1; j++)
//		{
//			sum += resultant[i][j];
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int rows, columns,sum=0,hint=0;//declaring variables
//	
//	cout << "Enter the number of rows:";
//	cin >> rows;
//	cout << "Enter the number of columns:";
//	cin >> columns;
//	//declaring the initial 2-D array
//	int* temp = new int[rows];
//
//	
//	int** array = new int*[rows];
//	for (int i = 0; i < rows; i++)
//	{
//		array[i] = new int [columns];
//	}
//	input(array,rows,columns);//taking input from the user
//	cout << "_________________________________________________________________\n";
//	cout << "The given array:" << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			cout << array[i][j] << "  ";
//		}
//		cout << endl;
//	}
//	calculate(array, rows, columns,temp);//calculating the size of new 2-D array
//	//declaring the resultant 2-D array
//
//	int** resultant = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//			resultant[i] = new int[temp[i]+1];
//	}
//	store_result(array, rows, columns, resultant);//storing the result in new 2-D array
//	
//	output(resultant, rows, columns,temp);//displaying the final matrix
//	int final=calculate_sum(resultant, rows, sum);//calculating the sum
//	cout << "The sum is " << final << " .";
//    //deallocating the memory
//	delete[]temp;
//	temp = NULL;
//	delete[]array;
//	array = NULL;
//	for (int i = 0; i < rows; i++)
//	{
//		delete[]resultant[i];
//		resultant[i] = NULL;
//	}
//	delete []resultant;
//
//}