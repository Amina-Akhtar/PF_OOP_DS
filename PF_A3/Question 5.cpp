#include<iostream>
#include<cstdlib>
#include<ctime>
#include <time.h>
#include<conio.h>

using namespace std;
int main()


{
	int p1win = 0, p2win = 0;
	for (int j = 1; j <= 5; j++)//condition for repetition of game
	{

		int t = 0, dice1 = 0, dice2 = 0, i = 1, p1sum = 0, p2sum = 0;
		srand(time(0));
		cout << "press any key for rolling dice: \n";//taking random number as input
		while (p1sum < 20 && p2sum < 20)
		{

			dice1 = rand() % 6 + 1;
			cout << "Player 1 turn: ";
			_getch();
			cout << dice1 << "\n";
			if (p1sum + dice1 > 20)
			{
				p1sum = p1sum;
				cout << "tmove not possible!\n";
			}
			else
				p1sum = p1sum + dice1;
			cout << "Player 1 total : " << p1sum << endl;

			dice2 = rand() % 6 + 1;
			cout << "Player 2 turn:";
			_getch();
			cout << dice2 << "\n";



			if (p2sum + dice2 > 20)
			{
				p2sum = p2sum;
				cout << "move not possible!\n";
			}
			else
				p2sum = p2sum + dice2;

			cout << "Player 2 total : " << p2sum << endl;
			cout << "________________________________________________________________________\n";
			//displaying the possible results
			if (p1sum == 20) {
				cout << "Player 1 wins!\n";
				p1win++;
				//	system("pause");
			}
			else if (p2sum == 20) {
				cout << "Player 2 wins!\n";
				p2win++;
				//	system("pause");
			}
		}
		if (p1win == 3)
		{
			cout << "Player 1 wins overall!!\n";
			break;
		}
		else if (p2win == 3)
		{
			cout << "Player 2 wins overall!!\n";
			break;
		}
		else if (p1win > 3 && p2win <3)
		{
			cout << "Player 2 wins overall!" << endl;
			break;
		}
		else if (p1win <3&&p2win > 3  )
		{
			cout << "Player 1 wins overall!" << endl;
			break;
		}
	
		
	}
		
	
	
	return 0;
}