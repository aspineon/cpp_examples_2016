#include <iostream>
#include <fstream>

using namespace std;


class Student {
public:
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
		//cout << endl << "Constructor called";
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
	Student(const Student& s) {
		delete [] this->grades;
		delete [] this->faculty;

		//cout << endl << "Copy constructor called";
		this->code = s.code;
		strcpy(this->name, s.name);
		this->faculty = new char[strlen(s.faculty) + 1];
		strcpy(this->faculty, s.faculty);

		//grades
		if (s.noGrades != 0) {
			this->grades = new int[s.noGrades];
			for (int i = 0; i < s.noGrades; i++)
				grades[i] = s.grades[i];
			this->noGrades = s.noGrades;
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


	void operator=(const Student& s2) {
		if (this == &s2)
			return;

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
	cout << endl << "Grades:";
	for (int i = 0; i < s.noGrades; i++)
		cout << " " << s.grades[i];
}

void main() {
	Student s1("John", 23, "CSIE");
	Student s2("Alice", 22, "MK");

	//s1 = s1;

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

	//reading an array o students
	Student *list;

	ifstream inputFile;
	inputFile.open("input.txt", ios::in);

	if (inputFile.is_open()) {

		int noStudents = 0;
		inputFile >> noStudents;

		//create the array
		list = new Student [noStudents];

		//read the students
		for (int i = 0; i < noStudents; i++) {
			inputFile >> list[i].code;
			inputFile.get();
			//inputFile >> list[i].name;
			inputFile.getline((char*)list[i].name, 50);
			inputFile >> list[i].noGrades;
			delete [] list[i].grades;
			list[i].grades = new int[list[i].noGrades];
			for (int j = 0; j < list[i].noGrades; j++) {
				inputFile >> list[i].grades[j];
			}
			
			//delete [] list[i].faculty;
			//list[i].faculty = NULL;
			char temp[1000];
			inputFile >> temp;
			list[i].setFaculty(temp);
		}
		inputFile.close();
		for (int i = 0; i < noStudents; i++)
			displayStudent(list[i]);
	}

	//serializing objects
	////ofstream saveFile;
	////saveFile.open(
	////	"data.bin", ios::out | ios::binary | ios::trunc);
	////if(saveFile.is_open()){
	////	//DON'T DO IT - IT's NOT OK
	////	saveFile.write((char*) &s1, sizeof(Student));
	////	saveFile.close();
	////}
	////ifstream readFile;
	////readFile.open("data.bin", ios::in | ios::binary);
	////if (readFile.is_open()) {
	////	Student temp;
	////	readFile.read((char*)&temp, sizeof(Student));
	////	readFile.close();
	////	cout<<endl<<"File student";
	////	displayStudent(temp);
	////
	////}

}
