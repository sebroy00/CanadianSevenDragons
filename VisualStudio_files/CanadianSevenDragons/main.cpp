/*
main.cpp
Sebastien Roy - 7759749
Nicolas Tremblay - 5992713
*/


#include <fstream>
#include <vector>
#include <algorithm>    // std::random_shuffle
#include"animalcard.h"
#include"nosplit.h"
#include"splittwo.h"
#include"splitfour.h"
#include"table.h"
#include"hand.h"
#include"player.h"
#include"exeptions.h"
#include"actioncard.h"  
#include"AnimalCardFactory.h"
#include"deck.h"

using namespace std;

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

void saveToFile(Deck<AnimalCard> deck, Table table, vector<Player> players) {
	ofstream saveFile; // création du fichier
	saveFile.open("saveGAME.txt"); // ouvrir
	int deckSize = deck.size();
	saveFile << "Deck: \n";
	for (int d = 0; d < deckSize; d++) {
		shared_ptr<AnimalCard> tmp = deck.draw();
		saveFile << tmp->getAnimalAt(0) << tmp->getAnimalAt(1) << tmp->getAnimalAt(2) << tmp->getAnimalAt(3) << " ";
	}
	saveFile << "\n \n";


	int numPlayers = players.size();
	saveFile << "Players: \n \n";
	for (int a = 0; a < numPlayers; a++) {
		saveFile << "Player " << a << "\n";
		saveFile << "--------------\n";
		saveFile << "Name: " << players.at(a).getName() << "\n";
		saveFile << "Secret Animal: " << players.at(a).getSecretAnimal() << "\n";
		for (int d = 0; d < players.at(a).hand.noCards(); d++) {
			shared_ptr<AnimalCard> tmp = players.at(a).hand[d];
			if (tmp != 0)
				saveFile << "Cards: " << tmp->getAnimalAt(0) << tmp->getAnimalAt(1) << tmp->getAnimalAt(2) << tmp->getAnimalAt(3) << " ";
		}
		saveFile << "\n\n";
	}
	saveFile << "\n \n";

	int tableSize = 103;
	saveFile << "Table: \n";
	for (int a = 0; a < tableSize; a++)
		for (int d = 0; d < tableSize; d++) {
			shared_ptr<AnimalCard> tmp = table.get(a, d);
			if (tmp != 0)
				saveFile << tmp->getAnimalAt(0) << tmp->getAnimalAt(1) << tmp->getAnimalAt(2) << tmp->getAnimalAt(3) << " ";
			else
				saveFile << "0000" << " ";
		}
	saveFile << "\n \n";
	saveFile.close(); // fermer
}

