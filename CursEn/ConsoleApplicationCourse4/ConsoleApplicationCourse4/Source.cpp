#include <iostream>
using namespace std;

class Student {
public:
	//attributes
	int code;
	char name[50];
	int * grades;
	int noGrades;
	char* faculty;
	//methods
	//constructor
	Student() {
		cout << endl << "Constructor called";
		code = 0;
		noGrades = 0;
		this->grades = NULL;
		strcpy(this->name, "John Doe");
		// DON'T this->faculty = "CSIE";
		this->faculty = new char [strlen("CSIE")+1];
		strcpy(this->faculty, "CSIE");
	}

	Student(char* name, int code, char*faculty) {
		cout << endl << "Constructor called";
		//shadowing 
		//code = code
		this->code = code;
		this->noGrades = 0;
		this->grades = NULL;
		strcpy(this->name, name);
		this->faculty = 
			new char[strlen(faculty) + 1];
		strcpy(this->faculty, faculty);

	}

};


void initStudent(Student* s) {
	s->code = 0;
	s->noGrades = 0;
	s->grades = NULL;
	//s->name = "John Doe";
	strcpy(s->name, "John Doe");
}

void initStudent2(Student& s) {
	s.code = 0;
	s.noGrades = 0;
	s.grades = NULL;
	//s->name = "John Doe";
	strcpy(s.name, "John Doe");
}

//overloading methods
int sum(int a, int b) {
	return a + b;
}
int sum(int a, int b, int c){
	return a + b + c;
}

int sum(double a, int b) {
	return a + b;
}

void displayStudent(Student s) {
	cout << endl << "The student name is "
		<< s.name << ", the code is "
		<< s.code << " and the faculty is "
		<< s.faculty;

}

void doesNothing() {
	Student s;
}

void main() {
	Student student1;
	Student student2("Gigel",3,"MAN");
	//initStudent(&student1);
	//initStudent2(student1);
	displayStudent(student1);
	displayStudent(student2);

	for (;;) {
		doesNothing();
	}
}