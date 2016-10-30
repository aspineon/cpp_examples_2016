#include <iostream>
using namespace std;

struct Student {
	int cod;
	char nume[50];
	int* note;
	int nrNote;
	float inaltime;
};

void afisareStudent(Student student) {
	cout << endl << "Studentul cu codul " << student.cod
		<< " are numele " << student.nume;
}

class ClasaStudent {
public:
	int cod;
	char nume[50];
private:
	int* note;
	int nrNote;
	int inaltime;
public:
	int getInaltime() {
		return inaltime;
	}
};


void main() {
	//construiesc un articol
	Student student1;
	//construiesc un obiect
	ClasaStudent student2;

	student1.cod = 1;
	//student1.nume = "Gigel";
	strcpy(student1.nume, "Gigel");

	//student2.nrNote = 0;


	cout << endl << "Studentul cu codul " << student1.cod
		<< " are numele " << student1.nume;

	cout << endl << "Studentul cu codul " << student2.cod
		<< " are numele " << student2.nume;



	ClasaStudent *ps = &student2;
	ps += 62;
	char* pps = (char*)&student2;
	pps += 64;
	*(int*)pps = (int)170;

	cout << endl << "Dimensiune stud "
		<< sizeof(student2);

	cout << endl << " Inaltimea studentului este "
	<< student2.getInaltime();


}