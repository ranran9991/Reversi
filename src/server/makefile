a.out: main.o GameServer.o CommandManager.o Command.o RoomCommand.o JoinCommand.o ListGamesCommand.o StartCommand.o GameRoom.o Task.o ThreadPool.o
	g++ -pthread -o ReversiServer main.o GameServer.o CommandManager.o Command.o RoomCommand.o JoinCommand.o ListGamesCommand.o  StartCommand.o GameRoom.o Task.o ThreadPool.o

main.o: main.cpp GameServer.h
	g++ -c main.cpp

GameServer.o: GameServer.cpp GameServer.h Task.h ThreadPool.h
	g++ -c GameServer.cpp

CommandManager.o: CommandManager.cpp CommandManager.h
	g++ -c CommandManager.cpp

Command.o: Command.cpp Command.h
	g++ -c Command.cpp

RoomCommand.o: RoomCommand.cpp RoomCommand.h
	g++ -c RoomCommand.cpp

JoinCommand.o: JoinCommand.cpp JoinCommand.h
	g++ -c JoinCommand.cpp

ListGamesCommand.o: ListGamesCommand.cpp ListGamesCommand.h
	g++ -c ListGamesCommand.cpp
	
StartCommand.o: StartCommand.cpp StartCommand.h
	g++ -c StartCommand.cpp

GameRoom.o: GameRoom.cpp GameRoom.h
	g++ -c GameRoom.cpp

Task.o: Task.cpp Task.h
	g++ -c Task.cpp

ThreadPool.o: ThreadPool.cpp ThreadPool.h
	g++ -c ThreadPool.cpp
