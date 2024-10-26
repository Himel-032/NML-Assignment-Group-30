#include <bits/stdc++.h>
#include "SolveLinearBy_Himel.h"
#include "RK4_Himel.h"
#include "non_linear_shahporan.h"
#include "MatrixInversion.h"

using namespace std;
int main()
{
    cout<<"Numercal Methods Laboratory Assignment"<<endl<<"Group No- 30"<<endl<<endl;
    while (1)
    {
        cout << "1.Solve Linear equations: " << endl;
        cout << "2.Solve Non-Linear equations: " << endl;
        cout << "3.Solve Differential Equation(Runge - Kutta Method): " << endl;
        cout << "4.Matrix Inversion: "<<endl<< endl;
        cout << "Enter the operation you want to solve : ";

        int cs;
        cin >> cs;
        cout << endl;
        switch (cs)
        {
        case 1:
            solveLinear();
            break;
        case 2:
            non_linear();
            break;
        case 3:
            solveDifferentialEquation();
            break;
        case 4:
            MakeInverse();
            break;
        default:
            cout << "Invalid selection!" << endl;
        }
        cout<<"Do you want to solve more(y/n)?:  ";
        char ch; cin>>ch;
        if(ch=='n' || ch=='N')
        {
            cout<<"You are successfully Exited from the application.."<<endl;
            break;
        }
        else
        {
            continue;
        }
    }
}