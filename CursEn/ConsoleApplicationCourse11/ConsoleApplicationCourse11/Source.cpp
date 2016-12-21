#include <iostream>
using namespace std;

class Product {
protected:
	int code;
	char name[50];
	float price;
	const int id;


public:
	//Product() {
	//	cout << endl << "Default product";
	//	code = 0;
	//	price = 0.0;
	//	strcpy(name, "");
	//}
	Product(int Code, float Price, char* Name, int Id):id(Id) {
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

	void print() {
		cout << endl << "The product "
			<< name << " ("<<code<<")"
			<<" has a price of "
			<< price << " RON";
	}

	~Product() {
		cout << endl << "Product destroyed";
	}
};

//inheritance
//is a relation
class PromotionalProduct:public Product {
	float discount;
public:
	PromotionalProduct()
		:Product(1000,0,"Default promotional product",0) {
		cout << endl << "Default promotional product";
		//this->code = 1000;
		//this->price = 0;
		//strcpy(name, "Default promotional product");
		discount = 0.1;	//default set to 10%
	}
	PromotionalProduct(int Code,
		char* Name, float Price, float Discount, int ID)
	:Product(Code,Price,Name,ID){
		//this->code = Code;
		//this->price = Price;
		//strcpy(name, Name);
		discount = Discount;	//default set to 10%
	}
	~PromotionalProduct() {
	}
};

void main() {
	//Product p1;
	Product p2(1, 2.5, "Still water",1);

	//p1.print();
	p2.print();

	cout << endl << "Working with extended classes";
	PromotionalProduct pp1;
	pp1.print();
	PromotionalProduct pp2(2, "Toy", 100, 0.3,1);
	pp2.print();

}