#include <iostream>
using namespace std;

class Student {
public:
	int cod;
	char nume[50];
	int* note;
	int nrNote;
	char* facultatea;

	//metode
	//speciale
	//constructor
	Student() {
		cout << endl << "Apel constructor default";
		cod = 0;
		nrNote = 0;
		note = NULL;
		//s.nume = "Anonim";
		strcpy(nume, "Anonim");
		//this->facultatea = "CSIE";
		this->facultatea = new char[strlen("CSIE") + 1];
		strcpy(this->facultatea, "CSIE");
	}

	Student(char *nume, int cod) {
		cout << endl << "Apel constructor cu argumente";
		//shadowing
		this->cod = cod;
		this->nrNote = 0;
		this->note = NULL;
		//s.nume = "Anonim"

		strcpy(this->nume, nume);
	}

};


//supraincarcare

int suma(int a, int b) {
	return a + b;
}

int suma(int a, int b, int c) {
	return a + b + c;
}

int suma(float a, int b) {
	return a + b;
}

void initializareStudent(Student& s) {
	s.cod = 0;
	s.nrNote = 0;
	s.note = NULL;
	//s.nume = "Anonim";
	strcpy(s.nume, "Anonim");
}

void afisareStudent(Student s) {
	cout << endl << "Studentul " << s.nume
		<< " are codul " << s.cod;
}

void faceNimic() {
	Student s;
}

void main() {
	Student student;
	//initializareStudent(student);
	afisareStudent(student);

	Student student2("Gigel",3);
	afisareStudent(student2);

	for (;;)
		faceNimic();
}