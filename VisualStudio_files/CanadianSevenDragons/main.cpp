#include"animalcard.h"
#include"nosplit.h"
#include"table.h"
#include"hand.h"


void TEST_classeTable() {
	Table table = Table();
	shared_ptr<NoSplit> sptr(new NoSplit("c"));
	table.addAt(sptr, 5, 50);
	table.addAt(sptr, 45, 51);
	table.addAt(sptr, 53, 54);
	cout << table.addAt(sptr, 52, 53) << endl;
	table.printTable();
	string animal("o");
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
	shared_ptr<NoSplit> sptr(new NoSplit("Q"));
	shared_ptr<NoSplit> sptr2(new NoSplit("P"));
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
	//TEST_classeTable();
	TEST_classeHand();
	char a;
	cin >> a;
	return 0;
}

