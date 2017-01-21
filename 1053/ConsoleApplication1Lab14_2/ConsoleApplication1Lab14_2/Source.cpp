#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define ARRAY_SIZE 200
#define TEST


void main() {
	string name;
	string message = "Hello World";
	message = message + " C++ !";
	name = message;

#ifdef TEST
	cout << endl << message;
#endif

	int values[ARRAY_SIZE];
	int values2[ARRAY_SIZE];


	//test STL
	list<string> students;
	students.push_back("Jonh");
	students.push_back("Alice");
	students.push_back("Alice");
	students.push_front("Bob");

	list<string>::iterator itList;
	for (itList = students.begin();
	itList != students.end(); itList++) {
		cout << endl << *itList;
	}

	cout << endl << "__________________";
	set<string> students2;
	students2.insert("John");
	students2.insert("Alice");
	students2.insert("Alice");
	students2.insert("Bob");

	set<string>::iterator itSet;
	itSet = students2.begin();
	while (itSet != students2.end()) {
		cout << endl << *itSet;
		itSet++;
	}

	map<int, string> student3;
	student3.insert(make_pair(101, "John"));
	student3.insert(make_pair(224, "Alice"));
	student3.insert(make_pair(678, "Bob"));

	string nameS = student3[101];

	cout << endl << "The name is" << nameS;
}