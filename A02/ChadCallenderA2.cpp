#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
    long int a = 2, b =7;
    Fraction c;
    Fraction d = 5;

    c.set(a, b);

    cout << double(c);
}