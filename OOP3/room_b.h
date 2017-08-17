#ifndef _ROOM_B_H
#include <iostream>

using namespace std;

class Room;

class Room_B: public Room {
public:
	Room_B() {}
	Room_B(const string &_type) {
		type = _type;
	}
	virtual void Message() const
	{
		cout << "You triggered the trap!" << endl;
		cout << "The hero suffered 20 damage." << endl;
	}
	virtual string get_type() const
	{
		return type;
	}
	virtual ~Room_B() {
		cout << "444";
	}
};

#endif