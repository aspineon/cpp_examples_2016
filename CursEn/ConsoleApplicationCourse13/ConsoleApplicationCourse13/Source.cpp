#include <iostream>
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

template <typename a> class TemplateBox{
	a content;
};

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
	//the first argument is the exe name & full path

	if (argc >= 2) {
		cout << endl << "The first:" << argv[0];
		cout << endl << "The second:" << argv[1];
	}

	try {
		int array [] = { 1,2,3,4 };
		doSomething(NULL, 4);
	}
	catch (exception e) {
		cout << endl << "Error message: " << e.what();
	}

	catch (out_of_range error) {
		cout << endl << "Received an out of range exception";
	}
	catch (out_of_range* error) {
		cout << endl << "Received an out of range exception";
	}
	catch (char* msg) {
		cout << endl << msg;
	}
	catch(...) {
		cout << endl << "Generic error";
	}

	//template

	int value = 34;
	Box intBox((char*)&value);
	Flower flower;
	Box flowerBox((char*)&flower); 
	Box flowerBox2((char*) &value);

	TemplateBox<int> b;
	TemplateBox<Flower> b;
}