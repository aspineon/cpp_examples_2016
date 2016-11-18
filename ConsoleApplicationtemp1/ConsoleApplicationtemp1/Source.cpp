#include <iostream>
#include <string>
using namespace std;

class Student{
	char* nume;
	char facultate[10];
	float medieGeneralaAniStudiu[3];
	int * note;
	int nrNote;
public:
	Student() {
		nume = NULL;
		strcpy(facultate, "");
		note = NULL;
		nrNote = 0;
		for (int i = 0; i < 3; i++)
			medieGeneralaAniStudiu[i] = 0;
	}

	
	Student(char*nume, char* facultate) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		strcpy(this->facultate, facultate);
		for (int i = 0; i < 3; i++)
			medieGeneralaAniStudiu[i] = 0;
		note = NULL;
		nrNote = 0;
	}
	
	Student(const Student& s) {
		if (s.nume != NULL) {
			nume = new char[strlen(s.nume)];
			strcpy(nume, s.nume);
		}
		else
			nume = NULL;

		strcpy(facultate, s.facultate);
		for (int i = 0; i < 3; i++)
			medieGeneralaAniStudiu[i] = s.medieGeneralaAniStudiu[i];

		if (s.note != NULL) {
			note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
				note[i] = s.note[i];
		}
		else
			note = NULL;
		nrNote = s.nrNote;
	}

	void operator=(const Student& s) {
		delete [] nume;
		delete [] note;

		if (s.nume != NULL) {
			nume = new char[strlen(s.nume)];
			strcpy(nume, s.nume);
		}
		else
			nume = NULL;

		strcpy(facultate, s.facultate);
		for (int i = 0; i < 3; i++)
			medieGeneralaAniStudiu[i] = s.medieGeneralaAniStudiu[i];

		if (s.note != NULL) {
			note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
				note[i] = s.note[i];
		}
		else
			note = NULL;
		nrNote = s.nrNote;
	}
	
	~Student() {
		delete [] nume;
		delete [] note;
	}
};


void something(Student &ps) {

}

void main() {
	Student s1;

	Student *ps1;
	Student *ps2;

	ps1 = &s1;
	ps1 = new Student();

	ps2 = ps1;

	delete ps1;

	/*Student s2("Ana", "MK");
	Student s3 = s2;

	Student lista1[3];

	Student *ps1 = new Student("Gigel", "CSIE");
	Student *ps2;
	ps2 = ps1;

	Student * lista2 = new Student[3];

	Student ** lista3 = new Student*[3];
	lista3[0] = new Student("Ion", "MAN");

	cout << "The end";*/
}