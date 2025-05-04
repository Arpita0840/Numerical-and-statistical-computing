#include <iostream>
#include <cmath>
using namespace std;
double f(double x) { return x*x*x - x - 2; } // Example: f(x) = x³ - x - 2

int main() {
    double a = 1, b = 2, c, error = 0.0001;
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval!";
        return 1;
    }

    do {
        c = (a + b) / 2;
        if (f(c) == 0.0) break;
        else if (f(a) * f(c) < 0) b = c;
        else a = c;
    } while (fabs(f(c)) > error);

    cout << "Root: " << c << endl;
    return 0;
}
