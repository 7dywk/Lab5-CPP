// Лабораторна робота № 5.3
// Варіант 4
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cassert>

using namespace std;

double z(const double x);
void run_tests();

int main()
{
    // Запуск юніт-тестів перед виконанням програми
    run_tests();

    double pp, pk; // початкове і кінцеве значення p
    int n;         // кількість відрізків

    cout << "p_poch = "; cin >> pp;
    cout << "p_kin = "; cin >> pk;
    cout << "n = "; cin >> n;

    double dp = (pk - pp) / n; // крок
    double p = pp;

    cout << fixed;
    cout << "------------------------" << endl;
    cout << "|" << setw(7) << "p" << " |"
         << setw(12) << "Result" << " |" << endl;
    cout << "------------------------" << endl;

    while (p <= pk + dp / 2.0)
    {
        // Головний вираз Варіанта 4
        double result = z(p * p + 1) - z(p * p - 1) + 2 * z(p);
        
        cout << "|" << setw(7) << setprecision(2) << p << " |"
             << setw(12) << setprecision(5) << result << " |" << endl;
        
        p += dp;
    }
    cout << "------------------------" << endl;

    return 0;
}

double z(const double x)
{
    if (abs(x) >= 1)
    {
        // Перша гілка: |x| >= 1
        return (sin(x) + 1) / (pow(cos(x), 2) + exp(x));
    }
    else
    {
        // Друга гілка: |x| < 1 (обчислення суми)
        double S = 0;
        int k = 0;
        double a = 1; // Перший доданок при k=0: (2^0 * x^0) / 0! = 1
        S = a;
        do
        {
            k++;
            double R = 2.0 * x / k; // Рекурентне співвідношення
            a *= R;
            S += a;
        } while (k < 6); // Сума до k=6 включно
        
        return S / exp(x * x); // Множимо суму на 1 / e^(x^2)
    }
}

void run_tests()
{
    // Тест 1: Перевірка першої гілки (|x| >= 1). Візьмемо x = 1
    double expected1 = (sin(1.0) + 1.0) / (pow(cos(1.0), 2) + exp(1.0));
    assert(abs(z(1.0) - expected1) < 1e-5);

    // Тест 2: Перевірка другої гілки (|x| < 1). Візьмемо x = 0
    // При x = 0 сума дорівнює 1, e^0 = 1, отже z(0) = 1
    assert(abs(z(0.0) - 1.0) < 1e-5);

    cout << "Unit-tests passed successfully!\n" << endl;
}
