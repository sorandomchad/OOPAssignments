#include "Fraction.h"

Fraction::Fraction(const long &right)
{
    numerator = right;
    denominator = 1;
}

Fraction::operator double()
{
    return double(numerator)/denominator;
}

Fraction Fraction::operator*(const Fraction &right)
{
    numerator = numerator * right.numerator;
    denominator = denominator * right.denominator;

    return *this;
}

Fraction Fraction::operator/(const Fraction &right)
{
    numerator = numerator * right.denominator;
    denominator = denominator * right.numerator;

    return *this;
}

Fraction Fraction::operator+(const Fraction &right)
{
    numerator = (numerator * right.denominator) + (denominator * right.numerator);
    denominator = denominator * right.denominator;

    return *this;
}

Fraction Fraction::operator-(const Fraction &right)
{
    numerator = (numerator * right.denominator) - (denominator * right.numerator);
    denominator = denominator * right.denominator;

    return *this;
}

Fraction Fraction::set(const long &a, const long &b)
{
    numerator = a;
    denominator = b;

    return *this;
}

unsigned long GCD(unsigned long int a, unsigned long int b)
{
    return a%b ? GCD(b, a%b) : b;
}