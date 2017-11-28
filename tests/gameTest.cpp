/*
 * gameTest.cpp
 *
 *  Created on: Nov 28, 2017
 *      Author: ranran9991
 */

#include "gtest/gtest.h"
#include "Game.h"
namespace{
class gameTest : public ::testing::Test{
protected:
	Game game;
	};
	TEST(gameTest, boardNotFull){
		Board* board = new Board();
		Game game(board);
		board->MakeMove(5, 6, 'X');
		board->MakeMove(6, 4, 'O');
		board->MakeMove(5, 3, 'X');
		board->MakeMove(4, 6, 'O');
		board->MakeMove(3, 5, 'X');
		board->MakeMove(6, 6, 'O');
		board->MakeMove(5, 7, 'X');
		board->MakeMove(6, 5, 'O');
		board->MakeMove(7, 5, 'X');
		ASSERT_TRUE(game.End());
	}
	TEST(gameTest, normal_boardFull){
			Board* board = new Board();
			Game game(board);
			board->MakeMove(3, 4, 'X');
			board->MakeMove(3, 5, 'O');
			board->MakeMove(4, 6, 'X');
			board->MakeMove(5, 7, 'O');
			board->MakeMove(2, 5, 'X');
			board->MakeMove(4, 3, 'O');
			board->MakeMove(6, 5, 'X');
			board->MakeMove(7, 6, 'O');
			board->MakeMove(4, 2, 'X');
			board->MakeMove(1, 5, 'O');
			board->MakeMove(1, 6, 'X');
			board->MakeMove(3, 3, 'O');
			board->MakeMove(4, 7, 'X');
			board->MakeMove(5, 1, 'O');
			board->MakeMove(2, 3, 'X');
			board->MakeMove(1, 7, 'O');
			board->MakeMove(3, 6, 'X');
			board->MakeMove(2, 7, 'O');
			board->MakeMove(4, 1, 'X');
			board->MakeMove(3, 1, 'O');
			board->MakeMove(5, 6, 'X');
			board->MakeMove(3, 7, 'O');
			board->MakeMove(5, 3, 'X');
			board->MakeMove(6, 4, 'O');
			board->MakeMove(3, 8, 'X');
			board->MakeMove(2, 8, 'O');
			board->MakeMove(5, 2, 'X');
			board->MakeMove(4, 8, 'O');
			board->MakeMove(3, 2, 'X');
			board->MakeMove(2, 1, 'O');
			board->MakeMove(5, 8, 'X');
			board->MakeMove(2, 2, 'O');
			board->MakeMove(6, 3, 'X');
			board->MakeMove(6, 1, 'O');
			board->MakeMove(7, 4, 'X');
			board->MakeMove(1, 4, 'O');
			board->MakeMove(1, 8, 'X');
			board->MakeMove(6, 7, 'O');
			board->MakeMove(7, 7, 'X');
			board->MakeMove(2, 4, 'O');
			board->MakeMove(8, 7, 'X');
			board->MakeMove(6, 8, 'O');
			board->MakeMove(7, 8, 'X');
			//KEEP GOING FROM HERE
			board->MakeMove(6, 8, 'O');
			board->MakeMove(7, 8, 'X');
			board->MakeMove(1, 7, 'O');
			board->MakeMove(3, 6, 'X');
			board->MakeMove(2, 7, 'O');
			board->MakeMove(4, 1, 'X');
			board->MakeMove(3, 1, 'O');
			board->MakeMove(5, 6, 'X');
			board->MakeMove(3, 7, 'O');
			board->MakeMove(5, 3, 'X');
			board->MakeMove(6, 4, 'O');
			board->MakeMove(3, 8, 'X');
			board->MakeMove(2, 8, 'O');
			board->MakeMove(5, 2, 'X');
			board->MakeMove(4, 8, 'O');
			board->MakeMove(3, 2, 'X');
			ASSERT_TRUE(game.End());
	}
}
