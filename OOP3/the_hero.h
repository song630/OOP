#ifndef _THE_HERO_H_

#include <string>
using namespace std;

struct Position
{
	int x;
	int y;
};

class Man {
public:
	Man() {}
	void init();
	bool move(const string &opr); // get an operation input first
	bool is_alive() const;
	Position get_pos() const;
	void set_find();
	bool found_princess() const;
	void suffer_damage();
	~Man() {}
	
private:
	int health; // 50 at the beginning of the game
	Position pos;
	bool find; // a state marking whether the pricess is found
};

#endif