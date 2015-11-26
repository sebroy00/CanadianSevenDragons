#include "player.h"

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


