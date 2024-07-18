#include<iostream>
#include<cmath>
using namespace std;
int  t = 0, cot = 0;

bool addelement( int setA[], int &noe, int Acap, int element)
{
cond:
	int chk = 0;
	cout << "Enter the element you want to add:";
        cin >> element;
		for (int i = 0; i <= cot; i++)
		{
			if ( element==setA[i])
			{
				chk++;
			}
		}
		if (chk == 0)
		{
		setA[t]=element;
		t++;
		}
		else
		{
		cout << "This element cannot be added as it is already present in the set .";				goto cond;
		}
	    cot++;
      return 0;
}
bool removeElement(int setA[], int& noe, int Acap, int element)
{
	int cow = 0;
	cout << "Enter the element you want to remove:";
	cin >> element;
	for (int i = 0; i < noe; i++)
	{
		if (setA[i] == element)
		{
			for (int j = i + 1; j < noe; j++)
			{
				setA[j-1] = setA[j];
			}
			cout << "The set is ";
			for (int i = 0; i < noe - 1; i++)
			{
				cout << setA[i] << " ";
			}
		}
		else
		{
			cow++;
		}
	}
	if (cow != 0)
	{
		cout << "This element is not present in the set."<<endl;
	}
	
	return 0;
}
bool searchElement(int setA[], int noe, int element)
{
	cout << "Enter the element you want to search:";
	cin >> element;
	int count = 0;
	for (int i = 0; i < noe; i++)
	{
		if (setA[i] == element)
		{
			count++;
		}
	}
	if (count== 0)
	{
		cout << "This element is not present in the set." << endl;
		return 0;
	}
	else if (count != 0)
	{
		cout << "This element is present in the set." << endl;
		return 1;
	}
}
int searchElementPosition(int setA[], int noe, int element)
{
	cout << "Enter the element of which you want to search the index:";
	cin >> element;
	int count = 0;
	for (int i = 0; i < noe; i++)
	{
		if (setA[i] == element)
		{
			cout << "The number " << element << " is present at index " << i << " ." << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "This elememnt is not present in the set." << endl;
	}
	return 0;
}
void displaySet(int setA[], int noe)	
{
	cout << "The elements in this set are: ";
	for (int i = 0; i < noe; i++)
	{
		cout << setA[i] << " ";
	}
	cout << "." << endl;
}
bool isEmpty(int noe)
{
	const int Acap = 100;
	int setA[Acap] = { 0 };
	int element=0;
	cout << "Enter the number of elements you want to add:" << endl;
	cout << "If you don't want to add an element press '0':";
	cin >> noe;
	if (noe == 0)
	{
		cout << "This set is empty." << endl;
		return 1;
	}
	else
	{
	for (int j = 0; j < noe; j++)
		{
			addelement(setA, noe, Acap, element);
		}
		cout << "This set is not empty." << endl;
		return 0;
	}
}
bool isFull(int noe, int capacity)
{
	char element=0;
	const int Acap = 100;
	int setA[Acap] = { 0 };
	cout << "NOTE: If you don't want to enter next element press'.'" << endl;
	cout << "Enter how many numbers you want to add:" ;
	cin >> noe;
    for (int j = 0; j < noe; j++)
	{
	cond:
		int chk = 0, i = 0, k = 1;
        cout << "Enter the element you want to add:";
		cin >> element;
		if (element == '.')
		{
			cout << "This set is not full." << endl;
			return 0;
		}
		else {
			for (int i = 0; i <= cot; i++)
			{
				if (element == setA[i])
				{
					chk++;
				}
			}
			if (chk == 0)
			{
				setA[t] = element;
				t++;
			}
			else
			{
				cout << "This element cannot be added as it is already present in the set .";
				goto cond;
			}
			cot++;
		}
	}
	cout << "This set is full.\n";
	return 0;
}
void intersection(int setA[], int setB[], int Anoe, int Bnoe, int setC[], int Cnoe)
{
	int k = 0;
	for (int i = 0; i < Anoe; i++)
	{
		for (int j = 0; j < Bnoe; j++)
		{
			if (setA[i] == setB[j])
			{
				 setC[k]= setA[i];
				k++;
			}
		}
	}
	cout << "The intersection of these two sets is  ";
	for (int i = 0; i < k; i++)
	{
		cout << setC[i] << " ";
	}
	cout << "." << endl;
}
void unionsets(int setA[], int setB[], int Anoe, int Bnoe, int setC[], int Cnoe)
{   int countA = 0, countB = 0;
	cout << "The union of these two sets is  ";
	int k = 0;
	for (int i = 0; i < Anoe; i++)
	{
		for (int j = 0; j < Bnoe; j++)
		{
			if (setA[i] == setB[j])
			{
				setC[k] = setA[i];
				k++;}
		}
	}
	for (int i = 0; i < Anoe; i++,countA=0)
	{
		for (int j = 0; j < Bnoe; j++)
		{
			if (setA[i] != setB[j])
			{
				countA++;
			}
		}
			if (countA == Bnoe)
				cout << setA[i]<<" ";
	}
	for (int i = 0; i < Bnoe; i++,countB=0)
	{
		for (int j = 0; j < Anoe; j++)
		{
			if (setB[i] != setA[j])
			{
				countB++;
			}
		}
			if (countB == Anoe)
				cout << setB[i]<<" ";
	}
	for (int i = 0; i < k; i++)
		{
			cout << setC[i] << " ";
		}
		cout << " ." << endl;
}
void difference(int setA[], int setB[], int Anoe, int Bnoe, int setC[], int Cnoe)
{
	int countAs = 0,k=0;
	for (int i = 0; i < Anoe; i++,countAs=0)
	{
		for (int j = 0; j < Bnoe; j++)
		{
			if (setA[i] != setB[j])
			{
				countAs++;
			}
		}
		if (countAs == Bnoe)
		{
			setC[i]=setA[i];
			k++;
		}
	}
	if (k == 0)
	{
		cout << "These two sets have no difference. \n";
	}
	else
	{
		cout << "The difference of these two sets is ";
		for (int i = 0; i < k; i++)
		{
			cout << setC[i] << " ";
		}
		cout << " ." << endl;
	}
}
void crossproduct(int setA[], int setB[], int Anoe, int Bnoe)
{
	cout << " { ";
		for (int i = 0; i < Anoe && i < Bnoe; i++)
		{
			cout << "( " << setA[i] << " ," << setB[i] << " ) ";
			if (i < Anoe - 1)
			{
				cout << " ,";
			}
		}
cout << " }"<<endl;
}
void createclone(int setA[], int Acap, int sourceset[], int sourcenoe)
{
	for (int i = 0; i < Acap; i++)
	{
		sourceset[i] = setA[i];
	}
	cout << "The clone set is ";
	for (int i = 0; i < sourcenoe; i++)
	{
		cout << sourceset[i] << " ";
	}
	cout << " ." << endl;
}
void powerset(int setA[], int noe)
{ 
	
	cout << "The powerset of this set is { {} ";
	
	int n = pow(2, noe);
	for (int i = 0; i <= n-1; i++)
	{
		if (i > 0)
		{
			cout << " { ";
		}
		for (int j = 0; j < noe; j++)
		{
			if (i & (1 << j))
			{
				cout << setA[j]<<" ";
			}
			
		}
		if (i > 0)
		{
			cout << " } ";
		}
    }
	cout << " }" << endl;
}
bool subset(int setA[], int setB[], int Anoe, int Bnoe)
{
	int subs = 0,cust=0;
	for (int i = 0; i < Anoe; i++)
	{
		for (int j = 0; j < Bnoe; j++)
		{
			if (setA[i] == setB[j])
			{
				cust++;
			}
		}
		subs = 0 + cust;
	}

	if (subs == Anoe || subs == Bnoe)
	{
		cout << "These sets are improper subets of each other .\n";
		return 2;
	}
	 else if (subs == Anoe -1|| subs == Bnoe-1)
	{
		cout << "These sets are proper subets of each other .\n";
		return 1;
	}
	 else if ((subs > 0 && subs <= Anoe - 2) || (subs > 0 || subs <= Bnoe - 2))
	{
		cout << "These sets are not subsets of each other." << endl;
		return 0;
	}
}



	int main()
	{
		menu:
    cout << "1.  Add an element in the set              \n";
	cout << "2.  Remove an element from the set         \n";
	cout << "3.  Search an element in the set           \n";
	cout << "4.  search an element's position in the set\n";
	cout << "5.  Check that set is empty                \n";
	cout << "6.  Check that set is full                 \n";
	cout << "7.  Display all the elements of the set    \n";
	cout << "8.  Intersection of two sets               \n";
	cout << "9.  Union of two sets                      \n";
	cout << "10. Difference of two sets                 \n";
	cout << "11. Check that two sets are subsets        \n";
	cout << "12. Display cross product                  \n";
	cout << "13. Display powerset                       \n";
	cout << "14. Create clone set                       \n";
	cout << "___________________________________________\n";
	cout << "Enter your choice :\n";
	int choice, element = 0, noe=0;
	char decision;
con:

	cin >> choice;
	if (choice <= 0 || choice > 14)
	{
		cout << "Invalid choice! Please enter the choice between 1 and 14.\n";
		goto con;
	}
	int Anoe, Bnoe, Cnoe;
	const int Acap = 100;
	const int Ccap = 100;
	int setA[Acap] = { 0 };
	const int Bcap = 100;
	int setB[Bcap] = { 0 };
	int setC[Ccap] = { 0 };
	if (choice == 1)
	{
	func1:
		noe = 1;
			addelement(setA, noe, Acap, element);

			cout << "The set is ";
			for (int i = 0; i < cot; i++)
			{
				cout << setA[i] << " ";
			}
			cout << " .";
		decision1:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func1;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision1;
		}

	}
	if (choice == 2)
	{
	func2:
		const int Acap = 100;
		int setA[Acap] = { 0 };
		cout << "Enter the number of elements you want to add:";
		cin >> noe;

		for (int j = 0; j < noe; j++)
		{
			addelement(setA, noe, Acap, element);
		}
		removeElement(setA, noe, Acap, element);
		decision2:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func2;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision2;
		}
	}
	if(choice==3)
	{
	func3:
		const int Acap = 100;
		int setA[Acap] = { 0 };
		cout << "Enter the number of elements you want to add:";
		cin >> noe;

		for (int j = 0; j < noe; j++)
		{
			addelement(setA, noe, Acap, element);
		}
		 searchElement( setA, noe, element);
		 decision3:
		 cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		 cout << "____________________________________________________________________________\n";
		 cin >> decision;
		 if (decision == 'y' || decision == 'Y')
		 {
			 goto func3;
		 }
		 else if (decision == 'm' || decision == 'M')
		 {
			 goto menu;
		 }
		 else
		 {
			 cout << "Invalid option entered!";
			 goto decision3;
		 }
	}
	if (choice == 4)
	{
	func4:
		const int Acap = 100;
		int setA[Acap] = { 0 };
		cout << "Enter the number of elements you want to add:";
		cin >> noe;

		for (int j = 0; j < noe; j++)
		{
			addelement(setA, noe, Acap, element);
		}
      searchElementPosition(setA, noe, element);
  decision4:
	  cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
	  cout << "____________________________________________________________________________\n";
	  cin >> decision;
	  if (decision == 'y' || decision == 'Y')
	  {
		  goto func4;
	  }
	  else if (decision == 'm' || decision == 'M')
	  {
		  goto menu;
	  }
	  else
	  {
		  cout << "Invalid option entered!";
		  goto decision4;
	  }
		
	}
	if (choice == 5)
	{
	func5:	
	isEmpty( noe);
decision5:
	cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
	cout << "____________________________________________________________________________\n";
	cin >> decision;
	if (decision == 'y' || decision == 'Y')
	{
		goto func5;
	}
	else if (decision == 'm' || decision == 'M')
	{
		goto menu;
	}
	else
	{
		cout << "Invalid option entered!";
		goto decision5;
	}
	}
	if (choice == 6)
	{
		func6:
		int capacity=0;
	 isFull( noe,  capacity);
 decision6:
	 cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
	 cout << "____________________________________________________________________________\n";
	 cin >> decision;
	 if (decision == 'y' || decision == 'Y')
	 {
		 goto func6;
	 }
	 else if (decision == 'm' || decision == 'M')
	 {
		 goto menu;
	 }
	 else
	 {
		 cout << "Invalid option entered!";
		 goto decision6;
	 }
	}
	if (choice == 7)
	{
	func7:
		t = 0;
		const int Acap = 100;
		int setA[Acap] = { 0 };
		cout << "Enter the number of elements you want to add:";
		cin >> noe;

		for (int j = 0; j < noe; j++)
		{
			addelement(setA, noe, Acap, element);
		}
		displaySet(setA, noe);
	decision7:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func7;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision7;
		}
	}
	if (choice == 8)
	{
	func8:
		t = 0;
		const int Acap = 100;
		int setA[Acap] = { 0 };
		cout << "Enter the number of elements you want to add for the first set:";
		cin >> Anoe;

		for (int j = 0; j < Anoe; j++)
		{
			addelement(setA, Anoe, Acap, element);
		}
		const int Bcap = 100;
		int setB[Bcap] = { 0 };
		cout << "Enter the number of elements you want to add for the second set:";
		cin >> Bnoe;

			for (int j = 0, t = 0; j < Bnoe; j++)
			{

			cont:
				const int Acap = 100;
				int setA[Acap] = { 0 };
				int chk = 0, i = 0, k = 1;
				cout << "Enter the element you want to add:";
				cin >> element;
				for (int i = 0; i <= cot; i++)
				{
					if (element == setB[i])
					{
						chk++;
					}
				}
				if (chk == 0)
				{
					setB[t] = element;
					t++;
				}
				else
				{
					cout << "This element cannot be added as it is already present in the set .";
					goto cont;
				}
		
		}
		Cnoe = Anoe + Bnoe;
		intersection( setA, setB,  Anoe,  Bnoe, setC, Cnoe);
	decision8:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func8;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision8;
		}

	}
	if (choice == 9)
	{
	func9:
		t = 0;
		const int Acap = 100;
		int setA[Acap] = { 0 };

		cout << "Enter the number of elements you want to add for the first set:";
		cin >> Anoe;

		for (int j = 0; j < Anoe; j++)
		{
			addelement(setA, Anoe, Acap, element);
		}
		const int Bcap = 100;
		int setB[Bcap] = { 0 };
		cout << "Enter the number of elements you want to add for the second set:";
		cin >> Bnoe;

		for (int j = 0, t = 0; j < Bnoe; j++)
		{
			
		conditi:
			const int Acap = 100;
			int setA[Acap] = { 0 };
			int chk = 0, i = 0, k = 1;
			cout << "Enter the element you want to add:";
			cin >> element;
			for (int i = 0; i <= cot; i++)
			{
				if (element == setB[i])
				{
					chk++;
				}
			}
			if (chk == 0)
			{
				setB[t] = element;
				t++;
			}
			else
			{
				cout << "This element cannot be added as it is already present in the set .";
				goto conditi;
			}
		}
		Cnoe = Anoe + Bnoe;
		unionsets(setA, setB, Anoe, Bnoe, setC, Cnoe);
	decision9:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func9;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision9;
		}
	}
	if (choice == 10)
	{
	func10:
		t = 0;
		const int Acap = 100;
		int setA[Acap] = { 0 };
		
		cout << "Enter the number of elements you want to add for the first set:";
		cin >> Anoe;

		for (int j = 0; j < Anoe; j++)
		{
			addelement(setA, Anoe, Acap, element);
		}
		cout << "Enter the number of elements you want to add for the second set:";
		cin >> Bnoe;

		for (int j = 0, t = 0; j < Bnoe; j++)
		{
			const int Acap = 100;
			int setA[Acap] = { 0 };
		conditio:
			int chk = 0, i = 0, k = 1;
			cout << "Enter the element you want to add:";
			cin >> element;
			for (int i = 0; i <= cot; i++)
			{
				if (element == setB[i])
				{
					chk++;
				}
			}
			if (chk == 0)
			{
				setB[t] = element;
				t++;
			}
			else
			{
				cout << "This element cannot be added as it is already present in the set .";
				goto conditio;
			}
		}
		Cnoe = Anoe + Bnoe;
	   difference(setA, setB, Anoe, Bnoe, setC, Cnoe);
	  
   decision10:
	   cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
	   cout << "____________________________________________________________________________\n";
	   cin >> decision;
	   if (decision == 'y' || decision == 'Y')
	   {
		   goto func10;
	   }
	   else if (decision == 'm' || decision == 'M')
	   {
		   goto menu;
	   }
	   else
	   {
		   cout << "Invalid option entered!";
		   goto decision10;
	   }
	}
	if (choice == 11)
	{
	func11:
		t = 0;
		const int Acap = 100;
		int setA[Acap] = { 0 };

		cout << "Enter the number of elements you want to add for the first set:";
		cin >> Anoe;

		for (int j = 0; j < Anoe; j++)
		{
			addelement(setA, Anoe, Acap, element);
		}
		const int Bcap = 100;
		int setB[Bcap] = { 0 };
		cout << "Enter the number of elements you want to add for the second set:";
		cin >> Bnoe;
		for (int j = 0, t = 0; j < Bnoe; j++)
		{
			const int Acap = 100;
			int setA[Acap] = { 0 };
		conditiones:
			int chk = 0, i = 0, k = 1;
			cout << "Enter the element you want to add:";
			cin >> element;
			for (int i = 0; i <= cot; i++)
			{
				if (element == setB[i])
				{
					chk++;
				}
			}
			if (chk == 0)
			{
				setB[t] = element;
				t++;
			}
			else
			{
				cout << "This element cannot be added as it is already present in the set .";
				goto conditiones;
			}
		}
		subset(setA, setB, Anoe, Bnoe);
	decision11:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func11;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision11;
		}
	}
	if (choice == 12)
	{
	func12:
		t = 0;
		const int Acap = 100;
		int setA[Acap] = { 0 };

		cout << "Enter the number of elements you want to add for the first set:";
		cin >> Anoe;

		for (int j = 0; j < Anoe; j++)
		{
			addelement(setA, Anoe, Acap, element);
		}
		const int Bcap = 100;
		int setB[Bcap] = { 0 };

		cout << "Enter the number of elements you want to add for the second set:";
		cin >> Bnoe;
		for (int j = 0, t = 0; j < Bnoe; j++)
		{
			const int Acap = 100;
			int setA[Acap] = { 0 };
		conditioness:
			int chk = 0, i = 0, k = 1;
			cout << "Enter the element you want to add:";
			cin >> element;
			for (int i = 0; i <= cot; i++)
			{
				if (element == setB[i])
				{
					chk++;
				}
			}
			if (chk == 0)
			{
				setB[t] = element;
				t++;
			}
			else
			{
				cout << "This element cannot be added as it is already present in the set .";
				goto conditioness;
			}
		}
		Cnoe = Anoe + Bnoe;
		crossproduct(setA, setB, Anoe, Bnoe);
	decision12:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func12;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision12;
		}

		}
	if (choice == 13)
	{
	func13:
		t = 0;
		const int Acap = 100;
		int setA[Acap] = { 0 };
		cout << "Enter the number of elements you want to add:";
		cin >> noe;

		for (int j = 0; j < noe; j++)
		{
			addelement(setA, noe, Acap, element);
		}
		powerset(setA, noe);
	decision13:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func13;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision13;
		}
	}
	if (choice == 14)
	{
	func14:
		t = 0;
		const int Acap = 100;
		int setA[Acap] = { 0 };

		cout << "Enter the number of elements :";
		cin >> Anoe;

		for (int j = 0; j < Anoe; j++)
		{
			addelement(setA, Anoe, Acap, element);
		}
		int sourceset[100];
		int sourcenoe = Anoe;
		createclone(setA, Acap, sourceset, sourcenoe);
	decision14:
		cout << "To repeat this function press 'y' and to go to main menu press 'm': \n";
		cout << "____________________________________________________________________________\n";
		cin >> decision;
		if (decision == 'y' || decision == 'Y')
		{
			goto func14;
		}
		else if (decision == 'm' || decision == 'M')
		{
			goto menu;
		}
		else
		{
			cout << "Invalid option entered!";
			goto decision14;
		}
	}
}