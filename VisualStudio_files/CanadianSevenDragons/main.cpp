#include"animalcard.h"
#include"nosplit.h"
#include"table.h"


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


int main() {
	TEST_classeTable();
	return 0;
}
