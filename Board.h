/*
 * Board.h
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
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
	const int height;
	const int width;
	bool MakeMoveDir(int, int, int, int, char);
	bool CheckLegalDir(int, int, int, int, char);
	bool CheckLegal(int, int, char);
public:
	Board(int = DEFAULT_SIZE_, int = DEFAULT_SIZE_);
	Board(const Board&);
	bool MakeMove(int, int, char);
	void ShowPossibleMoves(char);
	bool PossibleMoveExists(char);
	vector<pair<int, int> > getLegalMoves(char);
	int CountSign(char);
	virtual ~Board();
	friend ostream& operator<<(ostream&, Board&);
};
#endif /* BOARD_H_ */
