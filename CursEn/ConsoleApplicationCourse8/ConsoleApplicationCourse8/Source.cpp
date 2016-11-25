#include <iostream>
#include <fstream>
#include "Student.cpp"

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


};



void displayStudent(Student& s) {
	cout << endl << "The student name is "
		<< s.getName() << ", the code is "
		<< s.getCode() << " and the faculty is "
		<< s.getFaculty();
}

void main() {
	Student s1("John", 23, "CSIE");
	Student s2("Alice", 22, "MK");

	//working with text files
	ofstream report;
	report.open("students.txt", ios::out);
	if (report.is_open()) {
		report << "The student name is "
			<< s1.getName() << " and the faculty is "
			<< s1.getFaculty() << endl;
		report << "The student name is "
			<< s2.getName() << " and the faculty is "
			<< s2.getFaculty() << endl;
		report.close();
		cout << "Saving data ...";
	}
	else
		cout << endl << "Error opening the file";

}
