#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
	char* nume;
	int *note;
	int nrNote;
	int cod;
	Student(char* Nume, int Cod) {
		this->nume = new char[strlen(Nume) + 1];
		strcpy(this->nume, Nume);
		this->cod = Cod;
		this->note = NULL;
		this->nrNote = 0;
	}
	Student() {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		cod = 0;
		this->note = NULL;
		this->nrNote = 0;
	}
};

//compunere - has a
class Grupa {
public:
	Student* lista;
	int nrStudenti;
	char facultate[50];

	Grupa() {
		this->lista = NULL;
		this->nrStudenti = 0;
		strcpy(this->facultate, "");
	}
	Grupa(char* facultate) {
		strcpy(this->facultate, facultate);
		this->lista = NULL;
		this->nrStudenti = 0;
	}
};

ostream& operator<<(ostream&  out, Grupa& grupa) {
	out << endl << "Grupa din facultatea " << grupa.facultate;
	out << endl;
	for (int i = 0; i < grupa.nrStudenti; i++) {
		out << endl << grupa.lista[i].cod << " - " <<
			grupa.lista[i].nume;
		out << endl << "Note:";
		for (int j = 0; j < grupa.lista[i].nrNote; j++)
			out << " " << grupa.lista[i].note[j];
	}
	return out;
}

//supraincarcare << pentru scriere in fisier text
void operator<<(ofstream& fisier, Grupa& grupa) {
	fisier << "\t\t" << "Lista studenti grupa " <<
		grupa.facultate;
	for (int i = 0; i < grupa.nrStudenti; i++) {
		fisier << endl << i + 1 << "."
			<< grupa.lista[i].cod
			<< " - " << grupa.lista[i].nume;
	}
}

void main() {
	Grupa g1029("CSIE");
	cout << g1029;

	ifstream fisierStudenti;
	fisierStudenti.open("studenti.txt", ios::in);
	if (fisierStudenti.is_open()) {
		fisierStudenti >> g1029.facultate;
		fisierStudenti >> g1029.nrStudenti;
		g1029.lista = new Student[g1029.nrStudenti];
		for (int i = 0; i < g1029.nrStudenti; i++) {
			fisierStudenti >> g1029.lista[i].cod;

			char buffer[50];
			fisierStudenti.get();
			fisierStudenti.getline(buffer, 50);
			delete [] g1029.lista[i].nume;
			g1029.lista[i].nume =
				new char[strlen(buffer) + 1];
			strcpy(g1029.lista[i].nume, buffer);

			fisierStudenti >> g1029.lista[i].nrNote;
			g1029.lista[i].note = new int[g1029.lista[i].nrNote];

			for (int j = 0; j < g1029.lista[i].nrNote; j++) {
				fisierStudenti >> g1029.lista[i].note[j];
			}
		}//i

		fisierStudenti.close();

		cout << g1029;
	}// de la if

	 //scriere fisier text
	ofstream raport;

	raport.open("Lista studenti.txt", ios::out);
	if (raport.is_open()) {
		raport << g1029;
		raport.close();
	}

	//lucru cu fisiere binare
	//serializare

	//************
	// Scriere fisier binar
	//************

	ofstream fisierSalvare;
	fisierSalvare.open("Date.bin",
		ios::out | ios::binary | ios::trunc);
	if (fisierSalvare.is_open()) {
		//salvare date grupa
		//NU ASA - se scriu adrese
		//fisierSalvare.write((char*)&g1029, sizeof(Grupa));
		//fisierSalvare.close();
		//scriem facultatea
		fisierSalvare.write((char*) g1029.facultate,
			sizeof(g1029.facultate));
		//scriem numarul de studenti
		fisierSalvare.write((char*) &g1029.nrStudenti,
			sizeof(int));
		//scriem datele studentilor
		for (int i = 0; i < g1029.nrStudenti; i++) {
			fisierSalvare.write((char*) &g1029.lista[i].cod,
				sizeof(int));	//cod
			fisierSalvare.write((char*) &g1029.lista[i].nrNote,
				sizeof(int));	//nrNote
			for (int j = 0; j < g1029.lista[i].nrNote; j++)
			{
				fisierSalvare.write((char*) &g1029.lista[i].note[j],
					sizeof(int));	//fiecare nota
			}
			//gestiune nume student - variabil
			//scriu numarul de caractere, inclusiv /0
			int nrCaractere = strlen(g1029.lista[i].nume) + 1;
			fisierSalvare.write((char*) &nrCaractere,
				sizeof(int));
			fisierSalvare.write(g1029.lista[i].nume, nrCaractere);
		}//de la for studenti
		 //inchidem fisierul
		fisierSalvare.close();
	}

	//************
	// Citire fisier binar
	//************

	ifstream fisierIntrare;
	fisierIntrare.open("Date.bin",
		ios::in | ios::binary);
	if (fisierIntrare.is_open()) {

		Grupa grupa;
		cout << endl << "Test lucru fisiere binare - citire";
		cout << grupa;

		//NU MERGE - se citesc adrese salvate in fisier
		//fisierIntrare.read((char*)&test, sizeof(Grupa));

		//daca nu avem acces la atribute se folosesc variabile locale si apoi functii set

		//citim facultatea
		fisierIntrare.read(grupa.facultate, sizeof(grupa.facultate));
		//citim numarul de studenti
		fisierIntrare.read((char*)&grupa.nrStudenti, sizeof(int));
		//alocam vectorul - evitam un posibil memory leak
		delete [] grupa.lista;
		grupa.lista = new Student[grupa.nrStudenti];
		//citim datele fiecarui student
		for (int i = 0; i < grupa.nrStudenti; i++) {
			//citim id-ul
			fisierIntrare.read((char*)&grupa.lista[i].cod, sizeof(int));
			//citim numarul de note
			fisierIntrare.read((char*) &grupa.lista[i].nrNote, sizeof(int));

			//construim vectorul si citim notele
			delete [] grupa.lista[i].note;
			grupa.lista[i].note = new int[grupa.lista[i].nrNote];
			for (int j = 0; j < grupa.lista[i].nrNote; j++) {
				fisierIntrare.read((char*)&grupa.lista[i].note[j], sizeof(int));
			}

			//citim numele - este salvat in fisier, dar este precedat de numarul de caractere (inclusiv \0)
			int dimensiuneNume;
			fisierIntrare.read((char*) &dimensiuneNume, sizeof(int));

			delete [] grupa.lista[i].nume;
			grupa.lista[i].nume = new char[dimensiuneNume];
			fisierIntrare.read(grupa.lista[i].nume, dimensiuneNume*sizeof(char));

		}


		fisierIntrare.close();
		cout << grupa;
	}
}