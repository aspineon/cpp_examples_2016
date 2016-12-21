#include <iostream>
using namespace std;

class Produs {
protected:
	int cod;
	char denumire[50];
	float pret;

public:
	//Produs() {
	//	cout << endl << "Apel constr default PRODUS";
	//	cod = 0;
	//	pret = 0;
	//	strcpy(denumire, "");
	//}
	Produs(int Cod, char* Denumire, float Pret) {
		cout << endl << "Apel constr cu parametri PRODUS";
		cod = Cod;
		strcpy(denumire, Denumire);
		pret = Pret;
	}

	float getPret() {
		return this->pret;
	}

	int getCod() {
		return this->cod;
	}

	char* getDenumire() {
		return this->denumire;
	}

	void afisare() {
		cout << endl << "Produsul "
			<< denumire << " are pretul "
			<< pret << " si codul "
			<< cod;
	}
	~Produs() {
		cout << endl << "Apel destructor Produs";
	}
};


//derivare - relatia is a
class ProdusPromotie:public Produs {
	float discount;
public:
	ProdusPromotie():Produs(1000,"nimic",0) {
		cout << endl << "Apel constr default PRODUS-PROMOTIE";
		this->discount = 0;
		//this->cod = 0;
		//this->pret = 100;
		//strcpy(denumire, "Produs promotie");
		//discount = 0.1;
	}
	ProdusPromotie(int Cod,
		char* Denumire,
		float Pret, float Discount)
		:Produs(Cod,Denumire,Pret) {
		cout << endl << "Apel constr cu parametri PRODUS-PROMOTIE";
		/*this->cod = Cod;
		this->pret = Pret;
		strcpy(denumire, Denumire);*/
		discount = Discount;
	}

	//supradefinire metoda mostenita din baza
	//overriding
	void afisare() {
		//cout << endl << "Produsul "
		//	<< denumire << " are pretul "
		//	<< pret << " si codul "
		//	<< cod;
		//apel versiune din baza
		this->Produs::afisare();
		cout << " si are un discount de "
			<< this->discount;
	}
};


void main() {
	//Produs p1;
	//p1.afisare();
	Produs p2(1, "Masinuta", 23.8);
	p2.afisare();

	//Produs p3 = p2;
	//p1 = p2;

	cout << endl << "Produs promotie";
	ProdusPromotie pp1;
	pp1.afisare();

	ProdusPromotie pp2(2, "Biscuiti", 2.5, 0.15);
	pp2.afisare();
	//pp1.pret = 23;
}