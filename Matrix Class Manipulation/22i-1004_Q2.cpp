#include "22i-1004_Q2.h"

Matrix::Matrix()
{
	 matrix = NULL;
	 row = 0;
	 col = 0;

}

Matrix::Matrix(int x, int y)
{
	row = x;
	col = y;

	matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
}

Matrix::Matrix(const Matrix& obj)
{
	row = obj.row;
	col = obj.col;

	matrix = new int* [row];

	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = obj.matrix[i][j];
		}
	}
}

int Matrix::getRow()
{
	return row;
}

int Matrix::getCol()
{
	return col;
}

void Matrix::setRow(int x)
{
	row = x;
}

void Matrix::setCol(int x)
{
	col = x;
}

void Matrix::set(int i, int j, float val)
{
	matrix[i][j] = val;
}

float Matrix::get(int i, int j)const
{
	return matrix[i][j];
}

Matrix Matrix::multiplyElement(const Matrix obj)
{
	Matrix h(row, col);
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			h.matrix[i][j] = matrix[i][j] * obj.matrix[i][j];
		}
	}

	return h;

}

void Matrix::makeZero()
{
	int x, y;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] == 0)
			{
				x = i;
				y = j;
			}
		}
	}


	for (int k = 0; k < row; k++)
	{
		matrix[k][y] = 0;
	}

	for (int l = 0; l < col; l++)
	{
		matrix[x][l] = 0;
	}

}

bool Matrix::searchNumber(int number)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (matrix[i][j] = number)
			{
				return true;
			}
		}
	}

	return false;
}

//void Matrix::rotateBy90()
//{
//	
//}

int Matrix::LeftDiagonalTotal()       //only possible with square matrix
{
	int x = 0;

	for (int i = 0; i < row; i++)
	{
		x += matrix[i][i];
	}

	return x;
}

int Matrix::RightDiagonalTotal()     //only possible with square matrix
{
	int x = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i + j == row - 1)
			{
				x += matrix[i][j];
			}
		}
		
	}

	return x;
}

Matrix Matrix::Merge(Matrix m)
{
	if (row == m.row)
	{
		int x = col;
		int y = m.col;

		Matrix h(row, x + y);

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < x; j++)
			{
				h.matrix[i][j] = matrix[i][j];
			}

			for (int k = x; k < x + y; k++)
			{
				h.matrix[i][k] = m.matrix[i][k - x];
			}
		}
		
		return h;
	}
}

void Matrix::input()
{
	cout << "\nInput the Array:" << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void Matrix::display()
{
	cout << "\nThe Matrix:" << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

Matrix::~Matrix() 
{
	for (int i = 0; i < row; i++) 
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

int main()
{
	Matrix obj1(2, 2);                             //For basic input output and para constructor
	obj1.input();
	obj1.display();
	
	
	Matrix obj2(obj1);                          //For Copy Constructor
	cout << "\nObject made through Copy Constructor" << endl;
	obj2.display();

	Matrix obj9(3, 3);                             //For set and get at speicifc index
	obj9.input();
	obj9.display();
	obj9.set(2, 2, 8);
	cout << "\nMatrix after Setting: " << endl;
	obj9.display();
	cout << "Number at the index: " << obj9.get(1, 2) << endl;



	Matrix obj8(2, 2);                           //For multiply matrix elementwise
	obj8.input();
	obj8.display();
	Matrix mult = obj8.multiplyElement(obj1);
	cout << "\nMatrix multiplied elementwise: " << endl;
	mult.display();


	Matrix obj3(3, 3);                            //For makeZero Function
	obj3.input();
	obj3.display();
	obj3.makeZero(); 
	cout << "Specific Row and Column made zero: " << endl;
 	obj3.display();

	Matrix obj4(3, 3);                            //For searchNumber Function
	obj4.input();
	cout << endl << "Bool Result: " << obj4.searchNumber(5) << endl;

	//Matrix obj5(3, 3);                           //For rotateby90 Function
	//obj5.input();
	//obj5.rotateBy90();
	//obj5.display();

	Matrix obj6(3, 3);                           //For left diagonal total
	obj6.input();
	obj6.display();
	cout << "\nLeft Diagonal Sum: " << obj6.LeftDiagonalTotal() << endl;

	Matrix obj7(3, 3);                          //For right diagonal total
	obj7.input();
	obj7.display();
	cout << "\nRight Diagonal Sum: " << obj7.RightDiagonalTotal() << endl;

	Matrix obj10(2, 2);                          //For matrix merge
	obj10.input();
	obj10.display();
	Matrix merge = obj10.Merge(obj1);
	merge.display();


}