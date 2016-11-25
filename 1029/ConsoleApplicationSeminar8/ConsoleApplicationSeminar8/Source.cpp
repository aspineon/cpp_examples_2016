#include <iostream>
#include <fstream>
using namespace std;

class Persoana {
	char* nume;
	int cod;
public:
	Persoana(char* Nume, int  Cod) {
		this->nume = new char[strlen(Nume) + 1];
		strcpy(this->nume, Nume);
		cod = Cod;
	}
	Persoana(const Persoana& p) {
		nume = new char[strlen(p.nume) + 1];
		strcpy(nume, p.nume);
		cod = p.cod;
	}
	~Persoana() {
		delete [] nume;
	}
	void operator=(Persoana& p) {
		delete [] nume;
		nume = new char[strlen(p.nume) + 1];
		strcpy(nume, p.nume);
		cod = p.cod;
	}

	char* getNume() const {
		return this->nume;
	}

	int getCod() {
		return this->cod;
	}

	bool operator>(const Persoana& p2) {
		if (strcmp(this->nume, p2.nume) > 0)
			return true;
		else
			return false;
	}

	friend istream& operator >>(istream& input, Persoana& p);
};

istream& operator >>(istream& input, Persoana& p) {
	cout << endl << "Nume:";
	char buffer[1000];
	input >> buffer;
	delete [] p.nume;
	p.nume = new char[strlen(buffer) + 1];
	strcpy(p.nume, buffer);
	cout << endl << "Cod:";
	input >> p.cod;
	return input;
}

bool operator<(const Persoana& p1,
	const Persoana& p2) {
	if (strcmp(p1.getNume(), p2.getNume()) < 0)
		return true;
	else
		return false;
}


void main() {

	Persoana p1("Gigel", 1);
	//Persoana p2;

	//Persoana lista[3];
	Persoana *ps;	//pointer la o Persoana
	Persoana* *lista;	//pointer la un vector de pointeri de Persoane
	Persoana *lista2;	//pointer la un vector de Persoane

	//lista2 = new Persoana[3];
	lista = new Persoana*[3];
	for (int i = 0; i < 3; i++) {
		lista[i] = new Persoana("Anonim",0);
	}
	for (int i = 0; i < 3; i++) {
		cin >> *lista[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cout << endl << "Persoana:" << lista[i]->getNume();
	}

	ofstream raport;
	raport.open("raport.txt", ios::out | ios::app);
	if (raport.is_open()) {
		for (int i = 0; i < 3; i++)
		{
			raport << endl << "Persoana " <<
				lista[i]->getNume() << " are codul "
				<< lista[i]->getCod();
		}
	}
	else
		cout << endl << "Eroare deschidere fisier";

}