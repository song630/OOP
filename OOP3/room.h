#ifndef _ROOM_H_
#define _ROOM_H_

#include <iostream>
#include <string>
using namespace std;

class Room {
public:
	Room() {}
	Room(const string &_type) {
	    type = _type;
	}
	virtual void Message() const {}
	virtual string get_type() const {} // =====ERROR: foo() {} const
	virtual ~Room() {
		cout << "111";
	}
protected:
	string type;
};

#endif
