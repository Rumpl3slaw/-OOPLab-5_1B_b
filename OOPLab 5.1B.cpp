#include <iostream>
#include <Windows.h>

#include "Rational.h"
#include "Me_Error_size_memorry.h"
#include "My_Error_Range.h"


using namespace std;
int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		Rational a(17, 2, 33, 4);

		++a;
		cout << a;
		cout << endl;
		--a;
		cout << a;
		a++;
		cout << a;
		a--;
		cout << a;
		cout << endl;
		cout << a.operator string();
	}
	catch (My_Error_Range* a) {
		std::cout << a->What();
	}

	try { //захищений(контрольований) блок
		Rational b(17, 2, 33, 4);
		cin >> b;
		cout << b;

		cout << endl;
		cout << b.operator string();

		b.Dodavannya();
		cout << endl;

		b.Mnojennya();
		cout << endl;

		b.Vidnimannya();
		cout << endl;

		b.Value();
	}
	catch (std::out_of_range obj_1) {
		std::cout << obj_1.what();
	}

	try { //захищений(контрольований) блок
		int size(0);
		std::cout << "\n\nВведіть розмір масива: ";  std::cin >> size;

		if ((size < 0) || (size > 80'000'000))
			throw Me_Error_size_memorry("\nНевірно виділена пам’ять");
		Rational* c = new Rational[size];
	}
	catch (Me_Error_size_memorry& obj_2) {
		std::cout << obj_2.What();
	}

	return 0;
}