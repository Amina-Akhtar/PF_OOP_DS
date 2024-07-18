#pragma once
#include<iostream>
using namespace std;
class filters
{
public:
	void loadImage(int**& image, int rows, int cols);
	void loadImage2(int**& image, int& rows, int& cols);
	void saveImage(int** image, int rows, int cols);
	void changeBrightness(int**& image, int amnt, int rows, int cols);
	void Negative(int**& image, int rows, int cols);
	void FlipVertically(int**& image, int rows, int cols);
	void FlipHorizontally(int**& image, int rows, int cols);
	void combineSidebySide(int** image, int** image_2, int newrows, int newcols, int cols);
	void medianFilter(int**& image, int rows, int cols);
};