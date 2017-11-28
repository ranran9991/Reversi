/*
 * Board.cpp
 *
 *  Name: Ron Edi
 *  ID: 322956897
 *  Exercise Group: 05
 */

#include "Board.h"

Board::Board(int height, int width) : height(height), width(width) {
	// allocating memory for the board and assigning blanks
	board = new char*[height];
	for(int i = 0; i < height; i++){
		board[i] = new char[width];
		for(int j = 0; j < width; j++)
			board[i][j] = ' ';
	}
	// assigning the starting places
	board[height/2 - 1][width/2 - 1] =  'O';
	board[height/2][width/2] =  'O';
	board[height/2 - 1][width/2] =  'X';
	board[height/2][width/2 - 1] =  'X';
}

Board::~Board() {
	// deleting the board
	for(int i = 0; i < height; i++)
		delete[] board[i];
	delete[] board;
}

bool Board::CheckLegal(int x, int y, char sign) {
	--x; --y; // setting relevant values
	if (x >= height || x < 0 || y >= width || y < 0) return false;
	if (board[x][y] != ' ') return false;
	// checking for each direction
	for (int i = -1, j; i <= 1; i++)
		for (j = -1; j <= 1; j++)
			if (i != 0 || j != 0)
				// if there is a valid direction, return true
				if (CheckLegalDir(x+i, y+j, i, j, sign)) return true;
	// else, return false
	return false;
}

bool Board::MakeMove(int x, int y, char sign) {
	if (!CheckLegal(x, y, sign)) return false; // illegal move
	--x; --y; // setting relevant values
	// for each direction
	for (int i = -1, j; i <= 1; i++)
			for (j = -1; j <= 1; j++)
				if (i != 0 || j != 0)
					// making the move in this direction
					MakeMoveDir(x+i, y+j, i, j, sign);
	board[x][y] = sign; // assigning the char to the given place
	return true;
}

bool Board::PossibleMoveExists(char sign) {
	// for all places
	for (int i = 1, j; i <= height; i++)
		for (j = 1; j <= width; j++)
			// if move is legal in some place, return true
			if (CheckLegal(i, j, sign)) return true;
	// else, return false
	return false;
}

void Board::ShowPossibleMoves(char sign) {
	bool first = true;
	// for all places
	for (int i = 1, j; i <= height; i++){
		for (j = 1; j <= width; j++){
			// if place is legal
			if (CheckLegal(i, j, sign)) {
				if (first) first = false;
				else cout << ",";
				// print the place
				cout << "(" << i << "," << j << ")";
			}
		}
	}
}

bool Board::CheckLegalDir(int x, int y, int i, int j, char sign) {
	if (x >= height || x < 0 || y >= width || y < 0) return false;
	char place = board[x][y];
	if (place == ' ') return false; // if reached a space, return false
	if (place == sign) {
		/* if another place with the right char was found in the direction
		 * but it is next to the place we started searching from, return false
		 */
		if (board[x-i][y-j] == ' ') return false;
		return true; // else, the right char was found in the given direction
	}
	// if reached the other char, continue searching in the same direction
	return CheckLegalDir(x+i, y+j, i, j, sign);
}

bool Board::MakeMoveDir(int x, int y, int i, int j, char sign) {
	if (x >= height || x < 0 || y >= width || y < 0) return false;
	char place = board[x][y];
	if (place == ' ') return false; // if reached a space, return false
	if (place == sign) return true; // if reached the right char, end and return true
	// if this direction is legal
	if (MakeMoveDir(x+i, y+j, i, j, sign)) {
		// assign the char to the place
		board[x][y] = sign;
		return true;
	}
	return false; // else, this direction is illegal and return false
}

int Board::CountSign(char sign) {
	int count = 0;
	// for all places
	for (int i = 0, j; i < height; i++)
		for (j = 0; j < width; j++)
			// if given char was found, increase the counter
			if (board[i][j] == sign) ++count;
	return count;
}

vector<pair<int, int> > Board::getLegalMoves(char sign) {
	vector<pair<int, int> > legalMoves;
	int i,j;
	for(i = 0; i< height; i++){
		for(j = 0; j< width; j++){
			if (CheckLegal(i, j, sign)) {
				legalMoves.push_back(make_pair(i,j));
			}
		}
	}
	return legalMoves;
}

ostream& operator<<(ostream& os, Board& b){
	// printing the column numbers
	for(int i = 1; i < b.width+1; i++)
		os << " | " << i;
	os << " |" << endl;
	// printing each line
	for(int i = 0; i < b.height; i++){
		for(int j = 0; j < 4*b.width+2; j++)
			os << "-";
		os << endl << i+1 << "|";
		for(int j = 0; j < b.width; j++)
			os << " " << b.board[i][j] << " |";
		os << endl;
	}
	// printing the last line of ---
	for(int j = 0; j < 4*b.width+2; j++)
		os << "-";
	return os;
}
