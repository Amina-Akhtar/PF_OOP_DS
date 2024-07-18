#pragma once
#include<iostream>
using namespace std;
class Polynomial 
{
public:
	int totalterms;
	int* exp;
	int* coeff;
public:
	Polynomial();
	Polynomial(int count, int* c, int* e);
	Polynomial (const Polynomial &);
	Polynomial operator+ (const Polynomial&);
	Polynomial& operator ++();
	Polynomial& operator ++(int);
	bool operator !();
	bool operator!=(const Polynomial& );
	bool operator==(const Polynomial&);
	Polynomial& operator =(const Polynomial&);
	friend const Polynomial operator+ (int,const Polynomial &);
	friend ostream& operator<<(ostream&, Polynomial&);
	~Polynomial();
};