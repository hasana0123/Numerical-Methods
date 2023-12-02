#include <iostream>
#include <iomanip>
#include <cmath>
#define f(x) (x - cos(x))
#define e 0.00001

using namespace std;

float midpoint(float x1, float x2)
{
    return ((x1 + x2) / 2);
}

int main()
{
    float x1, x2, x0;

    cout << "Given function f(x)= x-cos(x)" << endl;
label:
    cout << "Enter the interval" << endl;
    cout << "x1=";
    cin >> x1;
    cout << "x2=";
    cin >> x2;

    if (f(x1) * f(x2) > 0)
    {
        cout << "Solution does not exist in given interval" << endl;
        goto label;
    }
    else
    {

        cout << "|-------|-------|-------|---------|-------|---------|" << endl;

        cout << "|" << fixed << setw(7) << "x1"
             << "|" << fixed << setw(7) << "x2"
             << "|" << fixed << setw(7) << "x0"
             << "|" << fixed << setw(9) << "f(x1)"
             << "|" << fixed << setw(7) << "f(x2)"
             << "|" << fixed << setw(9) << "f(x0)"
             << "|" << endl;
        cout << "|-------|-------|-------|---------|-------|---------|" << endl;
        cout << "|" << fixed << setw(6) << setprecision(5) << x1 << "|" << fixed << setw(7) << setprecision(5) << x2 << "|" << fixed << setw(7) << setprecision(5) << x0 << "|" << fixed << setw(9) << setprecision(5) << f(x1) << "|" << fixed << setw(7) << setprecision(5) << f(x2) << "|" << fixed << setw(9) << setprecision(5) << f(x0) << "|" << endl;
        cout << "|_______|_______|_______|_________|_______|_________|" << endl;
        do
        {
            x0 = midpoint(x1, x2);
            if (f(x1) * f(x0) < 0)
                x2 = x0;
            else
                x1 = x0;
            cout << "|" << fixed << setw(6) << setprecision(5) << x1 << "|" << fixed << setw(7) << setprecision(5) << x2 << "|" << fixed << setw(7) << setprecision(5) << x0 << "|" << fixed << setw(9) << setprecision(5) << f(x1) << "|" << fixed << setw(7) << setprecision(5) << f(x2) << "|" << fixed << setw(9) << setprecision(5) << f(x0) << "|" << endl;
            cout << "|_______|_______|_______|_________|_______|_________|" << endl;
        } while (fabs(x2 - x1) > e);
        cout << "The root in the above interval = " << x0 << endl;
    }
}
