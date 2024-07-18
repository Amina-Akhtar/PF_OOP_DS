#include <iostream>
#include <fstream>
#include<string>
#include"filters.h"
using namespace std;
void getsize(int& rows, int& cols,string&sen,int &magic)
{
	ifstream get;
	get.open("image1.pgm", ios::binary);
	getline(get, sen);
	get >> rows;
	get >> cols;
	get >> magic;
	get.close();
}

void sort(int temp[9])
{
	int temporary;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (temp[i] > temp[j])
			{
				temporary = temp[i];
				temp[i] = temp[j];
				temp[j] = temporary;
			}
		}
	}
}

void filters::loadImage(int**& image, int rows, int cols)
{
	string word;
	ifstream read;
	if (read.fail())
	{
		cout << "Error! unable to read file. " << endl;
		exit;
	}
	read.open("image1.pgm",ios::binary);
	
		getline(read,word);
	for (int i = 0; i < 3; i++)
	{
		read >> image[0][0];
}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				read >> image[i][j];
			}
		}
	read.close();
	cout << "Image loaded successfully!" << endl;
}

void filters::loadImage2(int**& image2, int& rows2, int& cols2)
{
	string word2;
	ifstream read2;
	if (read2.fail())
	{
		cout << "Error! unable to read file. " << endl;
		exit;
	}
	read2.open("image1.pgm", ios::binary);

	getline(read2, word2);
	for (int i = 0; i < 3; i++)
	{
		read2 >> image2[0][0];
	}
	for (int i = 0; i < rows2; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			read2 >> image2[i][j];
		}
	}
	read2.close();
	cout << "Image loaded successfully!" << endl;
}

void filters::saveImage(int** image, int rows, int cols)
{
	ofstream write;
	write.open("output.pgm", ios::binary|ios::out);
	{
		write <<"P2"<<endl;
		write << rows << " " << cols << " " << endl;
		write << "255" << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				write << image[i][j] << " ";
			}
			write << endl;
		}
		write.close();
	}
	cout << "File saved successfully in the output folder" << endl;
}

void filters::changeBrightness(int**& image, int amnt, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if ((image[i][j] - amnt < -255) || (image[i][j] - amnt > 255))
			{
				continue;
			}
			else
			{
				image[i][j] = image[i][j]+amnt;
			}
		}
	}
	saveImage(image, rows, cols);
}

void filters::Negative(int**& image_, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			image_[i][j] =255- image_[i][j] ;
		}
	}
}

void filters::FlipVertically(int**& image, int rows, int cols)
{
	int temp, hint;
	//code to flip image vertically
	if (rows % 2 == 0)
	{
		hint = rows / 2;
	}
	else
	{
		hint = (rows - 1) / 2;
	}
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < hint; j++)
		{
			temp = image[j][i];
			image[j][i] = image[rows - 1 - j][i];
			image[rows - 1 - j][i] = temp;
		}
	}
}

void filters::FlipHorizontally(int**& image, int rows, int cols)
{
	int temp, hint;
	//code to flip image horizontally
	if (rows % 2 == 0)
	{
		hint = rows / 2;
	}
	else
	{
		hint = (rows - 1) / 2;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < hint; j++)
		{
			temp = image[i][j];
			image[i][j] = image[i][cols - 1 - j];
			image[i][cols - 1 - j] = temp;
		}
	}
}

void filters::combineSidebySide(int** image, int** image2, int newrows, int newcols, int cols)
{
	//declaring a new 2-D array
	int** count = new int* [newrows];
	for (int i = 0; i < newrows; i++)
	{
		count[i] = new int[newcols];
	}
	for (int i = 0; i < newrows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			count[i][j] = image[i][j];
		}
	}
	for (int i = 0; i < newrows; i++)
	{
		for (int j = cols, k = 0; j < newcols && k < cols; j++, k++)
		{
			count[i][j] = image2[i][k];
		}
	}
	cout << "Images combined successfully!" << endl;
	//saving the data to file
	saveImage(count, newrows, newcols);
}

