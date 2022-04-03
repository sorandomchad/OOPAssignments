class Fraction
{
    private:
        long int numerator;
        long int denominator;

    public:
        Fraction() {numerator = 0, denominator = 1;}
        Fraction(const long&);

        // convert a Fraction object to double
        operator double();
        
        // overloading mathematical operators
        Fraction operator*(const Fraction&);
        Fraction operator/(const Fraction&);
        Fraction operator+(const Fraction&);
        Fraction operator-(const Fraction&);

        Fraction set(const long&, const long&);
        Fraction reduce(const long&, const long&); 
        // call this function to reduce the fractions
        // first parameter is numerator and second is denominator
};

unsigned long GCD(unsigned long int a, unsigned long int b);