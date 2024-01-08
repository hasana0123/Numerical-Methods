#include <iostream>
using namespace std;

int main() {
    float x[5],y[5],xf,sum;
    cout<<"Enter the values of x and y: "<<endl;
    for(int i =1;i<=5;i++)
    {
        cout<<"x"<<i<<"= ";
        cin>>x[i];
        cout<<"y"<<i<<"=";
        cin>>y[i];
    }
    
    cout<<"Enter the number at which value is to found: ==> ";
    cin>>xf;
    
    for(int i =1;i<=5;i++)
    {
        float mul =1;
        for(int j =1;j<=5;j++)
        {
            if(i!=j)
                mul = mul*((xf-x[j])/(x[i]-x[j]));
        }
        sum=sum+mul*y[i];
    }
    cout<<"Result===>"<<sum<<endl;
}