#include "player.h"

std::string Player::swapSecretAnimal(std::string & _secretAnimal) {
	string rtrn_secretAnimal = d_secretAnimal;
	d_secretAnimal = _secretAnimal;
	return rtrn_secretAnimal;
}

std::string Player::getSecretAnimal() {
	return d_secretAnimal;
}

void Player::printState() {
	/*On imprime quoi???*/
}


