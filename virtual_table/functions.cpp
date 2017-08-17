#include "basic.h"
#include "derived.h"
#include <iostream>

using namespace std;

void Base1::f1() // functions of Base1
{
	cout << "this is the virtual function f1 of Base1." << endl;
}

void Base1::g1()
{
	cout << "this is the virtual function g1 of Base1." << endl;
}

void Base1::h1()
{
	cout << "this is the virtual function h1 of Base1." << endl;
}

void Base1::pri_f()
{
	cout << "this is the private function of Base1." << endl;
}

void Base2::f2() // functions of Base2
{
	cout << "this is the virtual function f2 of Base2." << endl;
}

void Base2::g2()
{
	cout << "this is the virtual function g2 of Base2." << endl;
}

void Base2::h2()
{
	cout << "this is the virtual function h2 of Base2." << endl;
}

void Base3::f3() // functions of Base3
{
	cout << "this is the virtual function f3 of Base3." << endl;
}

void Base3::g3()
{
	cout << "this is the virtual function g3 of Base3." << endl;
}

void Base3::h3()
{
	cout << "this is the virtual function h3 of Base3." << endl;
}

void Derive_not_cover::deri_f()
{
	cout << "deri_f of class Derive_not_cover." << endl;
}

void Derive_cover::f1()
{
	cout << "overrided by f1() of class Derive_cover." << endl;
}

void Derive_cover::g1()
{
	cout << "overrided by g1() of class Derive_cover." << endl;
}

void Derive_cover::h1()
{
	cout << "overrided by h1() of class Derive_cover." << endl;
}

void Multi_derive::f1()
{
	cout << "overrided by f1() of Multi_derive." << endl;
}

void Multi_derive::m_derive_g()
{
	cout << "m_derive_g() of Multi_derive." << endl;
}