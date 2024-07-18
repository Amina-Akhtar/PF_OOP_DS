//#include"PointType.h"
//#include<iostream>
//using namespace std;
//PointType::PointType()
//{
//	x_coordinate = 0;
//	y_coordinate = 0;
//}
//PointType::PointType(int x,int y)
//{
//	x_coordinate = x;
//	y_coordinate = y;
//}
//void PointType::print()
//{
//	cout << "X coordinate: " << x_coordinate << endl;
//	cout << "Y coordinate: " << y_coordinate << endl;
//}
//int PointType::x_set()
//{
//	return x_coordinate;
//}
//int PointType::y_set()
//{
//	return y_coordinate;
//}
//void PointType::calculate_distance(PointType p1,PointType p2)
//{
//	int x = (p1.x_coordinate - p2.x_coordinate) * (p1.x_coordinate - p2.x_coordinate);
//	int y = (p1.y_coordinate - p2.y_coordinate) * (p1.y_coordinate - p2.y_coordinate);
//	float hint = sqrt(x + y);
//	cout << "The distance between two points p1 and p2 is " << hint <<" ." << endl;
//}
//PointType::~PointType()
//{
//	x_coordinate = 0;
//	y_coordinate = 0;
//}
//int main()
//{
//	int x, y;
//	cout << "Enter x-coordinate of first point:";
//	cin >> x;
//	cout << "Enter y-coordinate of first point:";
//	cin >> y;
//	PointType P1(x,y);
//	cout << "------------------------------" << endl;
//	cout << "Enter x-coordinate of second point:";
//	cin >> x;
//	cout << "Enter y-coordinate of second point:";
//	cin >> y;
//	PointType P2(x,y);
//	cout << "Point 1: " << endl;
//	P1.print();
//	cout << "------------------------------" << endl;
//	cout << "Point 2: " << endl;
//	P2.print();
//	cout << "------------------------------" << endl;
//	int x1 = P1.x_set();
//	int y1 = P1.y_set();
//	int x2 = P2.x_set();
//	int y2 = P2.y_set();
//	P1.calculate_distance(P1, P2);
//}