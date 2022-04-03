//***********************************
//   Assignment #1
//   Name: Chad Callender
//   CMPS 2143 - OOP
//   02/18/2022
//***********************************

/*  This program will compute the magnitude and phase a complex number of the form
    a + bi. The magnitude of a + bi is sqrt(a^2 + b^2) and its phase is the angle the
    number makes with the positive horizontal axis given by arctan(b / a).
*/

#include <iostream>
#include <cmath>

#define PI 3.1415926535897932384626433832

using namespace std;

class Phasor 
{   
    private:
        double magnitude;
        double phase;

    public:
        void setMagnitude(double);
        double getMagnitude() const;
        void setPhase(double);
        double getPhase() const;
        void print() const;

        Phasor();
        Phasor(double, double);
        ~Phasor() {}

        Phasor operator*(const Phasor&);
        Phasor operator/(const Phasor&);
};

void Phasor::setMagnitude(double mag)
{/* Parameters: real:double -- the real part of the complex number
                im:double -- the imaginary part of the complex number

    Description: setMagnitude takes a complex number a + bi, computes its magnitude
    by the formula sqrt(a^2 + b^2), and assigns the value to the magnitude attribue of the
    Phasor object. The function returns no value.
*/
    magnitude = mag;
}

double Phasor::getMagnitude() const
{/* Parameters: none

    Description: getMagnitude returns the magnitude attribute of the
    Phasor object. The function returns magnitude:double.
*/
    return magnitude;
}

void Phasor::setPhase(double p)
{/* Parameters: p:double - the phase of the angle

    Description: setPhase takes the phase of a complex number a + bi,
    normalizes the angle to lie between 0 and 360, and assigns the normalized angle
    to the phase attribue of the Phasor object. The function returns no value.
*/
    while (p < 0 || p > 360)
    {
        if (p < 0)
            p += 360;

        if (p > 360)
            p -= 360;
    }

    phase = p;
}


double Phasor::getPhase() const
{/* Parameters: none

    Description: getPhase returns the phase attribute of the
    Phasor object. The function returns phase:double.
*/
    return phase;
}

void Phasor::print() const
{/* Parameters: none

    Description: "print" prints the values of the magnitude and the phase of
    the Phasor object. The function returns no value.
*/
    cout << "Magnitude: " << getMagnitude() << " Phase: " << getPhase() << " degrees";
}

Phasor::Phasor()
{/* Parameters: none

    Description: Phasor is a default constructor that initializes the magnitude and
    the phase attributes of the Phasor object to 0. The function returns no value.

*/
    magnitude = 0;
    phase = 0;
}

Phasor::Phasor(double real, double im)
{/* Parameters: real:double -- the real part of the complex number
                im:double -- the imaginary part of the complex number

    Description: Phasor is an overloaded constructor takes a complex number a + bi
    and computes the magnitude and the phase of the number. The funciton computes the
    magnitude by the formula sqrt(a^2 + b^2) The phase is the angle the number makes
    with the positive horizontal axis given by the formula arctan(b / a). The resulting
    angle (in radians) is multiplied by 180 / pi to convert it to degrees. The setMagnitude
    and setPhase member functions are called to assign the calculated values to the
    phase and magnitude attributes of the Phasor object. The function returns no value.
*/
    double mag = sqrt(pow(real, 2) + pow(im, 2));
    double p = atan(im / real) * (180 / PI);

    setMagnitude(mag);    
    setPhase(p);
}

Phasor Phasor::operator*(const Phasor &obj)
{/* Parameters: obj:const Phasor&

    Description: operator* overloads the multiplication operator (*)
    to multiply two Phasor objects, say obj1 and obj2. The magitude of
    the product of obj1 and obj2 is the product of the magnitudes of obj1
    and obj2. The phase of the product of obj1 and obj2 is the sum of the
    phases of obj1 and obj2. The function returns phasor:Phasor.
*/
    Phasor phasor;
    phasor.magnitude = magnitude * obj.magnitude;
    phasor.phase = phase + obj.phase;
    phasor.setPhase(phasor.phase);

    return phasor;
}

Phasor Phasor::operator/(const Phasor &obj)
{/* Parameters: obj:const Phasor&

    Description: operator* overloads the division operator (/)
    to divide two Phasor objects, say obj1 and obj2. The magitude of
    the quotient of obj1 and obj2 is the quotient of the magnitudes of obj1
    and obj2. The phase of the product of obj1 and obj2 is the difference of the
    phases of obj1 and obj2. The function returns phasor:Phasor.
*/
    Phasor phasor;
    phasor.magnitude = magnitude / obj.magnitude;
    phasor.phase = phase - obj.phase;
    phasor.setPhase(phasor.phase);

    return phasor;
}

int main()
{
    Phasor A, D, E;
    Phasor B(sqrt(2), -sqrt(2));
    Phasor C(sqrt(2), sqrt(3));

    A.setMagnitude(3);
    A.setPhase(-45);

    D = B * C;
    E = B / C;

    cout << "===========================================\n";
    cout << "This is A\n";
    A.print();
    cout << "\n===========================================\n";

    cout << "\n===========================================\n";
    cout << "This is B\n";
    B.print();
    cout << "\n===========================================\n";

    cout << "\n===========================================\n";
    cout << "This is C\n";
    C.print();
    cout << "\n===========================================\n";

    cout << "\n===========================================\n";
    cout << "This is D\n";
    D.print();
    cout << "\n===========================================\n";

    cout << "\n===========================================\n";
    cout << "This is E\n";
    E.print();
    cout << "\n===========================================\n";
}