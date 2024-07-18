//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//void output(string** matrix, int rows, int columns)
//{
//	cout << "The matrix read from te file is :" << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			cout << matrix[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "____________________________________________________" << endl;
//}
//void calculate(string** matrix, int rows, int columns)
//{
//	int count_even = 0, count_odd = 0,k=0;
//	int** count = new int*[rows];
//	for (int i = 0; i < rows; i++)
//	{
//		count[i] = new int[2];
//	}
//	for (int i = 0; i < rows; i++,count_even=0,count_odd=0,k=0)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (matrix[i][j] == "yes")
//			{
//				count_even++;
//			}
//			else if (matrix[i][j] == "no")
//			{
//				count_odd++;
//			}
//		}
//		count[i][k++] = count_even;
//		count[i][k++] = count_odd;
//	}
//	//displaying the numbers of yes and no
//	cout << "The number of 'yes' and 'no' are " << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cout << count[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "____________________________________________________" << endl;
//	//deallocating the count matrix
//	for (int i = 0; i < rows; i++)
//	{
//		delete[] count[i];
//		count[i] = NULL;
//	}
//	delete[]count;
//
//
//}
//int **intermediate(string** matrix, int rows, int columns)
//{
//	//creating an intermediate matrix to recreate the original matrix
//	int** inter = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		inter[i] = new int[columns];
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (matrix[i][j] == "yes")
//			{
//				inter[i][j] = 1;
//			}
//			if (matrix[i][j] == "no")
//			{
//				inter[i][j] = 0;
//			}
//		}
//	}
//	return inter;
//	//deallocating the inter matrix
//	for (int i = 0; i < rows; i++)
//	{
//		delete[]inter[i];
//		inter[i] = NULL;
//	}
//	delete[]inter;
//}
//void back_track(int** check, int rows, int columns)
//{
//	string** result = new string*[rows];
//
//	for (int i = 0; i < rows; i++)
//	{
//		result[i] = new string[columns];
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (check[i][j] == 1)
//			{
//				result[i][j] = "yes";
//			}
//			if (check[i][j] == 0)
//			{
//				result[i][j] = "no";
//			}
//		}
//	}
//	//displaying the recreatd original matrix
//	cout << "The resultant matrix is :" << endl;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			cout << result[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "____________________________________________________" << endl;
//	//deallocating the result matrix
//	for (int i = 0; i < rows; i++)
//	{
//		delete[]result[i];
//		result[i] = NULL;
//	}
//	delete[]result;
//}
//void counter(string** matrix, int rows, int columns)
//{
//	int count = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < columns; j++)
//		{
//			if (matrix[i][j] == "yes")
//				count++;
//		}
//	}
//	cout << "The total number of 'yes' in this matrix is " << count << " ." << endl;
//}
//int main()
//{
//	int rows, columns;
//	ifstream read;
//	read.open("input.txt");
//	//reading data from the file
//	read >> rows;
//	read>>columns;
//	int** check = new int* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		check[i] = new int[columns];
//	}
//	string** matrix = new string * [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		matrix[i] = new string[columns];
//	}
//	for (int i = 0; i < rows; i++)
//    {
//		for (int j = 0; j < columns; j++)
//		{
//		read >> matrix[i][j];
//		}
//    }
//	read.close();
//	//displaing the data
//	output(matrix,rows,columns);
//	//calculating the total numbers of yes and no
//	calculate(matrix, rows, columns);
//	check=intermediate(matrix, rows, columns);
//	back_track(check,  rows,  columns);
//	counter(matrix, rows, columns);
//	//deallocating the created memory
//	for (int i = 0; i < rows; i++)
//	{
//	  delete[]matrix[i];				
//	  matrix[i] = NULL;
//	}
//	  delete []matrix;
//	 for (int i = 0; i < rows; i++)
//	  {
//		  delete[]check[i];
//		  check[i] = NULL;
//	  }
//	  delete[]check;
//	  
//	  
//	
//	
//		
//}
//
