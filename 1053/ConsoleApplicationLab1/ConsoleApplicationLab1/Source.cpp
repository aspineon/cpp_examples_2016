#include <iostream>

void methodReadANumber(int *address);

void main() {
	int vb1 = 10;
	int vb2 = 20;
	int *pointer_1;
	void *pointer_2;
	char *pointer_3;

	pointer_1 = (int*)100;
	pointer_3 = (char*) 200;
	*pointer_1 = 100;

	pointer_1 += 1;
	pointer_3 += 1;

	pointer_1 = &vb1;
	*pointer_1 = 30;

	std::cout << std::endl << "vb1 = " << vb1;
	std::cout << std::endl << " address of vb1  = "
		<< pointer_1;

	methodReadANumber(&vb1);
	//methodReadANumber(pointer_1);

	std::cout << std::endl << "vb1 = " << vb1;

}

void methodReadANumber(int *address) {
	//int vb1;
	std::cout << " Give us a number:";
	std::cin >> *address;
	//*address = vb1;
}