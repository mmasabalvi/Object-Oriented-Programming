#include<iostream>
using namespace std;

class point
{
private:

	int x, y;

public:

	point();
	point(int x, int y);

	int getx() const;
	int gety() const;

	void setx(int);
	void sety(int);

};

class triangle 
{
	point v1;
	point v2;
	point v3;

public:
	triangle();
	triangle(triangle& obj);
	triangle(int x1, int y1, int x2, int y2, int x3, int y3);

	int calculateArea();
	bool check();
	void display();
	bool operator==(const triangle& obj);

};

