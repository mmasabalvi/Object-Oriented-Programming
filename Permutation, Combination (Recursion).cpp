#include<iostream>
#include<cmath>
using namespace std;

int fact(int x)
{
	if (x == 1)
	{
		return 1;
	}

	else
	{
		return x * fact(x - 1);
	}
}


int main()
{
	int n, r;

	cout << "Enter the value of n: " << endl;
	cin >> n;

	cout << "Enter the value of r: " << endl;
	cin >> r;

	float permutation = static_cast<float>(fact(n)) / fact(n - r);

	cout << "Permutation of the given number is: " << permutation << endl;

	float combination = fact(n) / (static_cast<float>(fact(r)) * fact(n - r));

	cout << "Combination of the given number is: " << combination << endl;



}