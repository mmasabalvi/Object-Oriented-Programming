#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int determ(int** matrix, int size)        //pointer to 2d array of integers
{
	if (size == 1)
	{
		return **matrix;
	}

	if (size == 2) 
	{
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}

	int determinant = 0;


	for (int i = 0; i < size; i++)          //terates through each col
	{
		int** matrix1 = new int* [size - 1];    //submatrix which includes the curerent row and column


		for (int j = 0; j < size - 1; j++) 
		{
			matrix1[j] = new int[size - 1];

		}

		for (int j = 1; j < size; j++)   //iterates through each row except the first
		{
			int col = 0;

			for (int k = 0; k < size; k++) 
			{
				if (k != i) 
				{
					matrix1[j - 1][col++] = matrix[j][k];
				}
			}
		}

		int sign;
		if (i % 2 == 0)
		{
			sign = 1;
		} 

		else
		{
			sign = -1;
		}

		determinant += sign * matrix[0][i] * determ(matrix1, size - 1);

		
		for (int j = 0; j < size - 1; j++) 
		{
			delete[] matrix1[j];
		}

		delete[] matrix1;

	}

	return determinant;

	

}

int main()
{
	int size;
	cout << "Enter the size of the N x N Matrix: " << endl;
	cin >> size;

	int** arr = new int* [size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}

	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 100 + 1;
		}
	}
	
	cout << "Original Matrix: " << endl;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}

		cout << endl;
	}

	int determinant = determ(arr, size);
	cout << "Determinant: " << determinant << endl;


	if (determinant == 0)
	{
		cout << "Forces are not in equilibrium" << endl;
	}

	else
	{
		cout << "Forces are in equilibrium" << endl;
	}


	for (int i = 0; i < size; i++) 
	{
		delete[] arr[i];
	}

	delete[] arr;

}