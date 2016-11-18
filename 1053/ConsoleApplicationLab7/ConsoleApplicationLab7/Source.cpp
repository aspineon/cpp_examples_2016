#include <iostream>
using namespace std;

class FidelityCard {
	const int id;
	char owner[50];
	int* points;
	int noPayments;
	static int noCards;
public:
	FidelityCard(char* name):id(FidelityCard::noCards) {
		FidelityCard::noCards += 1;
		strcpy(this->owner, name);
		points = NULL;
		noPayments = 0;
	}
	FidelityCard(FidelityCard& card):id(++noCards) {
		strcpy(this->owner, card.owner);
		this->points = new int[card.noPayments];
		for (int i = 0; i < card.noPayments; i++)
			this->points[i] = card.points[i];
		this->noPayments = card.noPayments;
	}
	~FidelityCard() {
		delete [] this->points;
	}

	void displayData() {
		cout << endl << "Card owner: " << this->owner;
		cout << endl << "Points:";
		if (this->noPayments == 0)
			cout << "0";
		else
		{
			for (int i = 0; i < this->noPayments; i++)
				cout << " " << this->points[i];
		}
	}

	FidelityCard operator+(int value) {

		FidelityCard result = *this;

		int* newPoints = new int[this->noPayments + 1];
		for (int i = 0; i < this->noPayments; i++)
			newPoints[i] = this->points[i];
		newPoints[this->noPayments] = value;
		delete [] result.points;
		result.points = newPoints;
		result.noPayments += 1;

		return result;
	}

	void operator=(FidelityCard c) {
		strcpy(this->owner, c.owner);
		this->noPayments = c.noPayments;

		delete [] this->points;

		this->points = new int[c.noPayments];
		for (int i = 0; i < c.noPayments; i++)
			this->points[i] = c.points[i];

	}

	int getTotalPoints() {
		int s = 0;
		for (int i = 0; i < this->noPayments; i++)
			s += points[i];
		return s;
	}

	char* getName() {
		return this->owner;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->noPayments)
			return this->points[index];
		else
			throw exception("The index is wrong");
	}

	explicit operator int() {
		return this->getTotalPoints();
	}

	bool operator!() {
		if (this->noPayments == 0)
			return true;
		else
			return false;
	}

	friend istream& operator>>(istream& input, FidelityCard& c);

	friend FidelityCard operator+(int value, FidelityCard c);
};

int FidelityCard::noCards = 0;

FidelityCard operator+(int value, FidelityCard c) {
	FidelityCard result = c;

	int* newPoints = new int[c.noPayments + 1];
	for (int i = 0; i < c.noPayments; i++)
		newPoints[i] = c.points[i];
	newPoints[c.noPayments] = value;
	delete [] result.points;
	result.points = newPoints;
	result.noPayments += 1;

	return result;
}

bool operator>(FidelityCard c1, FidelityCard c2) {
	if (c1.getTotalPoints() > c2.getTotalPoints())
		return true;
	else
		return false;
}

istream& operator>>(istream& input, FidelityCard& c) {
	cout << endl<< "Owner name: ";
	input >> c.owner;

	//char temp[9000];
	//input >> temp;
	//c.owner = new char[strlen(temp) + 1];
	//strcpy(c.owner, temp);

	cout << "No of payments:";
	input >> c.noPayments;
	delete [] c.points;
	c.points = new int[c.noPayments];
	for (int i = 0; i < c.noPayments; i++) {
		cout << endl << "Points for the payment " << i + 1 << " :";
		input >> c.points[i];
	}

	return input;
}

ostream& operator<<(ostream& out, FidelityCard& c) {
	out << endl << "Owner " << c.getName();
	out << endl << "Total points " << c.getTotalPoints();
	return out;
}


void main() {
	//FidelityCard card1;
	FidelityCard card1("John");
	card1.displayData();

	//copy constructor
	FidelityCard card2 = card1;
	card2.displayData();

	FidelityCard card3("Alice");
	card3 = card1;

	card1 = card2 + 10; //card2.operator+(10);
	card1 = card1 + 20;
	card1 = 30 + card1;
	card1.displayData();

	if (card1 > card2)
		cout << endl << "Card1 has more points";

	cin >> card1;
	cout << card1;

	card1[1] = 99;
	cout << "The points of the 2nd payment are " << card1[1];
	cout << card1;

	int total = (int)card1;

	if (!card1)
		cout << endl << "It HASN'T points";
	else
		cout << endl << "It has points";

}