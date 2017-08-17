#include "out_of_bounds.h"
#include "templateVector.h"
using namespace std;

template <class T> Vector<T>::Vector(int size)
{
	m_pElements = new T[size];
	m_nSize = size;
}

template <class T> Vector<T>::Vector(const Vector& r)
{
	m_pElements = new T[r.m_nSize];
	m_nSize = r.m_nSize;
	for(int i = 0; i <= m_nSize - 1; i++)
		m_pElements[i] = r.m_pElements[i];
}

template <class T> Vector<T>::~Vector()
{
	delete [] m_pElements;
	cout << "dtor\n"; // marking the object has been deleted
}

template <class T>
T& Vector<T>::operator[](int index)
{
	if(index < 0 || index >= m_nSize) // raise
	{
		IndexOutofBounds err(index);
		err.errMessage();
		throw err;
	}
	return m_pElements[index];
}

template <class T> int Vector<T>::size()
{
	return m_nSize;
}

template <class T> int Vector<T>::inflate(int addSize)
{
	T *tempP = m_pElements;
	m_pElements = new T[m_nSize + addSize];
	for(int i = 0; i <= m_nSize - 1; i++)
		m_pElements[i] = tempP[i];
	m_nSize += addSize;
	return m_nSize;
}

template <class Type>
ostream& operator << (ostream& out, const Vector<Type> &v) //=========
{
	out << "< ";
	for(int i = 0; i <= v.m_nSize - 1; i++)
		out << v.m_pElements[i] << " ";
	out << ">";
	return out; //=========
}