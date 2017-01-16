#include <iostream>
using namespace std;

class ExceptieVarsta :public exception {
public:
	ExceptieVarsta(char* mesaj)
		:exception(mesaj) {

	}
};

class ExceptieNume :public exception {

};

class Student {
	char nume[10];
	int varsta;
public:


	Student(){}
	Student(char*Nume, int Varsta) {
		if(Varsta < 10 || Varsta >100)
			throw new ExceptieVarsta("Varsta gresita");
		if (Nume == NULL)
			throw "Nume inexistent";
		if(strlen(Nume)>9)
			throw new ExceptieNume();
		strcpy(nume, Nume);
		varsta = Varsta;
	}
	char* getNume() {
		return this->nume;
	}
	int getVarsta() {
		return this->varsta;
	}
};

template <typename T, typename R> class Cutie {
	T continut;
	R greutate;
public:
	Cutie(T Continut, R Greutate) {
		this->continut = Continut;
		this->greutate = Greutate;
	}

	void afisare() {
		cout << endl << "Cutia ce contine "
			<< this->continut << " cantareste "
			<< this->greutate;
	}
};

void Cutie<Student, float>::afisare() {
	cout << endl << "Cutia ce contine un student"
		<< " cantareste "
		<< this->greutate;
}

void main() {
	int varsta = 0;
	cout << endl << "Varsta studentului este:";
	cin >> varsta;

	try {
		Student s("Gigel", varsta);

		cout << endl << s.getNume() << " - "
			<< s.getVarsta();

		Cutie<int, int> c1(23, 45);
		c1.afisare();
		Cutie<Student, float> c2(s, 45);
		c2.afisare();
		Cutie<char*, float> c3("text", 45);
		c3.afisare();

	}
	catch (ExceptieNume* eroare) {
		cout << endl << "Nume gresit";
	}
	catch (ExceptieVarsta* e) {
		cout << endl << e->what();
	}
	catch (exception* eroare) {
		cout << endl << "Eroare " << eroare->what();
	}
	catch (...) {
		cout << endl << "S-a intamplat ceva ciudat";
	}
}