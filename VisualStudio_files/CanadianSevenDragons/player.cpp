
/*
player.cpp
Sebastien Roy
Nicolas Tremblay - 5992713
*/

#include "player.h"

Player::Player(char _secretAnimal) {
	d_secretAnimal = _secretAnimal;
	hand = Hand();
}

char Player::swapSecretAnimal(char & _secretAnimal) {
	char rtrn_secretAnimal = d_secretAnimal;
	d_secretAnimal = _secretAnimal;
	return rtrn_secretAnimal;
}

char Player::getSecretAnimal() {
	return d_secretAnimal;
}

void Player::printState() {
	/*On imprime quoi???*/
}

string Player::getName() {
	return d_name;
}

void Player::setName(string _name) {
	d_name = _name;
}


