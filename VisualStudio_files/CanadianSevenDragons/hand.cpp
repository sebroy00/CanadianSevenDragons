/*
hand.cpp
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/

#include "hand.h"
#include "exception.h"

Hand & Hand::operator+=(std::shared_ptr<AnimalCard> card) {
	d_animalcards.push_back(card);
	return (*this);
}

Hand & Hand::operator-=(std::shared_ptr<AnimalCard> card) {
	int lengthBefore = d_animalcards.size();
	d_animalcards.remove(card);
	if (d_animalcards.size() >= lengthBefore)
		throw MissingCard("impossible d'enlever cette carte (operateur hand)");
	return (*this);
}

std::shared_ptr<AnimalCard>& Hand::operator[](int position) {
	auto vi = d_animalcards.begin();
	std::advance(vi, position);
	return *vi;
}

int Hand::noCards() {
	return d_animalcards.size();
}