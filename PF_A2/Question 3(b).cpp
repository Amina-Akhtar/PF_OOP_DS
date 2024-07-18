//#include <iostream>
//using namespace std;
//int main()
//{
//	int quantity, discount, t_price, price = 99, cost;
//	cout << "Enter the quantity:" ;
//	cin >> quantity;
//	if (quantity == 0)
//		return 0;
//	else
//	{
//		cost = quantity * price;
//		if ((quantity >= 10) && (quantity <= 19))
//		{
//			discount = 0.2 * cost;
//			t_price = cost - discount;
//		}
//		else if ((quantity >= 20) && (quantity <= 49))
//		{
//			discount = 0.3 * cost;
//			t_price = cost - discount;
//        }
//		else if ((quantity >= 50) && (quantity <= 99))
//		{
//			discount = 0.4 * cost;
//			t_price = cost - discount;
//		}
//		else
//		{
//			discount = 0.5 * cost;
//			t_price = cost - discount;
//		}
//	}
//	cout << "The total cost of purchase is " << t_price << endl;
//	return 0;
//}