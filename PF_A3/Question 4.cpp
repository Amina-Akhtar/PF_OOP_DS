//#include<iostream>
//using namespace std;
//int main()
//{
//condition:
//	int z,f1=0,f2=1,f=0,i=0,num,nom,n,m,p=0,range,x=10000;
//	char ch;
//	//displaying the output menu
//	cout << "1.Display n term of fabonacci sequence:\n";
//	cout << "2.Display the first n fabonnaci numbers:\n";
//	cout << "3.Display fabonacci sequence between m and n:\n";
//	cin >> z;
//
//	if (z == 1)
//	{
//		cout << "Enter the number:\n";//taking input from the user
//		cin >> num;
//		while (i<=num-3)
//		{
//			f = f1 + f2;
//			f1 = f2;
//			f2 = f;
//			i++;
//		}
//		cout << "The " << num << "th term of the sequence is "<<f<<endl;//displaying the possible output
//	}
//	else if (z == 2)
//	{
//		cout << "Enter the number of terms till you want to continue the sequence:\n";//taking input
//		cin >> nom;
//		cout << "The sequence is " << f1 << " " << f2 << " ";
//		//performing calculations
//		while (i < nom-2)
//		{
//			f = f1 + f2;
//			f1 = f2;
//			f2 = f;
//			cout << f << " ";//dispalying output
//			i++;
//		}
//		cout << endl;
//	}
//	else if (z == 3)
//	{
//		cout << "Enter the number where the range starts:\n";
//		cin >> m;
//		cout << "Enter the number where the range ends:\n";
//		cin >> n;
//		cout << "The numbers between " << m << " and " << n << " are ";
//		while (i<x)
//		{
//			f = f1 + f2;
//			if(f>m&&f<n)
//			cout << f << " ";
//			f1 = f2;
//			f2 = f;
//			i++;
//			
//		}
//		cout << endl;
//	}
//	cout << "Press y to continue again" << endl;//asking choice to continue or terminate the program
//		cin >> ch;
//		if (ch == 'y')goto condition;
//	else	return 0;
//
//
//
//	return 0;
//}