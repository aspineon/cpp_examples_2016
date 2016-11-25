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
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
		code = p.code;
	}
	void operator=(const Person& p) {
		delete [] this->name;
		name = new char[strlen(p.name) + 1];
		strcpy(name, p.name);
		code = p.code;
	}

	char* getName() const {
		return this->name;
	}
	int getCode() const {
		//this->code = 23;
		return code;
	}

	explicit operator float() {
		float sum = 0;
		for (int i = 0; i < strlen(this->name); i++) {
			sum += this->name[i];
		}
		return sum;
	}

	friend istream& operator>>(istream& input, Person& p);
};

ostream& operator<<(ostream& out, const Person& p) {
	out << endl << "Name " << p.getName()
		<< " and code " << p.getCode();
	return out;
}

istream& operator>>(istream& input, Person& p) {
	cout << endl << "The name:";
	char buffer[1000];
	//input.get();
	//input.getline(buffer,1000);
	
	input >> buffer;
	delete [] p.name;
	p.name = new char[strlen(buffer) + 1];
	strcpy(p.name, buffer);
	cout << endl << "The code: ";
	input >> p.code;
	return input;
}


void main() {
	Person p1("John", 1);
	Person p2 = p1;
	p1 = p2;
	cout << p1;
	cin >> p1;
	cout << p1;

	float value = (float)p1;

	//Person list[3];
	Person *pp1;	//pointer to a person
	pp1 = new Person("John Doe", 1);
	//Person p3;
	//Person *pList;	//pointer to an array of persons
	//pList = new Person[3];

	Person* *list = new Person*[3];
	for (int i = 0; i < 3; i++) {
		list[i] = new Person("John Doe", 0);
	}
	for (int i = 0; i < 3; i++) {
		cin >> *list[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << *list[i];
	}

}