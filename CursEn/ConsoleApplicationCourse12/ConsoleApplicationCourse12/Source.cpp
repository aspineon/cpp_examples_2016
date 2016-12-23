#include <iostream>
using namespace std;

class Product {
protected:
	int code;
	char name[50];
	float price;
	//const int id;


public:
	Product() {
		cout << endl << "Default product";
		code = 0;
		price = 0.0;
		strcpy(name, "");
	}
	Product(int Code, float Price, char* Name, int Id) {
		cout << endl << "Known product";
		code = Code;
		price = Price;
		strcpy(name, Name);
	}
	char* getName() {
		return  name;
	}
	float getPrice() {
		return price;
	}

	int getCode() {
		return code;
	}

	virtual void print() {
		cout << endl << "The product "
			<< name << " (" << code << ")"
			<< " has a price of "
			<< price << " RON";
	}

	~Product() {
		cout << endl << "Product destroyed";
	}

	virtual void doSomething() = 0; //pure method
};

//inheritance
//is a relation
class PromotionalProduct :public Product {
	float discount;
public:
	PromotionalProduct()
		:Product(1000, 0, "Default promotional product", 0) {
		cout << endl << "Default promotional product";
		//this->code = 1000;
		//this->price = 0;
		//strcpy(name, "Default promotional product");
		discount = 0.1;	//default set to 10%
	}
	PromotionalProduct(int Code,
		char* Name, float Price, float Discount, int ID)
		:Product(Code, Price, Name, ID) {
		//this->code = Code;
		//this->price = Price;
		//strcpy(name, Name);
		discount = Discount;	//default set to 10%
	}
	~PromotionalProduct() {
	}

	//overriding the base class version of print
	void print() {
		cout << endl << "The product "
			<< name << " (" << code << ")"
			<< " has a price of "
			<< price << " RON"
			<< " and it has a discount of "
			<< discount * 100 << "%";
	}

	void printNew() {
		cout << endl << "The product "
			<< name << " (" << code << ")"
			<< " has a price of "
			<< price << " RON"
			<< " and it has a discount of "
			<< discount * 100 << "%";
	}

	void DoSomething() {

	}

	void doSomething() {

	}
};

void main() {
	//Product p1;
	Product p2(1, 2.5, "Still water", 1);

	//p1.print();
	p2.print();

	cout << endl << "Working with extended classes";
	PromotionalProduct pp1;
	pp1.print();
	PromotionalProduct pp2(2, "Toy", 100, 0.3, 1);
	cout << endl << "Test print after overriding it";
	pp2.print();
	pp2.printNew();

	//Product listP[5];
	//PromotionalProduct listPP[5];

	//pp2 = p2;
	p2 = pp2;
	p2.print();

	cout << endl << "Working with arrays";

	Product list[5];
	list[0] = Product(1, 2.5, "Pepsi", 1);
	list[1] = PromotionalProduct(2,
		"Drone", 400, 0.25, 1);
	list[2] = Product(1, 2.5, "Coca-Cola", 1);
	list[3] = PromotionalProduct(2,
		"Bike", 400, 0.25, 1);
	list[4] = Product(1, 2.5, "Still water", 1);

	for (int i = 0; i < 5; i++) {
		list[i].print();
	}

	Product* list2[5];
	list2[0] = new Product(1, 2.5, "Pepsi", 1);
	list2[1] = new PromotionalProduct(2,
		"Drone", 400, 0.25, 1);
	list2[2] = new Product(1, 2.5, "Coca-Cola", 1);
	list2[3] = new PromotionalProduct(2,
		"Bike", 400, 0.25, 1);
	list2[4] = new Product(1, 2.5, "Still water", 1);

	cout << endl << "Working with pointers";
	for (int i = 0; i < 5; i++) {
		list2[i]->print();
	}
}