#ifndef _ROOM_A_H_
#include <iostream>

using namespace std;

class Room;

class Room_A: public Room { // empty room
public:
	Room_A() {}
	Room_A(const string &_type) {
		type = _type;
	}
	virtual void Message() const
	{
		cout << "An empty room. Nothing happened here." << endl;
	}
	virtual string get_type() const
	{
		return type;
	}
	virtual ~Room_A() {
		cout << "333";
	}
};

#endif