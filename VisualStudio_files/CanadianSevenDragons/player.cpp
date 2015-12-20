
/*
player.cpp
Sebastien Roy - 7759749
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
	cout << "Joueur: " << d_name << endl;
	cout << "Carte Secrete: " << d_secretAnimal << endl << endl;
}

string Player::getName() {
	return d_name;
}

void Player::setName(string _name) {
	d_name = _name;
}
