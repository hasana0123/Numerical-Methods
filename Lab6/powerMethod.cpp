#include <iostream>
#include <cmath>
#define error 0.00001
using namespace std;

int main()
{
    int n;
    float evalue = 0, er = 0, emax = 0;
    cout << "enter order of the square matrix:";
    cin >> n;
    float x[n], y[n], a[n][n];
    cout << "enter the square matrix:" << endl;
    for (int i = 1; i <= n; i++)

    {
        for (int j = 1; j <= n; j++)
        {
            cout << "a[" << i << "]"
                 << "[" << j << "]: ";
            cin >> a[i][j];
        }
    }

    cout << "eigen vector:" << endl;
    for (int i = 1; i <= n; i++)
    {

        cout << "x[" << i << "]: ";
        cin >> x[i];
    }

    do
    {
        for (int i = 1; i <= n; i++)
        {
            y[i] = 0;
            for (int j = 1; j <= n; j++)
                y[i] = y[i] + a[i][j] * x[j];
        }
        emax = abs(y[1]);
        for (int i = 2; i <= n; i++)
        {
            if (abs(y[i]) > emax)
                emax = abs(y[i]);
        }
        er = abs(emax - evalue);
        evalue = emax;
        for (int i = 1; i <= n; i++)
            x[i] = y[i] / emax;

    } while (er > error);

    cout << "eigen value:" << evalue << endl;
    for (int i = 1; i <= n; i++)
        cout << "x[" << i << "]: " << x[i] << endl;

    return 0;
}
