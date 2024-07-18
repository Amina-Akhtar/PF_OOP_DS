//#include <iostream>
////#include<string>
//using namespace std;
//int main()
//{
//	float length, width, perimeter, area, t_price, p1, p2, p3, p4, p5;//declaring and initializing variables
//	char type, colour;
//	int crowns, card_b, glass;
//	cout << "please enter the length in inches; " << endl;
//	cin >> length;
//	cout << "please enter the width in inches: " << endl;
//	cin >> width;
//	area = length * width;//calculating area
//	perimeter = (length * 2) + (width * 2);//calculating perimeter
//	cout << "please enter the type of frame f for fancy and r for regular:" << endl;
//	cin >> type;
//	if (type == 'r')
//		p1 = 0.15 * perimeter;
//	else if (type == 'f')
//		p1 = 0.25 * perimeter;
//	else
//	{
//		cout << "invalid type" << endl;
//		return 0;
//	}
//	cout << "please enter the colour of frame(by default it is white):" << endl;//add colour cost if colour is other than default
//	cin >> colour;
//	if (colour == 'w')
//		p2 = 0;
//	else
//		p2 = 0.10 * perimeter;
//	cout << "please enter the number of crowns you want to add :" << endl;
//	cin >> crowns;
//	if (crowns > 0)
//		p3 = crowns * 0.35;
//	cout << "please enter '0' to add glass:" << endl;//calculating cost of  adding glass
//	cin >> glass;
//	   {
//	      if (glass ==0)
//		  p4 = (0.07 * area);
//	     else
//		 p4 = 0;
//       }
//		cout << "please enter '0' to add cardboard:" << endl;//calculating cost of adding cardboard
//		cin >> card_b;
//		{
//			if (card_b ==0)
//			p5 = (0.02 * area);
//			else
//			p5 = 0;
//		}
//		t_price = p1 + p2 + p3 + p4 + p5;//calculating total price
//		cout << "Total price for this frame is " <<"$ " << t_price << endl;//displaying total price
//		return 0;
//}