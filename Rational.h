#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Rational {
private:
	int a1, b1, a2, b2;
public:
	Rational();
	Rational(int, int, int, int);
	Rational(const Rational&);

	int Get_a1()const;
	int Get_b1()const;
	int Get_a2()const;
	int Get_b2()const;

	void Set_a1(int);
	void Set_b1(int);
	void Set_a2(int);
	void Set_b2(int);

	Rational& operator = (const Rational&);
	operator string() const;

	friend ostream& operator << (ostream&, const Rational&);
	friend istream& operator >>(istream&, Rational&);

	Rational& operator ++();
	Rational& operator --();

	Rational operator ++(int);
	Rational operator--(int);

	friend Rational operator +(Rational&, Rational&);
	friend Rational operator -(Rational&, Rational&);
	friend int operator *(Rational&, Rational&);

	double Value();
	double Dodavannya();
	double Vidnimannya();
	double Mnojennya();

};