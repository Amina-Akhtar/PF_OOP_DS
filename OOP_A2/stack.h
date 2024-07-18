#pragma once
#include<iostream>
using namespace std;
class stack 
{
private:
	int* array;
public:
	stack();
	stack(int);
	void resize(int &,int& );
	void push( int& , int& ,int );
	void pop(int &,int &);
	void calculate(int , int,stack &,int );
	~stack();
};