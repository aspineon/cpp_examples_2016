#include <iostream>
using namespace std;

class AgeException :public exception {
public:
	AgeException(char* msg):exception(msg) {

	}
};

class NameException :public exception {

};



class Student {
	char name[10];
	int age;
public:
	Student() {

	}
	Student(char* Name, int Age) {
		if (Age < 10 || Age > 100)
			throw AgeException("The age value is wrong");
		if (Name == NULL)
			throw new NameException();
		if (strlen(Name) > 9)
			throw "The name is too long";
		strcpy(name, Name);
		this->age = Age;
	}
	void display() {
		cout << endl << "The student "
			<< name << " is " << age << " years old.";
	}
};

//template Box
template <typename T, typename R> class Box {
	T content;
	R weight;
public:
	Box(T Content, R Weight) {
		this->content = Content;
		this->weight = Weight;
	}
	void display() {
		cout << endl << "The box content "
			<< this->content << " weights "
			<< this->weight;
	}

};

//function specialization
void Box<Student,float>::display(){
	cout << endl << "The stundent weights "
		<< this->weight;
}

Box<char*, int>::Box(char* Content, int Weight) {
	this->content = new char[strlen(Content) + 1];
	strcpy(content, Content);
	this->weight = Weight;
}


void main() {
	char* name = "John";
	int age;

	cout << endl << "The student age:";
	cin >> age;

	try {
		Student s(name, age);
		s.display();

		Box<char*,int> email("Question", 0);
		email.display();
		Box<int, float> something(23, 1.5);
		something.display();
		Box<Student, float> student(s, 54);
		student.display();

	}

	catch (NameException*) {
		cout << endl << "You are missing the name";
	}
	catch (AgeException e) {
		cout << endl << "Wrong age. Reason:"
			<< e.what();
	}
	catch (exception* ex) {
		cout << endl << "A problem:"
			<< ex->what();
	}
	catch (exception ex) {
		cout << endl << "A problem:"
			<< ex.what();
	}
	catch (...) {
		cout << endl << "Houston we have a problem !";
	}

}