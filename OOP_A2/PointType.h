#pragma once
#include<iostream>
using namespace std;
class PointType 
{
private:
	int x_coordinate;
	int y_coordinate;
public:
	PointType();
	PointType(int, int);
	void print();
	int x_set();
	int y_set();
	void calculate_distance(PointType,PointType);
	~PointType();
};
