a.out: Board.o Game.o Player.o HumanPlayer.o AIPlayer.o main.o
	g++ Board.o Game.o Player.o main.o HumanPlayer.o AIPlayer.o

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

main.o: main.cpp Game.h
	g++ -c main.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h
	g++ -c HumanPlayer.cpp

AIPlayer.o: AIPlayer.cpp AIPlayer.h
	g++ -c AIPlayer.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp
