#include"22i-1004_Q5.h"

Cent::Cent()
{
	cent = 0;
}

Cent::Cent(int c)
{
	cent = c;
}

Nickel::Nickel()
{
	nickel = 0;
}

Nickel::Nickel(int n)
{
	nickel = n;
}




Quarter::Quarter()
{
	quarter = 0;
}

Quarter::Quarter(int q)
{
	quarter = q;
}


Dollar::Dollar()
{
	dollar = 0;
}

Dollar::Dollar(int d)
{
	dollar = d;
}



Money::Money()
{
	D.dollar = 0;
	Q.quarter = 0;
	N.nickel = 0;
	C.cent = 0;
}

Money::Money(double x)
{
	money = x;

	int y = static_cast<int>(money * 100);

	int d = y / 100;
	D.dollar = d;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c = ((y % 100) % 25) % 5;
	C.cent = c;

}

void Money::setCent(int c)
{
	C.cent = c;
}

int Money::getCent()
{
	return C.cent;
}

void Money::setNickel(int n)
{
	N.nickel = n;
}

int Money::getNickel()
{
	return N.nickel;
}

void Money::setQuarter(int q)
{
	Q.quarter = q;
}

int Money::getQuarter()
{
	return Q.quarter;
}

void Money::setDollar(int d)
{

	D.dollar = d;
}

int Money::getDollar()
{
	return D.dollar;
}


void Money::setMoney(double d)
{

	money = d;
}

double Money::getMoney()
{
	return money;
}

Money Money::operator+(Money m)
{
	money += m.money;

	int y = static_cast<int>(money * 100);

	int d = y / 100;
	D.dollar = d;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;

}


Money Money::operator-(Money m)
{
	money -= m.money;

	int y = static_cast<int>(money * 100);

	int d = y / 100;
	D.dollar = d;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;

}

Money Money::operator+(Dollar d)
{
	money += d.dollar;

	D.dollar += d.dollar;

	return *this;
}


Money Money::operator-(Dollar d)
{
	money -= d.dollar;

	D.dollar -= d.dollar;

	return *this;
}

Money Money::operator+(Nickel d)
{
	money += d.nickel;

	int y = static_cast<int>(money * 100);

	int d1 = y / 100;
	D.dollar = d1;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;
}

Money Money::operator-(Nickel d)
{
	money -= d.nickel;

	int y = static_cast<int>(money * 100);

	int d1 = y / 100;
	D.dollar = d1;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;
}

Money Money::operator+(Quarter d)
{
	money += d.quarter;

	int y = static_cast<int>(money * 100);

	int d1 = y / 100;
	D.dollar = d1;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;
}

Money Money::operator-(Quarter d)
{
	money -= d.quarter;

	int y = static_cast<int>(money * 100);

	int d1 = y / 100;
	D.dollar = d1;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;
}

Money Money::operator+(Cent d)
{
	money += d.cent;

	int y = static_cast<int>(money * 100);

	int d1 = y / 100;
	D.dollar = d1;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;
}

Money Money::operator-(Cent d)
{
	money -= d.cent;

	int y = static_cast<int>(money * 100);

	int d1 = y / 100;
	D.dollar = d1;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;
}

Money Money::operator++()
{
	int y = static_cast<int>(money * 100);

	int rem = C.cent % 25;

	if (rem != 0)
	{
		C.cent += 25 - rem;
	}

	money = static_cast<double>(C.cent) / 100.0;
	y = static_cast<int>(money * 100);

	int d1 = y / 100;
	D.dollar = d1;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;
}

Money Money::operator--()
{
	int y = static_cast<int>(money * 100);

	int rem = C.cent % 25;

	if (rem != 0)
	{
		C.cent -= rem;
	}

	money = static_cast<double>(C.cent) / 100.0;
	y = static_cast<int>(money * 100);

	int d1 = y / 100;
	D.dollar = d1;

	int q = (y % 100) / 25;
	Q.quarter = q;

	int n = ((y % 100) % 25) / 5;
	N.nickel = n;

	int c1 = ((y % 100) % 25) % 5;
	C.cent = c1;

	return *this;
}


Quarter Money::operator!()
{
	int y = static_cast<int>(money * 100);

	Quarter temp;

	temp.quarter = y / 25;

	return temp;
}

Nickel Money::operator~()
{
	int y = static_cast<int>(money * 100);

	Nickel temp;

	temp.nickel = y / 5;

	return temp;
}

Money Money::operator/(int n)
{
	int y = static_cast<int>(money * 100);

	Money temp;

	temp.money = money / n;

	return temp;
}

Money Money::operator*(int n)
{
	int y = static_cast<int>(money * 100);

	Money temp;

	temp.money = money * n;

	return temp;
}

int main()
{
	double m;
	cout << "Enter the amount of money: " << endl;
	cin >> m;

	Money M1(m);

	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;

	double m2;
	cout << "Enter the new amount of money to add: " << endl;
	cin >> m2;

	Money M2(m2);

	M1 + M2;

	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;

	double m3;
	cout << "Enter the new amount of money to subtract: " << endl;
	cin >> m3;

	Money M3(m3);

	M1 - M3;

	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;

	int d1;
	cout << "Enter Dollars to add" << endl;
	cin >> d1;

	Dollar D1(d1);

	M1 + D1;

	cout << "Dollars added" << endl;
	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;
	int d2;
	cout << "Enter Dollars to subtract" << endl;
	cin >> d2;

	Dollar D2(d2);

	M1 - D2;

	cout << "Dollars subtracted" << endl;
	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;


	int n1;
	cout << "Enter Nickels to add" << endl;
	cin >> n1;

	Nickel N1(n1);

	M1 + N1;

	cout << "Nickels added" << endl;
	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;



	int n2;
	cout << "Enter Nickels to subtract" << endl;
	cin >> n2;

	Nickel N2(n2);

	M1 + N2;

	cout << "Nickels subtracted" << endl;
	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;

	////////Same Principle for functions of Quarter and Cents, therefore not added in main

	cout << "Rounding up the Money to the nearest quarter:" << endl;
	++M1;
	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;


	cout << "Rounding down the Money to the nearest quarter:" << endl;
	--M1;
	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;

	int n;
	cout << "Money Divided by n" << endl;
	cout << "Enter n: " << endl;
	cin >> n;

	M1 / n;

	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;
	int n7;

	cout << "Money Multiplied by n" << endl;
	cout << "Enter n: " << endl;
	cin >> n7;

	M1* n7;

	cout << "Money Total Now: " << M1.getMoney() << endl;
	cout << "Money divided in Parts" << endl;
	cout << "Dollars: " << M1.getDollar() << endl;
	cout << "Quarters: " << M1.getQuarter() << endl;
	cout << "Nickels: " << M1.getNickel() << endl;
	cout << "Cents: " << M1.getCent() << endl;
}
