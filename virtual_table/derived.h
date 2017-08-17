#ifndef _DERIVED_H

class Base1;
class Base2;
class Base3;

class Derive_not_cover: public Base1 { // virtual function in the son class does not
public:                                // override that in father class.
	virtual void deri_f()
	{
		cout << "deri_f of class Derive_not_cover." << endl;
	}
	virtual ~Derive_not_cover() {}
};

class Derive_cover: public Base1 {
public:
	virtual void f1()
	{
		cout << "overrided by f1() of class Derive_cover." << endl;
	} // "virtual" can be omitted, but better not to
	virtual void g1()
	{
		cout << "overrided by g1() of class Derive_cover." << endl;
	}
	virtual void h1()
	{
		cout << "overrided by h1() of class Derive_cover." << endl;
	}
	int derive_cover_member_var_1; // and it has another two member variables derived
	virtual ~Derive_cover()        // from class Base1.
	{
		cout << "dtor of Derive_cover." << endl;
	}
};

class Multi_derive: public Base1, public Base2, public Base3 {
	virtual void f1()
	{
		cout << "overrided by f1() of Multi_derive." << endl;
	}
	virtual void m_derive_g()
	{
		cout << "m_derive_g() of Multi_derive." << endl;
	} // does not override
	virtual ~Multi_derive() {}
};

#endif