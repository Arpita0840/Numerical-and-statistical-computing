#include <iostream>
#include <cmath>
using namespace std;
double f(double x) {
    return x * x * x - x - 2; // Example: f(x) = x^3 - x - 2
}

int main() {
    double x0, x1, x2, f0, f1, f2;
    int maxIter = 10;
    double error;

    cout << "Enter first guess: ";
    cin >> x0;
    cout << "Enter second guess: ";
    cin >> x1;
    cout << "Enter allowed error: ";
    cin >> error;

    cout << "\nIter\tx0\t\tx1\t\tx2\t\tf(x2)\n";

    for (int i = 1; i <= maxIter; i++) {
        f0 = f(x0);
        f1 = f(x1);

        if (f1 - f0 == 0) {
            cout << "Division by zero error!\n";
            break;
        }

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        cout << i << "\t" << x0 << "\t" << x1 << "\t" << x2 << "\t" << f2 << endl;

        if (fabs(f2) < error) {
            cout << "\nRoot found: " << x2 << endl;
            break;
        }

        x0 = x1;
        x1 = x2;
    }

    return 0;
}
