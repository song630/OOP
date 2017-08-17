#include "the_hero.h"
#include <iostream>

#define MAX_HEALTH 50
#define LOBBY_X_POS 2
#define LOBBY_Y_POS 1

void Man::init()
{
	health = MAX_HEALTH;
	pos.x = LOBBY_X_POS;
	pos.y = LOBBY_Y_POS;
	find = false;
}

bool Man::move(const string &opr)
{
	bool flag = false; // whether the input is legal
	if(opr == "up")
	{
		if(pos.x == 0)
			cout << "Cannot go up anymore." << endl << "Enter again: ";
		else
		{
			pos.x--;
			flag = true;
		}
	}
	else if(opr == "down")
	{
		if(pos.x == 2)
			cout << "Cannot go down anymore." << endl << "Enter again: ";
		else
		{
			pos.x++;
			flag = true;
		}
	}
	else if(opr == "left")
	{
		if(pos.y == 0)
			cout << "Cannot go left anymore." << endl << "Enter again: ";
		else
		{
			pos.y--;
			flag = true;
		}
	}
	else if(opr == "right")
	{
		if(pos.y == 2)
			cout << "Cannot go right anymore." << endl << "Enter again: ";
		else
		{
			pos.y++;
			flag = true;
		}
	}
	else
		cout << "Invalid input." << endl << "Enter again: ";
	return flag;
}

bool Man::is_alive() const
{
	if(health > 0)
		return true;
	else
		return false;
}

Position Man::get_pos() const
{
	return pos;
}

void Man::set_find()
{
	find = true;
}

bool Man::found_princess() const
{
	return find;
}

void Man::suffer_damage()
{
	health -= 20;
}