CC = g++

all:
	$(CC) -std=c++14 -o result main.cpp
	
clean:
	-f a.exe
