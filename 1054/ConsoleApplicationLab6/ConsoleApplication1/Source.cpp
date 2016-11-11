#include <iostream>
using namespace std;

//this source code has a bug that prevents the execution

class FidelityCard {
	char owner[50];
	int *points;
	int nrPayments;
public:
	FidelityCard(char* name) {
		strcpy(owner, name);
		this->points = NULL;
		nrPayments = 0;
	}
	~FidelityCard() {
		delete [] points;
	}
	FidelityCard(FidelityCard& card) {
		strcpy(this->owner, card.owner);
		this->points = new int[card.nrPayments];
		for (int i = 0; i < card.nrPayments; i++)
			this->points[i] = card.points[i];
		this->nrPayments = card.nrPayments;
	}

	int totalPoints() {
		int sum = 0;
		for (int i = 0; i < nrPayments; i++)
			sum += this->points[i];
		return sum;
	}

	void displayData() {
		cout << endl << "The client " << owner
			<< " has a total of " << this->totalPoints()
			<< " points";
	}

	void setPoints(int* values, int n) {
		delete [] this->points;
		this->points = new int[n];
		for (int i = 0; i < n; i++)
			points[i] = values[i];
		nrPayments = n;
	}

	//overload =
	void operator=(FidelityCard c) {
		strcpy(this->owner, c.owner);
		delete [] points;
		this->setPoints(c.points, c.nrPayments);
	}

	int* getPoints() {
		return this->points;
	}
	int getNoPoints() {
		return this->nrPayments;
	}
};

FidelityCard operator+(FidelityCard& c, int value) {
	FidelityCard result = c;
	int * newPoints = new int[c.getNoPoints() + 1];
	for (int i = 0; i < c.getNoPoints(); i++)
		newPoints[i] = c.getPoints()[i];
	newPoints[c.getNoPoints()] = value;
	result.setPoints(newPoints, c.getNoPoints() + 1);
	//avoid the memory leak
	delete [] newPoints;
	return result;
}

void main() {
	FidelityCard card1("John");
	card1.displayData();

	int values [] = { 10,20,30 };
	char* names [] = { "Mike", "Alice" };

	card1.setPoints(values, 3);
	card1.displayData();

	//copy constructor
	FidelityCard clone = card1;
	clone.displayData();

	FidelityCard card2("Alice");
	card2 = card1;

	card2 = card2 + 10;

	card2.displayData();
}