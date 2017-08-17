#pragma once
#ifndef _OUT_OF_RANGE_H_
#define _OUT_OF_RANGE_H_

using namespace std;

class INDEX_ERROR {
public:
	INDEX_ERROR(int val): bad_value(val) {}
	void Message() {
		cerr << "Index " << bad_value << " out of range!\n";
	}
	~INDEX_ERROR() {}
private:
	int bad_value;
};

#endif