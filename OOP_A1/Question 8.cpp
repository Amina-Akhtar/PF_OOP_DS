//#include<iostream>
//#include"combolock.h"
//using namespace std;
////constuctor initializing the password
//combolock::combolock()
//{
//	secret1 = 10;
//	secret2 = 20;
//	secret3 = 30;
//};
//void combolock::reset(int temp)
//{
//	temp = 0;
//}
//void combolock::turnleft(int &secret)
//{
//	if (secret == 0)
//	{
//		secret = 39;
//	}
//	else
//	{
//		secret--;
//	}
//}
//void combolock::turnright(int &secret)
//{
//	if (secret == 39)
//	{
//		secret = 0;
//	}
//	else
//	{
//		secret++;
//	}
//}
////function to verify the opening of the lock
//bool combolock::open(int temp,int k)
//{
//	if (k == 0&& temp  == secret1+1)
//	{
//		return true;
//	}
//	else if (k == 1&& temp == secret2 - 1)
//	{
//			return true;
//	}
//	else if (k == 2&& temp  == secret3+ 1)
//	{
//		return true;
//	}
//	
//	else
//	{
//		return false;
//	}
//
//}
////Driver code
//int main()
//{
//	int choice, temp, count = 0, pleasure=0,k;
//	combolock tick;
//	//loop to control the number of the rotations
//	for (k = 0; k < 3;k++ )
//	{
//		bool tree = false;
//		cout << "Enter the value less than 40 to set the number "<<k+1<<":";
//		cin >> temp;
//		while (temp < 0 || temp>40)
//		{
//			cout << "Invalid entry!" << endl;
//			cin >> temp;
//		}
//		cout << "_________________AVAILABLE CHOICES________________" << endl;
//		cout << "To reset press 1" << endl;
//		cout << "To turn left press 2" << endl;
//		cout << "To turn right press 3" << endl;
//		cout << "Resetting will not take any move." << endl;
//		cout << "TOTAL AVAILABLE MOVES:5" << endl;
//		cout << "___________________________________________________" << endl;
//		//loop to control the number of moves
//		for (int i = 5; i > 0; )
//		{
//			cout << "Enter your choice: ";
//			cin >> choice;
//			while (choice <= 0 || choice > 3)
//			{
//				cout << "Invalid choice! Enter a valid choice.";
//				cin >> choice;
//			}
//			if (choice == 1)
//			{
//				tick.reset(temp);
//				cout << "Remaining moves: " << i << endl;
//			}
//			else	if (choice == 2)
//			{
//				tick.turnleft(temp);
//				tree = tick.open(temp, k);
//				if (tree == true)
//				{
//					cout << "________________________________________________________" << endl;
//					cout << "The " << k + 1 << " number has been guessed correctly!" << endl;
//					cout << "________________________________________________________" << endl;
//					pleasure++;
//					break;
//					//terminating the loop
//				}
//				else
//				{
//					i--;
//					cout << "Remaining moves : " << i << endl;
//				}
//			}
//			else if (choice == 3)
//			{
//				tick.turnright(temp);
//				tree = tick.open(temp, k);
//				if (tree == true)
//				{
//					cout << "________________________________________________________" << endl;
//					cout << "The " << k + 1 << " number has been guessed correctly!" << endl;
//					cout << "________________________________________________________" << endl;
//					pleasure++;
//					break;
//					//terminating the loop
//				}
//				else
//				{
//					i--;
//					cout << "Remaining moves : " << i << endl;
//				}
//			}
//		}
//			//handling the incorrect guessing of the password
//			if ( pleasure==0||tree==false)
//			{
//				cout << "___________________________________________________" << endl;
//				cout << "Number" << k + 1 << " has not been guessed correctly!" << endl;
//				cout << "___________________________________________________" << endl;
//			}
//		
//	}
//	//opens the lock
//	if (k == 3 && pleasure == 3)
//	{
//	
//		cout << "The lock has been opened!" << endl;
//		cout << "___________________________________________________" << endl;
//	}
//	else
//	{
//		cout << "Oops! you have lost the moves." << endl;
//		cout << "___________________________________________________" << endl;
//
//	}
//	
//}