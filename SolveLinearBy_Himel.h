#include <bits/stdc++.h>
#include "JacobiMethod.h"
#include "GaussSeidel.h"
#include "GaussElimination.h"
#include "GaussJordanElimination.h"
#include "LUFactorization.h"
using namespace std;
void solveLinear()
{
    
    cout<<"1. Jacobi Iteration Method "<<endl;
    cout<<"2. Gauss-Seidel Iterative Method"<<endl;
    cout<<"3. Gauss Elimination Method"<<endl;
    cout<<"4. Gauss Jordan Elimination Method"<<endl;
    cout<<"5. LU Factorization Method"<<endl<<endl;
    cout<<"Enter the method of solution you want to use : ";

    int cs; cin >> cs;
    cout<<endl;
    switch (cs)
    {
    case 1:
        JacobiIterativeMethod();
        break;

    case 2:
        GaussSeidelIterativeMethod();
        break;

    case 3:
        GaussEliminationMethod();
        break;

    case 4:
        GaussJordanEliminationMethod();
        break;
      
    case 5 : LUFactorization();
        break;
      
    default:
        cout<<"Invalid selection!"<<endl;
        return;
      
    }
    return;
}