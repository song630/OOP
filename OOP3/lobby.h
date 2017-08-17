#ifndef _LOBBY_H_
#include <iostream>

using namespace std;

class Room;

class Lobby: public Room {
public:
	Lobby() {}
	Lobby(const string &_type) {
		type = _type;
	}
	virtual void Message() const
	{
		cout << "Welcome to the lobby!" << endl;
		cout << "Instructions: each room has four exits," << endl;
		cout << "you can type left/right/up/down to enter rooms." << endl;
		cout << "Your maximum health is 50, once your health decreases to 0, you die." << endl;
		cout << "Notice: Only after you found the princess can you leave the lobby." << endl;
	}
	virtual string get_type() const
	{
		return type;
	}
	virtual ~Lobby() {
		cout << "222";
	}
};

#endif