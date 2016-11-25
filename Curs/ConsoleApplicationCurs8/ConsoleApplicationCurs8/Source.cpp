#include <iostream>
#include <fstream>
using namespace std;


class Student {
public:
	int varsta;
	int cod;

	Student() {
		varsta = 0;
		cod = 1001;
	}
};

void main() {
	Student s1;
	Student s2;
	//test fisiere
	ofstream raport;
	raport.open("studenti.txt", ios::out);

	if (raport.is_open()) {
		raport << "Studentul cu codul " <<
			s1.cod << " are varsta " << s1.varsta<<endl;
		raport << "Studentul cu codul " << 
			s2.cod << " are varsta " << s2.varsta;
		raport.close();
	}
	else
		cout << endl << "Eroare deschidere fisier!";

}