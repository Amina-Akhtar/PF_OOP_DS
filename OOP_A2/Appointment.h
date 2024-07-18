#pragma once
#include<iostream>
using namespace std;
class Appointment
{
protected:
	string description; 
	string type;
	 int day; 
	 int month;
	 int year;
public:
	Appointment()
	{
		description = " ";
		day = 0, month = 0, year = 0;
	}
	Appointment(string description, int year, int month, int day)
	{
		this->description = description;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	Appointment(string type,string description, int year, int month, int day)
	{
		this->type = type;
		this->description = description;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	virtual bool occursOn(int year, int month, int day)
	{
		if (this->day == day && this->month == month && this->year == year)
		{
			cout << "Onetime appointment: ";
			return true;
		}
		else
		{
			return false;
		}
	}
	string getdescription()
	{
		return description;
	}
	string gettype()
	{
	return type;
	}
	int getyear()
	{
		return year;
	}
	int getmonth()
	{
		return month;
	}
	int getday()
	{
		return day;
	}

};
//Make constructors, getters() and occursOn().
class Onetime :public Appointment
{
public:
	Onetime()
	{
		description = " ";
		day = 0, month = 0, year = 0;
	}
	Onetime(string description, int year, int month, int day)
	{
		this->description = description;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	Onetime(string type, string description, int year, int month, int day)
	{
		this->type = type;
		this->description = description;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	virtual bool occursOn(int year, int month, int day)
	{
		return Appointment::occursOn( year, month,day);
	}
};
class Daily :public Appointment
{
public:
	Daily()
	{
		description = " ";
		day = 0, month = 0, year = 0;
	}
	Daily(string description, int year, int month, int day)
	{
		this->description = description;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	Daily(string type, string description, int year, int month, int day)
	{
		this->type = type;
		this->description = description;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	virtual bool occursOn(int year, int month, int day)
	{
		if ( day>= this->day &&this->year==year)
		{
			cout << "Daily appointment: ";
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Monthly :public Appointment
{
	//constructors and overriding function occursOn().just call parent one from hereand return the answer.
public:
	 Monthly()
	{
		description = " ";
		day = 0, month = 0, year = 0;
	}
     Monthly(string description, int year, int month, int day)
	{
		this->description = description;
		this->year = year;
		this->month = month;
		this->day = day;
	}
	 Monthly(string type, string description, int year, int month, int day)
	 {
		 this->type = type;
		 this->description = description;
		 this->year = year;
		 this->month = month;
		 this->day = day;
	 }
	virtual bool occursOn(int year,int month,int day)
	{
		if (day==this->day )
		{
			cout << "Monthly appointment: ";
			return true;
		}
		else
		{
			return false;
		}
	}
	// same things with other
};

