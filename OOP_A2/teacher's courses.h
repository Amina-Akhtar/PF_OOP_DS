#pragma once
#include<iostream>
using namespace std;
class courses
{
private:
	int id;
	string title;
	int teacherid;
public:
	courses();
	void getdata(int tid);
	void information();
};
class teachers
{
private:
	int tid;
	string name;
	courses* list;
public:
	teachers();
	void addcourse(teachers teach[10], int check,int number);
	void display(teachers teach[10], int count,int number);
	~teachers();

};