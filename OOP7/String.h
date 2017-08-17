#pragma once
#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

class String {
public:
	String(): p_string(NULL) {} // default Ctor
	String(int length, char ch); // Ctor ===== only inline function with {}
	String(const String&); // copy Ctor
	String(const char*); // can this copy Ctor do sth like String s = "1111"?
	friend bool operator == (const String& s1, const String& s2);
	friend bool operator != (const String& s1, const String& s2);
	String& operator = (const String& other);
	String& operator = (const char *str); // can do assignments like s = "1111";
	String& operator += (const String& other);
	String& operator += (const char *str);
	char& operator [] (const int index); // overrode index operator(left value)
	const char& operator [] (const int index) const; // overrode index operator(right value)
	friend String operator + (const String& s1, const String& s2);
	friend String operator + (const char *str, const String& s2);
	friend String operator + (const String& s1, const char *str);
	friend ostream& operator << (ostream&, const String&);
	friend istream& operator >> (istream&, String&); // the parameter cannot be const
	unsigned int s_size() const; // use size_type (or size_t)?
	bool is_empty() const;
	~String();
private:
	char *p_string;
};

// most overrode arithmetic operators and relationship operators
// should be defined as non-member function,
// but overrode assignmment operators should.

bool operator == (const String& s1, const String& s2);
bool operator != (const String& s1, const String& s2);
String operator + (const String& s1, const String& s2);
String operator + (const char *str, const String& s2);
String operator + (const String& s1, const char *str);
ostream& operator << (ostream&, const String&);
istream& operator >> (istream&, String&);

#endif