#include "22i-1004_Q3.h"

MetroSystem::MetroSystem()
{
	Metro = NULL;
}

MetroStation* MetroSystem::getPtr()
{
	return Metro;
}

void MetroSystem::setPtr(MetroStation* obj)
{
	Metro = obj;
}

MetroStation::MetroStation()
{
	stationName = NULL;
	nextStation = NULL;
	previousStation = NULL;
}

MetroStation::MetroStation(const char* name)
{
	int x = 0;

	while (name[x] != '\0')
	{
		x++;
	}

	stationName = new char[x + 1];

	for (int i = 0; i < x; i++)
	{
		stationName[i] = name[i];
	}

	stationName[x] = '\0';

	nextStation = NULL;
	previousStation = NULL;
}


MetroSystem& MetroSystem::operator+(MetroStation& obj)
{
	string name;

	cout << "Enter the Name of the Previous Station, after which the New Station should be added " << endl;
	cin >> name;

	MetroStation* ptr = Metro;

	while (ptr->stationName != name)
	{
		ptr = ptr->nextStation;
	}

	MetroStation* temp1 = ptr->nextStation;  

	ptr->nextStation = &obj;
	obj.nextStation = temp1;
	obj.previousStation = ptr;

	if (temp1 != NULL)
	{
		temp1->previousStation = &obj;
	}

	MetroStation::num += 1;
	return *this;
	
}

bool compare(const char* s1, const char* s2)
{
	int j = 0;

	while (s1[j] != '\0' && s2[j] != '\0') 
	{
		if (s1[j] != s2[j]) 
		{
			return false;
		}

		j++;
	}
	return (s1[j] == '\0' && s2[j] == '\0');
}

MetroSystem MetroSystem::operator-(MetroStation& obj)
{
	MetroStation* ptr = Metro;

	while (ptr != NULL && !compare(ptr->stationName, obj.stationName))
	{
		ptr = ptr->nextStation;
	}


	if (ptr != NULL)
	{
		MetroStation* temp1 = ptr->previousStation;
		MetroStation* temp2 = ptr->nextStation;

		if (temp1 != NULL)
		{
			temp1->nextStation = temp2;
		}

		if (temp2 != NULL)
		{
			temp2->previousStation = temp1;
		}

		

		obj.stationName = NULL;
		obj.nextStation = NULL;
		obj.previousStation = NULL;

		delete[] ptr->stationName; 
		delete ptr;

		//ptr = NULL;

		MetroStation::num -= 1;
		
	}

	else
	{
		cout << "Ptr was null" << endl;
	}
	
	

	return *this;
}

MetroSystem& MetroSystem::operator=(MetroStation& obj)
{
	if (Metro == NULL)
	{
		Metro = &obj;
	}

	else
	{
		MetroStation* ptr = Metro;

		while (ptr->nextStation != NULL)
		{
			ptr = ptr->nextStation;
		}

		ptr->nextStation = &obj;
		obj.previousStation = ptr;
	}

	MetroStation::num += 1;

	return *this;
}

 
ostream& operator<<(ostream& out, MetroSystem& obj)
{
	out << "All Metro Stations: " << endl;

	MetroStation* ptr = obj.Metro;

	int x = 1;

	while (ptr != NULL) 
	{
		if (ptr->stationName != NULL)
		{
			out << x << ". " << ptr->stationName << endl;
		}
		
		ptr = ptr->nextStation;
		x++;
	}
	out << endl;
	return out;

}

istream& operator>>(istream& in, MetroStation& obj)
{
	

	char name[50];
	in >> name;

	int x = 0;

	while (name[x] != '\0')
	{
		x++;
	}

	obj.stationName = new char[x + 1];

	for (int i = 0; i < x; i++)
	{
		obj.stationName[i] = name[i];
	}

	obj.stationName[x] = '\0';
	//MetroStation::num += 1;

	return in;
}

int main()
{
	MetroSystem system;
	int x = 1;

	cout << "Fully linked Metro System containing stations to be added by the user" << endl << endl;

	cout << "Enter the First Metro Station: " << endl;

	MetroStation* s1 = new MetroStation;

	cin >> *s1;

	system.setPtr(s1);
	
//	s1 = *system.getPtr();


	//MetroStation station[50];

	while (true)
	{
		int i = 0;

		cout << "Total Stations: " << MetroStation::num << endl;
		cout << "Main Metro Station: " << s1->stationName << endl;

		cout << "\nChoose from the following" << endl;

		cout << "[1] Add Metro Station at end" << endl;
		cout << "[2] Add Metro Station in between" << endl;
		cout << "[3] Remove Metro Station" << endl;
		cout << "[4] Display Metro Stations" << endl;
		cout << "[5] Exit Program" << endl;

		

		cin >> x;

		switch (x)
		{
		case 1: {
			MetroStation* s2 = new MetroStation;
			cout << "Enter name: ";
			cin >> *s2;
			system = *s2;
			
			
			break;
		}

		case 2: {
			MetroStation* s3 = new MetroStation;
			cout << "Enter name: ";
			cin >> *s3;
			system + *s3;
			

			break;
		}

		case 3: {
			MetroStation* s4 = new MetroStation;
			cout << "Enter name: ";
			cin >> *s4;
			system - *s4;
			

			break;
		}

		case 4: {
			cout << system;
			break;
		}

		case 5: {
			return 0;
			/*x = 0;
			break;*/
		}

		default: {
			cout << "Invalid choice. Please enter again" << endl;
			return 0;
		}
		}

		i++;
	}

	return 0;
}
