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
	out << "Grupa din facultatea " << grupa.facultate;
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
			fisierStudenti.getline(buffer,50);
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
}