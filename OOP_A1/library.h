#pragma once
#include<iostream>
using namespace std;
class library
{
private:
	char* id = new char[5];
	char* booktitle = new char[30];
	char* author = new char[30];
	int patron_subs;

public:
	library();
	void add_book(library obj[10],int &k);
	void edit_details(library onj[10],int ind);
	void delete_book(library onj[10], int &ind);
	void display(library obj[10],int ind);
};
