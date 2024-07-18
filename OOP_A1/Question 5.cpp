//#include<iostream>
//#include "library.h"
//using namespace std;
//library::library()
//{
//	patron_subs = 0;
//}
//void library::add_book(library obj[10],int &k)
//{
//	int count = 0,size=0;
//	char *hope=new char[5];
//	cout << "Enter the publication id of the book (XXXX)." << endl;
//	cin.ignore();
//	n:
//	cin.getline(obj[k].id, 5);
//	//check that if entered publication id already exists
//	for (int i = k; obj[k].id[i] != '\0'; i++)
//	{
//		size++;
//	}
//	for (int i = 0; i < k; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (obj[k].id[j] == obj[i].id[j])
//			{
//				count++;
//			}
//		}
//	}
//	if (count >=size)
//	{
//		cout << "This book already exists.Please enter another one." << endl;
//		count = 0;
//		goto n;
//	}
//	cout << "Enter the title of the book." << endl;
//	cin.getline(obj[k].booktitle, 30);
//	cout << "Enter the name of the author of the book." << endl;
//	cin.getline(obj[k].author, 30);
//	cout << "Enter the number of the patron subscribers." << endl;
//	cin >> obj[k].patron_subs;
//	k++;
//	cout << "____________________________________________" << endl;
//	cout << "The book has been added successfully" << endl;
//	cout << "____________________________________________" << endl;
//	//deallocating the memory
//	delete[]hope;
//}
//void library::edit_details(library obj[10],int ind)
//{
//	char *search=new char[5];
//	cout << "Enter the publication id of the book of which you want to edit the details" << endl;
//	cin.ignore();
//k:
//	cin.getline(search, 5);
//	int jump = -1, choice, count = 0, size = 0;
//	for (int i =0; search[i]!='\0'; i++)
//	{
//		size++;
//	}
//	for (int i = 0; i < ind; i++)
//	{
//		for(int j=0;j<size;j++)
//		if (search[j] == obj[i].id[j])
//		{
//			count++;
//		}
//		if (count == size)
//		{
//			jump = i;
//			break;
//		}
//	}
//	//handling invalid publication id
//	if (jump == -1)
//	{
//		cout << "The book with this publication id does not exist. Try another id. " << endl;
//		goto k;
//	}
//	cout << "____________________OPTIONS_____________________" << endl;
//    cout << "1.Publication id " << endl;
//	cout << "2.Title " << endl;
//	cout << "3.Author " << endl;
//	cout << "4.Patron subscribers " << endl;
//	cout << "_________________________________________________" << endl;
//	cout << "Enter the number of the thing you want to edit" << endl; 
//	cin >> choice;
//	if (choice <= 0 || choice > 5)
//	{
//		cout << "Invalid choice!" << endl;
//		cin >> choice;
//	}
//	//editing the details
//	if (choice == 1)
//	{
//		cout << "Enter the new publication id :" << endl;
//		cin.ignore();
//		cin.getline(id, 5);
//		obj[jump].id = obj[ind].id;
//	}
//	else if (choice == 2)
//	{
//		cout << "Enter the new book title :" << endl;
//		cin.ignore();
//		cin.getline(obj[ind].booktitle, 30);
//		obj[jump].booktitle = obj[ind].booktitle;
//	}
//	else if (choice == 3)
//	{
//		cout << "Enter the new name of book author :" << endl;
//		cin.ignore();
//		cin.getline(obj[ind].author, 30);
//		obj[jump].author = obj[ind].author;
//	}
//	else if (choice == 4)
//	{
//		cout << "Enter the new number of patron subscribers :" << endl;
//		cin.ignore();
//		cin >> obj[ind].patron_subs;
//		obj[jump].patron_subs = obj[ind].patron_subs;
//	}
//	cout << "____________________________________________" << endl;
//	cout << "The details have been edited successfully" << endl;
//	cout << "____________________________________________" << endl;
//	//deallocating the memory
//	delete[]search;
//}
//void library::delete_book(library obj[10],int &ind)
//{
//	int count = 0,jump,hint=-1;
//	char* search=new char[5];
//	cout << "Enter the publication id of the book of which you want to delete." << endl;
//	cin.ignore();
//	l:
//	cin.getline(search, 5);
//	for (int i = 0; i < ind; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			if (search[j] == obj[i].id[j])
//			{
//				count++;
//			}
//		if (count == 4)
//		{
//			hint++;
//			jump = i;
//			break;
//		}
//	}
//	if (hint == -1)
//	{
//		cout << "The book with this publication id does not exist. Try another id ." << endl;
//		goto l;
//	}
//	//deleting the asked book
//	for (int v = 0; v < ind; v++)
//	{
//		obj[jump] = obj[jump+1];
//	}
//	ind--;
//	cout << "____________________________________________" << endl;
//	cout << "The book has been deleted successfully" << endl;
//	cout << "____________________________________________" << endl;
//	delete[]search;
//}
//void library::display(library obj[10],int ind)
//{
//	cout << "The books available in the library are :" << endl;
//	//displaying all the available books in the library
//	cout << "Sr.\tPublication id\tBook title\tBook author\tPatron subscribers" << endl;
//	for (int i = 0; i < ind; i++)
//	{
//		cout << i+1 << ".\t" << obj[i].id << "\t\t " << obj[i].booktitle << "\t\t " << obj[i].author << "\t\t " << obj[i].patron_subs << endl;
//	}
//	cout << "_____________________________________________________________________" << endl;
//}
//int main()
//{
//	//declaraton and initialization of variables
//	int choice = ' ';
//	static int ind = 0;
//	char desire = ' ';
//	library obj[10],lab;
//	string* hope = new string[10];
//	while (desire == 'y' || desire == 'Y' || desire == ' ')
//	{
//	cout << "______________________MENU______________________" << endl;
//	cout << "1.Add a book" << endl;
//	cout << "2.Edit the details of a book" << endl;
//	cout << "3.Delete a book" << endl;
//	cout << "4.Display all the books" << endl;
//	cout<<  "_________________________________________________" << endl;
//			cout << "Enter the choice:";
//			cin >> choice;
//			//andling the invalid choice
//			while (choice <= 0 || choice >= 5) {
//				cout << "Invalid choice!"<<endl;
//				cin >> choice;
//			}
//		if (choice == 1)
//		{
//			lab.add_book(obj,ind);
//		}
//		if (choice == 2)
//		{
//			lab.edit_details(obj,ind);
//		}
//		if (choice == 3)
//		{
//			lab.delete_book(obj,ind);
//		}
//		if (choice == 4)
//		{
//			lab.display(obj,ind);
//		}
//		//controlling the repetition of loop
//		cout << "To perform another function, press y.";
//		cout << "Pressing any other key will exit the program" << endl;
//		cin >> desire;
//		if (desire != 'y' && desire != 'Y')
//		{
//			cout << "____________________________________________" << endl;
//			cout << "The program has been exited." << endl;
//			cout << "____________________________________________" << endl;
//			//end of the program
//		}
//	}
//}