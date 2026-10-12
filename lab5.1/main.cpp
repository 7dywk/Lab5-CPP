
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// Прототип функції k(x, y)
double k(const double x, const double y);
void run_tests();

int main()
{
    run_tests();
    
    double p, q;
    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    // Зберігаємо значення k(1+p, q^2), щоб піднести його до квадрату (k^2)
    double k1 = k(1 + p, pow(q, 2));
    
    // Обчислюємо головний вираз за формулою з варіанта 4
    double c = (pow(k1, 2) - k(q * p, 1)) / (1 + k(pow(p, 2), q));

    cout << "c = " << c << endl;

    return 0;
}

// Визначення функції k(x, y)
double k(const double x, const double y)
{
    return (sin(x) / (pow(y, 2))) + (cos(y) / (pow(x, 2)));
}

void run_tests() {
    double result = k(1.0, 1.0);
    double expected = 1.38177;
    
    assert(abs(result - expected) < 0.0001);
    
    cout << "Unit-test completed" << endl;
}
