#ifndef DECK_H
#define DECK_H

#include "animalcard.h"

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template<class T>
class Deck : public vector<T>{
public:
	//try to get the element on top
	shared_ptr<T> draw();
};
#endif //!DECK_H

template <typename T>
shared_ptr<T> Draw::draw(){
	//faire un shared pointer vide
	shared_ptr<T> pointer;
	pointer = this->back();
	return pointer;
};