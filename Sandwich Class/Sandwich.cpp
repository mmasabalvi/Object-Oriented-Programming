#include "Sandwich.h"

//Default Const
Sandwich::Sandwich()
{
	name[50] = '\0';
	filling[50] = '\0';
	size[50] = '\0';
	is_ready = 0;
	price = 0;
}

//Parametrized Const
Sandwich::Sandwich(char* fillingVal, double priceVal)
{
	name[50] = '\0';
	setFilling(fillingVal);
	price = priceVal;
	is_ready = 0;
	price = 0;
}

Sandwich::Sandwich(char* fillingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status)
{
	setFilling(fillingVal);
	price = priceVal;
	setName(nameVal);
	setSize(sizeVal);
	is_ready = ready_status;
}


// Copy Const
//Sandwich::Sandwich(const Sandwich& sandwichh)
//{
//	//name = sandwichh.name;
//	setName(sandwichh.getName());
//	setFilling(sandwichh.filling);
//	setSize(sandwichh.size);
//	price = sandwichh.price;
//	is_ready = sandwichh.is_ready;
//}

//Setter Functions

void Sandwich::setFilling(char* fillingVal)
{
	int i = 0;
	while (fillingVal[i] != '\0')
	{
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		filling[j] = fillingVal[j];
	}

	filling[i] = '\0';
}

void Sandwich::setPrice(double priceVal)
{
	price = priceVal;
}

void Sandwich::setName(char* nameVal)
{
	int i = 0;
	while (nameVal[i] != '\0')
	{
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		name[j] = nameVal[j];
	}
	name[i] = '\0';
}

void Sandwich::setSize(char* sizeVal)
{
	int i = 0;
	while (sizeVal[i] != '\0')
	{
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		size[j] = sizeVal[j];
	}
	size[i] = '\0';
}

void Sandwich::setReady(bool x)
{
	is_ready = x;

}

//Getter Functions

char* Sandwich::getFilling()
{
	return filling;
}

double Sandwich::getPrice()
{
	return price;
}

char* Sandwich::getName()
{
	return name;
}

char* Sandwich::getSize()
{
	return size;
}

bool Sandwich::getReady()
{
	return is_ready;
}

//Calc Functions

void Sandwich::makeSandwich()
{
	if (getFilling() != NULL)           //as make sandwich inside class so no need for Sandwich::getfillling()
	{
		setReady(1);					 // can i directly do is_ready=1, if its public or private
		cout << "Sandwich already made" << endl;
	}
	
	else
	{
		cout << "Making Sndwich..." << endl;
	}
}

bool Sandwich::check_status()
{
	if (getReady() == 1)
	{
		return true;
	}

	else
	{
		return false;
	}
}



int main()
{

	char filling1[] = "Cheese";
	char name1[] = "Sandwich 1";
	char size1[] = "Medium";

	cout << "Type 1: " << endl;
	Sandwich type1(filling1, 700, name1, size1, false);

	cout << type1.getName() << endl;
	cout << type1.getFilling() << endl;
	cout << type1.getPrice() << endl;
	cout << type1.getSize() << endl;
	cout << type1.check_status() << endl;
	type1.makeSandwich();

	char filling2[] = "Chicken";
	char name2[] = "Sandwich 2";
	char size2[] = "Small";

	cout << "\nType 2: " << endl;
	Sandwich type2(filling2, 400, name2, size2, true);

	cout << type2.getName() << endl;
	cout << type2.getFilling() << endl;
	cout << type2.getPrice() << endl;
	cout << type2.getSize() << endl;
	cout << type2.check_status() << endl;
	type2.makeSandwich();


	char filling3[] = "Beef";

	cout << "\nType 3: " << endl;
	Sandwich type3(filling3, 400);

	cout << type3.getFilling() << endl;
	cout << type3.getPrice() << endl;
	type3.makeSandwich();

	char filling4[] = "Mutton";
	char name4[] = "Sandwich 4";
	char size4[] = "Large";

	cout << "\nType 4: " << endl;
	Sandwich type4(filling4, 1000, name4, size4, false);

	cout << type4.getName() << endl;
	cout << type4.getFilling() << endl;
	cout << type4.getPrice() << endl;
	cout << type4.getSize() << endl;
	cout << type4.check_status() << endl;
	type4.makeSandwich();
	
	char filling5[] = "Vegetable";

	cout << "\nType 5: " << endl;
	Sandwich type5(filling5, 800);

	cout << type5.getFilling() << endl;
	cout << type5.getPrice() << endl;
	type5.makeSandwich();

}

	
