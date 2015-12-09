/*
player.h
Sebastien Roy
Nicolas Tremblay - 5992713
*/

#include<iostream>
#include"hand.h"

#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
class Player {
	char d_secretAnimal;
	string d_name;
public:
	Player(char);
	Hand hand;
	char swapSecretAnimal(char&);
	char getSecretAnimal();
	void printState();
	string getName();
	void setName(string);
};
#endif // !PLAYER_H

