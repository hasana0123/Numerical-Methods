#include <iostream>
 
using namespace std;
 
    // int inputNum(int numEqn)
    // {
    //     cout<<"Enter the number of equations: ";
    //     cin>> numEqn;
    //     return numEqn;
    // }
    
    // void inputMat(int numEqn,int* mat)
    // {
    //     for(int i=0;i<numEqn;i++)
    //     {
    //         for(int j=0;j<numEqn+1;j++)
    //         {
    //             cout<<"mat"<<i<<j<<"= ";
    //             cin>>*mat;
    //             mat++;
    //         }
    //     }
    // }
    // void Operation1()
    // {
    //     float fact;
    //     for(int i =0;i<=numEqn-1;i++)
    //     {
    //         for(int j=i+1;j<=numEqn;j++)
    //         {
    //             fact = mat[j][i]/mat[i][i];
    //             for(int k=1; k<=numEqn+1)
    //             {
    //                 mat[j][k]=mat[j][k]-fact*mat[i][k]
    //             }
    //         }
    //     }
    //     x[numEqn]=mat[numEqn][numEqn+1]/mat[n][n];
        
    // }
    // float BackSub()
    // {
    //     float sum;
    //     for(int i=numEqn-1;i>=1;i++)
    //     {
    //         sum=0;
    //         for(int j=i+1;j<numEqn;j++)
    //         {
    //             sum=sum+mat[i][j]*x[j];
    //         }
    //         x[i]=(mat[i][numEqn+1])/mat[i][i];
    //     }
    //     cout<<x[i];
    // }
 
 
 
 
int main() {
     float fact;
     int numEqn;
     float sum;
    int mat[numEqn][numEqn+1];
      cout<<"Enter the number of equations: ";
        cin>> numEqn;
    float x[numEqn];
      for(int i=1;i<=numEqn;i++)
        {
            for(int j=0;j<numEqn+1;j++)
            {
                cout<<"mat"<<i<<j<<"= ";
                cin>>mat[i][j];
            }
        }
     
        for(int i =1;i<=numEqn-1;i++)
        {
            for(int j=i+1;j<=numEqn;j++)
            {
                fact = mat[j][i]/mat[i][i];
                for(int k=1; k<=numEqn+1;k++)
                {
                    mat[j][k]=mat[j][k]-fact*mat[i][k];
                }
            }
        }
        x[numEqn]=mat[numEqn][numEqn+1]/mat[numEqn][numEqn];
    
        for(int i=numEqn-1;i>=1;i++)
        {
            sum=0;
            for(int j=i+1;j<numEqn;j++)
            {
                sum=sum+mat[i][j]*x[j];
            }
            x[i]=(mat[i][numEqn+1])/mat[i][i];
        cout<<x[i];
        }
    
}