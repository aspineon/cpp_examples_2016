#include <iostream>

using namespace std;

void interchangeValues(int a, int b);
void interchangeValues2(int* pa, int* pb);

void main() {
	int A;
	int vb1 = 0xA;
	int vb2 = 20;
	char c;
	float vb3;
	short int vb4;

	//interchange
	int temp = vb2;
	vb2 = vb1;
	vb1 = temp;

	std::cout << "\n vb1 = " << vb1;
	cout << endl << " vb2  = " << vb2;

	interchangeValues2(&vb1, &vb2);

	std::cout << "\n vb1 = " << vb1;
	cout << endl << " vb2  = " << vb2;
}

//method for interchanging
void interchangeValues(int a, int b) {
	int temp = b;
	b = a;
	a = temp;
}


void interchangeValues2(int* pa, int* pb) {
	int temp = *pb;
	*pb = *pa;
	*pa = temp;
}