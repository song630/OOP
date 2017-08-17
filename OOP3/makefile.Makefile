CC = g++
OBJ = func.o game.o
HEADER = lobby.h room_a.h room_b.h prison.h monster.h
app: $(OBJ)
	$(CC) -o app $(OBJ)
game.o: game.cpp room.h $(HEADER) the_hero.h
	$(CC) -c game.cpp
func.o: func.cpp the_hero.h
	$(CC) -c func.cpp