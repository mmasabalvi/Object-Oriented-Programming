#include "CSR.h"

//Default Constructor

CSR::CSR()
{
    csrID = 0;
    csrName[50] = '\0';
    hours = 0;
    complaintsResolved = 0;
    payrate = 0;
    wage = 0;
}

//Getters Definition

int CSR::getCSRID() const {
    return csrID;
}

const char* CSR::getName() const {
    return csrName;
}

int CSR::getHours() const
{
    return hours;
}

int CSR::getComplaintsResolved() const {
    return complaintsResolved;
}

float CSR::getPayrate() const {
    return payrate;
}

float CSR::getWage() const {
    return wage;
}


//Setters Definition

void CSR::setCSRID(int ID) {
    csrID = ID;
}

void CSR::setName(const char *n)
{

    int i = 0;
    while (n[i] != '\0')
    {
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        csrName[j] = n[j];
    }

    csrName[i] = '\0';
    //strncpy_s(csrName, n, sizeof(csrName)); // Copy the input into the character array
    //csrName[sizeof(csrName) - 1] = '\0';  // Ensure null-terminated
}

void CSR::setHours(int h) {
    hours = h;
}

void CSR::setComplaintsResolved(int cpsResolved) {
    complaintsResolved = cpsResolved;
}


//Static Setter

void CSR::setTotalCpsResolved(int totalCpsResolved) {
    totalComplaintsResolved = totalCpsResolved;
}


//Calculation Functions

void CSR::calcPayrate() {
    payrate = 25 + (25 * float(complaintsResolved));
}

void CSR::calcWage() {
    wage = float(hours) * payrate;
}


//Static Getter

int CSR::getTotalCpsResolved() {
    return totalComplaintsResolved;
}

//Destructor
//CSR::~CSR() {
//    delete[] csrName;  
//}

//Global Scope Functions

CSR getCSR_at(CSR employees[], int index)
{
    return employees[index];
}

void calcTotalComplaints(CSR employees[7])                               //should i pass getter as an augment - No as can be accesed using objec subscript
{
    int x = 0;

    for (int i = 0; i < 7; i++)
    {
        x += employees[i].getComplaintsResolved();
    }

    CSR::setTotalCpsResolved(x);

}

void calcAllEmployeeWages(CSR employees[7])
{
    float totalWages = 0;

    for (int i = 0; i < 7; i++)
    {
        totalWages += float(employees[i].getWage());
    }

    cout << "Total Wages of all Employees is: " << totalWages << endl;
}

void SortByHours(CSR employees[7])
{
    CSR h;

    cout << "Sorted by hours in descending order: " << endl;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7 - i; j++)
        {
            if (employees[j].getHours() < employees[j + 1].getHours())
            {
                h = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = h;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << "." << endl;
        cout << "Employee ID: " << employees[i].getCSRID() << endl;
        cout << "Employee Name: " << employees[i].getName() << endl;
        cout << "Employee Hours Worked:" << employees[i].getHours() << endl;
        cout << "Employee Complaints Resolved: " << employees[i].getComplaintsResolved() << endl;
        cout << "Employee Payrate: " << employees[i].getPayrate() << endl;
        cout << "Employee Wage: " << employees[i].getWage() << endl << endl;
    }

}

void SortByComplaintsRes(CSR employees[7])
{
    CSR h;

    cout << "Sorted by complaints resolved in descending order: " << endl;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7 - i; j++)
        {
            if (employees[j].getComplaintsResolved() < employees[j + 1].getComplaintsResolved())
            {
                h = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = h;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << "." << endl;
        cout << "Employee ID: " << employees[i].getCSRID() << endl;
        cout << "Employee Name: " << employees[i].getName() << endl;
        cout << "Employee Hours Worked:" << employees[i].getHours() << endl;
        cout << "Employee Complaints Resolved: " << employees[i].getComplaintsResolved() << endl;
        cout << "Employee Payrate: " << employees[i].getPayrate() << endl;
        cout << "Employee Wage: " << employees[i].getWage() << endl << endl;
    }
}

