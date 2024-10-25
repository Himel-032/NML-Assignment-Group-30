#ifndef FALSE_POSITION_H
#define FALSE_POSITION_H

#include <vector>
#include <cmath>
#include <iostream>
#include <set>
#include <iomanip>

using namespace std;
double evaluate_Polynomial(const vector<double> &coeffs, double x)
{
    double result = 0.0;
    int degree = coeffs.size() - 1;
    for (int i = 0; i <= degree; ++i)
    {
        result += coeffs[i] * pow(x, degree - i);
    }
    return result;
}

double falsePositionSingleRoot(const vector<double> &coeffs, double a, double b, double tol)
{
    double c;

    while ((b - a) >= tol)
    {

        c = a - (evaluate_Polynomial(coeffs, a) * (b - a)) / (evaluate_Polynomial(coeffs, b) - evaluate_Polynomial(coeffs, a));

        if (fabs(evaluate_Polynomial(coeffs, c)) < tol)
        {
            return c;
        }

        if (evaluate_Polynomial(coeffs, c) * evaluate_Polynomial(coeffs, a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    return c;
}

void false_position()
{
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    degree++;

    vector<double> coeffs(degree);
    cout << "Enter the coefficients of the polynomial from highest degree to lowest (constant last):" << endl;
    for (int i = 0; i < degree; ++i)
    {
        cin >> coeffs[i];
    }

    double tol = 0.0001;

    char choice;
    cout << "Do you want to set a custom tolerance (y/n)? ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter the tolerance (error threshold): ";
        cin >> tol;
    }

    int numIntervals;
    cout << "Enter the number of intervals you want to search for roots: ";
    cin >> numIntervals;

    set<double> roots;

    for (int i = 0; i < numIntervals; ++i)
    {
        double a, b;
        cout << "Enter interval " << i + 1 << " (e.g., -10 10): ";
        cin >> a >> b;

        double fa = evaluate_Polynomial(coeffs, a);
        double fb = evaluate_Polynomial(coeffs, b);

        if (fabs(fa) < tol)
        {
            roots.insert(a);
            cout << "Root found at endpoint: " << fixed << setprecision(4) << a << endl;
        }

        if (fabs(fb) < tol)
        {
            roots.insert(b);
            cout << "Root found at endpoint: " << fixed << setprecision(4) << b << endl;
        }

        if (fa * fb < 0)
        {
            double root = falsePositionSingleRoot(coeffs, a, b, tol);
            roots.insert(root);

            cout << "Root found in the interval (" << a << ", " << b << "): " << fixed << setprecision(4) << root << endl;
        }
        else if (fa == 0 || fb == 0)
        {

            cout << "Root found at endpoint in the interval (" << a << ", " << b << ")." << endl;
        }
        else
        {
            cout << "No sign change in the interval (" << a << ", " << b << "). "
                 << "f(" << a << ") = " << fa << ", f(" << b << ") = " << fb << ". No root found." << endl;
        }
    }

    if (roots.empty())
    {
        cout << "No roots found in the specified intervals." << endl;
    }
    else
    {
        cout << "Roots found:" << endl;
        for (double root : roots)
        {
            cout << fixed << setprecision(4) << root << endl;
        }
    }
}

#endif
