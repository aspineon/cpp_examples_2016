#include <iostream>
using namespace std;

class Person {
protected:
	char name[50];
	int age;
public:
	//Person() {
	//	cout << endl << "Default Constructor in Person";
	//	strcpy(name, "");
	//	age = 0;
	//}
	Person(char* Name, int Age) {
		strcpy(name, Name);
		age = Age;
	}
	virtual void print() {
		cout << endl << "The person "
			<< this->name << " is "
			<< this->age << " years old";
	}
	char* getName() {
		return this->name;
	}
	int getAge() {
		return age;
	}
	void setAge(int value) {
		this->age = value;
	}
};

//inheritance
class Student :public Person {
	char faculty[100];
	int grades[30];
	int noGrades;
public:
	Student():Person("John Doe",20) {
		cout << endl << "Default Constructor in Student";
		//strcpy(this->name, "John Doe");
		strcpy(this->faculty, "CSIE");
		noGrades = 0;
	}
	Student(char* name, 
		int age, 
		char* faculty):Person(name,age) {
		strcpy(this->faculty, faculty);
		this->noGrades = 0;
	}

	//overriding a parent class methods
	void print() {
		cout << endl << "The student "
			<< this->name << " is "
			<< this->age << " years old and is enrolled at "
			<< this->faculty;
		cout << endl << "No grades: "
			<< this->noGrades;
	}

};

void main() {
	//Person p1;
	Person p2("Alice", 22);

	//p1.print();
	p2.print();

	Student s1;
	Student s2("Alice", 21, "MK");
	s1.print();
	s2.print();

	//p2 = s1;
	//p2.print();
}