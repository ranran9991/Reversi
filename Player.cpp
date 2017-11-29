/*
 * Player.cpp
 *
 *  Created on: Nov 25, 2017
 *      Author: ron
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
