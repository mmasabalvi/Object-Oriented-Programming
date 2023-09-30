#include<iostream>
#include<cmath>
using namespace std;

int power(int x, int degree)
{
	int result = 1;

	for (int i = 0; i < degree; i++)
	{
		result *= x;
	}

	return result;
}


int eval(int* ptr, int x, int degree, int size)
{
	double sum = 0; 

	for (int i = size-1; i >= 0; i--)
	{
		if (degree >= 0)
		{
			sum += (ptr[i] * power(x, degree));
			
			
		}
		degree--;
	}

	return sum;
}

int main()
{
	int degree;
	int x;

	cout << "Enter the degree of the Polynomial:" << endl;
	cin >> degree;

	cout << "Enter the value of the variable x:" << endl;
	cin >> x;

	int size = degree + 1;

	int *ptr = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter the coefficient for x^" << i << ": " << endl;   // states in question that program must prompt user for  values to be stored in the coefficient array. 															// therefore, coefficients arent computed and input is taken from user directly
		cin >> ptr[i];													//therefore coefficients aren't computedand value is taken directly

	}

	cout << "Polynomial answer is: " << eval(ptr, x, degree, size);

}