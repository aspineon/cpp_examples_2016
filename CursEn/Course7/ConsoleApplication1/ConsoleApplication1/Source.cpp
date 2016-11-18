#include <iostream>
using namespace std;


class Student {
	const int id;
	char name[50];
	int * grades;
	int noGrades;
public:
	static int noStudents;
public:
	Student(char* name,int Id):id(Id) {
		noStudents++;
		strcpy(this->name, name);
		this->grades = NULL;
		this->noGrades = 0;
	}

	Student(char* name) :id(noStudents) {
		noStudents++;
		strcpy(this->name, name);
		this->grades = NULL;
		this->noGrades = 0;
	}

	~Student() {
		delete [] this->grades;

		//noStudents--;
	}
	Student(Student& s):id(s.id) {

		noStudents++;

		strcpy(name, s.name);
		if (s.noGrades != 0) {
			grades = new int[s.noGrades];
			for (int i = 0; i < s.noGrades; i++)
				grades[i] = s.grades[i];
		}
		else
			this->grades = NULL;
		this->noGrades = s.noGrades;
	}
	void operator=(Student s) {
		//s.noGrades = 30;

		delete [] this->grades;

		strcpy(name, s.name);
		if (s.noGrades != 0) {
			grades = new int[s.noGrades];
			for (int i = 0; i < s.noGrades; i++)
				grades[i] = s.grades[i];
		}
		else
			this->grades = NULL;
		this->noGrades = s.noGrades;
	}

	static int getNoStudents() {
		return Student::noStudents;
	}

	//cast to float
	explicit operator float() {
		float sum = 0;
		for (int i = 0; i < this->noGrades; i++)
			sum += this->grades[i];
		return sum / this->noGrades;
	}

	bool operator!() {
		if (this->noGrades == 0)
			return true;
		else
			return false;
	}

	int operator[](int index) {
		if (index >= 0 && index < this->noGrades) {
			return this->grades[index];
		}
		else
			throw exception("The index is wrong!");
	}

	friend void operator+=(Student& s, int value);
};

int Student::noStudents = 0;

void operator+=(Student& s, int value) {
	int * newGrades = new int[s.noGrades + 1];
	for (int i = 0; i < s.noGrades; i++)
		newGrades[i] = s.grades[i];
	delete [] s.grades;
	newGrades[s.noGrades] = value;
	s.grades = newGrades;
	s.noGrades += 1;
}

bool operator==(Student& s1, Student& s2) {
	float av1 = (float) s1;
	float av2 = (float) s2;
	if (av1 == av2)
		return true;
	return false;
 }

void main() {

	//Student s1;
	Student s1("John",1);
	Student s2("Alice",2);
	s1 = s2;

	//cout << endl << "The number of students:"
	//	<< Student::noStudents;

	cout << endl << "The number of students:"
		<< Student::getNoStudents();

	double vb2 = 10.4;
	float vb3 = vb2; //implicit
	float vb4 = (float) vb2;	//explicit

	if (!s1)
		cout << endl << "The student has no grades";

	s1 += 10;
	s1 += 9;
	float average = (float)s1;


	if (!s1)
		cout << endl << "The student has no grades";

	int firstGrade = s1[0];


	cout << endl << "The average is " << average;
}