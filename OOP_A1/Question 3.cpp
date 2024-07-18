//#include<iostream>
//using namespace std;
//void input(int** array, int r, int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			array[i][j] = rand() % 2;
//		}
//	}
//}
//void output(int** array, int r, int c)
//{
//	for (int i = 0; i < r; i++)
//	{
//		for (int j = 0; j < c; j++)
//		{
//			cout << array[i][j]<<" ";
//		}
//			cout << endl;
//	}
//
//}
//void display(int move)
//{
//	cout << "________________________________RULES:)_______________________________" << endl;
//	cout << "Initially your position is 0,0.You have total " << move << " moves." << endl;
//	cout << "->To move up, press 1" << endl;
//	cout << "->To move down, press 2" << endl;
//	cout << "->To move left, press 3" << endl;
//	cout << "->To move right, press 4" << endl;
//	cout << "____________________________BEST OF LUCK_________________________________" << endl;
//}
//int main()
//{
//	int r, c,choice,i=0,j=0,clue,move;
//	cout << "Enter the number of rows:";
//	cin >> r;
//	while (r < 3)
//	{
//		cout << "Enter the row size greater than 4" << endl;
//		cin >> r;
//	}
//	cout << "Enter the number of columns:";
//	cin >> c;
//	while (c < 3)
//	{
//		cout << "Enter the column size greater than 4" << endl;
//		cin >> c;
//	}
//	move = (r * c) ;
//	int** array = new int* [r];
//	for (int i = 0; i < r; i++)
//	{
//		array[i] = new int[c];
//	}
//	cout << "_______________________WELCOME TO THE MAZE GAME_______________________" << endl << endl;
//	//taking random input
//	input(array, r, c);
//	cout << "Game puzzle:" << endl;
//	//displaying the game puzzle
//	output(array, r, c);
//	//displaying the rules of the game 
//	display(move);
//	//restricting the number of moves
//	choice = array[i][j];
//	for(int k=0;k<move;)
//	{
//		cout << "Enter your choice:" << endl;
//		cin >> clue;
//		while (clue <= 0 || clue > 5)
//		{
//			cout << "Invalid choice" << endl;
//			cin >> clue;
//		}
//		if (clue == 1)
//		{
//			if (i - 1 >= 0)
//			{
//				i = i-1;
//				if (array[i][j] == 0)
//				{
//					i = i + 1;
//					cout << "OOPS!! You have hit a wall."<<endl;
//					choice = array[i][j];
//				}
//				else
//				{
//					cout << "You are at position " << i<< " " << j << endl;
//					choice = array[i][j];
//				}
//			}
//			else
//			{
//				cout << "You cannot take this move as it is out of bound :(" << endl;
//			}
//			k++;
//	    }
//		if (clue == 2)
//		{
//			if (i + 1 <r)
//			{
//				i = i + 1;
//				if (array[i][j] == 0)
//				{
//					cout << "OOPS!! You have hit a wall." << endl;
//					i = i - 1;
//					choice = array[i][j];
//				}
//				else
//				{
//					cout << "You are at position " << i << " " << j << endl;
//					choice = array[i][j];
//				}
//			}
//			else
//			{
//				cout << "You cannot take this move as it is out of bound :(" << endl;
//			}
//			k++;
//		  }
//		if (clue == 3)
//		{
//			if (j - 1 >=0)
//			{
//				j = j - 1;
//				if (array[i][j] == 0)
//				{
//					cout << "OOPS!! You have hit a wall." << endl;
//					j = j + 1;
//					choice = array[i][j];
//				}
//				else
//				{
//					cout << "You are at position " << i << " " << j << endl;
//					choice = array[i][j];
//				}
//			}
//			else
//			{
//				cout << "You cannot take this move as it is out of bound :(" << endl;
//			}
//			k++;
//	    }
//		if (clue == 4)
//		{
//			if (j + 1 <c)
//			{
//				j = j + 1;
//				if (array[i][j] == 0)
//				{
//					j = j - 1;
//					cout << "OOPS!! You have hit a wall." << endl;
//					choice = array[i][j];
//				}
//				else
//				{
//					cout << "You are at position " << i << " " << j << endl;
//					choice = array[i][j];
//				}
//			}
//			else
//			{
//				cout << "You cannot take this move as it is out of bound :(" << endl;
//			}
//			k++;
//	   }
//		//displaying the result
//		if (i==r&&j==c)
//		{
//			cout << "CONGRATS!!!you have won the game" << endl;
//			break;
//		}
//
//	}
//	//displaying the result
//	if (i != r && j != c)
//	{
//		cout << endl << endl;
//		cout << "______________________GAME ENDED!!!_______________________" << endl;
//		cout << "You have lost the game. Better luck next time! " << endl;
//	}
//	//deallocating the memory
//	for (int i = 0; i < r; i++)
//	{
//		delete[]array[i];
//		array[i] = NULL;
//	}
//	delete[]array;
//}