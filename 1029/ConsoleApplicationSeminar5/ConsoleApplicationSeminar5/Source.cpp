#include <iostream>
using namespace std;

class Persoana {
private:
	int cod;
	char* nume;
public:
	Persoana(){
		this->cod = 0;
		//NU ASA
		//this->nume = "Anonim";
		this->nume = 
			new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
	}
	Persoana(int cod,char* nume) {
		this->cod = cod;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	~Persoana() {
		cout << endl << "Apel destructor";
		delete [] this->nume;
	}

	Persoana(Persoana& existent) {
		cout << endl<<"Apel constructor copiere";
		this->cod = existent.cod;
		this->nume = new char[strlen(existent.nume) + 1];
		strcpy(nume, existent.nume);
	}

	//functii accesor
	//mod citire
	int getCod() {
		return this->cod;
	}
	char* getNume() {
		return this->nume;
	}
	//mod scriere
	void setNume(char* numeNou) {
		if (this->nume != NULL)
			delete [] this->nume;
		this->nume = 
			new char[strlen(numeNou) + 1];
		strcpy(this->nume, numeNou);
	}
};

void ceva() {
	Persoana p(1, "Test");
}

void afisarePersoana(Persoana p) {
	cout << endl << "Numele persoanei este "
		<< p.getNume();
	cout << endl << "Codul persoanei este "
		<< p.getCod();
}

void main() {

	ceva();

	Persoana p1;
	Persoana p2(1, "Gigel");
	cout << endl << "Numele persoanei p1 este "
		<< p1.getNume();
	p2.setNume("Ionel");
	cout << endl << "Numele persoanei p2 este "
		<< p2.getNume();
	afisarePersoana(p2);

	
}