void SortByWages(CSR employees[7])
{
    CSR h;

    cout << "Sorted by wages in descending order: " << endl;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7 - i; j++)
        {
            if (employees[j].getWage() < employees[j + 1].getWage())
            {
                h = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = h;
            }
        }
    }

    for (int i = 0; i < 7; i++)
    {
        cout << i + 1 << "." << endl;
        cout << "Employee ID: " << employees[i].getCSRID() << endl;
        cout << "Employee Name: " << employees[i].getName() << endl;
        cout << "Employee Hours Worked:" << employees[i].getHours() << endl;
        cout << "Employee Complaints Resolved: " << employees[i].getComplaintsResolved() << endl;
        cout << "Employee Payrate: " << employees[i].getPayrate() << endl;
        cout << "Employee Wage: " << employees[i].getWage() << endl << endl;
    }
}



int main()
{
    const int noOfEmployees = 7;

    CSR employees[noOfEmployees];

    int t1 = 0;

    char* t2 = new char[10];

    /*const int size = 50;
    char t2[size];*/
    /*char* t2 = NULL;*/
    /*const int size = 15;
    char t2[size]*/;
    //t2 = new char[10];

    int t3 = 0;
    int t4 = 0;


    for (int i = 0; i < noOfEmployees; i++)                                           //should index be 1 and 7 or 0 and 6
    {
        cout << "Input the data for Employee " << i + 1 << ":" << endl;

        cout << "CSR ID: ";
        cin >> t1;
        employees[i].setCSRID(t1);

        cout << endl;

        cout << "CSR Name: ";
        cin >> t2;
        employees[i].setName(t2);

        cout << endl;

        cout << "Hours worked: ";
        cin >> t3;
        employees[i].setHours(t3);

        cout << endl;

        cout << "Complaints Resolved: ";
        cin >> t4;
        employees[i].setComplaintsResolved(t4);

        cout << endl;
        cout << endl;
    }

    //Calculating Payrate for all Employees

    for (int i = 0; i < noOfEmployees; i++)
    {
        employees[i].calcPayrate();
    }

    //Calculating Wage for all Employees

    for (int i = 0; i < noOfEmployees; i++)
    {
        employees[i].calcWage();
    }


    //Global Functions called
    int x = 1;

    while (x != 7)
    {
        cout << "\nFor the following operations input the specific number" << endl;
        cout << "[1] Returns object at the specific index" << endl;
        cout << "[2] Calculate Total Complaints Resolved by all Employees" << endl;
        cout << "[3] Calculate the wages of all Employees" << endl;
        cout << "[4] Sort Employees in descending order based onhours worked" << endl;
        cout << "[5] Sort Employees in descending order based on complaints resolved" << endl;
        cout << "[6] Sort Employees in descending order based on Wages" << endl;
        cout << "[7] Exit" << endl;
        cin >> x;

        switch (x)
        {
        case 1:
        {int index;

        cout << "Enter the index to return the Object at it: " << endl;
        cin >> index;

        CSR h = getCSR_at(employees, index);

        cout << "CSR ID: " << h.getCSRID() << endl;
        cout << "CSR Name: " << h.getName() << endl;
        cout << "Hours worked: " << h.getHours() << endl;
        cout << "Complaints Resolved: " << h.getComplaintsResolved() << endl;
        break;
        }

        case 2:
            cout << "Total Complaints Resolved by all: " << endl;
            calcTotalComplaints(employees);
            cout << CSR::getTotalCpsResolved();
            break;

        case 3:
            calcAllEmployeeWages(employees);
            break;

        case 4:
            SortByHours(employees);
            break;

        case 5:
            SortByComplaintsRes(employees);
            break;

        case 6:
            SortByWages(employees);
            break;

        case 7:
            break;

        default:
            cout << "Error! Invaild Input entered. Kindly enter correct input" << endl;
            break;
        }

    }

}
