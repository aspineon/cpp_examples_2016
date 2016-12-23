#include <iostream>
using namespace std;

//abstract class
class ISell {
public:
	virtual float getSellingPrice() = 0;
};

//abstract class
class Toy {
protected:
	char minAge;
	char name[50];
	float price;
public:
	float getPrice() {
		return this->price;
	}
	//virtual pure method - abstract
	virtual void getDescription() = 0;

	Toy(char Age, char* Name, float Price) {
		minAge = Age;
		strcpy(name, Name);
		price = Price;
	}
};

class WoodToy :public Toy {
	float weight;
public:
	WoodToy(char Age,
		char* Name, float Price, float Weight) 
		:Toy(Age,Name,Price) {
		this->weight = Weight;
	}

	void getDescription() {
		cout << endl << "The wood toy "
			<< name << " weights " << weight << " kg";
	}
};

enum AccType {AAA = 10,AA = 20,L14};

class ElectricToy:public Toy {
	int noBatteries;
	AccType type;
public:
	void getDescription() {
		cout << endl << "The " << this->name
			<< " requires " << noBatteries
			<< " batteries of type " << type;
	}

	ElectricToy(char Age, char* Name, float Price,
		int No, AccType Type)
	:Toy(Age,Name,Price){
		this->noBatteries = No;
		this->type = Type;
	}
};

class SmartToy:public Toy {
protected:
	float screenSize;
public:
	SmartToy(char Age, char* Model, float Price,
		float Size) :Toy(Age, Model, Price) {
		this->screenSize = Size;
	}
};

class SmartWatch :public SmartToy,public ISell {
public:
	void getDescription() {
		cout << endl << "The smartwatch, model "
			<< name << " has a screen size of "
			<< screenSize << " inch";
	}

	SmartWatch(char Age, char* Model, float Price,
		float ScreenSize)
	:SmartToy(Age,Model,Price,ScreenSize){

	}

	float getSellingPrice() {
		return this->getPrice();
	}
};

class Pet:public ISell {
	char type[50];
public:
	Pet(char* type) {
		strcpy(this->type, type);
	}

	float getSellingPrice() {
		return 0;
	}
};

void main() {
	//Toy toy(3, "Doll", 25);
	Toy *toy = NULL;
	WoodToy w(3,"Horse",35,0.8);

	Toy* presents[5];
	Toy* *presents2 = new Toy*[5];

	//up-casting
	//don't use addresses of stack objects
	//presents[0] = &w;
	presents[0] = new WoodToy(3, "Horse", 35, 0.8);
	presents[1] = new ElectricToy(
		10, "RC Tank", 68,4,AccType::AAA);
	presents[2] = new SmartWatch(14, "Eboda", 99, 4);
	presents[3] = new ElectricToy(
		10, "RC Rally car", 68, 4, AccType::AAA);
	presents[4] = new WoodToy(3, "Doll", 35, 0.8);

	float sum = 0;
	for (int i = 0; i < 5; i++) {
		presents[i]->getDescription();
		sum += presents[i]->getPrice();
	}
	cout << endl << "Total value of presents:" << sum;

	ISell* thingsToSell[2];
	thingsToSell[0] = new SmartWatch(14, "Eboda", 99, 4);
	thingsToSell[1] = new Pet("cat");

	for (int i = 0; i < 2; i++)
		cout<<endl<<"Price:"
		<<thingsToSell[i]->getSellingPrice();

}