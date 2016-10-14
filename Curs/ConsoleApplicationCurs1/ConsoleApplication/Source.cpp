#include <iostream>

using namespace std;


void interschimbareValori(int a, int b);
void interschimbareValori2(int* pa, int* pb);

void main() {
	int A;
	int vb1 = 0xA; // 10
	int vb2 = 20;
	char c;
	float vb3;
	short int vb4;
	unsigned int vb5;

	void *pointer = (void*)100;
	int* pointerInt = (int*)200;
	char* pointerChar = (char*)300;

	//pointer += 1;
	pointerInt += 1;
	pointerChar += 1;

	//pointerInt = &vb1;
	//pointerInt = &vb2;
	//*pointerInt = 99; //vb2 = 99


	std::cout << "\n vb1 = " << vb1;
	cout << endl << " vb2 = " << vb2;

	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;

	std::cout << "\n vb1 = " << vb1;
	cout << endl << " vb2 = " << vb2;

	interschimbareValori2(&vb1, &vb2);

	std::cout << "\n vb1 = " << vb1;
	cout << endl << " vb2 = " << vb2;
}

void interschimbareValori(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void interschimbareValori2(int* pa, int* pb) {
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}