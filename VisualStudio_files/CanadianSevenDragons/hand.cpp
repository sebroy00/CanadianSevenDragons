#include "hand.h"

Hand & Hand::operator+=(std::shared_ptr<AnimalCard> card) {
	d_animalcards.push_back(card);
	return (*this);
}

Hand & Hand::operator-=(std::shared_ptr<AnimalCard> card) {
	int lengthBefore = d_animalcards.size();
	d_animalcards.remove(card);
	if (d_animalcards.size() < lengthBefore)
		throw new exception(); //a modifier
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