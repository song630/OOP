CC = g++
OBJ = function.o main.o
HEADER = out_of_bounds.h templateVector.h
app: function.o main.o
	$(CC) -o app function.o main.o
main.o: main.cpp function.cpp $(HEADER)
	$(CC) -c main.cpp
function.o: function.cpp $(HEADER)
	$(CC) -c function.cpp