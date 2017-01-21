#include <iostream>
#include <string>
#include <set>
#include <list>
#include <map>


using namespace std;

int suma(int a, int b) {
	return a + b;
}

int suma(int a, int b, int...) {
	return 0;
}

void ceva(int * valori, int n) {
	if (valori == NULL)
		//throw exception("Am primit null");
		throw new exception("Am primit null");
	//throw "Am primit null";
	for (int i = 0; i < n; i++)
		cout << " " << valori[i];
}

class Frigider {

};

class Floare {

};

template <typename T> class TemplateCutie {
	T continut;
public:
	TemplateCutie(T valoare) {
		cout << endl << "Apel constructor";
		continut = valoare;
	}

	bool operator>(TemplateCutie& t) {
		return continut > t.continut;
	}
};

//specializare de metode
TemplateCutie<char*>::TemplateCutie(char* valoare) {
	cout << endl << "Apel constructor specializat";
	continut = new char[strlen(valoare)+1];
	strcpy(continut, valoare);
}

bool TemplateCutie<char*>::operator>(TemplateCutie& t) {
	if (strcmp(continut, t.continut) == 0)
		return true;
	else
		return false;
}


class Cutie {
	char* continut;
public:
	Cutie(char* valoare) {
		continut = valoare;
	}
};



void main(int argc, char** argv) {


	Frigider f;
	Cutie cutieFrigider((char*) &f);
	Floare floare;
	Cutie cutieFloare((char*) &floare);
	int vb;
	Cutie cutieInt((char*) &vb);

	Cutie cutieFloare2((char*) &f);

	TemplateCutie<int> tc(23);
	TemplateCutie<Frigider> tcf(f);
	TemplateCutie<Floare> tcfloare(floare);
	TemplateCutie<char*> email("Salut");

	string nume;
	nume = "Gigel";
	nume = "Ana";
	string numeComplet = nume + " Popescu";
	cout << endl << numeComplet;



}