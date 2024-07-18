#pragma once
#include<iostream>
using namespace std;
class mystring {
private:
	char *array=new char[100];

public:
	
	void input();
	int length();
    void concatenate(mystring str2,int s,int s1,int s2);
	void substring(int s);
	void search( mystring str2, int s1, int s2);
	void reverse(int siz);


};