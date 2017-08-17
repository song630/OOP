#ifndef _MONSTER_H_
#include <iostream>

using namespace std;

class Room;

class Monster_room: public Room {
public:
	Monster_room();
	Monster_room(const string &_type) {
		type = _type;
	}
	virtual void Message() const
	{
		cout << "You ran into the monster of this castle!" << endl;
		cout << "you were killed by it." << endl;
	}
	virtual string get_type() const
	{
		return type;
	}
	virtual ~Monster_room() {
		cout << "666";
	}
};

#endif