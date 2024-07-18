//#include<iostream>
//using namespace std;
//int main()
//{
//	const int ANSWERS[20] = { 66,68,65,65,67,65,66,65,67,68,66,67,68,65,68,67,67,66,68,65 };
//	char option;
//	int incorrect[100] = { 0 };
//	int ASCIoption,correct=0,wrong=0,total=20;
//	int user[100] = { 0 };
//    cout << "NOTE:Use only UPPERCASE to enter the options\n";
//	cout << "Enter the selected options from (A,B,C,D):  \n";
//    for (int i = 0,k=1; i <20; i++,k++)
//	{
//	condition:
//		cout << k << ". ";
//		cin >> option;
//		if (option != 'A' &&   option != 'B' &&option != 'C' && option != 'D')
//        {
//			cout << "Invalid option entered! Please enter a valid option. " << endl;
//			goto condition;
//		}
//		ASCIoption = (int)option;
//		user[i] = ASCIoption;
//	}
//	for (int i = 0,K=0; i < 20; i++)
//	{
//		if (ANSWERS[i] == user[i])
//		{
//			correct++;
//		}
//		else
//		{
//			incorrect[K] = i+1;
//			K++;
//		}
//	}
//	wrong = total - correct;
//	cout << "______________________________Result______________________________" << endl;
//	if (correct >= 15)
//	{
//		cout << "You have passed this exam!\n";
//	}
//	else if(correct<15)
//	{
//		cout << "You have failed this exam!\n";
//	}
//	cout << "Correctly attempted questions are " << correct << "\n";
//	cout << "Incorrectly attempted questions are " << wrong << "\n";
//	if (correct < 20)
//	{
//	  cout << "Incorrect attempted question numbers are ";
//	  for (int i = 0; i < wrong; i++)
//		 {
//			cout << incorrect[i] << " ";
//	     }
//		cout << ".";
//	}
//	cout << "                                                                   \n";
//}