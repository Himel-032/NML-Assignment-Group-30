#include<bits/stdc++.h>
#include"SolveLinearBy_Himel.h"
#include"RK4_Himel.h"

using namespace std;
int main()
{
   
    cout<<"1.Solve Linear equations: "<<endl;
    cout<<"2.Solve Non-Linear equations: "<<endl;
    cout<<"3.Solve Differential Equation(Runge - Kutta Method): "<<endl;
    cout<<"4.Matrix Inversion: "<<endl<<endl; 
    cout<<"Enter the operation you want to solve : ";
    
    int cs; cin>>cs;
    cout<<endl; 
    switch(cs){
        case 1: solveLinear();
        break;
        /*case 2: 
            break;
        */
        case 3:
            solveDifferentialEquation();
            break;
            /*
        case 4:
            MakeInverse();
            break;
            */
         
        default :
         cout<<"Invalid selection!"<<endl;
    }

}