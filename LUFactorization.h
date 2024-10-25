
/*
#include<bits/stdc++.h>

using namespace std;

// Function to perform LU factorization
void LU_Factorization(const vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U)
{
    int n = A.size();

    // Initialize L and U
    L.assign(n, vector<double>(n, 0));
    U.assign(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                L[j][i] = 0; // Lower triangular part
            }
            else
            {
                U[i][j] = A[i][j]; // Upper triangular part
            }
        }

        for (int j = i; j < n; j++)
        {
            L[j][i] = A[j][i]; // Copy elements to L
            for (int k = 0; k < i; k++)
            {
                L[j][i] -= L[j][k] * U[k][i]; // Subtract the already calculated elements
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            U[i][j] /= L[i][i]; // Normalize the row in U
        }
    }
}

// Function to perform forward substitution
vector<double> forward_substitution(const vector<vector<double>> &L, const vector<double> &b)
{
    int n = L.size();
    vector<double> y(n);

    for (int i = 0; i < n; i++)
    {
        y[i] = b[i];
        for (int j = 0; j < i; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
        y[i] /= L[i][i]; // Normalize
    }

    return y;
}

// Function to perform backward substitution
vector<double> backward_substitution(const vector<vector<double>> &U, const vector<double> &y)
{
    int n = U.size();
    vector<double> x(n);

    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= U[i][j] * x[j];
        }
    }

    return x;
}

// Function to solve the linear equations using LU factorization
void LUFactorization()
{
    int n;
    cout << "Enter the number of equations (and variables): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter the coefficients of the equations (each equation in a new line):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter the constant terms (right-hand side):" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    vector<vector<double>> L, U;

    // Perform LU factorization
    LU_Factorization(A, L, U);

    // Perform forward substitution to solve Ly = b
    vector<double> y = forward_substitution(L, b);

    // Perform backward substitution to solve Ux = y
    vector<double> x = backward_substitution(U, y);

    // Output the results
    cout << "The solutions (roots) are:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << x[i] << endl;
    }
}

*/
#include <bits/stdc++.h>
using namespace std;

// Function to perform LU factorization
void LU_Factorization(const vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U)
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
                L[j][i] -= L[j][k] * U[k][i];
            }
            L[j][i] /= U[i][i];
        }
    }
}


vector<double> forward_substitution( vector<vector<double>> &L,  vector<double> &b)
{
    int n =L.size();
    vector<double>y(n);

    for (int i = 0;i < n; i++)
    {
        y[i] =b[i];
        for (int j =0;j<i;j++)
        {
            y[i] -= L[i][j] * y[j];
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
        for (int j = i + 1; j < n; j++)
        {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    return x;
}


void LUFactorization()
{
    int n;
    cout<<"Enter the number of equations (and variables): ";
    cin>>n;

    vector<vector<double>>A(n, vector<double>(n));
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
