#include <iostream>
#include <math.h>
#include <iomanip>
#define f(x) (x - cos(x))
#define e 0.0001

using namespace std;

void table()
{
    cout << "|" << setw(3) << "---|" << setw(15) << "---------------|" << setw(15) << "---------------|" << setw(15) << "---------------|" << setw(15) << "---------------|" << setw(15) << "---------------|" << endl;
}

int main()
{
    float x0, x1, x2;
    int i = 1;
    cout << "Enter the range: " << endl;
    cout << "x1= ";
    cin >> x1;
    cout << "x2= ";
    cin >> x2;

    table();
    cout << "|" << setw(3) << "itn"
         << "|" << setw(15) << "x1"
         << "|" << setw(15) << "x2"
         << "|" << setw(15) << " f(x1) "
         << "|" << setw(15) << "f(x2)"
         << "|" << setw(15) << "x3"
         << "|" << endl;
    table();
    do
    {
        x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        cout << "|" << setw(3) << i << "|" << setw(15) << setprecision(4) << x1 << "|" << setw(15) << setprecision(4) << x2 << "|" << setw(15) << setprecision(4) << f(x1) << "|" << setw(15) << setprecision(4) << f(x2) << "|" << setw(15) << setprecision(4) << x0 << "|" << endl;
        x1 = x2;
        table();
        x2 = x0;
        i++;
    } while (fabs(x2 - x1) > e);
    cout << "Required root = " << x1 << endl;
}