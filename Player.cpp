#include "Player.h"

Player::Player(char sign) : sign(sign) { }

bool Player::MakeMove(int x, int y) {
	return board->MakeMove(x, y, sign);
}

void Player::ShowPossibleMoves() {
	return board->ShowPossibleMoves(sign);
}

bool Player::PossibleMoveExists() {
	return board->PossibleMoveExists(sign);
}

void Player::SetBoard(Board* b) {
	board = b;
}

char Player::GetSign() {
	return sign;
}

Player::~Player() { }
