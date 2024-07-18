//#include <iostream>
//using namespace std;
//int main()
//{
//	int meal, currency, mealprice;
//	float  quantity, salestax, totalprice;
//	cout << "Code    Meal             Per kg price in pakistani rupees" << endl;//displaying menu
//	cout << "1    Chicken Handi        1800      " << endl;
//	cout << "2    Chicken Karahi       2000      " << endl;
//	cout << "3    Chicken Tikka        2200      " << endl;
//	cout << "4    Chicken Haleem        500      " << endl;
//	cout << "5    Creamy Chicken        2500      " << endl;
//
//	cout << "Please enter your choice:" << endl;//taking choice from user
//	cin >> meal;
//	if ((meal < 1) || (meal > 5))
//	{
//		cout << "Invalid code, sorry";
//		return 0;
//	}
//
//	cout << "Please enter quantity in kgs:" << endl;//taking quantity from user
//	cin >> quantity;
//	if (quantity == 0)
//	{
//		cout << "invalid quantity ,sorry";
//		return 0;
//	}
//	cout << "Please enter currency in which you want to buy:1 for Pkr, 2 foe Dollar , 3 for Euro:" << endl;//taking currency from user
//	cin >> currency;
//	if ((currency < 1) || (currency > 3))
//	{
//		cout << "invalid currency ,sorry";
//		return 0;
//	}
//  
//	if (meal == 1)// calculating mealprice
//		mealprice = quantity * 1800;
//	else if (meal == 2)
//		mealprice = quantity * 2000;
//	else if (meal == 3)
//		mealprice = quantity * 2200;
//	else if (meal == 4)
//		mealprice = quantity * 500;
//	else
//		mealprice = quantity * 2500;
//
//	if (mealprice <= 1000)	//calculating salestax
//		salestax = 0;
//	else if ((mealprice >= 1000) || (mealprice <= 3000))
//		salestax = mealprice * 0.02;
//	else
//		salestax = (mealprice * 0.05);
//	
//    totalprice = mealprice + salestax;
//
//   
//	if (currency == 1)//converting into required currency
//	{
//		cout << "meal price: " << "Rs " << mealprice << endl;
//		cout << "sales tax: " << "Rs" << salestax << endl;
//		cout << "total price: " << "Rs" << totalprice << endl;
//	}
//	else if (currency == 2)
//	{
//		cout << "meal price: " << "$" << mealprice / 236.91 << endl;
//		cout << "sales tax: " << "$" << salestax / 236.91 << endl;
//		cout << "total price: " << "$" << totalprice / 236.91 << endl;
//	}
//	else 
//	{
//        cout << "meal price: " << "€" << mealprice / 237.43 << endl;
//		cout << "sales tax: " << "€" << salestax /237.43<< endl;
//		cout << "total price: " << "€" << totalprice /237.43 << endl; 
//	}
//	return 0;
//}
