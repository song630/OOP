#include "fraction.h"
using namespace std;

int greatest_common_divisor(int a, int b)
{
	int c;
	do {
		c = a % b;
		a = b;
		b = c;
	} while(c);
	return a;
}

int least_common_multiple(int a, int b, int divisor)
{
	return (a*b / divisor);
}

Fraction operator + (const Fraction& f1, const Fraction& f2)
{
	Fraction result;
	int max_divisor = greatest_common_divisor(f1.denominator, f2.denominator);
	result.denominator = least_common_multiple(f1.denominator, f2.denominator,
						max_divisor);
	result.numerator = result.denominator/f1.denominator * f1.numerator +
		               result.denominator/f2.denominator * f2.numerator;
	int new_divisor = greatest_common_divisor(result.numerator, result.denominator);
	result.numerator /= new_divisor;
	result.denominator /= new_divisor;
	return result;
}

Fraction operator - (const Fraction& f1, const Fraction& f2)
{
	Fraction result;
	int max_divisor = greatest_common_divisor(f1.denominator, f2.denominator);
	result.denominator = least_common_multiple(f1.denominator, f2.denominator,
						max_divisor);
	result.numerator = result.denominator/f1.denominator * f1.numerator -
		               result.denominator/f2.denominator * f2.numerator;
	int new_divisor = greatest_common_divisor(result.numerator, result.denominator);
	result.numerator /= new_divisor;
	result.denominator /= new_divisor;
	if(result.denominator < 0) //===== prevent an object like 11/-5
	{
		result.denominator = -result.denominator;
		result.numerator = -result.numerator;
	}
	return result;
}

Fraction operator * (const Fraction& f1, const Fraction& f2)
{
	Fraction result(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
	int new_divisor = greatest_common_divisor(result.numerator, result.denominator);
	result.numerator /= new_divisor;
	result.denominator /= new_divisor;
	return result;
}

Fraction operator / (const Fraction& f1, const Fraction& f2)
{
	if(f2.numerator == 0) // ERROR
		throw runtime_error("The operation is not illegal!");
	Fraction result;
	/*
	using
	Fraction result(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
	may cause runtime_error given (3/10) / (-5/2).
	*/
	result.numerator = f1.numerator * f2.denominator;
	result.denominator = f1.denominator * f2.numerator;
	int new_divisor = greatest_common_divisor(result.numerator, result.denominator);
	result.numerator /= new_divisor;
	result.denominator /= new_divisor;
	if(result.denominator < 0)
	{
		result.denominator = -result.denominator;
		result.numerator = -result.numerator;
	}
	return result;
}

Fraction& Fraction::operator += (const Fraction f)
{
	*this = (*this) + f;
	return *this;
}

Fraction& Fraction::operator -= (const Fraction f)
{
	*this = (*this) - f;
	return *this;
}

Fraction& Fraction::operator *= (const Fraction f)
{
	*this = (*this) * f;
	return *this;
}

Fraction& Fraction::operator /= (const Fraction f)
{
	*this = (*this) / f;
}

bool operator == (const Fraction f1, const Fraction f2)
{
	if(static_cast<double> (f1) == static_cast<double> (f2))
		return true;
	else
		return false;
}

bool operator != (const Fraction f1, const Fraction f2)
{
	if(!(f1 == f2))
		return true;
	else
		return false;
}

bool operator < (const Fraction f1, const Fraction f2)
{
	if(static_cast<double> (f1) < static_cast<double> (f2))
		return true;
	else
		return false;
}

bool operator > (const Fraction f1, const Fraction f2)
{
	if(static_cast<double> (f1) > static_cast<double> (f2))
		return true;
	else
		return false;
}

bool operator <= (const Fraction f1, const Fraction f2)
{
	if(f1 < f2 || f1 == f2)
		return true;
	else
		return false;
}

bool operator >= (const Fraction f1, const Fraction f2)
{
	if(f1 > f2 || f1 == f2)
		return true;
	else
		return false;
}

Fraction::operator double() const
{
	double result;
	return result = static_cast<double> (numerator)
	                / static_cast<double> (denominator);
}

Fraction::operator string() const
{
	ostringstream s_nume, s_deno;
	string s1, s2, result;
	s_nume << numerator;
	s_deno << denominator;
	s1 = s_nume.str();
	s2 = s_deno.str();
	return result = s1 + "/" + s2;
}

istream& operator >> (istream& in, Fraction& f)
{
	in >> f.numerator >> f.denominator;
	while(!in || (f.denominator == 0 && f.numerator != 0) || f.denominator < 0) // prevent an object like 11/-5
	{
		cout << "Invalid input!\n";
		f = Fraction();
		cout << "Enter again: \n";
		in >> f.numerator >> f.denominator;
	}
	return in;
}

ostream& operator << (ostream& out, const Fraction& f)
{
	out << f.numerator << "/" << f.denominator;
	return out;
}
