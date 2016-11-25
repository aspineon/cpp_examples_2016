#include <iostream>
using namespace std;

class Person {
	char* name;
	int code;
public:
	Person(char* Name, int Code) {
		name = new char[strlen(Name) + 1];
		strcpy(name, Name);
		code = Code;
	}
	~Person() {
		delete [] name;
	}

	Person(const Person& p) {
		this->code = p.code;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}

	void operator=(const Person& p) {
		delete [] this->name;
		this->code = p.code;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
	}

	char* getName() const {
		return name;
	}
	int getCode() const {
		//this->code = 23;
		return code;
	}

	char& operator[](int index) {
		if (index >= 0 && index < strlen(name)) {
			return name[index];
		}
		throw exception("Wrong index");
	}

	friend istream& operator>>(istream& in, Person& p);
};

ostream& operator<<(ostream& out, const Person& p) {

	out << endl << "The person " << p.getName()
		<< " has the id " << p.getCode();
	return out;
}

istream& operator>>(istream& in, Person& p) {
	cout << endl << "The code:";
	in >> p.code;
	cout << endl << "The name:";
	char buffer[1000];
	in >> buffer;
	delete []  p.name;
	p.name = new char[strlen(buffer) + 1];
	strcpy(p.name, buffer);
	return in;
}


void main() {
	//Person p1;
	Person p1("John", 1);
	Person p2 = p1;
	p1 = p2;

	cin >> p1;
	cout << p1;

	char letter = p1[0];
	cout << endl << "The initial is " << letter;
	p1[0] = 'a';
	cout << p1;

	//define an array of 3 persons
	//Person list[3];
	Person *pp; //define a pointer to a Person
	pp = new Person("John",1);
	//Person *list; //pointer to an array of Persons
	//list = new Person[3];

	//array of pointers to Persons
	Person* *list = new Person*[3]; 
	for (int i = 0; i < 3; i++)
		list[i] = new Person("John Doe",0);

	for (int i = 0; i < 3; i++) {
		cin >> *list[i];
	}

	for (int i = 0; i < 3; i++) {
		cout << *list[i];
	}

	
}
