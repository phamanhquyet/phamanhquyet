#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction() {
        this->numerator = 0;
        this->denominator = 1;
    }
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    int FindTheGreatestCommonDivisor(int a, int b) {
        int r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }
    void NormalizeFraction() {
        int x = FindTheGreatestCommonDivisor(numerator, denominator);
        numerator /= x;
        denominator /= x;
    }
    void display() {
        NormalizeFraction();
        if (numerator * denominator < 0 && numerator % denominator != 0)
            cout << "-" << abs(numerator) << "/" << abs(denominator) << endl;
        else if (numerator == denominator)
            cout << "1" << endl;
        else if (numerator == 0)
            cout << "0" << endl;
        else if (numerator % denominator == 0)
            cout << numerator / denominator << endl;
        else
            cout << abs(numerator) << "/" << abs(denominator) << endl;

    }
};
int main()
{
    int num, den;
    cin >> num >> den;

    Fraction* pF = new Fraction(num, den);
    Fraction f;

    pF->display(); // Fraction from 'num' and 'den'
    f.display(); // 0

    return 0;
}

