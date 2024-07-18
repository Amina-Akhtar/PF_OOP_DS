#include"22L6198 List.h"
#include <iostream>
using namespace std;
void menu(int &code)
{
	cout << "Code     Function" << endl;
	cout << "1.     Insert element" << endl;
	cout << "2.     Delete element" << endl;
	cout << "3.     Print list" << endl;
	cout << "4.     Union of two lists" << endl;
	cout << "5.     Terminate the program" << endl;
	cout << "Enter the code for desired function:";
	cin >> code;
	while (code < 1 || code>5)
	{
		cout << "Enter the code between 1 to 5:";
		cin >> code;
	}
}
int main()
{
	sortedset<int> s1;
	int code=0,value;
	do {
		menu(code);
		if (code == 1)
		{
			Condition:
			cout << "Enter the value to insert:";
			cin >> value;
			if (s1.check(value))
			{
				s1.insert(value);
			}
			else
			{
				cout << "Element cannot be added as it is already present in the list" << endl;
				goto Condition;
			}
			cout << "-------------------------------------------------------------" << endl;
		}
		else if (code == 2)
		{
			s1.delete_element();
		}
		else if (code == 3)
		{
			s1.print();
		}
		else if (code == 4)
		{
			int s;
			sortedset<int> s2;
			cout << "Enter the size of second list:";
			cin >> s;
			while (s <= 0)
			{
				cout << "Enter the size greater than 0:";
				cin >> s;
			}
			for (int i = 0; i < s; i++)
			{
			condition:
				cout << "Enter the value to insert:";
				cin >> value;
				if (s2.check(value))
				{
					s2.insert(value);
						cout << "Element added to the list successfully!" << endl;
				}
				else
				{
					cout << "Element cannot be added as it is already present in the list" << endl;
					goto condition;
				}
				cout << "-------------------------------------------------------------" << endl;
			}
             cout<<"Union of two sets: "<<endl;
			s1.union_set(s2);
			s1.clear();
			s2.clear();
		}
	} while (code == 0||code!=5);
	if (code == 5)
	{
		cout << "The program has been terminated successfully!" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
	return 0;
}