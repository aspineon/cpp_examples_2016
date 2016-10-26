#include <iostream>
using namespace std;

struct Student {
	int cod;
	char nume[50]; //vector static
	int * note;		//vector dinamic
	int  nrNote;
};

void initializareStudent(Student* ps) {
	ps->cod = 0;
	strcpy(ps->nume, "Anonim");
	ps->nrNote = 0;
	ps->note = NULL; //=0
}

class ClasaStudent {
public:
	int cod;
	char nume[50]; //vector static
private:
	int * note;		//vector dinamic
	int  nrNote;
};

void main() {
	//creare articol
	Student student1;

	//student1.cod = 1;
	//student1.nume = "Gigel";
	//strcpy(student1.nume, "Gigel");

	initializareStudent(&student1);

	//student1.nume[3] = 0; //echivalent cu '\0'
	//student1.nume[5] = 'a';

	cout << endl << "Studentul cu numele " <<
		student1.nume << " are codul " <<
		student1.cod;

	//creare obiect
	ClasaStudent student2;

	//cout << endl << "Studentul cu numele " <<
	//	student2.nume << " are codul " <<
	//	student2.cod;

	//student2.nrNote = 0;
}

