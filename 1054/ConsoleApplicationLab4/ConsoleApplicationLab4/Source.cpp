#include <iostream>
using namespace std;

class Student {
private:
	int code;
	char name[50];
	char* faculty;
	int *grades;
	int noGrades;
public:
	Student() {
		code = 0;
		this->noGrades = 0;
		this->grades = NULL;
		strcpy(this->name, "John Doe");
		this->faculty =
			new char[strlen("CSIE") + 1];
		strcpy(this->faculty, "CSIE");
	}

	Student(int code, char* name, char* faculty) {
		this->noGrades = 0;
		this->grades = NULL;

		this->code = code;
		strcpy(this->name, name);
		this->faculty = 
			new char[strlen(faculty) + 1];
		strcpy(this->faculty, faculty);
	}

	void displayStudent() {
		cout << endl << this->name << " is a student at "
			<< this->faculty << " with id "
			<< this->code;
		cout << endl << "The grades are:";
		for (int i = 0; i < this->noGrades; i++)
			cout << " " << this->grades[i];
	}

	//method for accessing the code
	int getCode() {
		return this->code;
	}

	//method for setting the grades
	void setGrades(int* inputGrades, int n) {

		if (this->grades != NULL)
			delete [] this->grades;

		this->grades = new int[n];
		for (int i = 0; i < n; i++)
			this->grades[i] = inputGrades[i];
		this->noGrades = n;
	}

	void addGrade(int newGrade) {

		int* newGrades = 
			new int[this->noGrades + 1];
		for (int i = 0; i < this->noGrades; i++)
			newGrades[i] = this->grades[i];
		newGrades[this->noGrades] = newGrade;

		if (this->grades != NULL)
			delete [] this->grades;

		this->grades = newGrades;
		this->noGrades += 1;

	}
};

void main() {
	Student s1;
	Student s2(1,"Lilly","MK");

	s1.displayStudent();
	s2.displayStudent();

	cout << endl << " S2 code is "
		<< s2.getCode();

	int testGrades [] = {9,9,10};
	s2.setGrades(testGrades, 3);

	s2.displayStudent();

	s2.addGrade(8);

	s2.displayStudent();
}