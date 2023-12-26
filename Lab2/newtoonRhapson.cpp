#include <iostream>
#include <math.h>
#include <iomanip>
#define f(x) (x - cos(x))
#define fd(x) (1 + sin(x))
#define e 0.0001

using namespace std;

int main()
{
    float x0, x1, temp;
    int i;
    do
    {
        cout << "Enter the first estimation of x0 : " << endl;
        cin >> x0;
    } while (fd(x0) == 0);
    cout << "|" << setw(3) << "---|" << setw(15) << "---------------|" << setw(15) << "---------------|" << setw(15) << "---------------|" << setw(15) << "---------------|" << endl;
    cout << "|" << setw(3) << "itn"
         << "|" << setw(15) << "x0"
         << "|" << setw(15) << "f(x0)"
         << "|" << setw(15) << "f'(x0)"
         << "|" << setw(15) << "x1"
         << "|" << endl;
    cout << "|" << setw(3) << "___|" << setw(15) << "_______________|" << setw(15) << "_______________|" << setw(15) << "_______________|" << setw(15) << "_______________|" << endl;
    i = 1;
    do
    {
        temp = x0;
        x1 = x0 - (f(x0) / fd(x0));
        x0 = x1;
        cout << "|" << setw(3) << i << "|" << setw(15) << setprecision(4) << temp << "|" << setw(15) << setprecision(4) << f(temp) << "|" << setw(15) << setprecision(4) << fd(temp) << "|" << setw(15) << setprecision(4) << x0 << "|" << endl;
        cout << "|" << setw(3) << "___|" << setw(15) << "_______________|" << setw(15) << "_______________|" << setw(15) << "_______________|" << setw(15) << "_______________|" << endl;
        i++;
    } while (fabs(x1 - temp) > e);
    cout << "Required root of the function = " << x0 << endl;
}