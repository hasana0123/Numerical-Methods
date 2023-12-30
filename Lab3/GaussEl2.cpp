#include <iostream>

using namespace std;

int getNum()
{
    int Num;
    cout << "How many equations?:";
    cin >> Num;
    return Num;
}

void input(float **a, int n)
{
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
    float fact;
    for (int i = 1; i <= n - 1; i++)
     {
        if (a[i][i] == 0)
        {
            cout << "Mathematical Error!" << endl;
            exit(0);
        }
        
        for (int j = i+1; j <= n; j++)
        {
            fact = a[j][i] / a[i][i];
            for (int k = 1; k <= n + 1; k++)
                a[j][k] = a[j][k] - fact * a[i][k];
        }
    }
}

void BackwarsSubs(float *x, float **a, int n)
{
    for (int i = n ; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
            x[i] = x[i] - a[i][j] * x[j];

        x[i] = x[i] / a[i][i];
    }
}

void output(float *x, int n)
{
    for (int i = 1; i <= n; i++)
        cout << "x" << i << "=" << x[i] << endl;
}

int main()
{
    int n;
    n = getNum();

    // dynamically allocate new memory for 2d array

    float *x = new float[n + 1]; 
    float **a = new float *[n+1];

    for (int i = 1; i <= n; i++)
        a[i] = new float[n + 2];

    input(a, n);

    ForwardElimination(a, n);

    x[n] = a[n][n + 1] / a[n][n];

    BackwarsSubs(x, a, n);

    cout << "Solution: " << endl;
    output(x, n);

    // delete dynamically allocated memory

    delete[] x;

    for (int i = 1; i <= n; i++)
        delete[] a[i];

    delete[] a;
}