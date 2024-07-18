//#include<iostream>
//#include"mystring.h"
//using namespace std;
//
//int mystring::length()
//{
//	int s = 0;
//	//calculating the length of the string
//	for (int i = 0; array[i] != '\0'; i++)
//	{
//		s++;
//	}
//	return s;
//}
//
//void mystring::concatenate(mystring str2, int s, int s1, int s2)
//{
//	char* newstr = new char[s + 1];
//	for (int i = 0; i < s1; i++)
//	{
//		newstr[i] = array[i];
//	}
//	for (int i = s1, k = 0; i < s; i++)
//	{
//		newstr[i] = str2.array[k++];
//	}
//	//displaying the consatenated string
//	cout << "The concatenatd string is :" << endl;
//	for(int i = 0; i<s; i++)
//	{
//		cout << newstr[i];
//	}
//	cout << endl;
//	//deallocating the memory
//	delete[]newstr;
//}
//
//void mystring::substring(int s)
//{
//	int index;
//	cout << "Enter the index to make the sub string :" << endl;
//	cin >> index;
//	if (index > s-1)
//	{
//		cout << "This substring is not possible as the index is greater than the size." << endl;
//	     
//	}
//	else
//	{
//		//displaying the substring
//		cout << "The sub string is :" << endl;
//		for (int i = index; i < s; i++)
//		{
//			cout << array[i];
//		}
//	}
//	cout << endl;
//}
//
//void mystring::search( mystring str2,int s1,int s2)
//{
//	int count=0,choice,hint=1;
//	
//	for (int i = 0,k=0; i < s1; i++)
//	{
//		if (array[i] == str2.array[k])
//		{
//			k++;
//			count++;
//		}
//		else
//		{
//			hint++;
//			k = 0;
//			if (count > 0)
//			{
//				hint++;
//			}
//			count = 0;
//		}
//		if (count == s2)
//		{
//
//			cout << "The word is found at index " << hint-1 << " ." << endl;
//			break;
//		}
//	}
//	
//	if (count == 0)
//	{
//		cout << "The word is not found in the string." << endl;
//	}
//}
//
//void mystring::reverse(int siz)
//{
//	char* reverse = new char[siz + 1];
//	int you = siz-1;
//	for (int i = 0; i < siz; i++)
//	{
//		reverse[i] = array[you--];
//		
//	}
//	//displaying the output
//	cout << "The reversed string is :" << endl;
//	for (int i = 0; i < siz; i++)
//	{
//		cout <<reverse[i];
//	}
//	cout << endl;
//	//deallocating the memory
//	delete[]reverse;
//}
////function to take the input from the user
//void mystring::input()
//{
//	cin.clear();
//	cin.getline(array, 100);	
//}
//
//int main()
//{
//	mystring str1,str2;
//	int choice;
//	char decision = ' ';
//	//handling the repetition of the loop
//	while (decision == 'y' || decision == 'Y' || decision == ' ')
//	{
//	cout << "______________________OPTIONS______________________" << endl;
//	cout << "1.Length of string" << endl;
//	cout << "2.Concatenate two strings" << endl;
//	cout << "3.Make a substring" << endl;
//	cout << "4.Search a word in the string" << endl;
//	cout << "5.Reverse the string" << endl;
//	cout << "___________________________________________________" << endl;
//	
//		cout << "Enter your choice" << endl;
//		cin >> choice;
//		//handing the incalid entries
//		while (choice <= 0 || choice > 6)
//		{
//			cout << "Invalid choice" << endl;
//			cin >> choice;
//		}
//		if (choice == 1)
//		{
//			int s;
//			cout << "Enter the string :"<<endl;
//		   cin.ignore();
//			str1.input();
//			//function calling
//			s= str1.length( );
//			cout << "The size of the string is " << s <<" . "<< endl;
//			cout << "___________________________________________________" << endl;
//
//		}
//		if (choice == 2)
//		{
//			int s1, s2,s;
//			cout << "Enter the first string" << endl;
//			cin.ignore();
//			str1.input();
//			s1 = str1.length();
//			cout << "Enter the second string" << endl;
//			str2.input();
//			s2 = str2.length();
//			s = s1 + s2;
//			//function calling
//			str1.concatenate(str2,s,s1,s2);
//			cout << "___________________________________________________" << endl;
//		}
//		if (choice == 3)
//		{
//			int s;
//			cout << "Enter the string" << endl;
//			cin.ignore();
//			str1.input();
//			s = str1.length();
//			//function calling
//			str1.substring(s);
//			cout << "___________________________________________________" << endl;
//		}
//		if (choice == 4)
//		{
//			int s1,s2;
//			cout << "Enter the string:" << endl;
//			cin.ignore();
//			str1.input();
//			s1 = str1.length();
//			cout << "Enter the word you want to search in the string:";
//			str2.input();
//			s2 = str2.length();
//			//function calling
//			str1.search( str2,s1, s2);
//			cout << "___________________________________________________" << endl;
//		}
//		if (choice == 5)
//		{
//			int siz;
//			cout << "Enter the string" << endl;
//			cin.ignore();
//			str1.input();
//			siz = str1.length();
//			//function calling
//			str1.reverse(siz);
//			cout << "___________________________________________________" << endl;
//
//		}
//		cout << "To execute another function press y " << endl;
//		cin>>decision;
//		//displaying prompt message foe exiting the loop
//		if (decision != 'y' && decision != 'Y')
//		{
//			cout << "The program has been exited!" << endl;
//			return 0;
//		}
//	}
//}