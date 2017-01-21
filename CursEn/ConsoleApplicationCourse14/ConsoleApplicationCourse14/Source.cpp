#include <iostream>
#include <string>
#include <set>
#include <list>
#include <map>

using namespace std;




class Flower {

};
class Box {
	char* content;
public:
	Box(char* value) {
		content = value;
	}

};



template <typename a> class TemplateBox {
	a content;

public:
	TemplateBox(a value) {
		cout << endl << "Template constructor";
		this->content = value;
	}

	bool operator>(TemplateBox& const box) {
		return (this->content > box.content);
	}
};

//specilization of the template constructor for char*
TemplateBox<char*>::TemplateBox(char* value) {
	cout << endl << "Specialized constructor for char*";
	this->content = new char[strlen(value) + 1];
	strcpy(content, value);
}

bool TemplateBox<char*>::operator>(TemplateBox& const box) {
	if (strcmp(this->content, box.content) == 1)
		return true;
	else
		return false;
}



void doSomething(int* values, int no) {
	if (values == NULL) {
		//throw exception("Received null");
		//throw new exception("Received null");
		throw "Received null";
	}
	for (int i = 0; i < no; i++)
		cout << " " << values[i];

	cout << endl << "Method terminated";
}

int sum(int a, int b) {
	return a + b;
}

int sum(int a, int b, int ...) {
	return 0;
}


class NoNameException :public exception {

};

void main(int argc, char** argv) {
	
	//template

	int value = 34;
	Box intBox((char*) &value);
	Flower flower;
	Box flowerBox((char*) &flower);
	Box flowerBox2((char*) &value);

	TemplateBox<int> b1(23);
	TemplateBox<Flower> b2(flower);
	TemplateBox<char*> b3("John");

	//STL examples
	string name;
	name = "John";
	name = "Alice";
	string fullName = "Alice " + name;

	cout << endl << "Name:" << fullName;

	list<string> names;
	names.push_back("Jonh");
	names.push_back("Alice");
	names.push_back("Bianca");


	//for (int i = 0; i < names.size(); i++) {
	//	cout << endl << names[i];
	//}
	list<string>::iterator it;
	for (it = names.begin(); it != names.end(); it++) {
		cout << endl << *it;
	}

}