#include <iostream>
using namespace std;

class Student {
private:
	int cod;
	char nume[50];
	int* note;
	int nrNote;
	char* facultatea;
public:
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
		this->facultatea = new char[strlen("CSIE") + 1];
		strcpy(this->facultatea, "CSIE");
	}

	~Student() {
		cout << endl << "Apel destructor!";
		if (this->facultatea != NULL)
			delete this->facultatea;
	}

	//functii accesor
	//acces in mod citire
	int getCod() {
		return this->cod;
	}
	char* getNume() {
		return this->nume;
	}

	char* getFacultate() {
		return this->facultatea;
	}

	//mod scriere
	void setFacultate(char* denumireNoua) {
		//NU ASA
		//this->facultatea = denumireNoua;

		if (strlen(denumireNoua) >= 2) {

			if (this->facultatea != NULL)
				delete [] this->facultatea;
			this->facultatea = new char[strlen(denumireNoua) + 1];
			strcpy(this->facultatea, denumireNoua);
		}
		else
		{
			//cout << endl << "Denumire gresita !";
			throw exception("Denumire gresita !");
		}
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

//void initializareStudent(Student& s) {
//	s.cod = 0;
//	s.nrNote = 0;
//	s.note = NULL;
//	//s.nume = "Anonim";
//	strcpy(s.nume, "Anonim");
//}

void afisareStudent(Student s) {
	cout << endl << "Studentul " << s.getNume()
		<< " are codul " << s.getCod()
		<< " si este la facultatea " << s.getFacultate();
}

void faceNimic() {
	Student s;
}

void main() {
	Student student;
	//initializareStudent(student);
	afisareStudent(student);
	student.setFacultate("MK");

	Student student2("Gigel",3);
	afisareStudent(student2);

	//for (;;)
	//	faceNimic();
}