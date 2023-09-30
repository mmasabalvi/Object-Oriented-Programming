#include<iostream>
#include<cmath>
using namespace std;


int digits(int x)
{
	if (x < 10)
	{
		return x;										//if single digit then return
	}

	else
	{
		return x % 10 + digits(x / 10);					//program to split numbers, first mod 10, then divide by 10
	}
}


int root(int x)
{
	int sum = digits(x);

	if (sum < 10)
	{
		return sum;                                    // if sum single digit, then final answer = sum
	}

	else
	{
		return digits(sum);
	}
}


int main()
{
	int num;

	cout << "Enter an integer: " << endl;
	cin >> num;

	cout << digits(num) << endl;
	cout << "The Digital Root is: " << root(num) << endl;

}