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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "a" << i << j << "=";
            cin >> a[i][j];
        }
    }
}

void augmentedMat(float **a, float **b, float **c, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            c[i][j] = a[i][j];

        for (int j = n + 1; j <= 2 * n; j++)
            c[i][j] = b[i][j - n];
    }
}

void ForwardElimination(float **c, int n)
{
    float piv, fact;
    for (int i = 1; i <= n; i++)
    {
        if (c[i][i] == 0)
        {
            cout << "Mathematical Error!" << endl;
        }
        piv = c[i][i];
        for (int j = 1; j <= 2 * (n + 1); j++)
        {
            c[i][j] /= piv;
        }
        for (int k = 1; k <= n; k++)
        {
            fact = c[k][i];
            if (i != k)
                for (int j = 1; j <= 2 * (n + 1); j++)
                {
                    c[k][j] = c[k][j] - fact * c[i][j];
                }
        }
    }
}

void identity(float **c, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 2 * n; j++)
        {
            if (j == n + 1)
            {
                cout << ":"
                     << "a" << i << j << "= " << left << setw(15) << setprecision(4) << c[i][j];
            }
            else
                cout << "a" << i << j << "= " << left << setw(15) << setprecision(4) << c[i][j];
        }
        cout << endl;
    }
}

void output(float **c, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n + 1; j <= 2 * n; j++)
        {
            cout << "a" << i << "=" << left << setw(15) << setprecision(4) << c[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    n = getNum();

    float **a = new float *[n + 1];
    float **b = new float *[n + 1];
    float **c = new float *[n + 1];

    for (int i = 1; i <= n; i++)
    {
        a[i] = new float[n + 1];
        b[i] = new float[n + 1];
    }

    for (int i = 1; i <= n; i++)
    {
        c[i] = new float[2 * n + 1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                b[i][j] = 1;
            else
                b[i][j] = 0;
        }
    }

    input(a, n);
    cout << "Augmented matrix" << endl;
    augmentedMat(a, b, c, n);
    cout << "Forward Elimination" << endl;
    ForwardElimination(c, n);
    cout << "Identity matrix" << endl;
    identity(c, n);
    cout << "Solution:" << endl;
    output(c, n);

    for (int i = 1; i <= n; i++)
    {
        delete[] c[i];
        delete[] a[i];
        delete[] b[i];
    }

    delete[] a;
    delete[] b;
    delete[] c;
}
