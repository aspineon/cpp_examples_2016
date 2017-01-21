#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define ARRAY_SIZE 100
#define NO_DO_DEBUG

void main() {
	string message;
	message = "Hello World";
	message = message + " C++ !";
	string backUp = message;

#ifdef DO_DEBUG
	cout << endl << message;
#endif
	int values1[100];
	int values2[ARRAY_SIZE];

	//test the list
	list<string> names;
	names.push_back("John");
	names.push_back("Alice");
	names.push_back("Mike");
	names.push_back("Mike");
	names.push_front("Bob");

	//get an iterator
	list<string>::iterator itList;
	for (itList = names.begin();
	itList != names.end(); itList++) {
		cout << endl << *itList;
	}

	vector<int> values;
	values.push_back(23);
	values.push_back(45);
	cout << endl << values[0];

	//testing a set
	set<string> names2;
	names2.insert("John");
	names2.insert("Alice");
	names2.insert("Mike");
	names2.insert("Mike");
	names2.insert("Bob");

	set<string>::iterator itSet;
	itSet = names2.begin();
	while (itSet != names2.end()) {
		cout << endl << *itSet;
		itSet++;
	}

	map<int, string> students;
	students.insert(make_pair(101, "John"));
	students.insert(make_pair(220, "Alice"));

	string name = students[221];
	if (!name.empty()) {
		cout << endl << "The name is " << name;
	}
	else
		cout << endl << "The students doesn't exist";
}