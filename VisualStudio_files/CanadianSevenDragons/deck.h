
#ifndef DECK_H
#define DECK_H
#include "animalcard.h"

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Deck : public std::vector<T>{
	std::vector<T> ac;

public:
	std::shared_ptr<T> draw();
};
#endif //!DECK_H

template <class T>
std::shared_ptr<T> Deck::draw(){
	return ac.pop_back();
}