CC = g++

pdadd: data_file.o pdadd.o
	$(CC) -o pdadd data_file.o pdadd.o
pdlist: data_file.o pdlist.o
	$(CC) -o pdlist data_file.o pdlist.o
pdshow: data_file.o pdshow.o
	$(CC) -o pdshow data_file.o pdshow.o
pdremove: data_file.o pdremove.o
	$(CC) -o pdremove data_file.o pdremove.o


data_file.o: data_file.cpp basic.h
	$(CC) -c data_file.cpp
pdadd.o: pdadd.cpp basic.h
	$(CC) -c pdadd.cpp
pdlist.o: pdlist.cpp basic.h
	$(CC) -c pdlist.cpp
pdshow.o: pdshow.cpp basic.h
	$(CC) -c pdshow.cpp
pdremove.o: pdremove.cpp basic.h
	$(CC) -c pdremove.cpp