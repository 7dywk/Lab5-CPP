#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// Функція k(x, y)
double k(const double x, const double y)
{
    return (sin(x) / pow(y, 2)) + (cos(y) / pow(x, 2));
}

// Функція з тестами
void test_k()
{
    const double eps = 1e-4;

    assert(abs(k(1.0, 1.0) - 1.38177) < eps);
    assert(abs(k(2.0, 2.0) - 0.12329) < eps);
    assert(abs(k(1.0, 2.0) - (-0.20577)) < eps);
    
    cout << "All Unit Tests passed successfully!\n" << endl;
}

int main()
{
    // 1. Спочатку запускаємо тести
    test_k();

    // 2. Якщо тести пройшли успішно, виконується основна програма
    double p, q;
    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    double c = (pow(k(1.0 + p, pow(q, 2)), 2) - k(q * p, 1.0)) / (1.0 + k(pow(p, 2), q));
    cout << "c = " << c << endl;

    return 0;
}
