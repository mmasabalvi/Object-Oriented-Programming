#include <iostream>
using namespace std;


void star(int n)
{
    if (n != 0)
    {
        cout << "*";
        star(--n);
    }
}


// Prints Whitespaces
void whiteSpace(int n)
{
    if (n != 0)
    {
        cout << " ";
        whiteSpace(--n);
    }
}


void lower(int n, int space, int x)
{
    if (x != n)
    {
        space -= 2;

        // For one line
        star(++x);
        whiteSpace(space);
        star(x);

        // Go to next line
        cout << "\n";
        lower(n, space, x);
    }
}

void upper(int n, int space)
{
    if (n != 0)
    {
        space += 2;

        // For one line
        star(n);
        whiteSpace(space);
        star(n);

        // Go to next line
        cout << "\n";
        upper(--n, space);
    }
}

void printHollowDiamond(int n)
{
    // Declaring Variables
    int x = 0;
    int space = -2;

    // Print upper half
    upper(n, space);

    // Print lower half
    space = 2 * n;
    lower(n, space, x);
}


int main()
{
    int n; 
    cout << "Enter the value of n: " << endl;
    cin >> n;
    printHollowDiamond(n);
}



