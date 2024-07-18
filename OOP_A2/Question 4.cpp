//#include"Polynomial.h"
//#include<iostream>
//using namespace std;
//Polynomial::Polynomial()
//{
//	totalterms = 0;
//	coeff = nullptr;
//	exp = nullptr;
//}
//Polynomial::Polynomial(int count,int*c,int *e)
//{
//	totalterms = count;
//	coeff = new int[totalterms];
//	exp = new int[totalterms];
//	for (int i = 0; i < totalterms; i++)
//	{
//		coeff[i] = c[i];
//		exp[i] = e[i];
//	}
//}
//Polynomial::Polynomial(const Polynomial& obj)
//{
//	totalterms = obj.totalterms;
//	for (int i = 0; i < totalterms; i++)
//	{
//		coeff[i] = obj.coeff[i];
//		exp[i] = obj.exp[i];
//	}
//}
//bool Polynomial:: operator !()
//{
//	if (totalterms == 0 && exp[0] == 0 && coeff[0] == 0)
//	{
//		return !true;
//	}
//	else
//	{
//		return !false;
//	}
//}
//bool Polynomial:: operator!=(const Polynomial& p)
//{
//	int count = 0;
//	for (int i = 0; i < totalterms; i++)
//	{
//		if (coeff[i] != p.coeff[i] || exp[i] != p.exp[i])
//		{
//			count++;
//		}
//	}
//	if (count == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//bool Polynomial:: operator==(const Polynomial& p)
//{
//	int count = 0;
//	for (int i = 0; i < totalterms; i++)
//	{
//		if (coeff[i] == p.coeff[i] || exp[i] == p.exp[i])
//		{
//			count++;
//		}
//	}
//	if (count == 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//Polynomial Polynomial:: operator+ (const Polynomial& p)
//{
//	int chance = 0;
//	if (totalterms >= p.totalterms)
//	{
//		chance = totalterms;
//	}
//	else
//	{
//		chance = p.totalterms;
//	}
//	int count = 0;
//	int *e=new int[2*totalterms];
//	int *c=new int[2*totalterms];
//	for (int i = 0,k=0; i < chance;i++,k++ )
//	{
//		if (exp[i] == p.exp[i])
//		{
//			c[k] = coeff[i] + p.coeff[i];
//			e[k] = exp[i];
//			count++;
//		}
//		else
//		{
//			c[k] = coeff[i];
//			e[k] = exp[i];
//			count++;
//			++k;
//			if (i < p.totalterms)
//			{
//				c[k] = p.coeff[i];
//				e[k] = p.exp[i];
//				count++;
//			}
//		}
//	}
//	//nameless temporary object
//	return Polynomial (count, c, e);
//}
//Polynomial &Polynomial::operator ++()
//{
//	for (int i = 0; i < totalterms; i++)
//	{
//		coeff[i] += 1;
//	}
//		return *this;
//}
//Polynomial &Polynomial:: operator ++(int hint)
//{
//	for (int i = 0; i < totalterms; i++)
//	{
//		coeff[i] += 1;
//	}
//	return *this;
//}
//const Polynomial operator+ (int num, const Polynomial& p)
//{
//	int hint = 0;
//	for (int i = 0; i < p.totalterms; i++)
//	{
//		if (p.exp[i] == 0)
//		{
//			hint = i;
//			break;
//		}
//	}
//	p.coeff[hint] += num;
//	Polynomial temp(p.totalterms, p.coeff,p.exp);
//	return temp;
//}
//Polynomial& Polynomial::operator =(const Polynomial& obj)
//{
//	totalterms = obj.totalterms;
//	for (int i = 0; i < totalterms; i++)
//	{
//		coeff[i] = obj.coeff[i];
//		exp[i] = obj.exp[i];
//	}
//	return *this;
//}
//ostream& operator<<(ostream& out, Polynomial& p)
//{
//	for (int i = 0; i < p.totalterms; i++)
//	{
//		out << "(" << p.coeff[i] << ") x^" << p.exp[i];
//		if (i < p.totalterms - 1)
//		{
//			out << " + ";
//		}
//	}
//	return out;
//}
//Polynomial::~Polynomial()
//{
//	totalterms = 0;
//	delete[]coeff;
//	coeff = nullptr;
//	delete[]exp;
//	exp = nullptr;
//}
//
//int main()
//{
//	int coeff_p1[] = { 1,2,5 };
//	int exp_p1[] = { 4,2,0 };
//	int coeff_p2[] = { 4,3 };
//	int exp_p2[] = { 6,2};
//	Polynomial p1(3, coeff_p1, exp_p1);
//	Polynomial p2(2, coeff_p2, exp_p2);
//	cout << "P1= " <<p1<< endl;
//	cout << "-------------------------------------" << endl;
//	cout << "P2= " << p2 << endl;
//	cout << "-------------------------------------" << endl;
//	if (! p1)
//	{
//		cout << "P1 is not zero." << endl;
//	}
//	else
//	{
//		cout << "P1 is zero." << endl;
//	}
//	cout << "-------------------------------------" << endl;
//	if (p1 != p2)
//	{
//		cout << "P1 is equal to P2" << endl;
//	}
//	else
//	{
//		cout << "P1 is not equal to P2" << endl;
//	}
//	cout << "-------------------------------------" << endl;
//    Polynomial	p3 = p1 + p2;
//    cout << "Addition: ";
//	cout << "P3= " << p3 << endl;
//	cout << "-------------------------------------" << endl;
//	cout << "Pre-increment:  ";
//	cout << "P1= "<<++p1<<endl; 
//	cout << "P1= " << p1 << endl;
//	cout << "-------------------------------------" << endl;
//	cout << "Post-increment:  ";
//	cout << "P1= " << p1++ << endl;
//	cout << "P1= " << p1 << endl;
//	cout << "-------------------------------------" << endl;
//	cout << "Constant Addition:  ";
//    p3 = 2+p1 ;
//	cout << "P3= " << p3 << endl;
//	cout << "-------------------------------------" << endl;
//}