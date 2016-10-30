#include <iostream>
using namespace std;

class Student {
private:
	int cod;
	char nume[50];
	int varsta;
	int* note;
	int nrNote;
	char* facultate;
	int codFacultative[10];
	int nrFacultative;
public:
	//metode constructor
	//default
	Student() {
		cout << endl << "Constructor default";
		this->cod = 0;
		this->nrNote = 0;
		this->note = NULL;
		this->varsta = 0;
		//this->nume = "Gigel";
		strcpy(this->nume, "Anonim");
		//alocare spatiu
		this->facultate = 
			new char [strlen("CSIE")+1];
		strcpy(this->facultate, "CSIE");
		this->nrFacultative = 0;
	}

	//constructor cu argumente
	Student(char* nume, int cod, 
		char* facultate,
		int* optionale,
		int nrOptionale) {

		this->cod = cod;
		this->facultate = 
			new char[strlen(facultate) + 1];
		strcpy(this->facultate, facultate);
		strcpy(this->nume, nume);

		for (int i = 0; i < nrOptionale; i++)
			this->codFacultative[i] = optionale[i];

		this->nrFacultative = nrOptionale;

		this->varsta = 0;
		this->nrNote = 0;
		this->note = NULL;
	}

	void afisareStudent() {
		cout << endl << "Studentul " << this->nume
			<< " are codul " << this->cod
			<< " si este in facultatea " 
			<< this->facultate;
	}

	int getCod() {
		return this->cod;
	}
};

void main() {
	Student s;
	Student s2;
	//cout << s.cod;
	s.afisareStudent();
	s2.afisareStudent();
	cout << endl << "Codul este " << s2.getCod();

	int optionale [] = { 23,68,21 };
	Student s3("Gigel", 1, "MAN", optionale, 3);
	s3.afisareStudent();
}