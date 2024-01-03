#include <iostream>
#include <iomanip>

using namespace std;

int getNum()
{
    int Num;
    cout << "Enter the number of equations?: ";
    cin >> Num;
    return Num;
}

void input(float **a, int n)
{
    cout << "Input: " << endl;
    cout << "----------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cout << "a" << i << j << "=";
            cin >> a[i][j];
        }
    }
}

void ForwardElimination(float **a, int n)
{
    float piv, fact;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][i] == 0)
        {
            cout << "Mathematical Error!" << endl;
        }
        piv = a[i][i];
        for (int j = 1; j <= n + 1; j++)
        {
            a[i][j] /= piv;
        }
        for (int k = 1; k <= n; k++)
        {
            fact = a[k][i];
            if (i != k)
                for (int j = 1; j <= n + 1; j++)
                {
                    a[k][j] = a[k][j] - fact * a[i][j];
                }
        }
    }
}

void identity(float **a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            if (j == n+1)
                cout << ":"
                     << "a" << i << j << "=" << setw(7) << setprecision(4) << left << a[i][j];
            else
                cout << "a" << i << j << "=" << setw(7) << setprecision(4) << left << a[i][j];
        }
        cout << endl;
    }
}

void output(float **a, int n)
{
    cout << "Solution:" << endl;
    cout << "\n\n"
         << endl;
    cout << "---------------------" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << "=" << a[i][n + 1] << endl;
    }
}

int main()
{
    int n;
    n = getNum();

    float **a = new float *[n + 1];

    for (int i = 1; i <= n; i++)
    {
        a[i] = new float[n + 2];
    }

    input(a, n);
    ForwardElimination(a, n);

    cout << "\n\nIdentity matrix" << endl;
    cout << "--------------------" << endl;
    identity(a, n);
    output(a, n);

    for (int i = 1; i <= n; i++)
        delete[] a[i];
    delete[] a;
}
