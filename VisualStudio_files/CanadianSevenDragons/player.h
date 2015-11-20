#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<string>

using namespace std;
class Player {
	string d_secretAnimal;
public:
	std::string swapSecretAnimal(std::string&);
	std::string getSecretAnimal();
	void printState();
};
#endif // !PLAYER_H

