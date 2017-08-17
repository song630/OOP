#include "fraction.h"
#include "function.cpp"
using namespace std;

int main()
{
	Fraction f1(3, 10);
	Fraction f2(0, 0);
	Fraction f3;
	string a = f1;
    f3 = f1 / f2;
	cout << f3;

	system("pause");
	return 0;
}
