#include <iostream>
using namespace std;

class Person {
private:
	int code;
	char* name;
public:
	Person() {
		this->code = 0;
		this->name = 
			new char[strlen("John Doe") + 1];
		strcpy(this->name, "John Doe");
	}
	Person(int Code, char* Name) {
		code = Code;
		this->name = new char[strlen(Name) + 1];
		strcpy(this->name, Name);
	}

	~Person() {
		if (this->name != NULL)
			delete [] this->name;
	}

	//copy constructor
	Person(Person& person) {
		cout << endl << "Calling COPY-CSTR";
		this->code = person.code;
		this->name = 
			new char[strlen(person.name) + 1];
		strcpy(this->name, person.name);
	}

	//accessor methods for read access
	int getCode() {
		return this->code;
	}
	char* getName() {
		return this->name;
	}
	//for writing
	void setName(char* newName) {
		delete [] this->name;

		this->name = new char[strlen(newName) + 1];
		strcpy(this->name, newName);
	}
};

void printPerson(Person p) {
	cout << endl << "The person name is "
		<< p.getName();
	cout << endl << "The person code is "
		<< p.getCode();
}

void something() {
	Person p(0, "Test");
}

void main() {

	something();

	Person p1;
	Person p2(1, "John");
	cout << endl << "The person name is "
		<< p2.getName();
	p2.setName("Mike");

	cout << endl << "The person name is "
		<< p2.getName();

	printPerson(p2);

	p1 = p2;


	//printPerson(p1);
}