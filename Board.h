/*
 * Board.h
 *
 *  Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 *
 *  Ran Elgiser
 *  ID: 322768805
 *  Exercise Grope: 05
 */

#ifndef BOARD_H_
#define BOARD_H_
#define DEFAULT_SIZE_ 8
#include <iostream>
#include <vector>
using namespace std;

class Board {
private:
	char** board;
	int height;
	int width;
	bool MakeMoveDir(int, int, int, int, char);
	bool CheckLegalDir(int, int, int, int, char);
	bool CheckLegal(int, int, char);
public:
	Board(int = DEFAULT_SIZE_, int = DEFAULT_SIZE_);
	Board(const Board&);
	Board& operator=(const Board&);
	bool MakeMove(int, int, char);
	void ShowPossibleMoves(char);
	bool PossibleMoveExists(char);
	vector<pair<int, int> > GetLegalMoves(char);
	char OtherSign(char);
	int CountSign(char);
	int Score(char);
	virtual ~Board();
	friend ostream& operator<<(ostream&, Board&);
};
#endif /* BOARD_H_ */
