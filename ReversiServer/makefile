a.out: main.o GameServer.o
	g++ -o ReversiServer main.o GameServer.o

main.o: main.cpp GameServer.h
	g++ -c main.cpp

GameServer.o: GameServer.cpp GameServer.h
	g++ -c GameServer.cpp
