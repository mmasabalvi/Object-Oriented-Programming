#include "header.h"

double sqRoot(double num)
{
	double x = num / 2.0;

	for (int i = 0; i < 10; ++i)
	{
		x = 0.5 * (x + num / x);
	}

	return x;
}

point::point()
{
	x = 0;
	y = 0;
}

point::point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int point::getx() const
{
	return x;
}

int point::gety() const
{
	return y;
}

void point::setx(int x1)
{
	x = x1;
}

void point::sety(int y1)
{
	y = y1;
}

triangle::triangle()
{
	v1.setx(0);
	v1.sety(0);

	v2.setx(0);
	v2.sety(0);

	v3.setx(0);
	v3.sety(0);
}

triangle::triangle(triangle& obj)
{
	this->v1 = obj.v1;
	this->v2 = obj.v2;
	this->v3 = obj.v3;
}

triangle::triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	v1.setx(x1);
	v1.sety(y1);

	v2.setx(x2);
	v2.sety(y2);

	v3.setx(x3);
	v3.sety(y3);
}

int triangle::calculateArea()
{
	//Area (if vertices given) = 1/2 *	∣x1(y2−y3) + x2(y3−y1) + x3(y1−y2)∣

	int prod = v1.getx() * (v2.gety() - v3.gety()) + v2.getx() * (v3.gety() - v1.gety()) + v3.getx() * (v1.gety() - v2.gety());

	if (prod < 0)
	{
		prod *= -1;
	}

	int area = prod / 2;

	return area;
}
 
bool triangle::check()
{
	double l1 = ((v2.getx() - v1.getx()) * (v2.getx() - v1.getx())) + ((v2.gety() - v1.gety()) * (v2.gety() - v1.gety()));
	double len1 = sqRoot(l1);

	double l2 = ((v3.getx() - v2.getx()) * (v3.getx() - v2.getx())) + ((v3.gety() - v2.gety()) * (v3.gety() - v2.gety()));
	double len2 = sqRoot(l2);

	double l3 = ((v1.getx() - v3.getx()) * (v1.getx() - v3.getx())) + ((v1.gety() - v3.gety()) * (v1.gety() - v3.gety()));
	double len3 = sqRoot(l3);

	if ((len1 + len2 > len3) && (len1 + len3 > len2) && (len2 + len3 > len1))
	{
		return 1;
	}
	 
	else
	{
		return 0;
	}
}

void triangle::display()
{
	int area = calculateArea();

	cout << "\nThe Triangle's area is " << area << endl;

	double l1 = ((v2.getx() - v1.getx()) * (v2.getx() - v1.getx())) + ((v2.gety() - v1.gety()) * (v2.gety() - v1.gety()));
	double len1 = sqRoot(l1);

	double l2 = ((v3.getx() - v2.getx()) * (v3.getx() - v2.getx())) + ((v3.gety() - v2.gety()) * (v3.gety() - v2.gety()));
	double len2 = sqRoot(l2);

	double l3 = ((v1.getx() - v3.getx()) * (v1.getx() - v3.getx())) + ((v1.gety() - v3.gety()) * (v1.gety() - v3.gety()));
	double len3 = sqRoot(l3);

	if (len1 == len2 && len1 == len3)
	{
		cout << "The Triangle is Equilateral" << endl;
	}

	else if (len1 != len2 && len1!= len3 && len2!=len3)
	{
		cout << "The Triangle is Scalene" << endl;
	}

	else
	{
		cout << "The Triangle is Isoceles" << endl;
	}
	
}

bool triangle::operator==(const triangle& obj)
{
	
	 return (v1.getx() == obj.v1.getx() && v1.gety() == obj.v1.gety() &&
		v2.getx() == obj.v2.getx() && v2.gety() == obj.v2.gety() &&
		v3.getx() == obj.v3.getx() && v3.gety() == obj.v3.gety());
}

int main()
{
	int check = 1;

	while (check == 1)
	{
		int x1, y1, x2, y2, x3, y3;

		cout << "\nEnter the vertices of the triangle: " << endl;
		cout << "(Format: x1, y1, x2, y2, x3, y3)" << endl;

		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		triangle T1(x1, y1, x2, y2, x3, y3);

		cout << "\nUsing check function: " << endl;

		if (T1.check() == 1)   //check function
		{
			cout << "Triangle is formed by the vertices provided above" << endl;
			T1.display(); //display function
			check = 0;
		}
		else
		{
			cout << "Wrong vertices entered. Triangle is not formed" << endl;
			cout << "Enter Vertices again" << endl;
			check = 1;

		}

	}
		        
		triangle T2(1, 0, 2, 3, 4, 0);      //copy const

		cout << "\nAnother triangle formed using hardcoded input" << endl;

		cout << "\nUsing check function: " << endl;

		if (T2.check() == 1)   //check function
		{
			cout << "Triangle is formed by the vertices provided above" << endl;
		}
		else
		{
			cout << "Wrong vertices entered. Triangle is not formed" << endl;
		}

		triangle T3(T2);

		cout << "\nThird Triangle formed using Copy Constructor" << endl;
		cout << "\nChecking if Traingle 2 and 3 are equal, using ==operator" << endl;

		if (T2 == T3)         //==operator
		{
			cout << "Both Triangles have same vertices" << endl;
		}

		else
		{
			cout << "Both Triangles do not have the same vertices" << endl;
		}

		int x4, y4, x5, y5, x6, y6;

		cout << "\nEnter the vertices of a forth triangle: " << endl;
		cout << "(Format: x1, y1, x2, y2, x3, y3)" << endl;

		cin >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
		triangle T4(x4, y4, x5, y5, x6, y6);

		cout << "Using check function: " << endl;

		if (T4.check() == 1)   //check function
		{
			cout << "Triangle is formed by the vertices provided above" << endl;
		}
		else
		{
			cout << "Wrong vertices entered. Triangle is not formed" << endl;
		}

		T4.display();

		cout << "Checking if triangle 1 and 4 are equal" << endl;

		if (T4 == T2)         //==operator
		{
			cout << "Both Triangles have same vertices. They are equal" << endl;
		}

		else
		{
			cout << "Both Triangles do not have the same vertices. They are not equal" << endl;
		}
}
