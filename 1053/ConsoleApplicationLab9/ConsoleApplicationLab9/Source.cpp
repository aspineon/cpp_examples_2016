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
	Student * list;
	int noStudents;
	char* name;
public:
	Team() {
		list = NULL;
		noStudents = 0;
		name = new char[1];
		strcpy(name, "");
	}
	Team(char* teamName) {
		name = new char[strlen(teamName) + 1];
		strcpy(name, teamName);
		list = NULL;
		noStudents = 0;
	}

	friend ostream& operator<<(ostream& out, Team& t);
	friend void operator>>(ifstream& file, Team& t);
};

ostream& operator<<(ostream& out, Team& t) {
	out << endl << "Team: " << t.name;
	for (int i = 0; i < t.noStudents; i++)
	{
		out << t.list[i];
	}
	return out;
}

void operator>>(ifstream& file, Team& t) {
	char buffer[1000];
	file >> buffer;
	delete [] t.name;
	t.name = new char[strlen(buffer) + 1];
	strcpy(t.name, buffer);
	file >> t.noStudents;
	delete [] t.list;
	t.list = new Student[t.noStudents];

	for (int i = 0; i < t.noStudents; i++) {
		//file >> buffer;
		file.get();
		file.getline(buffer, 100);
		t.list[i].setName(buffer);
		int code;
		file >> code;
		t.list[i].setCode(code);
	}


}

void main() {
	Team g1053("1053");
	cout << g1053;

	ifstream inputFile;
	inputFile.open("students.txt", ios::in);
	if (inputFile.is_open()) {
		inputFile >> g1053;
		inputFile.close();
		cout << g1053;
	}

	ofstream report;
	report.open("report.txt", ios::out | ios::trunc);
	if (report.is_open()) {
		report << "\t\t" << g1053.name << " students";
		for (int i = 0; i < g1053.noStudents; i++) {
			report << endl << i + 1 << g1053.list[i];
		}
		report.close();
	}

	//serialization of Team
	ofstream saveFile;
	saveFile.open("students.bin",
		ios::out | ios::binary | ios::trunc);
	if (saveFile.is_open()) {
		//DON'T DO THIS
		//saveFile.write((char*)&g1053, sizeof(Team));

	}

	saveFile.close();

}