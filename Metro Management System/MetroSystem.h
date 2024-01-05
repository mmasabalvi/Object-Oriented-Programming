#include<iostream>
using namespace std;


struct MetroStation 
{
	char* stationName;

	MetroStation* nextStation;

	MetroStation* previousStation;

	MetroStation();
	
	MetroStation(const char*);

	static int num;
};
int MetroStation::num = 1;

class MetroSystem
{
private:
	MetroStation * Metro;

public:
	MetroSystem();
	MetroStation* getPtr();
	void setPtr(MetroStation*);
	MetroSystem& operator+(MetroStation& obj);
	MetroSystem operator-(MetroStation& obj); 
	MetroSystem& operator=(MetroStation& obj);

	friend ostream& operator<<(ostream& out, MetroSystem& obj);
	friend istream& operator>>(istream& in, MetroStation& obj);
};
