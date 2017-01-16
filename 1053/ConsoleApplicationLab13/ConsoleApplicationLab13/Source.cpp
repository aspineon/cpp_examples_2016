#include <iostream>
using namespace std;

class MissingNameException :public exception {

};

class AgeException :public exception {
public:
	AgeException(char* msg) :exception(msg) {

	}
};

class Student {
	char name[10];
	int age;
public:
	Student() {

	}
	Student(char* Name, int Age) {
		if (Age < 10 || Age > 100)
			throw new AgeException("Wrong age");
		if (Name == NULL)
			throw new MissingNameException();
		if (strlen(Name) > 9)
			throw "The name is too large";
		strcpy(name, Name);
		age = Age;
	}
	void display() {
		cout << endl << "The student "
			<< name << " is " << age
			<< " years old.";
	}
};

template <typename T,typename R> class Box {
	T content;
	R weight;
public:
	Box(T Content, R Weight) {
		content = Content;
		this->weight = Weight;
	}

	void display() {
		cout << endl << "The box content "
			<< content << " weights "
			<< weight;
	}
};

//specializing display for T = student
void Box<Student, int>::display() {
	cout << endl << "The student weigth is "
		<< this->weight;
}

void main() {
	char *name = "John";
	int age;

	cout << endl << "The student age:";
	cin >> age;

	try {
		Student s(name, age);
		s.display();

		Box<int,float> integerBox(23, 0);
		Box<char*, float> email("Hello", 0);
		Box<Student, int> student(s, 54);

		integerBox.display();
		email.display();
		student.display();
	}

	catch (MissingNameException* e) {
		cout << endl << "You sent NULL for name";
	}
	catch (AgeException* ex) {
		cout << endl << "Age problem"
			<< ex->what();
	}
	catch(exception* er) {
		cout << endl << "A problem: " <<
			er->what();
	}
	catch (...) {
		cout << endl << "Houston we have a problem!";
	}
	
}