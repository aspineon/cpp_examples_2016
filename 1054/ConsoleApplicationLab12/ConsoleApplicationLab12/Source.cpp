#include <iostream>
using namespace std;


class Sellable {
public:
	virtual float getSellingPrice() = 0;;
};


//abstract class
class Toy {
protected:
	char minAge;
	char name[50];
	float price;
public:
	Toy(char Min, char* Name, float Price) {
		this->minAge = Min;
		strcpy(name, Name);
		price = Price;
	}
	float getPrice() {
		return price;
	}
	//virtual pure method - abstract
	virtual void getDescription() = 0;
};

enum AccType { AAA = 10, AA = 20, L14 };

class ElectricToy :public Toy {
	int noAcc;
	AccType type;
public:
	void getDescription() {
		cout << endl << "The toy "
			<< name << " requires "
			<< noAcc << " " << type
			<< " batteries";
	}
	ElectricToy(char Age, char* Name,
		float Price, int No, AccType Type)
		:Toy(Age, Name, Price) {
		noAcc = No;
		type = Type;
	}
};

class WoodToy :public Toy {
private:
	float weight;
public:
	//override the abstract method
	void getDescription() {
		cout << endl << "The wood toy is a "
			<< name << " and it weights "
			<< weight;
	}

	WoodToy(char Age,
		char* Name,
		float Price,
		float Weight) :Toy(Age, Name, Price) {
		this->weight = Weight;
	}
};

class Pet:public Sellable {
	char type[50];
public:
	Pet(char *Type) {
		strcpy(type, Type);
	}

	float getSellingPrice() {
		return 0;
	}
};


//another abstract class
class SmartToy :public Toy {
protected:
	float screenSize;

public:
	SmartToy(char Age, char* Model,
		float Price, float Screen)
		:Toy(Age, Model, Price) {
		screenSize = Screen;
	}
};

class SmartWatch :public SmartToy,public Sellable {
public:
	void getDescription() {
		cout << endl << "The smartwatch, model "
			<< name << " has a screen size of "
			<< screenSize << " inches";
	}

	SmartWatch(int Age, char* Model, float price,
		float Screen)
		:SmartToy(Age, Model, price, Screen) {

	}

	float getSellingPrice() {
		return this->getPrice();
	}
};

void main() {
	//Toy toy(3,"Doll",23.7);
	//using Toy as a reference type - pointer
	Toy *toy;

	Toy* presents[5];
	Toy* *presents2 = new Toy*[5];

	WoodToy woodToy(6, "Horse", 35, 0.8);
	//avoid getting addresses of stack based objects
	//presents[0] = &woodToy;

	presents[0] = new WoodToy(
		6, "Horse", 35, 0.8);
	presents[1] = new ElectricToy(
		10, "RC Tank", 190, 4, AccType::AAA);
	presents[2] = new SmartWatch(10, "Eboda", 99, 4.0);
	presents[3] = new ElectricToy(
		10, "RC Rally car", 290, 4, AccType::L14);
	presents[4] = new WoodToy(
		6, "Doll", 35, 0.8);

	float sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += presents[i]->getPrice();
		presents[i]->getDescription();
	}
	cout << endl << "Total value of presents list:"
		<< sum;

	Sellable* list[2];
	list[0] = new Pet("cat");
	list[1] = new SmartWatch(10, "Eboda", 99, 4.0);

	for (int i = 0; i < 2; i++)
		cout << endl << "Price:" << list[i]->getSellingPrice();

}