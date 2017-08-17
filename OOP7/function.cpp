#include "String.h"
#include "out_of_range.h"
#include <stdexcept>
#include <cassert>
#include <iomanip>
#define MAX_LENGTH 255
using namespace std;

String::String(int length, char ch)
{
	assert(length > 0); // generate a compile-time error
	p_string = new char[length + 1];
	for(int i = 0; i <= length - 1; i++)
		p_string[i] = ch;
	p_string[length] = '\0';
}

String::String(const String& other) //===== must use user-defined copy Ctor
{                                   // when the class has pointer data member.
	assert(other.p_string != NULL); // not NULL
	int length = strlen(other.p_string); // '\0' not considered in strlen()
	p_string = new char[length + 1];
	p_string = strcpy(p_string, other.p_string);
	p_string[length] = '\0';
}

String::String(const char *str)
{
	assert(str != NULL);
	int length = strlen(str);
	p_string = new char[length + 1];
	p_string = strcpy(p_string, str);
	p_string[length] = '\0';
}

String& String::operator = (const String& other) //=====
{
	assert(other.p_string != NULL); // must not assign to itself
	int length = strlen(other.p_string);
	p_string = new char[length + 1];
	p_string = strcpy(p_string, other.p_string);
	p_string[length] = '\0';
	return *this; // must return this
}

String& String::operator = (const char *str)
{
	assert(str != NULL);
	int length = strlen(str);
	p_string = new char[length + 1];
	p_string = strcpy(p_string, str);
	p_string[length] = '\0';
	return *this; // must return this
}

String& String::operator += (const String& other)
{
	if(other.p_string == NULL)
		return *this;
	else
	{
		int new_length = strlen(p_string) + strlen(other.p_string);
		int pre_length = strlen(p_string);
		char *temp = new char[pre_length];
		temp = strcpy(temp, p_string);
		p_string = new char[new_length + 1];
		for(int i = 0; i <= pre_length - 1; i++)
			p_string[i] = temp[i];
		for(int i = pre_length; i <= new_length - 1; i++)
			p_string[i] = other.p_string[i - pre_length];
		p_string[new_length] = '\0';
		return *this;
	}
}

String& String::operator += (const char *str)
{
	if(str == NULL)
		return *this;
	else
	{
		int new_length = strlen(p_string) + strlen(str);
		int pre_length = strlen(p_string);
		int add_length = strlen(str);
		char *temp = new char[pre_length];
		temp = strcpy(temp, p_string);
		p_string = new char[new_length + 1];
		for(int i = 0; i <= pre_length - 1; i++)
			p_string[i] = temp[i];
		for(int i = pre_length; i <= new_length - 1; i++)
			p_string[i] = str[i - pre_length];
		p_string[new_length] = '\0';
		return *this;
	}
}

char& String::operator [] (const int index)
{
	if(index < 0 || index >= s_size())
	{
		INDEX_ERROR err(index);
		err.Message();
		throw err;
	}
	return p_string[index];
}

const char& String::operator [] (const int index) const
{
	return (*this)[index];
}

bool operator == (const String& s1, const String& s2)
{
	if(strlen(s1.p_string) != strlen(s2.p_string))
		return false;
	return !strcmp(s1.p_string, s2.p_string);
}

bool operator != (const String& s1, const String& s2)
{
	return !(s1 == s2);
}

String operator + (const String& s1, const String& s2)
{
	int length_1 = strlen(s1.p_string);
	int length_2 = strlen(s2.p_string);
	int new_length = length_1 + length_2;
	String s;
	s.p_string = new char[new_length + 1];
	for(int i = 0; i <= length_1 - 1; i++)
		s.p_string[i] = s1.p_string[i];
	for(int i = length_1; i <= new_length - 1; i++)
		s.p_string[i] = s2.p_string[i - length_1];
	s.p_string[new_length] = '\0';
	return s;
}

String operator + (const char *str, const String& s2)
{
	int length_1 = strlen(str);
	int length_2 = strlen(s2.p_string);
	int new_length = length_1 + length_2;
	String s;
	s.p_string = new char[new_length + 1];
	for(int i = 0; i <= length_1 - 1; i++)
		s.p_string[i] = str[i];
	for(int i = length_1; i <= new_length - 1; i++)
		s.p_string[i] = s2.p_string[i - length_1];
	s.p_string[new_length] = '\0';
	return s;
}

String operator + (const String& s1, const char *str)
{
	int length_1 = strlen(s1.p_string);
	int length_2 = strlen(str);
	int new_length = length_1 + length_2;
	String s;
	s.p_string = new char[new_length + 1];
	for(int i = 0; i <= length_1 - 1; i++)
		s.p_string[i] = s1.p_string[i];
	for(int i = length_1; i <= new_length - 1; i++)
		s.p_string[i] = str[i - length_1];
	s.p_string[new_length] = '\0';
	return s;
}

ostream& operator << (ostream& out, const String& other)
{
	if(other.p_string != NULL)
		out << other.p_string;
	return out;
}

istream& operator >> (istream& in, String& other)
{
	char temp[MAX_LENGTH];
	in >> setw(255) >> temp;
	other = temp; // call the assignment function defined above
	return in;
}

unsigned int String::s_size() const
{
	if(is_empty())
		return 0;
	return strlen(p_string);
}

bool String::is_empty() const
{
	if(p_string == NULL)
		return true;
	else
		return false;
}

String::~String()
{
	delete [] p_string;
}