#pragma once
#ifndef _TEMPLATE_VECTOR_H_
#define _TEMPLATE_VECTOR_H_

#include "out_of_bounds.h"
using namespace std;

class IndexOutOfBounds;
template <class T> class Vector; //=======
template <class Type>
ostream& operator << (ostream& out, const Vector<Type> &v);

template <class T>
class Vector {
public:
	Vector() {} // create an empty vector
	Vector(int size); // create a vector of size elements
	Vector(const Vector& r); // copy ctor
	virtual ~Vector();
	T& operator[](int index);
	// return the specified element, throws exception when index < 0 or >= m_nSize
	int size(); // return the size of the vector
	int inflate(int addSize);
	// expand the storage to m_nSize + addSize, return the new size
	friend ostream& operator<< <T> (ostream&, const Vector<T>&); // one-to-one type

private:
	T *m_pElements;
	int m_nSize;   
};

#endif