#include <iostream>
using namespace std;

class FidelityCard {
private:
	char name[50];
	int* points;
	int noPayments;

public:
	FidelityCard() {
		strcpy(name, "John Doe");
		points = NULL;
		this->noPayments = 0;
	}
	FidelityCard(char* name) {
		strcpy(this->name, name);
		points = NULL;
		noPayments = 0;
	}

	~FidelityCard() {
		cout << endl << "Destructor called!";
		delete [] this->points;
	}

	//copy constructor
	FidelityCard(FidelityCard& existingCard) {
		cout << endl << "Copy constructor called";
		strcpy(this->name, existingCard.name);
		this->noPayments = existingCard.noPayments;
		this->points = 
			new int[existingCard.noPayments];
		for (int i = 0; i < this->noPayments; i++)
			points[i] = existingCard.points[i];
	}

	//accessor methods
	//for reading
	char* getName() {
		return this->name;
	}

	int getNoPayments() {
		return this->noPayments;
	}
	//for writing
	void setPoints(int* points, int n) {
		//DON'T
		//this->points = points;

		if (this->points != NULL)
			delete [] this->points;

		this->points = new int[n];

		for (int i = 0; i < n; i++) {
			this->points[i] = points[i];
		}
		this->noPayments = n;
	}

	void addPoints(int value) {
		int *temp = 
			new int[this->noPayments + 1];
		for (int i = 0; i < noPayments; i++)
			temp[i] = points[i];
		temp[noPayments] = value;
		this->points = temp;
		this->noPayments += 1;
	}

	int* getPoints() {
		return this->points;
	}

};//class ends here

void printData(FidelityCard fc) {
	cout << endl << "Card owner: " << fc.getName();
	cout << endl << "Available points:";
	int sum = 0;
	for (int i = 0; i < fc.getNoPayments(); i++)
		sum += fc.getPoints()[i];
	cout << sum;
}

void something() {
	FidelityCard fc("Mike");
	int existingPoints [] = { 10,67,5 };
	fc.setPoints(existingPoints, 3);
}

void main() {

	something();

	FidelityCard card1;
	FidelityCard card2("Mike");
	cout << endl << "The owner name is "
		<< card2.getName();
	printData(card2);

	int existingPoints [] = { 10,67,5 };
	card2.setPoints(existingPoints, 3);

	int existingPoints2 [] = { 10,20 };
	card2.setPoints(existingPoints2, 2);
	card2.addPoints(10);

	printData(card2);
}