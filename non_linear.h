#ifndef SOLVER_H
#define SOLVER_H

#include <bits/stdc++.h>
#include "bisection.h"
#include "false_position.h"
#include "secant.h"
#include "newton_raphson.h"


using namespace std;

void non_linear()
{
    cout << "Non-Linear Equation Solving System." << endl;
    cout << "1. Bi-Section" << endl;
    cout << "2. False Position" << endl;
    cout << "3. Secant " << endl;
    cout << "4. Newton-Raphson " << endl;
    cout << "Enter your choice (1-4): " << endl;

    int n;
    cin >> n;

    switch (n)
    {
    case 1:
        bisection();
        break;
    case 2:
        false_position();
        break;
    case 3:
        secant();
        break;
    case 4:
        newton_raphson();
        break;
   
    default:
        cout << "Invalid choice, please enter a number between 1-5." << endl;
        break;
    }
}

#endif // SOLVER_H
