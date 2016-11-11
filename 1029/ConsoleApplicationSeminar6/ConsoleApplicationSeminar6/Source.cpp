#include <iostream>
using namespace std;

class CardFidelitate {
	char nume[50];
	int* puncte;
	int nrCumparaturi;
public:
	CardFidelitate() {
		strcpy(nume, "Anonim");
		puncte = NULL;
		nrCumparaturi = 0;
	}
	CardFidelitate(char* Nume) {
		strcpy(nume, Nume);
		puncte = NULL;
		nrCumparaturi = 0;
	}
	~CardFidelitate() {
		delete [] puncte;
	}

	CardFidelitate(CardFidelitate& card) {
		cout << endl << "Apel constructor copiere";
		strcpy(nume, card.nume);
		this->setPuncte(card.puncte, 
			card.nrCumparaturi);

	}

	char* getNume() {
		return this->nume;
	}

	int getTotalPuncte() {
		int suma = 0;
		for (int i = 0; i < this->nrCumparaturi; i++) {
			suma += puncte[i];
		}
		return suma;
	}

	void setPuncte(int* puncteExistente, int n) {
		this->puncte = new int[n];
		for (int i = 0; i < n; i++)
			puncte[i] = puncteExistente[i];
		this->nrCumparaturi = n;
	}

	void adaugaPuncte(int valoare) {
		int* temp = new int[this->nrCumparaturi + 1];
		for (int i = 0; i < nrCumparaturi; i++)
			temp[i] = this->puncte[i];
		temp[nrCumparaturi] = valoare;
		delete [] puncte;
		puncte = temp;
		nrCumparaturi += 1;
	}

};

void afisareDateCard(CardFidelitate& c) {
	cout << endl << "Cardul lui " << c.getNume()
		<< " are " << c.getTotalPuncte() << " puncte ";
}

void main() {
	CardFidelitate card1;
	CardFidelitate card2("Gigel");

	afisareDateCard(card1);
	afisareDateCard(card2);

	int valori [] = { 10,20,30 };
	char* nume [] = { "Gigel","Ana" };

	card1.setPuncte(valori, 3);
	afisareDateCard(card1);

	card2.adaugaPuncte(5);
	card2.adaugaPuncte(10);
	afisareDateCard(card2);

}