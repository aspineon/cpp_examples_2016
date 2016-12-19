#include <iostream>
#include <fstream>

using namespace std;


class Student {
public:
	//atribute
	int cod;
	char nume[50];
	int * note;
	int nrNote;
	char* facultate;

public:
	//metode
	//constructor
	Student() {
		//cout << endl << "Constructor implicit";
		cod = 0;
		nrNote = 0;
		this->note = NULL;
		strcpy(this->nume, "Anonim");
		// DON'T this->faculty = "CSIE";
		this->facultate = new char[strlen("CSIE") + 1];
		strcpy(this->facultate, "CSIE");
	}

	//constructor cu parametri
	Student(char* name, int code, char*faculty) {
		//cout << endl << "Constructor cu argumente";
		//shadowing 
		//code = code
		this->cod = code;
		this->nrNote = 0;
		this->note = NULL;
		strcpy(this->nume, name);
		this->facultate =
			new char[strlen(faculty) + 1];
		strcpy(this->facultate, faculty);

	}

	~Student() {
		//cout << endl << "Destructor !!!!!";
		if (this->facultate != NULL)
			delete [] this->facultate;
		if (this->note != NULL)
			delete [] note;
	}

	//copy constructor
	Student(const Student& s) {

		//cout << endl << "Copy constructor";
		this->cod = s.cod;
		strcpy(this->nume, s.nume);
		this->facultate = new char[strlen(s.facultate) + 1];
		strcpy(this->facultate, s.facultate);

		//grades
		if (s.nrNote != 0) {
			this->note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
				note[i] = s.note[i];
			this->nrNote = s.nrNote;
		}
		else
		{
			this->nrNote = 0;
			this->note = NULL;
		}
	}

public:
	//accessor methods
	//for reading
	int getCode() {
		return this->cod;
	}

	char* getFaculty() {
		return this->facultate;
	}
	char* getName() {
		return this->nume;
	}

	//write access
	void setFaculty(char* newFaculty) {
		//validating the input
		if (strlen(newFaculty) >= 2) {

			//this->faculty = newFaculty; DON'T
			if (this->facultate != NULL)
				delete [] this->facultate;
			this->facultate = new char[strlen(newFaculty) + 1];
			strcpy(this->facultate, newFaculty);
		}
		else {
			throw exception("The name is too short!");
		}

	}


	void operator=(const Student& s2) {

		if (this == &s2)
			return;

		delete [] this->note;
		delete [] this->facultate;

		cout << endl << "Operator = called";
		this->cod = s2.cod;
		strcpy(this->nume, s2.nume);
		this->facultate = new char[strlen(s2.facultate) + 1];
		strcpy(this->facultate, s2.facultate);

		//grades
		if (s2.nrNote != 0) {
			this->note = new int[s2.nrNote];
			for (int i = 0; i < s2.nrNote; i++)
				note[i] = s2.note[i];
			this->nrNote = s2.nrNote;
		}
		else
		{
			this->nrNote = 0;
			this->note = NULL;
		}
	}


	//metoda pentru serializare obiect intr-un fisier binar
	void salvareObiect(ofstream& fisier) {
		if (fisier.is_open()) {
			//scriem codul
			fisier.write((char*)&this->cod,sizeof(int));
			//scriem numarul note
			fisier.write((char*)&this->nrNote, sizeof(int));
			//scriem numele
			fisier.write(this->nume, sizeof(this->nume));
			//scriem notele
			for (int i = 0; i < this->nrNote; i++) {
				fisier.write((char*)&this->note[i], sizeof(int));
			}
			//definim un buffer
			char buffer[1000];
			strcpy(buffer, this->facultate);
			fisier.write(buffer, sizeof(buffer));
		}
	}

	//metoda pentru deserializare
	void citireObiect(ifstream& fisier) {
		//citire cod
		fisier.read((char*) &this->cod, sizeof(int));
		//numar note
		fisier.read((char*) &this->nrNote, sizeof(int));
		//nume
		fisier.read(this->nume, sizeof(Student::nume));
		delete [] this->note;

		int nrCaractere = 23;

		fisier.seekg( (-1) * nrCaractere, ios::cur);

		this->note = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++) {
			fisier.read((char*)&this->note[i], sizeof(int));
		}
		char buffer[1000];
		fisier.read(buffer, sizeof(buffer));
		delete [] this->facultate;
		this->facultate = new char[strlen(buffer) + 1];
		strcpy(this->facultate, buffer);
	}

};

void displayStudent(Student& s) {
	cout << endl << "Numele studentului este "
		<< s.getName() << ", are codul "
		<< s.getCode() << " si este la facultatea "
		<< s.getFaculty();
	cout << endl << "Note:";
	for (int i = 0; i < s.nrNote; i++)
		cout << " " << s.note[i];
}

void main() {
	Student s1("Gigel", 23, "CSIE");
	Student s2("Ionel", 22, "MK");

	//working with text files
	ofstream report;
	report.open("studenti.txt", ios::out);
	if (report.is_open()) {
		report << "Numele studentului este "
			<< s1.getName() << " si este din facultatea "
			<< s1.getFaculty() << endl;
		report << "Numele studentului este "
			<< s2.getName() << " si este din facultatea "
			<< s2.getFaculty() << endl;
		report.close();
		cout << "Salvare date ...";
	}
	else
		cout << endl << "Eroare deschidere fisier";

	//citire fisiere text
	ifstream dateStudenti;
	dateStudenti.open("input.txt", ios::in);
	if (dateStudenti.is_open()) {
		int nrStudenti;
		dateStudenti >> nrStudenti;
		//Student lista [nrStudenti];
		Student *lista = new Student[nrStudenti];
		for (int i = 0; i < nrStudenti; i++) {
			dateStudenti >> lista[i].cod;
			//dateStudenti >> lista[i].nume;
			dateStudenti.get();
			dateStudenti.getline(lista[i].nume, 50);
			dateStudenti >> lista[i].nrNote;
			delete [] lista[i].note;
			lista[i].note = new int[lista[i].nrNote];
			for (int j = 0; j < lista[i].nrNote; j++) {
				dateStudenti >> lista[i].note[j];
			}
			char temp[100];
			dateStudenti >> temp;
			delete [] lista[i].facultate;
			lista[i].facultate = new char[strlen(temp) + 1];
			strcpy(lista[i].facultate,temp);

		}//i
		dateStudenti.close();
		for (int i = 0; i < nrStudenti; i++)
			displayStudent(lista[i]);
	}

	//serializare obiecte
	//ofstream fisierSalvare;
	//fisierSalvare.open(
	//	"date.bin", ios::out | ios::binary | ios::trunc);
	//if (fisierSalvare.is_open()) {

	//	//NU este ok - sunt salvate adrese
	//	//fisierSalvare.write((char*)&s1,sizeof(Student));

	//	s1.salvareObiect(fisierSalvare);

	//	fisierSalvare.close();
	//}

	ifstream fisierInput;
	fisierInput.open(
		"date.bin", ios::in | ios::binary);
	if (fisierInput.is_open()) {
		Student temp;
		cout << endl << "Obiect citit";
		//fisierInput.read((char*)&temp, sizeof(Student));

		temp.citireObiect(fisierInput);

		fisierInput.close();
		displayStudent(temp);
	}
}
