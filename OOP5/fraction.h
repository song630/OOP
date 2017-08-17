#pragma once
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

class Fraction {
public:
	Fraction(): numerator(0), denominator(1) {} // default ctor
	explicit Fraction(int nume, int deno): numerator(nume), denominator(deno) { // denominator should not be 0
		if((deno == 0 && nume != 0) || denominator < 0) // prevent an object like 11/-5
			throw runtime_error("Illegal initialization!");
	}
	Fraction(const Fraction& f) {
		numerator = f.numerator;
		denominator = f.denominator;
	} // copy ctor
	friend Fraction operator + (const Fraction& f1, const Fraction& f2);
	friend Fraction operator - (const Fraction& f1, const Fraction& f2);
	friend Fraction operator * (const Fraction& f1, const Fraction& f2);
	friend Fraction operator / (const Fraction& f1, const Fraction& f2);
	Fraction& operator += (const Fraction f); // better define related assignment operator
	Fraction& operator -= (const Fraction f); // if one arithmetic operator is already defined.
	Fraction& operator *= (const Fraction f);
	Fraction& operator /= (const Fraction f);
	friend bool operator == (const Fraction f1, const Fraction f2);
	friend bool operator != (const Fraction f1, const Fraction f2);
	friend bool operator < (const Fraction f1, const Fraction f2);
	friend bool operator > (const Fraction f1, const Fraction f2);
	friend bool operator <= (const Fraction f1, const Fraction f2);
	friend bool operator >= (const Fraction f1, const Fraction f2);
	operator double() const; // when performing 1 + 2/3(which is not defined in operator reloading),
	operator string() const; // "2/3" can be converted to double(but the prototype is not Fraction).
	friend istream& operator >> (istream& in, Fraction& f);
	friend ostream& operator << (ostream& out, const Fraction& f);
	~Fraction() {}

private:
	int numerator;
	int denominator;
};

int greatest_common_divisor(int a, int b);
int least_common_multiple(int a, int b);

#endif
