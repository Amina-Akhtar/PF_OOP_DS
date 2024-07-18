//#include"stack.h"
//#include<iostream>
//using namespace std;
//stack::stack()
//{
//	array = NULL;
//}
//stack::stack(int size)
//{
//	array=new int[size];
//}
//void stack::resize( int& top,int&s)
//{
//	int* temp = new int[s];
//	for (int i = 0; i < s; i++)
//	{
//		temp[i] = array[i];
//	}
//	array = nullptr;
//     array = new int[s*2];
//	for (int i = 0; i < s ; i++)
//	{
//		array[i] = temp[i];
//	}
//	s *= 2;
//	delete[]temp;
//	temp = nullptr;
//}
//void stack :: push(int& top, int& s, int data)
//{
//	array[s] = data;
//	s++;
//	top = array[s - 1];
//}
//void stack:: pop(int &top,int &s)
//{
//	top = array[s - 1];
//	s--;
//}
//void stack::calculate(int top,int mysize,stack &object,int s)
//{
//	int  result = 0, sum = 0,hint=-1;
//	for (int i = 0; i < mysize;)
//	{
//		if (top == 0)
//		{
//			hint = 0;
//			object.pop(top, s);
//			i++;
//		}
//		if (top != 0&&hint==0)
//		{
//			sum += top;
//			object.pop(top, s);
//			i++;
//			result = sum;
//		}
//		else
//		{
//			object.pop(top, s);
//			i++;
//		}
//	}
//	cout << "-----------------------------------------------" << endl;
//	cout << "The number of chocolates sold is " << result << endl;
//	cout << "-----------------------------------------------" << endl; 
//}
//stack::~stack()
//{
//	delete[]array;
//}
//int main()
//{
//	int s, top = -1, count = 0,num;
//	cout << "Enter the number of minutes:";
//	cin >> s;
//	int mysize = s;
//	stack object(s);
//	cout << "Enter the amount of chocolate: " << endl;
//	for (int i = 0; i < s; i++)
//	{
//		cin >> num;
//		while (num < 0)
//		{
//			cout << "Enter the positive amount :";
//			cin >> num;
//		}
//		object.push(top, count, num);
//	}
//	s -= 1;
//	object.calculate(top, mysize, object,s);
//	object.resize(top,mysize);
//	return 0;
//}