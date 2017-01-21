#include <iostream>
#include <string>
#include <list>
#include <set>
#include <map>
using namespace std;

#define NMAX 100
#define NO_PRINT_MESAJ


void main() {
	string text = "Hello World";
	text = text + " C++ !";

#ifndef NO_PRINT_MESAJ
	cout << endl << text;
#endif

	int valori[NMAX];

	list<string> listaPersoane;
	listaPersoane.push_back("Gigel");
	listaPersoane.push_back("Ionel");
	listaPersoane.push_back("Ionel");
	listaPersoane.push_front("Alex");

	list<string>::iterator it;
	for (it = listaPersoane.begin();
	it != listaPersoane.end();
		it++) {
		cout << endl << *it;
	}

	set<string> studenti;
	studenti.insert("Gigel");
	studenti.insert("Ionel");
	studenti.insert("Ionel");
	studenti.insert("Alex");

	cout << endl << "Lista studenti:";
	set<string>::iterator itSet;
	for (itSet = studenti.begin();
	itSet != studenti.end(); itSet++) {
		cout << endl << *itSet;
	}

	//test map
	map<int, string> persoane;
	persoane.insert(pair<int, string>(101, "Gigel"));
	persoane.insert(make_pair(103, "Ionel"));
	persoane.insert(make_pair(225, "Ana"));
	persoane.insert(make_pair(103, "Popescu"));

	string numePers = persoane[103];
	if (!numePers.empty())
		cout << endl << "Persoana cu codul 103 :" << numePers;
	else
		cout << endl << "Persoana cu codul 103 nu exista";
}