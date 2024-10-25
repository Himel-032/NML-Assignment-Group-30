
#include <bits/stdc++.h>
using namespace std;

// Function to perform LU factorization
void LU_Factorization( vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U)
{
    int n = A.size();

    
    L.assign(n,vector<double>(n,0));
    U.assign(n,vector<double>(n,0));

    for (int i =0; i < n; i++)
    {
       
        L[i][i]=1;  // diagonal elements of l must be 1

        for (int j =i; j < n; j++)
        {
           
            U[i][j] =A[i][j];
            for (int k = 0; k < i; k++)
            {
                U[i][j] -= L[i][k] * U[k][j];
            }
        }

        for (int j =i+1;j<n;j++)
        {
            
            L[j][i] = A[j][i];
            for (int k=0;k<i;k++)
            {
                L[j][i] -= L[j][k] *U[k][i];
            }
            L[j][i] /=U[i][i];
        }
    }
}


vector<double> forward_substitution( vector<vector<double>> &L,  vector<double> &b)
{
    int n =L.size();
    vector<double>y(n);

    for (int i =0;i < n; i++)
    {
        y[i] =b[i];
        for (int j =0;j<i;j++)
        {
            y[i] -= L[i][j]*y[j];
        }
        y[i] /= L[i][i];
    }

    return y;
}


vector<double> backward_substitution( vector<vector<double>> &U,  vector<double> &y)
{
    int n = U.size();
    vector<double> x(n);

    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (int j = i + 1;j<n; j++)
        {
            x[i] -=U[i][j]*x[j];
        }
        x[i] /=U[i][i];
    }

    return x;
}


void LUFactorization()
{
    int n;
    cout<<"Enter the number of equations (and variables): ";
    cin>>n;

    vector<vector<double>>A(n,vector<double>(n));
    vector<double>b(n);

    cout<<"Enter the coefficients of the equations (each equation in a new line):" << endl;
    for (int i =0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }

    cout << "Enter the constant terms (right-hand side):" << endl;
    for (int i =0;i<n;i++)
    {
        cin>>b[i];
    }

    vector<vector<double>>L,U;

   
    LU_Factorization(A,L,U);

    // solve Ly = b
    vector<double> y = forward_substitution(L,b);

    // solve Ux = y
    vector<double>x=backward_substitution(U,y);

    
    cout << "The solutions (roots) are:"<<endl;
    for (int i =0; i<n;i++)
    {
        cout<<"x"<<i+1<<" = "<<fixed<<setprecision(4)<<x[i]<< endl;
    }
}
