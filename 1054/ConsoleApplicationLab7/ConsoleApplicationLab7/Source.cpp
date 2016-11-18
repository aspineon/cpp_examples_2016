#include <iostream>
using namespace std;

//this source code has a bug that prevents the execution

class FidelityCard {
	const int id;
	char owner[50];
	int *points;
	int nrPayments;
	static int noCards;
public:
	FidelityCard(char* name):id(noCards) {
		FidelityCard::noCards += 1;
		strcpy(owner, name);
		this->points = NULL;
		nrPayments = 0;
	}
	~FidelityCard() {
		delete [] points;
	}
	FidelityCard(FidelityCard& card):id(noCards++) {
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
		this->setPoints(c.points, c.nrPayments);
	}

	int* getPoints() {
		return this->points;
	}
	int getNoPoints() {
		return this->nrPayments;
	}

	char* getName() {
		return this->owner;
	}

	friend istream& operator>>(istream& input, FidelityCard& c);


	int& operator[](int index) {
		if (index >= 0 && index < this->nrPayments)
			return this->points[index];
		else
			throw exception("Wrong index");
	}
};

int FidelityCard::noCards = 0;

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

FidelityCard operator+(int value, FidelityCard& c) {
	return c + value;
}

istream& operator>>(istream& input, FidelityCard& c) {
	cout << endl << "Card owner:";
	input >> c.owner;

	//char temp[1000];
	//input >> temp;
	//delete [] c.owner;
	//c.owner = new char[strlen(temp) + 1];
	//strcpy(c.owner, temp);

	cout << endl << "No payments:";
	input >> c.nrPayments;
	delete [] c.points;
	c.points = new int[c.nrPayments];
	for (int i = 0; i < c.nrPayments; i++) {
		cout << endl << "Points for payment " << i + 1 << ": ";
		input >> c.points[i];
	}

	return input;
}

ostream& operator<<(ostream& out, FidelityCard& c) {
	out << "Owner :" << c.getName();
	out << "Total points: " << c.totalPoints();
	return out;
}

enum tipS {ID, IF, FR};

tipS getTip(int cod) {

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
	card2 = 10 + card2;

	card2.displayData();

	cin >> card2;
	cout << card2;

	card2[1] = 99;
	cout << endl << "Payment 2 points " << card2[1];

	tipS tip;
	int tipStudent;
	cin >> tipStudent;
	if (tipStudent == 1)
		tip = tipS::FR;
}