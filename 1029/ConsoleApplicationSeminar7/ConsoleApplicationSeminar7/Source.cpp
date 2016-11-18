#include <iostream>
using namespace std;

class CardFidelitate {
	const int cod;
	char nume[50];
	int* puncte;
	int nrCumparaturi;
public:
	CardFidelitate():cod(0) {
		strcpy(nume, "Anonim");
		puncte = NULL;
		nrCumparaturi = 0;
	}
	CardFidelitate(char* Nume, int Cod):cod(Cod) {
		strcpy(nume, Nume);
		puncte = NULL;
		nrCumparaturi = 0;
	}
	~CardFidelitate() {
		delete [] puncte;
	}

	CardFidelitate(CardFidelitate& card):cod(card.cod) {
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
		delete [] puncte;
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

	void operator=(const CardFidelitate& c) {
		strcpy(nume, c.nume);
		this->setPuncte(c.puncte,c.nrCumparaturi);
	}

	int operator[](int index) {
		if (index >= 0 && index < this->nrCumparaturi)
			return this->puncte[index];
		else
			throw exception("Index gresit !");
	}

	operator int() {
		return this->getTotalPuncte();
	}

	bool operator!() {
		if (this->nrCumparaturi == 0)
			return true;
		else
			return false;
	}

	friend istream& operator>>(istream& input, CardFidelitate& c);

};//sfarsit clasa

void afisareDateCard(CardFidelitate& c) {
	cout << endl << "Cardul lui " << c.getNume()
		<< " are " << c.getTotalPuncte() << " puncte ";
}

istream& operator>>(istream& input, CardFidelitate& c) {
	cout << "Nume client:";

	//char temp[1000];
	//input >> temp;
	//delete [] c.nume;
	//c.nume = new char[strlen(temp) + 1];
	//strcpy(c.nume, temp);

	input >> c.nume;	
	cout << endl << "Numar cumparaturi";
	input >> c.nrCumparaturi;
	delete [] c.puncte;
	c.puncte = new int[c.nrCumparaturi];
	for (int i = 0; i < c.nrCumparaturi; i++) {
		cout << endl << "Puncte pentru ziua " << i + 1 << ":";
		input >> c.puncte[i];
	}
	return input;
}

ostream& operator<<(ostream& iesire, CardFidelitate& c) {
	iesire <<endl << "Numele clientului " << c.getNume();
	iesire << endl << "Puncte" << c.getTotalPuncte();
	return iesire;
}

void main() {
	CardFidelitate card1;
	CardFidelitate card2("Gigel",1);

	afisareDateCard(card1);
	afisareDateCard(card2);

	int valori [] = { 10,20,30 };
	char* nume [] = { "Gigel","Ana" };

	card1.setPuncte(valori, 3);
	afisareDateCard(card1);

	card2.adaugaPuncte(5);
	card2.adaugaPuncte(10);
	afisareDateCard(card2);

	card1 = card2;
	afisareDateCard(card1);

	cin >> card2;
	cout << card2;

	cout << "Punctele din ziua a 2-a" << card2[1];

	int totalPuncte = (int)card2;

	if (!card2)
		cout << endl << "Nu are puncte";
	else
		cout << endl << "ARE puncte";

}