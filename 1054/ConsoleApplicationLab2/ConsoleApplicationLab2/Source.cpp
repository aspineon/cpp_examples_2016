#include <iostream>
using namespace std;

void main() {
	//array
	//static array of integer
	int values1[10];
	//values1 = new int[20]; //it's not possible
	//dynamic array of integers
	int* values2;

	//testing 0XCCCCC
	//values2[0] = 100;

	values1[0] = 100;

	//print array values
	for (int i = 0; i < 10; i++) {
		cout << endl << "values1[" << i << "] = " <<
			values1[i];
	}

	values2 = new int[10];
	//for (;;) {
	//	//new int[50];//memory leak
	//	//delete [] values2;
	//	values2 = new int[20];
	//}

	//array of chars
	//static
	char name1[100];
	name1[4] = 0;
	name1[1] = 48; //= '0'
	//dynamic
	char* name2;
	//print a string
	cout << endl << "The name is " << name1;

	//initialising strings
	char testName [] = "Ana";
	//testName = "Gigel";

	name2 = "Gigel"; //the constant string is on stack

	//delete [] name2;  //run time exception
	name2 = "Popescu";

	char studentName[100];
	strcpy(studentName, "Popescu");
	strcpy(studentName, "Alexandru");
	strcat(studentName, " Ionut");

	cout << endl << "Student name = " << studentName;

	char* personName;
	//1 create space in HEAP
	personName = 
		new char[strlen("Popescu Alexandru")+1];
	//2 copy the value
	strcpy(personName, "Popescu Alexandru");
	cout << endl << "Person name = " 
		<< personName;

	//change the value
	delete [] personName; //avoiding Memory leaks
	personName = new char[strlen("Test") + 1];
	strcpy(personName, "Test");

	cout << endl << "Person name = "
		<< personName;

}