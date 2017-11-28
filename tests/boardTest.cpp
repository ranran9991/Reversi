/*
 * gameTest.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: ranran9991
 */
#include "gtest/gtest.h"
#include "Board.h"
namespace{
class boardTest : public ::testing::Test {
	protected:
	Board board;
	};
	TEST(boardTest, IllegalMove){
		Board board;
		ASSERT_FALSE(board.MakeMove(1, 5, 'X'));
	}
	TEST(boardTest, LegalMove){
		Board board;
		ASSERT_TRUE(board.MakeMove(3, 4, 'X'));
	}
	TEST(boardTest, outOfBoundsMove){
		Board board;
		ASSERT_FALSE(board.MakeMove(9, 2, 'o'));
	}
	TEST(boardTest, NegValueMoveCordinates){
		Board board;
		ASSERT_FALSE(board.MakeMove(-1, 4, 'X'));
	}
	TEST(boardTest, legalMoveVectorStart){
		Board board;
		vector< pair<int, int> > expectedVek;
		expectedVek.push_back(make_pair(3,4));
		expectedVek.push_back(make_pair(4,3));
		expectedVek.push_back(make_pair(5,6));
		expectedVek.push_back(make_pair(6,5));
		ASSERT_EQ(board.getLegalMoves('X'), expectedVek);
	}
	TEST(boardTest, legalMoveVectorX){
		Board board;
		board.MakeMove(3,4,'X');
		vector< pair<int, int> > expectedVek;
		expectedVek.push_back(make_pair(5,6));
		expectedVek.push_back(make_pair(6,5));
		expectedVek.push_back(make_pair(6,6));
		ASSERT_EQ(board.getLegalMoves('X'), expectedVek);
	}
	TEST(boardTest, legalMoveVectorO){
		Board board;
		board.MakeMove(3,4,'X');
		vector< pair<int, int> > expectedVek;
		expectedVek.push_back(make_pair(3,3));
		expectedVek.push_back(make_pair(3,5));
		expectedVek.push_back(make_pair(5,3));
		ASSERT_EQ(board.getLegalMoves('O'), expectedVek);
	}

}
