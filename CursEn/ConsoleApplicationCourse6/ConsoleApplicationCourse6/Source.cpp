#include <iostream>
using namespace std;

class Student {
private:
	//attributes
	int code;
	char name[50];
	int * grades;
	int noGrades;
	char* faculty;

public:
	//methods
	//constructor
	Student() {
		cout << endl << "Constructor called";
		code = 0;
		noGrades = 0;
		this->grades = NULL;
		strcpy(this->name, "John Doe");
		// DON'T this->faculty = "CSIE";
		this->faculty = new char[strlen("CSIE") + 1];
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

	~Student() {
		cout << endl << "Destructor !!!!!";
		if (this->faculty != NULL)
			delete [] this->faculty;
		if (this->grades != NULL)
			delete [] grades;
	}

	//copy constructor
	Student(Student& student) {
		cout << endl << "Copy constructor called";
		this->code = student.code;
		strcpy(this->name, student.name);
		this->faculty = new char[strlen(student.faculty) + 1];
		strcpy(this->faculty, student.faculty);

		//grades
		if (student.noGrades != 0) {
			this->grades = new int[student.noGrades];
			for (int i = 0; i < student.noGrades; i++)
				grades[i] = student.grades[i];
			this->noGrades = student.noGrades;
		}
		else
		{
			this->noGrades = 0;
			this->grades = NULL;
		}
	}

public:
	//accessor methods
	//for reading
	int getCode() {
		return this->code;
	}

	char* getFaculty() {
		return this->faculty;
	}
	char* getName() {
		return this->name;
	}

	//write access
	void setFaculty(char* newFaculty) {
		//validating the input
		if (strlen(newFaculty) >= 2) {

			//this->faculty = newFaculty; DON'T
			if (this->faculty != NULL)
				delete [] this->faculty;
			this->faculty = new char[strlen(newFaculty) + 1];
			strcpy(this->faculty, newFaculty);
		}
		else {
			throw exception("The name is too short!");
		}

	}

	void operator=(Student s2) {

		delete [] this->grades;
		delete [] this->faculty;

		cout << endl << "Operator = called";
		this->code = s2.code;
		strcpy(this->name, s2.name);
		this->faculty = new char[strlen(s2.faculty) + 1];
		strcpy(this->faculty, s2.faculty);

		//grades
		if (s2.noGrades != 0) {
			this->grades = new int[s2.noGrades];
			for (int i = 0; i < s2.noGrades; i++)
				grades[i] = s2.grades[i];
			this->noGrades = s2.noGrades;
		}
		else
		{
			this->noGrades = 0;
			this->grades = NULL;
		}
	}

	friend Student operator+(Student& s, int value);

};

Student operator+(Student& s, int value) {
	Student result = s;
	int* newGrades = new int[result.noGrades+1];
	for (int i = 0; i < result.noGrades; i++)
		newGrades[i] = result.grades[i];
	newGrades[result.noGrades] = value;

	delete [] result.grades;
	result.grades = newGrades;

	return result;
}
Student operator+(int value, Student& s) {
	return s + value;
}

void displayStudent(Student& s) {
	cout << endl << "The student name is "
		<< s.getName() << ", the code is "
		<< s.getCode() << " and the faculty is "
		<< s.getFaculty();
}

//overloading operators 
//s1 = s2
//s1 = s2 = s3;
//void operator=(Student s1, Student s2) {
//
//}



void main() {
	//Student student1;
	Student student2("John", 3, "MAN");
	displayStudent(student2);
	//displayStudent(student2);

	//change faculty 
	//student2.setFaculty("CSIE");
	//displayStudent(student2);

	//calling the copy-constructor
	cout << endl << "Test copy constructor";
	Student student3 = student2;
	displayStudent(student3);

	Student student4;
	student4 = student2;

	student4 = student4 + 9;
	displayStudent(student3);
}