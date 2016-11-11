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
			delete [] this->facultatea;
	}

	//copy constructor
	Student(Student& s) {
		cout << endl << "Apel constructor de copiere";
		this->cod = s.cod;
		strcpy(nume, s.nume);
		facultatea = new char[strlen(s.facultatea) + 1];
		strcpy(this->facultatea, s.facultatea);
		this->nrNote = s.nrNote;
		this->note = new int[s.nrNote];
		for (int i = 0; i < s.nrNote; i++)
			this->note[i] = s.note[i];

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


	Student operator=(Student s2) {

		cout << endl << "Apel operator =";

		delete [] this->note;
		delete [] this->facultatea;

		cout << endl << "Apel constructor de copiere";
		this->cod = s2.cod;
		strcpy(nume, s2.nume);
		facultatea = new char[strlen(s2.facultatea) + 1];
		strcpy(this->facultatea, s2.facultatea);
		this->nrNote = s2.nrNote;
		this->note = new int[s2.nrNote];
		for (int i = 0; i < s2.nrNote; i++)
			this->note[i] = s2.note[i];

		return *this;
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

void afisareStudent(Student& s) {
	cout << endl << "Studentul " << s.getNume()
		<< " are codul " << s.getCod()
		<< " si este la facultatea " << s.getFacultate();
}

void faceNimic() {
	Student s;
}

//stud1 = stud2
//stud1 = stud2 = stud3;

void main() {
	Student student;
	////initializareStudent(student);
	//afisareStudent(student);
	//student.setFacultate("MK");

	Student student2("Gigel",3);
	afisareStudent(student2);

	//apel explicit
	Student student3 = student2;

	Student student4;

	student4.operator=(student3);
	student4 = student3;	//operatorul =

	int vb1 = 10;
	int vb2;
	vb2 = vb1 + 20;

	//vb2 = operator+(vb1, 20);
	//operator=(vb2, operator+(vb1, vb2));



	//for (;;)
	//	faceNimic();
}