void filters::medianFilter(int**& image, int rows, int cols)
{
	int* temp = new int[9];
	int siz = 0, k, i = 0, j = 0;
	int top = i + 1, hop = j + 1;
	for (int i = 0; i < rows; i++, top++, hop = i + 1)
	{
		for (int j = 0; j < cols; j++)
		{

			for (int m = i; m < i + 3 && m < rows; m++)
			{
				for (int k = j; k < j + 3 && k < cols; k++)
				{
					temp[siz++] = image[m][k];
				}
			}
			if (siz == 9)
			{
				sort(temp);
				image[top][hop++] = temp[4];
				siz = 0;
			}
		}
	}
	
}
int main()
{
	filters picture;
	int rows = 0, cols = 0,magic=0;
	string sen = " ";
	getsize(rows, cols,sen,magic);
	int** image = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		image[i] = new int[cols];
	}
	picture.loadImage(image, rows, cols);
	int option = 0;
	while (option != -1)
	{
		cout << "Choose an option:\n" << endl;
		cout << " 1. Combine Two images side by side " << endl;
		cout << " 2. Change Brightness of Image" << endl;
		cout << " 3. Find Negative of an Image " << endl;
		cout << " 4. Flip an image Vertically" << endl;
		cout << " 5. Flip an image Horizontally" << endl;
		cout << " 6. Apply Median Filter (Remove Noise)" << endl;
		cout << "ENTER -1 TO EXIT" << endl;
		cin >> option;
		if (option == 1) //sidebyside
	    {
			int rows2=0, cols2=0,format2, newcols, newrows;
			string magic2;
			ifstream search;
			search.open("image2.pgm",ios::binary);
			{
				getline(search, magic2);
				search >>  rows2 >> cols2 >> format2;
			}
			search.close();
			int** image2 = new int* [rows];
			for (int i = 0; i < rows; i++)
			{
				image2[i] = new int[cols];
			}
			picture.loadImage2(image2, rows2, cols2);
			if (rows < rows2)
			{
				newrows = rows;
			}
			else if (rows2 < rows)
			{
				newrows = rows2;
			}
			else if (rows == rows2)
			{
				newrows = rows;
			}
			newcols = cols + cols2;
			picture.combineSidebySide(image, image2, newrows, newcols, cols);
		}
		else if (option == 2) { //brightness
			int amnt;
			cout << "Enter the amount for brightness:(-255 to 255) " << endl;
			cin >> amnt;
			while (amnt < -255 || amnt>255)
			{
				cout << "Invalid amount!" << endl;
				cin >> amnt;
			}
			picture.changeBrightness(image, amnt, rows, cols);
			cout << "Brightness of image has been changed successfully!" << endl;
			
		}
		else if (option == 3) { //negative
			picture.loadImage(image, rows, cols);
			picture.Negative(image, rows, cols);
			cout << "Negative of the image successfull!" << endl;
			picture.saveImage(image, rows, cols);

		}
		else if (option == 4) { //flip vettically
			picture.loadImage(image, rows, cols);
			picture.FlipVertically(image, rows, cols);
			cout << "Image vertical flip successful!" << endl;
			picture.saveImage(image, rows, cols);
		}
		else if (option == 5) { //flip horizontally
			picture.loadImage(image, rows, cols);
			picture.FlipHorizontally(image, rows, cols);
			cout << "Image horizontal flip successful!" << endl;
			picture.saveImage(image, rows, cols);
		}
		else if (option == 6) { //median
			picture.loadImage(image, rows, cols);
			picture.medianFilter(image, rows, cols);
			cout << "Meadian filter applied successfully!" << endl;
			picture.saveImage(image, rows, cols);
		}
		else if (option == -1)
		{
			cout << "The program has been exited." << endl;
			break;
		}
	}
}











