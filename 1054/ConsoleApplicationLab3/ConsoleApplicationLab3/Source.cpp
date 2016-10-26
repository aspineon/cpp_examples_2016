#include <iostream>
using namespace std;

class Student {
public:
	int code;
	char* name;
public:
	int* grades;
	int noGrades;
};

Student initStudent(Student s) {
	s.code = 0;
	//DON'T DO THIS
	//s.name = "John Doe";
	s.name = new char [strlen("John Doe")+1];
	strcpy(s.name, "John Doe");
	s.noGrades = 0;
	s.grades = NULL; // = 0
	return s;
}

void initStudent2(Student *ps)
{
	ps->code = 0;
	//DON'T DO THIS
	//ps->name = "John Doe";
	ps->name = new char[strlen("John Doe") + 1];
	strcpy(ps->name, "John Doe");
	ps->noGrades = 0;
	ps->grades = NULL;
}

void initStudent3(Student& s) {
	s.code = 0;
	//DON'T DO THIS
	//s.name = "John Doe";
	s.name = new char[strlen("John Doe") + 1];
	strcpy(s.name, "John Doe");
	s.noGrades = 0;
	s.grades = NULL; // = 0
}

void changeStudentName(Student& s) {

	cout << endl << "Please insert the new name ";

	char temp[1000];
	cin >> temp;

	//clear the memory leak
	if(s.name!=NULL)
		delete [] s.name;

	s.name = new char [strlen(temp)+1];
	strcpy(s.name, temp);

}

void main() {
	//creating an object
	Student student;

	//student = initStudent(student);
	//initStudent2(&student);
	initStudent3(student);

	cout << endl << "The student " <<
		student.name << " has the code " <<
		student.code;

	changeStudentName(student);

	cout << endl << "The student " <<
		student.name << " has the code " <<
		student.code;
}