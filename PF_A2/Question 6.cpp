//#include <iostream>
//using namespace std;
//int main()
//{
//	int amount,tens,unit;//declaring variables
//	
//	
//	cout << "Enter the amount:" << endl;//taking amount from user
//	cin >> amount;
//	if ((amount < 1) || (amount > 100))
//	cout << "Invalid amount entered." << endl;//handling invalid quantity
//	
//	
//	tens = amount / 10;//calculating tens
//	unit = amount % 10;//calculating ones
//	if ((amount >= 11) && (amount <= 19))
//	{
//		if (amount == 11)cout << " eleven ONLY ";
//		if (amount == 12)cout << " twelve ONLY ";
//		if (amount == 13)cout << " thirteen ONLY ";
//		if (amount == 14)cout << " fourteen ONLY ";
//		if (amount == 15)cout << " fifteen ONLY ";
//		if (amount == 16)cout << " sixteen ONLY ";
//		if (amount == 17)cout << " seventeen ONLY ";
//		if (amount == 18)cout << " eighteen ONLY ";
//		if (amount == 19)cout << " ninteen ONLY ";
//
//	}
//	else if ((unit >= 1) && (unit <= 9))
//	{
//		if (tens == 1)cout << "ten ";
//		if (tens == 2)cout << "twenty ";
//		if (tens == 3)cout << "thirty ";
//		if (tens == 4)cout << "forty ";
//		if (tens == 5)cout << "fifty ";
//		if (tens == 6)cout << "sixty ";
//		if (tens == 7)cout << "seventy ";
//		if (tens == 8)cout << "eightY ";
//		if (tens == 9)cout << "ninty ";
//    }
//	 else if ((unit >= 1) && (unit <= 9))
//	{
//		if (unit == 1)cout << "one ONLY ";
//		if (unit == 2)cout << "two ONLY ";
//		if (unit == 3)cout << "three ONLY ";
//		if (unit == 4)cout << "four ONLY ";
//		if (unit == 5)cout << "five ONLY ";
//		if (unit == 6)cout << "six ONLY ";
//		if (unit == 7)cout << "seven ONLY ";
//		if (unit == 8)cout << "eight ONLY ";
//		if (unit == 9)cout << "nine ONLY";
//
//	}
//	else if  (amount == 100)
//	
//		cout << "Hundred ONLY" << endl;//displaying output
//	
//	return 0;
//}