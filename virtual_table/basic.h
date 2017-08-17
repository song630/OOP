#ifndef _BASIC_H

#include <iostream>
using namespace std;

class Base1 {
public:
	virtual void f1() 
	{
		cout << "this is the virtual function f1 of Base1." << endl;
	}
	virtual void g1() 
	{
		cout << "this is the virtual function g1 of Base1." << endl;
	}
	virtual void h1() 
	{
		cout << "this is the virtual function h1 of Base1." << endl;
	}
	int pub_member_variable_1;
	int pub_member_variable_2;
	virtual ~Base1() 
	{
		cout << "dtor of Base1." << endl;
	}
private:
	virtual void pri_f() 
	{
		cout << "this is the private function of Base1." << endl;
	} // use pointer to access a private member function
	int pri_x;
};

class Base2 { // class 2 and 3 is for trial of multi-derived class
public:
	virtual void f2() 
	{
		cout << "this is the virtual function f2 of Base2." << endl;
	}
	virtual void g2() 
	{
		cout << "this is the virtual function g2 of Base2." << endl;
	}
	virtual void h2() 
	{
		cout << "this is the virtual function h2 of Base2." << endl;
	}
	virtual ~Base2() {}
};

class Base3 {
public:
	virtual void f3() 
	{
		cout << "this is the virtual function f3 of Base3." << endl;
	}
	virtual void g3() 
	{
		cout << "this is the virtual function g3 of Base3." << endl;
	}
	virtual void h3() 
	{
		cout << "this is the virtual function h3 of Base3." << endl;
	}
	virtual ~Base3() {}
};

#endif