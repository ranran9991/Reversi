a.out: Board.o Game.o Player.o HumanPlayer.o AIPlayer.o RemotePlayer.o main.o
	g++ -o Reversi Board.o Game.o Player.o main.o HumanPlayer.o AIPlayer.o RemotePlayer.o

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

RemotePlayer.o: RemotePlayer.cpp RemotePlayer.h
	g++ -c RemotePlayer.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp
