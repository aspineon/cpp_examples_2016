#include <iostream>
using namespace std;

class Person {
protected:
	char name[50];
	int age;
public:
	//Person() {
	//	cout << endl << "Default Person constructor";
	//	strcpy(name, "");
	//	age = 0;
	//}
	Person(char* Name, int Age) {
		strcpy(name, Name);
		age = Age;
	}
	char* getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
	void setAge(int value) {
		this->age = value;
	}
	void print() {
		cout << endl << "The person "
			<< this->name << " is "
			<< this->age << " years old";
	}
};

class Student:public Person {
	int grades[30];
	int noGrades;
	char faculty[100];
public:
	Student():Person("John Doe",20) {
		cout << endl << "Default Student constructor";
		//strcpy(this->name, "John Doe");
		strcpy(this->faculty, "CSIE");
		this->noGrades = 0;
	}
	Student(char* name, 
		int age, 
		char* faculty):Person(name,age) {
		noGrades = 0;
		strcpy(this->faculty, faculty);
	}

	//overriding print
	void print() {
		cout << endl << "The student "
			<< this->name << " is "
			<< this->age << " years old and is enrolled at "
			<< this->faculty;
		cout << endl << "No grades:" << this->noGrades;
	}
};

void main() {
	//Person p1;
	Person p2("Alice", 22);

	//p1.print();
	p2.print();

	Student s1;
	s1.print();

	s1.getAge();

	//up-casting
	p2 = s1;
	p2.print();
}