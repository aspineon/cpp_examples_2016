#include <iostream>
using namespace std;


void citireValoareConsola();
int citireValoareConsola2();
void citireValoriConsola(int* pV1, int *pV2);

void main() {

	int valoare = 0xA;// valoare  = 10
	int valoare2 = 20;

	int *pointerValoare = &valoare;
	valoare = 30;
	*pointerValoare = 40;

	cout << endl << " Valoare initiala = " 
		<< valoare;
	cout << "\n Introduceti o valoare:";
	cin >> valoare;
	cout << endl << "Valoare citita = " 
		<< valoare;

	valoare = citireValoareConsola2();

	cout << endl << "Valoare citita = "
		<< valoare;

	cout << endl << "******* Test pointeri ";

	citireValoriConsola(&valoare, &valoare2);

	cout << endl << "Valoare citita = "
		<< valoare;
	cout << endl << "Valoare citita = "
		<< valoare2;
}

void citireValoareConsola() {
	int vb;
	cout << endl << "Da-mi o valoare: ";
	cin >> vb;
}

int citireValoareConsola2() {
	int vb;
	cout << endl << "Da-mi o valoare: ";
	cin >> vb;
	return vb;
}

void citireValoriConsola(int* pV1, int *pV2 ) {
	int vb1;
	int vb2;
	cout << endl << "Da-mi prima valoare: ";
	cin >> vb1;
	cout << endl << "Da-mi a 2-a valoare: ";
	cin >> vb2;
	*pV1 = vb1;
	*pV2 = vb2;
}