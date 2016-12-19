#include <iostream>
using namespace std;

class Persoana {
protected:
	char nume[50];
	int varsta;
public:
	//Persoana() {
	//	cout << endl << "Apel constructor Persoana";
	//	strcpy(nume, "");
	//	varsta = 0;
	//}
	Persoana(char *Nume, int Varsta) {
		strcpy(nume, Nume);
		varsta = Varsta;
	}
	void afisare() {
		cout << endl << "Persoana "
			<< this->nume << " are varsta "
			<< this->varsta;
	}

	char* getNume() {
		return this->nume;
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsta(int valoare) {
		this->varsta = valoare;
	}

	~Persoana() {
		cout << endl << "Apel destructor persoana";
	}
};

class Student:public Persoana {
	char facultate[100];
	int note[100];
	int nrNote;
public:
	Student():Persoana("Anonim",21) {
		cout << endl << "Apel constructor Student";
		//strcpy(this->nume,"Anonim");
		strcpy(facultate, "CSIE");
		nrNote = 0;
	}

	Student(char* Nume,
		int Varsta,
		char* Facultatea):Persoana(Nume,Varsta) {
		strcpy(this->facultate, Facultatea);
		this->nrNote = 0;
	}

	~Student() {
		cout << endl << "Apel destructor student";
	}

	//supradefinire metoda mostenita din Persoana
	void afisare() {
		cout << endl << "Studentul(a) "
			<< this->nume << " are varsta "
			<< this->varsta << " si este la facultatea"
			<< this->facultate;
		cout << endl << "Notele:";
		for (int i = 0; i < this->nrNote; i++)
			cout << " " << this->note[i];
	}
};

void main() {
	//Persoana p1;
	Persoana p2("Gigel", 22);
	//p1.afisare();
	p2.afisare();

	Student s1;
	cout << endl << "Nume student:" << s1.getNume();
	s1.afisare();
	s1.setVarsta(23);
	s1.afisare();

	Student s2("Ana", 21, "MK");
	s2.afisare();

	//up-casting
	p2 = s2;
	p2.afisare();

}