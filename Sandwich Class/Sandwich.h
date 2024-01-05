//#ifndef HEADER1_H
#include<iostream>
//#define	HEADER1_H
using namespace std;

class Sandwich {

private:

	char name[50];
	char filling[50];
	char size[50];
	bool is_ready;
	double price;

public:

	//bool x;
	//Default Const
	Sandwich();

	//Parametrized Const
	Sandwich(char* fillingVal, double priceVal);
	Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status);

	//Copy Const
	Sandwich(const Sandwich& sandwich);

	//Setters
	void setFilling(char* fillingVal);
	void setPrice(double priceVal);
	void setName(char* nameVal);
	void setSize(char* sizeVal);
	void setReady(bool x);

	//Getters
	char* getFilling();
	double getPrice();
	char* getName();
	char* getSize();
	bool getReady();

	//Calc Functions
	void makeSandwich();
	bool check_status();

};

//#endif
