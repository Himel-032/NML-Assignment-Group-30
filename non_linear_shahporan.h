#include <bits/stdc++.h>
#include "bisection.h"
#include "false_position.h"
#include "secant.h"
#include "newton_raphson.h"

using namespace std;

int non_linear()
{
    int method;
    cout << "Select the method to use:\n1. Bisection\n2. False Position\n3. Secant\n4. Newton-Raphson\n";
    cout << "Give Number (1-4): " << endl;
    cin >> method;

    switch (method)
    {
    case 1:
    {
        bisection();
        break;
    }
    case 2:
    {
        false_position();
        break;
    }
    case 3:
    {
        secant();
        break;
    }
    case 4:
    {
        newton_raphson();
        break;
    }
    default:
        cout << "Invalid choice. Please select a method between 1 and 4." << endl;
        break;
    }

    return 0;
}