/*
exception.h
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

using namespace std;

class IllegalPlacement{
	string msg;
public:
	IllegalPlacement(string m) : msg(m) { }
	void setMessage(string m) { msg = m; }
	string getMessage() { return msg; }
	void report() {
		std::cout << "Placement Illegale : " << msg << std::endl;
	}
};

class MissingCard {
	string msg;
public:
	MissingCard(string m) : msg(m) { }
	void setMessage(string m) { msg = m; }
	string getMessage() { return msg; }
	void report() {
		std::cout << "Manque une carte : " << msg << std::endl;
	}
};
#endif // !EXCEPTION_H