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

float error(float x1, float x2)
{
    float err = x1 - x2;
    if (err < 0)
    {
        return (err * (-1));
    }
    else
    {
        return err;
    }
}

int main()
{
    float x1, x2, x0, temp1, temp2, err;
    cout << "Enter the interval" << endl;
    cout << "x1=";
    cin >> x1;
    cout << "x2=";
    cin >> x2;

    if (f(x1) * f(x2) > 0)
    {
        cout << "Solution does not exist in given interval" << endl;
    }
    else
    {
        x0 = midpoint(x1, x2);
        temp1 = (f(x1) * f(x0) < 0) ? x1 : x2;
        err = error(x0, temp1);

        cout << "|" << setw(7) << "X1" << setw(5) << "|" << setw(7)
             << "X2"
             << "|" << setw(7)
             << "X0"
             << "|" << setw(7)
             << "f(x1)"
             << "|" << setw(9)
             << "f(x2)"
             << "|" << setw(6)
             << "f(x0)"
             << "|" << endl;
        cout << "|" << fixed << setw(5) << setprecision(4) << x1 << fixed << setw(7) << setprecision(4) << "|" << fixed << setw(6) << setprecision(4) << x2 << "|" << fixed << setw(7) << setprecision(4) << x0 << "|" << fixed << setw(9) << setprecision(4) << f(x1) << "|" << fixed << setw(7) << setprecision(4) << f(x2) << "|" << fixed << setw(9) << setprecision(4) << f(x0) << "|" << endl;

        while (err > e)
        {
            temp2 = x0;
            x0 = midpoint(temp2, temp1);
            temp1 = (f(x0) * f(temp1) < 0) ? temp1 : temp2;
            err = error(x0, temp1);
            // cout<<"|--------|-----------|---------|----------|----------|----------|-----------|"<<endl;
            cout << "|" << fixed << setw(5) << setprecision(4) << temp2 << fixed << setw(7) << setprecision(4) << "|" << fixed << setw(6) << setprecision(4) << temp1 << "|" << fixed << setw(7) << setprecision(4) << x0 << "|" << fixed << setw(9) << setprecision(4) << f(temp2) << "|" << fixed << setw(7) << setprecision(4) << f(temp1) << "|" << fixed << setw(9) << setprecision(5) << f(x0) << "|" << endl;
        }
        cout << "The root of the equation is " << x0 << endl;
    }
}