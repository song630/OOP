#pragma once
#ifndef _OUT_OF_BOUNDS_H_
#define _OUT_OF_BOUNDS_H_

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class IndexOutofBounds {
public:
	IndexOutofBounds(int val): bad_value(val) {}
	void errMessage() {
		cerr << "Index " << bad_value << " is out of range!\n";
	}
	~IndexOutofBounds() {}
private:
	int bad_value;
};

#endif