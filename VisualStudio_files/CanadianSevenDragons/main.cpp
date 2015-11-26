#include <fstream>
#include"animalcard.h"
#include"nosplit.h"
#include"splittwo.h"
#include"splitfour.h"
#include"table.h"
#include"hand.h"
#include"player.h"


void TEST_classeTable() {
	Table table = Table();
	shared_ptr<NoSplit> sptr(new NoSplit('a'));
	shared_ptr<SplitTwo> sptrTWO(new SplitTwo('c', 'o'));
	shared_ptr<SplitTwo> sptrTHREE(new SplitTwo('o', 'c'));

	shared_ptr<SplitFour> sptr4a(new SplitFour('b', 'a', 'd', 'c'));
	shared_ptr<SplitFour> sptr4b(new SplitFour('a', 'b', 'c', 'd'));
	shared_ptr<SplitFour> sptr4c(new SplitFour('b', 'c', 'd', 'a'));
	shared_ptr<SplitFour> sptr4d(new SplitFour('c', 'd', 'a', 'b'));

	table.addAt(sptr, 5, 50);
	cout << table.addAt(sptr4a, 52, 53) << endl;
	cout << table.addAt(sptr, 52, 54) << endl;
	cout << table.addAt(sptr4d, 52, 55) << endl;
	table.printTable();
	cout << endl;
	cout << "before pick at" << endl;
	table.pickAt(52, 54);
	cout << "after pick at" << endl;
	table.printTable();
	cout << endl;
	cout << "add at count: " << table.addAt(sptr, 52, 54) << endl;
	cout << "after add at" << endl;
	table.printTable();
	cout << endl;

	cout << "add at count: " << table.addAt(sptr, 53, 54) << endl;
	cout << "after add at" << endl;
	table.printTable();
	cout << endl;


	char animal('a');
	if (table.win(animal))
		cout << "win";
}

void printHand(Hand h) {
	for (int c = 0; c < 3; c++) {
		for (int i = 0; i < h.noCards(); i++) {
			if (c == 0) {
				cout << i;
				string space = to_string(i).length() == 1 ? "  " : " ";
				cout << space;
			}
			if (c == 1) h[i]->printRow();
			if (c == 2) h[i]->printRow();
		}
		cout << endl;
	}
}

void TEST_classeHand() {
	Hand h = Hand();
	shared_ptr<NoSplit> sptr(new NoSplit('Q'));
	shared_ptr<NoSplit> sptr2(new NoSplit('P'));
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	h += sptr;
	h += sptr2;
	printHand(h);
}
int main() {
	int numPlayers;
	cout << "Number of players";
	cin >> numPlayers;
	if (numPlayers < 2 || numPlayers > 5)
		numPlayers = 2;
	
	//array of players ? PROBLEM : different secretCards
	
	
	return 0;
}

