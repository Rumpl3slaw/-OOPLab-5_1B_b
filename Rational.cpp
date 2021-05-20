#include <sstream>
#include <Windows.h>

#include "Rational.h"
#include "My_Error_Range.h"


int Rational::Get_a1()const { return a1; }
int Rational::Get_b1()const { return b1; }
int Rational::Get_a2()const { return a2; }
int Rational::Get_b2()const { return b2; }

void Rational::Set_a1(int value) { a1 = value; }
void Rational::Set_b1(int value) { b1 = value; }
void Rational::Set_a2(int value) { a2 = value; }
void Rational::Set_b2(int value) { b2 = value; }


Rational::Rational() { a1 = 0, b1 = 0, a2 = 0, b2 = 0; }

Rational::Rational(int a1 = 0, int b1 = 0, int a2 = 0, int b2 = 0)	throw(My_Error_Range)
{
	if ((a1 <= 0) || (b1 <= 0) || (a2 <= 0) || (b2 <= 0))
		throw new My_Error_Range("\n\nНеправильно введені дані");		//генерування об'єкта винятка

	this->a1 = a1;
	this->b1 = b1;
	this->a2 = a2;
	this->b2 = b2;
}
Rational::Rational(const Rational& X)
{
	a1 = X.Get_a1();
	b1 = X.Get_b1();
	a2 = X.Get_a2();
	b2 = X.Get_b2();
}
Rational& Rational::operator =(const Rational& X)
{
	a1 = X.a1;
	b1 = X.b1;
	a2 = X.a2;
	b2 = X.b2;
	return *this;
}
ostream& operator << (ostream& out, const Rational& X)
{
	out << "\n\nВведені значення :";
	out << "\n a1 = " << X.a1;
	out << "\n b1 = " << X.b1;
	out << "\n a2 = " << X.a2;
	out << "\n b2 = " << X.b2;
	return out;
}
istream& operator >>(istream& in, Rational& X)	throw(std::out_of_range)
{
	int a1_1, b1_1, a2_1, b2_1;

	cout << "Введіть чисельник першого дробу(а1) = "; cin >> a1_1;
	cout << "Введіть знаменник першого дробу(b1) = "; cin >> b1_1;
	cout << "Введіть чисельник другого дробу(а2) = "; cin >> a2_1;
	cout << "Введіть знаменник другого дробу(b2) = "; cin >> b2_1;

	if ((a1_1 <= 0) || (b1_1 <= 0) || (a2_1 <= 0) || (b2_1 <= 0))
		throw std::out_of_range{ "\n\nДані введені неправильно" };

	X.a1 = a1_1;
	X.b1 = b1_1;
	X.a2 = a2_1;
	X.b2 = b2_1;

	return in;
}
Rational::operator string()const
{
	stringstream ss;
	ss << "" << a1 << endl;
	ss << "" << b1 << endl;
	ss << "" << a2 << endl;
	ss << "" << b2 << endl;
	return ss.str();
}
Rational& Rational::operator ++()
{
	++a1;
	++b1;
	return *this;
}
Rational& Rational::operator --()
{
	--a1;
	--b1;
	return *this;
}
Rational Rational::operator ++(int)
{
	Rational F(*this);
	a2++;
	b2++;
	return  F;
}
Rational Rational::operator --(int)
{
	Rational F(*this);
	a2--;
	b2--;

	return  F;
}
double Rational::Mnojennya()
{
	int Ma = (a1 * a2);
	int Mb = (b1 * b2);
	cout << "Множення дробів = " << Ma << "/" << Mb << endl;
	return Ma;
}
double Rational::Dodavannya()
{
	int Da = (a1 * b2 + a2 * b1);
	int Db = (b1 * b2);
	cout << "Додавання дробів = " << Da << "/" << Db << endl;
	return Da, Db;
}
double Rational::Vidnimannya()
{
	int Va = (a1 * b2 - a2 * b1);
	int Vb = (b1 * b2);
	cout << "Віднімання дробів = " << Va << "/" << Vb << endl;
	return Va, Vb;
}
double Rational::Value()
{
	cout << "Перший оперований дріб : " << Get_b1() << "/" << Get_a1() << endl;
	cout << "Другий оперований дріб : " << Get_b2() << "/" << Get_a2() << endl;
	return 1. * a1 / b1;
}

