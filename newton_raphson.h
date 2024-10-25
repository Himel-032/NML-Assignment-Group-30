#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#include <vector>
#include <cmath>
#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

double evaluate_polynomial(const vector<double> &coeffs, double x)
{
    double result = 0.0;
    int degree = coeffs.size() - 1;
    for (int i = 0; i <= degree; ++i)
    {
        result += coeffs[i] * pow(x, degree - i);
    }
    return result;
}

double evaluate_derivative(const vector<double> &coeffs, double x)
{
    double result = 0.0;
    int degree = coeffs.size() - 1;
    for (int i = 0; i < degree; ++i)
    {
        result += coeffs[i] * (degree - i) * pow(x, degree - i - 1);
    }
    return result;
}

double newtonRaphsonMethod(const vector<double> &coeffs, double x0, double tol, int maxIter)
{
    double x1;
    for (int i = 0; i < maxIter; ++i)
    {
        double f0 = evaluate_polynomial(coeffs, x0);
        double f0_prime = evaluate_derivative(coeffs, x0);

        if (fabs(f0_prime) < tol)
        {
            cout << "Derivative too small, stopping iteration." << endl;
            return x0;
        }

        x1 = x0 - f0 / f0_prime;

        if (fabs(x1 - x0) < tol)
        {
            return x1;
        }

        x0 = x1;
    }

    return x1;
}

void newton_raphson()
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
    int maxIter = 100;

    char choice;
    cout << "Do you want to set a custom tolerance (y/n)? ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter the tolerance (error threshold): ";
        cin >> tol;
    }

    int numInitialGuesses;
    cout << "Enter the number of initial guesses you want to search for roots: ";
    cin >> numInitialGuesses;

    set<double> roots;

    for (int i = 0; i < numInitialGuesses; ++i)
    {
        double x0;
        cout << "Enter initial guess " << i + 1 << ": ";
        cin >> x0;

        double root = newtonRaphsonMethod(coeffs, x0, tol, maxIter);
        roots.insert(root);
        cout << "Root found: " << fixed << setprecision(4) << root << endl;
    }

    if (roots.empty())
    {
        cout << "No roots found in the specified intervals." << endl;
    }
    else
    {
        cout << "Unique roots found:" << endl;
        for (double root : roots)
        {
            cout << fixed << setprecision(4) << root << endl;
        }
    }
}

#endif
