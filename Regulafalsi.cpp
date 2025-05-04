#include <cmath>
using namespace std;
double f(double x) {
    return x * x * x - x - 2; // Example: f(x) = x^3 - x - 2
}

int main() {
    double a, b, c, fa, fb, fc;
    double error;
    int maxIter = 20;

    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;
    cout << "Enter allowed error: ";
    cin >> error;

    fa = f(a);
    fb = f(b);

    if (fa * fb >= 0) {
        cout << "The function has same signs at a and b. Try different values." << endl;
        return 1;
    }

    cout << "\nIter\ta\t\tb\t\tc\t\tf(c)\n";

    for (int i = 1; i <= maxIter; i++) {
        c = (a * fb - b * fa) / (fb - fa);
        fc = f(c);

        cout << i << "\t" << a << "\t" << b << "\t" << c << "\t" << fc << endl;

        if (fabs(fc) < error) {
            cout << "\nRoot found: " << c << endl;
            break;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }
  return 0;
}