int main() {
	vector<char> secretAnimals = { 'b','d','h','m','w' };

	/*shuffle device*/
	std::random_device rd;
	std::mt19937 mt(rd());

	int in_numPlayers;
	cout << "-------Preparation-------" << endl;
	cout << "Nombre de joueurs: ";
	cin >> in_numPlayers;
	cout << endl;
	/*on doit avoir un nombre entre 2 et 5*/
	in_numPlayers = in_numPlayers > 5 ? 5 : in_numPlayers;
	in_numPlayers = in_numPlayers < 2 ? 2 : in_numPlayers;

	/*shuffle the secret animals*/
	shuffle(secretAnimals.begin(), secretAnimals.end(), mt);

	/*create all players, in a vector*/
	vector<Player> players(in_numPlayers, Player('0'));

	/*create Deck of cards*/
	AnimalCardFactory acf = AnimalCardFactory();
	Deck<AnimalCard> deck = acf.getDeck();

	char a;

	string name;
	int playersCreated = 0;
	while (playersCreated < in_numPlayers) {
		players[playersCreated] = Player(secretAnimals[playersCreated]);
		cout << "Nom du joueur " << playersCreated << ": ";
		cin >> name;
		players[playersCreated].setName(name);
		players[playersCreated].hand += deck.draw();
		players[playersCreated].hand += deck.draw();
		players[playersCreated].hand += deck.draw();
		playersCreated++;
	}

	system("cls");

	bool winner(false);
	bool cardPlaced(false);
	Table table = Table();
	string orientation;
	string pause;

	while (!winner) {
		cout << "Pause game? (Y/N) ";
		cin >> pause;
		cout << endl;
		if (pause == "Y") {
			saveToFile(deck, table, players);
			return 0;
		}
		for (vector<Player>::iterator p = players.begin(); p != players.end(); p++) {

			/*imprime l'etat du joueur*/
			(*p).printState();

			/*imprime la table*/
			cout << "Table: " << endl;
			cout << "------------------------" << endl;

			table.printTable();
			cout << endl;

			cout << "------------------------" << endl;

			/*imprime la hand du joueur*/
			cout << "Cartes: " << endl;
			printHand((*p).hand);
			cout << endl;

			int in_cardPosition, in_xCoord, in_yCoord, pickCards, in_changeOrientation;
			do {
				try {
					/*choisir la carte a utiliser*/
					cout << endl;
					cout << "Choix de carte (99 pour passer son tour): ";
					cin >> in_cardPosition;

					if (in_cardPosition == 99)
						break;
					else if (in_cardPosition < (*p).hand.noCards() && in_cardPosition > -1) { //verif s'il y a vraiment une carte a cette position

						shared_ptr<AnimalCard> cardChoice = (*p).hand[in_cardPosition];
						AnimalCard* cardTest = cardChoice.get();

						/*essayer de faire un cast*/
						if (dynamic_cast<ActionCard*>(cardTest)) { /*essayer de faire le cast a un action card*/
							QueryResult qr;

							//voir quelle carte d'action a ete joue
							if (dynamic_cast<BearAction*>(cardTest)) {
								(*p).hand -= cardChoice;
								BearAction* ba = dynamic_cast<BearAction*>(cardTest);
								qr = ba->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								ba->perform(table, &players[0], qr);
							}
							else if (dynamic_cast<WolfAction*>(cardTest)) {

								WolfAction* wa = dynamic_cast<WolfAction*>(cardTest);
								qr = wa->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								while (!table.get(qr.getX, qr.getY)) {
									qr = wa->query();
								}
								wa->perform(table, &players[0], qr);
								printHand(p->hand);
								(*p).hand -= cardChoice;
							}
							else if (dynamic_cast<HareAction*>(cardTest)) {

								HareAction* ha = dynamic_cast<HareAction*>(cardTest);
								qr = ha->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								while (!table.get(qr.getX, qr.getY)) {
									qr = ha->query();
								}
								ha->perform(table, &p[0], qr);
								(*p).hand -= cardChoice;
							}
							else if (dynamic_cast<DeerAction*>(cardTest)) {

								DeerAction* da = dynamic_cast<DeerAction*>(cardTest);
								qr = da->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								da->perform(table, &players[0], qr);
								(*p).hand -= cardChoice;

							}
							else if (dynamic_cast<MooseAction*>(cardTest)) {
								MooseAction* ma = dynamic_cast<MooseAction*>(cardTest);
								qr = ma->query();
								qr.nombreDeJoueurs = in_numPlayers;
								qr.nomDuJoueur = p->getName();
								ma->perform(table, &players[0], qr);
								(*p).hand -= cardChoice;
							}
							system("pause");
							cardPlaced = true;
						}
						else {
							/*changer orientation*/
							cout << "Changer orientation de la carte? (oui : 1 -- non : 0) ";
							cin >> in_changeOrientation;
							if (in_changeOrientation == 1) {
								cout << "Quelle orientation? (D = DOWN ; U = UP)";
								cin >> orientation;
								cardChoice->setOrientation(orientation == "D" ? DOWN : UP);
							}

							/*imprime la carte (avec son changement d'orientation s'il y a lieu*/
							cout << endl << "Carte choisie: ";
							cout << endl;
							cardChoice->printRow();
							cout << endl;
							cardChoice->printRow();
							cout << endl << endl;

							/*placement de carte*/
							cout << "A quel endroit voulez vous placer la carte?" << endl;
							cout << "Coordonnee verticale:    ";
							cin >> in_xCoord;
							cout << "Coordonnee horizontale:  ";
							cin >> in_yCoord;

							/*ajouter carte sur la table*/
							pickCards = table.addAt(cardChoice, in_xCoord, in_yCoord);
							/*on enleve la carte de la hand du joueur*/
							(*p).hand -= cardChoice;

							/*pige les cartes du deck pour le mettre dans la hand du joueur d'apres la valeur retournee par addAt*/
							while (pickCards > 0) {
								(*p).hand += deck.draw();
								pickCards--;
							}

							/*le tour du joueur est fini*/
							system("pause");
							cardPlaced = true;
						}
					}
					else {
						cout << "Aucune carte a cette position" << endl;
					}
				}
				catch (IllegalPlacement i) {
					i.report();
				}
			} while (!cardPlaced);

			/*Verification s'il y a un gagnant*/
			for (vector<Player>::iterator w = players.begin(); w != players.end() && !winner; w++) {
				a = (*w).getSecretAnimal();
				winner = table.win(a);
			}

			system("cls"); /*clear screen*/
			cardPlaced = false; /*reset les valeurs pour le prochain joueur*/
		}
	}

	cout << "Le gagnant est le joueur avec la carte: " << a << endl;
	cout << "Merci d'avoir joue!";
	return 0;
}

