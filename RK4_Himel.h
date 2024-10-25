#include<bits/stdc++.h>
using namespace std;
double rk4(double x0, double y0, double xEnd, double h, function<double(double, double)> &f)
{
    double x =x0;
    double y =y0;

    while (x<=xEnd)
    {
        double k1 =h * f(x, y);
        double k2 =h * f(x + h / 2, y + k1 / 2);
        double k3 =h * f(x + h / 2, y + k2 / 2);
        double k4 =h * f(x + h, y + k3);
        y =y + (k1 + 2 * k2 + 2 * k3 + k4)/6;
        x =x + h;
    }
    return y;
}
void solveDifferentialEquation()
{
    cout<<setprecision(5)<<fixed;
   
    cout<<"1. dy/dx = x - y"<<endl;
    cout<<"2. dy/dx = y * sin(x)"<<endl;
    cout<<"3. dy/dx = 2x + 3y"<<endl;
    cout<<"4. dy/dx =  y/2 - x^2"<<endl<<endl; 
    cout<<"Select an equation type:";
    int cs; cin>>cs;
    cout<<endl;
    double x0,y0,xEnd,h;
    cout<<"Enter initial value of x: "; cin>>x0;
    cout<<"Enter inital value of y : "; cin>>y0;
    cout<<"Enter value of x where you need the solution: "; cin>>xEnd;
    cout<<"Enter the step size: "; cin>>h;


    function<double(double, double)> eqn;
    switch (cs)       // Lamda function for various equation
    {
    case 1:
        eqn =[](double x, double y) { return x - y; };
        break;
    case 2:
        eqn =[](double x, double y) { return y * sin(x); };
        break;
    case 3:
        eqn =[](double x, double y) { return 2*x + 3*y; };
        break;
    case 4:
        eqn =[](double x, double y) { return y/2 - x*x; };
        break;
    default:
        cout<<"Invalid selection!"<<endl;
        return;
    }
    double result = rk4(x0,y0,xEnd,h,eqn);
    cout<<"The solution at x = "<<xEnd<<" is: "<<result<<endl;

    return;
}