#ifndef _PRISON_H_
#include <iostream>

using namespace std;

class Room;

class Prison: public Room {
public:
	Prison() {}
	Prison(const string &_type) {
		type = _type;
	}
	virtual void Message() const
	{
		cout << "Congratulations! You've found the princess." << endl;
		cout << "Now you have to leave the castle via the lobby." << endl;
	}
	virtual string get_type() const
	{
		return type;
	}
	virtual ~Prison() {
		cout << "555";
	}
};

#endif