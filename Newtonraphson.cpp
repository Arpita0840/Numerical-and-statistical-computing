#include <iostream>
#include <cmath>
using namespace std;

double f(double x) { return x * x - 2; }       // Example: f(x) = x^2 - 2
double df(double x) { return 2 * x; }          // Derivative: f'(x) = 2x

int main() {
    double x, error;
    cout << "Enter initial guess: ";
    cin >> x;
    cout << "Enter allowed error: ";
    cin >> error;

    while (fabs(f(x)) > error)
        x = x - f(x) / df(x);

    cout << "Root: " << x << endl;
    return 0;
}
