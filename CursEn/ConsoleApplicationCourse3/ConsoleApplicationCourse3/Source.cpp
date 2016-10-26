#include <iostream>
using namespace std;

struct Student {
	int code;
	char name[50];
	int* grades;
	int noGrades;
	int height;
};

void displayStudentData(Student stud) {
	cout << endl << "The student " << stud.name
		<< " has the code " << stud.code;
}



class StudentClass {
public:
	int code;
	char name[50];
private:
	int* grades;
	int noGrades;
	int height;
public:
	int getHeight() {
		return height;
	}
};


void main() {
	//define an article
	Student stud1;
	//define an object
	StudentClass stud2;
	Student * pStud;
	StudentClass *pStud2;

	//use the article
	stud1.code = 1;
	//stud1.name = "Gigel";
	strcpy(stud1.name, "Gigel");

	cout << endl << "The student 1 code is " << stud1.code
		<<" and the name is "<<stud1.name;

	cout << endl << "The student 2 code is " << stud2.code
		<< " and the name is " << stud2.name;

	//stud2.height = 170;
	char* ps = (char*)&stud2;
	*(int*)(ps + 64) = (int)170;

	cout << endl << "The height is " << stud2.getHeight();
}