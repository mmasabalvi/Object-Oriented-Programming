#include<iostream>
using namespace std;

void pattern(int x, int y, char symb, int i)
{
	if (i < x)
	{
		if (i == 0 || i == x / 2)
		{
			for (int j = 0; j < y; j++)
			{
				cout << symb;
			}
		}

		cout << symb;
		cout << endl;


		pattern(x, y, symb, i + 1);
	}
}

int main()
{
	int x, y;
	char symb;

	cout << "Please enter the length (odd number only) :";
	cin >> x;

	while (x % 2 == 0)
	{
		cout << "Invalid Input. Please enter again:";
		cin >> x;
	}

	cout << "Please enter the width:";
	cin >> y;

	cout << "Enter the symbol:" << endl;
	cin >> symb;

	cout << "Printing F as Assignment was difficut:" << endl;
	

	pattern(x, y, symb, 0);
}

