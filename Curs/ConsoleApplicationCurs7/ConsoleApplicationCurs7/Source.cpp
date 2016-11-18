#include <iostream>
using namespace std;

//int nrStudenti = 0;

class Student {
	const int cod;
	char nume[50];
	int *note;
	int nrNote;
	
	static int nrStudenti;

public:

	
	//Student() {

	//}
	Student(char* nume, int Cod):cod(Cod) {

		Student::nrStudenti++;

		strcpy(this->nume, nume);
		this->nrNote = 0;
		this->note = NULL; 
	}

	~Student() {
		delete [] this->note;
	}
	Student(Student& s):cod(s.cod) {

		Student::nrStudenti++;

		strcpy(this->nume, s.nume);
		if (s.nrNote != 0) {
			this->nrNote = s.nrNote;
			this->note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
				note[i] = s.note[i];
		}
		else
		{
			this->note = NULL;
			this->nrNote = 0;
		}
	}

	void operator=(const Student& s) {

		delete [] this->note;

		strcpy(this->nume, s.nume);
		if (s.nrNote != 0) {
			this->nrNote = s.nrNote;
			this->note = new int[s.nrNote];
			for (int i = 0; i < s.nrNote; i++)
				note[i] = s.note[i];
		}
		else
		{
			this->note = NULL;
			this->nrNote = 0;
		}
	}

	static int getNrStudenti() {
		return Student::nrStudenti;
	}

	friend ostream& operator<<(
		ostream& consola, const Student& s);
	friend istream& operator>>(istream& intrare, Student& s);

	void operator+=(int nota) {
		int* nou = new int[this->nrNote + 1];
		for (int i = 0; i < nrNote; i++)
			nou[i] = this->note[i];
		delete [] note;
		nou[this->nrNote] = nota;
		this->note = nou;
		this->nrNote += 1;
	}
};

int Student::nrStudenti = 0;

//void ceva(Student s) {
//
//}
//
//Student altceva() {
//
//}
ostream& operator<<(ostream& consola, const Student& s) {
	consola << endl << "Studentul " << s.nume;
	consola << endl << "Notele sunt:";
	for (int i = 0; i < s.nrNote; i++)
		consola << " " << s.note[i];
	return consola;
}

istream& operator>>(istream& intrare, Student& s) {
	cout << endl << "Numele este:";
	//char temp[1000]	//pt dinamic

	intrare >> s.nume;
	cout << endl << "Nr note:";
	intrare >> s.nrNote;
	delete [] s.note;
	s.note = new int[s.nrNote];
	for (int i = 0; i < s.nrNote; i++) {
		cout << endl << "Nota ";
		intrare >> s.note[i];
	}

	return intrare;

}

void main() {

	//Student s;
	Student s1("Gigel",1);
	Student s3("Ana", 2);
	//ceva(s1);

	//constructor de copire
	Student s2 = s1;

	//operator =
	s2 = s1;

	//s2 = altceva();

	//cout << endl <<"In program au fost creati x studenti:"
	//	<< Student::nrStudenti;

	cout << endl <<"In program au fost creati x studenti:"
		<< Student::getNrStudenti();

	cout << s1 << s2;
	cin >> s1;
	cout << s1;

	s1 += 10;
}