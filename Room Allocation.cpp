#include<iostream>

using namespace std;
int main()
{
	int** a = new int* [4];					//A- Block 4 floors

	for (int i = 0; i < 4; i++)
	{
		a[i] = new int[5];                  // 5 rooms on each floor 
	}

	int room = 301;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			a[i][j] = room;
			room++;
		}

		room -= 105;
	}


	int** b = new int* [3];					//A- Block 4 floors

	for (int i = 0; i < 3; i++)
	{
		b[i] = new int[5];                  // 5 rooms on each floor 
	}

	room = 201;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			b[i][j] = room;
			room++;
		}

		room -= 105;
	}


	int** c = new int* [7];					//A- Block 4 floors

	for (int i = 0; i < 7; i++)
	{
		c[i] = new int[5];                  // 5 rooms on each floor 
	}

	room = 601;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			c[i][j] = room;
			room++;
		}

		room -= 105;
	}


	char choice = 'N';

	while(choice!='Y')
	{

			cout << "BLock A:" << endl;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << a[i][j] << "  ";
				}

				cout << endl;
			}

			cout << endl;

			cout << "BLock B:" << endl;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << b[i][j] << "  ";
				}

				cout << endl;
			}

			cout << endl;

			cout << "BLock C:" << endl;

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << c[i][j] << "  ";
				}

				cout << endl;
			}

			int n;
			cout << "\nPlease enter the number of room(s) you want from BLock A:" << endl;
			cin >> n;

			int* arrA = new int[n];

			cout << "Please enter your desired room(s): " << endl;

			for (int i = 0; i < n; i++)
			{
				cin >> arrA[i];

			}

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < n; k++)
					{
						if (arrA[k] == a[i][j])
						{
							a[i][j] = 0;
						}
					}

				}
			}

			/*for (int i = 0; i < n; i++)
			{
				bool available = 0;

				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						if (arrA[i] == a[j][k])
						{
							available = 1;
							a[j][k] = 0;
							break;
						}
					}

					if (available == 1)
					{
						break;
					}
				}

				if (available == 0)
				{
					cout << "Room " << arrA[i] << " is unavailable.Please enter another : " << endl;
					cin >> arrA[i];

					for (int j = 0; j < 4; j++)
					{
						for (int k = 0; k < 5; k++)
						{
							if (arrA[i] == a[j][k])
							{
								a[j][k] = 0;
							}
						}
					}
				}


			}*/


			cout << "\nPlease enter the number of room(s) you want from Block B:" << endl;
			cin >> n;

			int* arrB = new int[n];

			cout << "Please enter your desired room(s): " << endl;

			for (int i = 0; i < n; i++)
			{
				cin >> arrB[i];
			}

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < n; k++)
					{
						if (arrB[k] == b[i][j])
						{
							b[i][j] = 0;

						}
					}
				}
			}

			/*for (int i = 0; i < n; i++)
			{
				bool available = 0;

				for (int j = 0; j < 3; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						if (arrB[i] == b[j][k])
						{
							available = 1;
							b[j][k] = 0;
							break;
						}
					}

					if (available == 1)
					{
						break;
					}
				}

				if (available == 0)
				{
					cout << "Room " << arrB[i] << " is unavailable.Please enter another : " << endl;
					cin >> arrB[i];

					for (int j = 0; j < 3; j++)
					{
						for (int k = 0; k < 5; k++)
						{
							if (arrB[i] == b[j][k])
							{
								b[j][k] = 0;
							}
						}
					}
				}


			}*/


			cout << "\nPlease enter the number of room(s) you want from BLock C:" << endl;
			cin >> n;

			int* arrC = new int[n];

			cout << "Please enter your desired room(s): " << endl;

			for (int i = 0; i < n; i++)
			{
				cin >> arrC[i];
			}

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < n; k++)
					{
						if (arrC[k] == c[i][j])
						{
							c[i][j] = 0;
						}
					}

				}
			}

			/*for (int i = 0; i < n; i++)
			{
				bool available = 0;

				for (int j = 0; j < 7; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						if (arrC[i] == c[j][k])
						{
							available = 1;
							c[j][k] = 0;
							break;
						}
					}

					if (available == 1)
					{
						break;
					}
				}

				if (available == 0)
				{
					cout << "Room " << arrC[i] << " is unavailable.Please enter another : " << endl;
					cin >> arrC[i];

					for (int j = 0; j < 7; j++)
					{
						for (int k = 0; k < 5; k++)
						{
							if (arrC[i] == c[j][k])
							{
								c[j][k] = 0;
							}
						}
					}
				}


			}*/
		

			cout << "\nBLock A:" << endl;

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << a[i][j] << "  ";
				}

				cout << endl;
			}
			cout << endl;

			cout << "BLock B:" << endl;

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << b[i][j] << "  ";
				}

				cout << endl;
			}

			cout << endl;

			cout << "BLock C:" << endl;

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << c[i][j] << "  ";
				}

				cout << endl;
			}

			cout << "\nDo you want to exit the program? (Y/N)" << endl;
			cin >> choice;
			cout << endl;

			//cout << "Please select more rooms: " << endl;

			delete[] arrA;
			delete[] arrB;
			delete[] arrC;

	}
	
	cout << "Program exited" << endl;

	for (int i = 0; i < 4; i++)
	{
		delete[] a[i];
	}

	delete[] a;


	for (int i = 0; i < 3; i++)
	{
		delete[] b[i];
	}

	delete[] b;


	for (int i = 0; i < 7; i++)
	{
		delete[] c[i];
	}

	delete[] c;

}
