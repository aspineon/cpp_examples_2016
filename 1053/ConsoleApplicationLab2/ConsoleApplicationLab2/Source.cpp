#include <iostream>
using namespace std;

void main() {
	//static arrays
	int values1[100];
	int values3[10];

	//dynamic
	int* values2;
	values2 = new int[50];

	//printing
	values1[0] = 99;
	values1[1] = 98;
	cout << endl << "First 5 values from values1";
	for (int i = 0; i < 5; i++)
		cout << " " << values1[i];


	cout << endl << "First 5 values from values2";
	for (int i = 0; i < 5; i++)
		cout << " " << values2[i];


	//change the size
	//int values1[101];

	//it's a mistake
	//values3[10] = 99;
	//values3[11] = 99;
	//values3[12] = 100;
	//values3[13] = 101;

	//cout << endl << "First 5 values from values1";
	//for (int i = 0; i < 5; i++)
	//	cout << " " << values1[i];

	//change the size
	//for (;;) {
	//	values2 = new int[51];
	//}
	//1 clean-up
	//for (;;) {
	//	delete [] values2;
	//	values2 = new int[51];
	//}

	int *temp = new int[51];
	for (int i = 0; i < 50; i++)
		temp[i] = values2[i];
	delete [] values2;
	values2 = temp;

	//values1 = new int[200];
	//delete [] values1;

	//strings
	//static string
	char name[50];
	char name2 [] = "Popescu";
	//name2 = "Ionut";

	//messing up with the ending /0
	//name2[7] = 'i'; // '\0'

	cout << endl << "Person name: " << name2;

	//dynamic string
	char* studentName;
	//studentName = "Ionut";

	studentName = new char[strlen("Ionut")+1];
	strcpy(studentName, "Ionut");

	cout << endl << "The student name is " << studentName;

	//delete [] studentName;
	//studentName = "Popescu";
	cout << endl << "The student name is " << studentName;
}