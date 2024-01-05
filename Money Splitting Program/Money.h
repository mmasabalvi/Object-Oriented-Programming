#include<iostream>
using namespace std;

class Cent
{
private:


public:
	int cent;
	Cent();
	Cent(int);

};


class Nickel
{
private:


public:
	int nickel;
	Nickel();
	Nickel(int);

};


class Quarter
{
private:


public:
	int quarter;
	Quarter();
	Quarter(int);

};


class Dollar
{
private:


public:
	int dollar;
	Dollar();
	Dollar(int);

};

class Money
{
private:
	float money;

	Dollar D;
	Quarter Q;
	Nickel N;
	Cent C;

public:
	Money();
	Money(double);

	void setCent(int);
	int getCent();

	void setNickel(int);
	int getNickel();

	void setQuarter(int);
	int getQuarter();

	void setDollar(int);
	int getDollar();

	void setMoney(double);
	double getMoney();

	//Implement getters and setter functions
	Money operator+(Money m);
	Money operator-(Money m);

	Money operator+(Dollar d);
	Money operator-(Dollar d);

	Money operator+(Nickel d);
	Money operator-(Nickel d);

	Money operator+(Quarter d);
	Money operator-(Quarter d);

	Money operator+(Cent d);
	Money operator-(Cent d);

	Money operator ++();
	Money operator --();

	//bool operator>=();
	//bool operator<=();

	Quarter operator!();

	Nickel operator~();

	Money operator/(int n);

	Money operator*(int n);
};


