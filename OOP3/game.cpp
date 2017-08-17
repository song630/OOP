#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "room.h"
#include "lobby.h"
#include "room_a.h"
#include "room_b.h"
#include "prison.h"
#include "monster.h"
#include "the_hero.h"

using namespace std;

int main(void)
{
	Room *castle[3][3];
	Room *ptr_room;
	Lobby l("lobby");
	Room_A a1("room_a"), a2("room_a"), a3("room_a"), a4("room_a");
	Room_B b1("room_b"), b2("room_b"), b3("room_b");
	Prison p("prison");
	Monster_room mon("monster");
	Man hero;
	string opr;
	Position coordinate;
	int randx, randy;

	hero.init();
	ptr_room = &l;
	castle[2][1] = ptr_room;
	ptr_room = &a1;
	castle[2][0] = ptr_room;
	ptr_room = &b1;
	castle[2][2] = ptr_room;
	ptr_room = &b2;
	castle[1][0] = ptr_room;
	ptr_room = &a2;
	castle[1][1] = ptr_room;
	ptr_room = &a3;
	castle[1][2] = ptr_room;
	ptr_room = &p;
	castle[0][0] = ptr_room;
	ptr_room = &a4;
	castle[0][1] = ptr_room;
	ptr_room = &b3;
	castle[0][2] = ptr_room;

	srand((unsigned)time(NULL));
	do {
		randx = rand() % 3; // generate a random integer within the range of 0~2
		randy = rand() % 3; // should not cover the prison or the lobby
	} while(randx == 2 && randy == 1 || randx == 0 && randy == 0);
	ptr_room = &mon; // the monster room is randomly placed
	castle[randx][randy] = ptr_room; // cover the previous room
	// cout << randx << randy << endl;

	castle[2][1]->Message(); // print the beginning info of the lobby
	while(1)
	{
		if(!hero.is_alive())
		{
			cout << "Game over!" << endl;
			break;
		}
		cin >> opr;
		while(!hero.move(opr)) // if the input is illegal
			cin >> opr;
		coordinate.x = hero.get_pos().x;
		coordinate.y = hero.get_pos().y;

		if(castle[coordinate.x][coordinate.y]->get_type() == "lobby") // get to the lobby
		{
			if(hero.found_princess()) // has found the princess
			{
			    cout << "You and the princess left the castle via the lobby." << endl;
				cout << "You win!" << endl;
				break;
			}
			else // do not show the lobby message again.
                cout << "You entered the lobby." << endl;
		}
		else if(castle[coordinate.x][coordinate.y]->get_type() == "prison") // get to prison
		{
			if(!hero.found_princess()) // has not entered this room before
			{
				castle[coordinate.x][coordinate.y]->Message();
				hero.set_find();
			}
			else; // do not show the prison message again
		}
		else // room_a, room_b, or the monster-room
		{
			castle[coordinate.x][coordinate.y]->Message();
			if(castle[coordinate.x][coordinate.y]->get_type() == "monster")
			{
				for(int i = 0; i <= 2; i++)
					hero.suffer_damage();
			}
			if(castle[coordinate.x][coordinate.y]->get_type() == "room_b")
				hero.suffer_damage();
		}

		if(coordinate.x == randx && (coordinate.y == randy + 1 || coordinate.y == randy - 1))
			cout << "You heard something howling! Watch out, the monster may be very close." << endl;
		else if(coordinate.y == randy && (coordinate.x == randx + 1 || coordinate.x == randx - 1))
			cout << "You heard something howling! Watch out, the monster may be very close." << endl;
	}

	system("pause");
	return 0;
}
