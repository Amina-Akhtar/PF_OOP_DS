//#include <iostream>
//using namespace std;
//int main()
//{
//	char  gender;
//	float	A1, A2, A3, A4, A5, B, wrist, hip, forearm, waist, bodyweight, bodyfat, bodyfat_per;//declaring variables
//	
//	cout << "Enter the gender:" << endl;
//	cin >>gender;
//	
//		if ((gender == 'm') || (gender == 'M'))
//
//		{
//			cout << "Enter body weight:" << endl;
//			cin >> bodyweight;
//			cout << "Enter wrist measurement at fullest point:" << endl;
//			cin >> wrist;
//			A1 = (bodyweight * 1.082) + 94.42;
//			A2 = wrist / 4.15;
//			B = A1 - A2;
//			bodyfat =  B-bodyweight;//calculating bodyfat
//			bodyfat_per = (bodyweight * 100) / bodyfat;//calculating bodyfat percentage
//			cout << "Body fat is " << bodyfat_per << endl;
//			cout << "Body fat percentage is " << bodyfat_per << "%" << endl;
//		}
//
//
//
//
//		else if ((gender == 'f') || (gender == 'F'))
//
//		{
//			cout << "Enter body weight:" << endl;
//			cin >> bodyweight;
//			cout << "Enter wrist measurement at fullest point:" << endl;
//			cin >> wrist;
//			cout << "Enter waist measurement:" << endl;
//			cin >> waist;
//			cout << "Enter hip measurement:" << endl;
//			cin >> hip;
//			cout << "Enter forearm measurement:" << endl;
//			cin >> forearm;
//			A1 = (bodyweight * 0.732) + 8.987;
//			A2 = wrist / 3.140;
//			A3 = waist * 0.157;
//			A4 = hip * 0.249;
//			A5 = forearm * 0.434;
//			B = A1 + A2 - A3 - A4 + A5;
//			bodyfat = bodyweight- B ;
//			bodyfat_per = bodyfat * 100 / bodyweight;
//			cout << "Body fat is " << bodyfat_per << endl;//displlaying bodyfat
//			cout << "Body fat percentage is " << bodyfat_per << "%" << endl;//displaying bodyfat percentage
//		}
//		else if ((gender |= 'M') || (gender |= 'F') || (gender |= 'm') || (gender |= 'f'))
//		{
//			cout << "invalid gender" << endl;//handling invalid condition
//			return 0;
//		}
//	
//   return 0;
//}
//
