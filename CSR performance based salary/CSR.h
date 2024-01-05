//#ifndef HEADER_H
#include <iostream>
//#define HEADER_H
using namespace std;

class CSR {

private:

	int csrID;
	char csrName[100];
	int hours;
	int complaintsResolved;
	float payrate;
	float wage;
	static int totalComplaintsResolved;

public:

	//Default Constructor
	CSR();

	//Getters
	int getCSRID() const;
	const char* getName() const;
	int getHours() const;
	int getComplaintsResolved() const;
	float getPayrate() const;
	float getWage() const;

	//Setters
	void setCSRID(int ID);
	void setName(const char* n);
	void setHours(int hours);
	void setComplaintsResolved(int cpsResolved);

	//Static Setter
	static void setTotalCpsResolved(int totalCpsResolved);

	//Calculation Functions
	void calcPayrate();
	void calcWage();

	//Static Getter
	static int getTotalCpsResolved();

	//Destructor
	/*~CSR();*/

};

int CSR::totalComplaintsResolved = 0;

//Global Scope 

CSR getCSR_at(CSR employees[], int index);

void calcTotalComplaints(CSR employees[7]);

void calcAllEmployeeWages(CSR employees[7]);

void SortByHours(CSR employees[7]);

void SortByComplaintsRes(CSR employees[7]);

void SortByWages(CSR employees[7]);


//#endif
