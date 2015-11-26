#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>

using namespace std;
class Player {
	char d_secretAnimal;
public:
	char swapSecretAnimal(char&);
	char getSecretAnimal();
	void printState();
};
#endif // !PLAYER_H

