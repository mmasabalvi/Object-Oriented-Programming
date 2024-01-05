//#ifndef	22I-1004_Q1_H
//#define 22I-1004_Q1

#include<iostream>
using namespace std;


class Matrix {
private:

	int** matrix;
	int row;
	int col;

public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);    

	int getRow();
	int getCol();

	void setRow(int);
	void setCol(int);

	void set(int i, int j, float val);
	float get(int i, int j)const;
	Matrix multiplyElement(const Matrix);   /////
	void makeZero();
	bool searchNumber(int number);  //
	void rotateBy90();                     /////
	int LeftDiagonalTotal();
	int RightDiagonalTotal();
	Matrix Merge(Matrix m);                /////       
	void input();
	void display();

	~Matrix();
};

//#endif
