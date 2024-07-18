#pragma once
#include<iostream>
using namespace std;
class customer {
private:
	int id;
	string name;
	int discount;
public:
	customer();
	customer(int id,string name,int amount);
	void setdata_c(int ide,string nam,int dis);
	int getID();
	string getname();
	int getdiscount();
	string tostring();
};
class invoice {
private:
	int id;
	double amount;
	customer cust;
public:
	invoice();
	invoice(int id, customer cust, double amount);
	void setdata_i(int, customer, double);
	int getid();
	customer getcustomer();
	double getamount();
	int getcustomerid();
	string getcustomername();
	int getcustomerdiscount();
	double getamountafterdiscount();
	string tostring(customer);
};
