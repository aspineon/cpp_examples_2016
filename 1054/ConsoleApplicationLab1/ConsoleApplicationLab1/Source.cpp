#include <iostream>
using namespace std;


int methodReadANumber();
int methodRead2Numbers(int* addDestination);
void methodRead2Numbers(
	int* addDestination1,
	int* addDestination2);

void main() {
	int vb1 = 10;
	int vb2 = 20;
	//define a pointer
	int *vb_pointer = (int*)100;
	void *vb_pointer2;
	char *vb_pointer3 = (char*)200;
	vb_pointer += 1; //-> 104
	vb_pointer3 += 1; //->201

	vb_pointer = &vb1;
	std::cout << endl << "vb1 = " << vb1;
	std::cout << std::endl<< "vb1 = " << *vb_pointer;

	vb1 = methodReadANumber();
	cout << endl << "vb1 = " << vb1;

	vb1 = methodRead2Numbers(&vb2);
	cout << endl << "vb1 = " << vb1;
	cout << endl << "vb2 = " << vb2;

	methodRead2Numbers(&vb1, &vb2);
	cout << endl << "vb1 = " << vb1;
	cout << endl << "vb2 = " << vb2;
}

int methodReadANumber() {
	int vb1;
	cout << endl << "Give us a number:";
	cin >> vb1;
	return vb1;
}

int methodRead2Numbers(int* addDestination) {
	int vb1;
	int vb2;
	cout << endl << "Give us the 1st number:";
	cin >> vb1;
	cout << endl << "Give us the 2nd number:";
	cin >> vb2;
	*addDestination = vb2;
	return vb1;
}

void methodRead2Numbers(
	int* addDestination1, 
	int* addDestination2) 
{
	cout << endl << "Give us the 1st number:";
	cin >> *addDestination1;
	cout << endl << "Give us the 2nd number:";
	cin >> *addDestination2;
}