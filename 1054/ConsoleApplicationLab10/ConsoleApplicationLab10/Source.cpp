#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
	char name[50];
	int code;
public:
	Student() {
		strcpy(name, "John Doe");
		code = 0;
	}
	Student(char* name, int code) {
		strcpy(this->name, name);
		this->code = code;
	}

	void setName(char* name) {
		strcpy(this->name, name);
	}
	void setCode(int code) {
		this->code = code;
	}

	friend ostream& operator<<(ostream& out, Student& s);
};

ostream& operator<<(ostream& out, Student& s) {
	out << endl << s.code << " - " << s.name;
	return out;
}

//composition - has a relation
class Team {
public:
	Student *list;
	int noStudents;
	char* name;
public:
	Team() {
		list = NULL;
		noStudents = 0;
		name = new char[strlen("") + 1];
		strcpy(name, "");
	}
	Team(char* teamName) {
		name = new char[strlen(teamName) + 1];
		strcpy(this->name, teamName);
		list = NULL;
		noStudents = 0;
	}

	friend ostream& operator<<(ostream& out, Team& team);
	friend void operator>>(ifstream& file, Team& team);
};

ostream& operator<<(ostream& out, Team& team) {
	out << endl << "Team: " << team.name;
	for (int i = 0; i < team.noStudents; i++)
		out << endl << team.list[i];
	return out;
}

void operator>>(ifstream& file, Team& team) {
	file >> team.noStudents;
	char buffer[1000];
	file >> buffer;
	delete [] team.name;
	team.name = new char[strlen(buffer) + 1];
	strcpy(team.name, buffer);
	//file >> team.name;

	//create the list
	delete [] team.list;
	team.list = new Student[team.noStudents];
	for (int i = 0; i < team.noStudents; i++) {
		int code;
		file >> code;
		team.list[i].setCode(code);
		file.get();
		file.getline(buffer, 100);
		team.list[i].setName(buffer);
	}
}

void main() {
	Team g1054("1054");
	cout << g1054;

	ifstream inputFile;
	inputFile.open("students.txt", ios::in);
	if (inputFile.is_open()) {
		inputFile >> g1054;
		inputFile.close();
		cout << g1054;
	}

	ofstream report;
	report.open("list.txt", ios::out | ios::trunc);
	if (report.is_open()) {
		report << endl << "\t" << g1054.name <<
			" team members";
		for (int i = 0; i < g1054.noStudents; i++) {
			report << endl << i + 1 << ". " << g1054.list[i];
		}
		report.close();
	}

	//work with binary files
	ofstream saveFile;
	saveFile.open("Students.bin", 
		ios::out | ios::binary | ios::trunc);
	if (saveFile.is_open()) {

		//DON'T DO IT
		//saveFile.write((char*)&g1054, sizeof(Team));
		
		//write the number of students
		saveFile.write((char*)&g1054.noStudents, sizeof(int));
		//determine the size of the team name
		int nameSize = strlen(g1054.name) + 1;
		saveFile.write((char*)&nameSize, sizeof(int));
		//write the name
		saveFile.write(g1054.name, nameSize*sizeof(char));
		//write the students
		for (int i = 0; i < g1054.noStudents; i++) {
			//write the code
			saveFile.write((char*)&g1054.list[i].code, sizeof(int));
			//write the student name
			saveFile.write(g1054.list[i].name, 
				sizeof(g1054.list[i].name));
		}
		saveFile.close();
	}
	cout << endl << "Data has been saved !";
	
	ifstream inputFile2;
	inputFile2.open("Students.bin",
		ios::in | ios::binary);
	if (inputFile2.is_open()) {
		Team copy;
		cout << copy;
		//WILL NOT WORK
		//inputFile2.read((char*)&copy, sizeof(Team));

		//read the number of students
		inputFile2.read((char*)&copy.noStudents, sizeof(int));
		int temp;
		//read the team name size
		inputFile2.read((char*)&temp, sizeof(int));
		delete [] copy.name;
		copy.name = new char[temp];
		inputFile2.read(copy.name, temp);
		//read the students
		delete [] copy.list;
		copy.list = new Student[copy.noStudents];
		for (int i = 0; i < copy.noStudents; i++) {
			int code;
			inputFile2.read((char*)&code, sizeof(int));
			copy.list[i].setCode(code);
			char buffer[50];
			inputFile2.read(buffer, sizeof(buffer));
			copy.list[i].setName(buffer);
		}

		cout << endl << "Data recovered !";
		cout << copy;
		inputFile2.close();
	}
}