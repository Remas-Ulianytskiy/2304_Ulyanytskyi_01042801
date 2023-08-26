#include <iostream>

using namespace std;

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

    int biggest_divisor(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {}

    friend ostream& operator<<(ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }

    void simplify()
    {
        int gcd = biggest_divisor(m_numerator, m_denominator);
        m_numerator /= gcd;
        m_denominator /= gcd;
    }
};

void print_fraction(const unique_ptr<Fraction>& ptr)
{
    if (ptr)
        cout << *ptr;
}

int main()
{
    unique_ptr<Fraction> ptr = make_unique<Fraction>(49, 11711);

    print_fraction(ptr);

    return 0;
}
