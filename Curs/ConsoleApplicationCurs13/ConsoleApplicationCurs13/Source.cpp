#include <iostream>
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
};

class Cutie{
	char* continut;
public:
	Cutie(char* valoare) {
		continut = valoare;
	}
};



void main(int argc, char** argv) {

	if (argc >= 2) {
		cout << endl << "Argument 1: " << argv[0];
		cout << endl << "Argument 2: " << argv[1];
	}

	try {
		int vector [] = { 1,2,3,4 };
		ceva(NULL, 4);
		try {
			int vb = 10 / 0;
		}
		catch (...) {

		}
	}
	catch(exception e){
		cout << endl << e.what();
	}
	catch (exception* error) {
		cout << endl << "Am primit pointer " << error->what();
	}
	catch (...) {
		cout << endl << "Mesaj generic";
	}

	Frigider f;
	Cutie cutieFrigider((char*)&f);
	Floare floare;
	Cutie cutieFloare((char*) &floare);
	int vb;
	Cutie cutieInt((char*) &vb);

	Cutie cutieFloare2((char*) &f);

	TemplateCutie<int> tc;
	TemplateCutie<Frigider> tcf;
	TemplateCutie<Floare> tcfloare;
}