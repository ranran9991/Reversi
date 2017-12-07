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

#include "Player.h"

Player::Player() { }

void Player::SetBoard(Board* b) {
	board = b;
}

void Player::SetSign(char c) {
	sign = c;
}

char Player::GetSign() {
	return sign;
}

bool Player::PossibleMoveExists() {
	return board->PossibleMoveExists(sign);
}

Player::~Player() { }
