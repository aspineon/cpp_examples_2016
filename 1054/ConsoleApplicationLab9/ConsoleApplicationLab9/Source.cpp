#include <iostream>
#include <fstream>
using namespace std;

class Student {
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
			report <<endl <<  i+1 << ". " << g1054.list[i];
		}
		report.close();
	}
}