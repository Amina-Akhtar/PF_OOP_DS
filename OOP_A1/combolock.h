#pragma once
#include<iostream>
using namespace std;
class combolock
{
private:
	int secret1;
	int secret2;
	int secret3;

public:
	combolock();

	void reset(int temp);
	void turnleft(int &secret);
	void turnright(int &secret);
	bool open(int temp, int k);
};

