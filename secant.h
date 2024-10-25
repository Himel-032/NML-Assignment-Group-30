#ifndef SECANT_H
#define SECANT_H

#include <vector>
#include <cmath>
#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

double evaluate_secant(const vector<double> &coeffs, double x)
{
    double result = 0.0;
    int degree = coeffs.size() - 1;
    for (int i = 0; i <= degree; ++i)
    {
        result += coeffs[i] * pow(x, degree - i);
    }
    return result;
}

double secantMethod(const vector<double> &coeffs, double x0, double x1, double tol, int max_iter = 100)
{
    double x2;

    for (int iter = 0; iter < max_iter; ++iter)
    {
        double f0 = evaluate_secant(coeffs, x0);
        double f1 = evaluate_secant(coeffs, x1);

        if (fabs(f1 - f0) < 1e-10)
        {
            cout << "Warning: Small denominator in secant method. Adjust your initial guesses." << endl;
            return x1;
        }

        x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

        if (fabs(x2 - x1) < tol)
        {
            return x2;
        }

        x0 = x1;
        x1 = x2;
    }

    cout << "Warning: Secant method did not converge within the maximum number of iterations." << endl;
    return x1;
}

void secant()
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
        double x0, x1;
        cout << "Enter two initial guesses for interval " << i + 1 << " (e.g., x0 x1): ";
        cin >> x0 >> x1;

        double f0 = evaluate_secant(coeffs, x0);
        double f1 = evaluate_secant(coeffs, x1);

        if (fabs(f0) < tol)
        {
            roots.insert(x0);
            cout << "Root found at endpoint: " << fixed << setprecision(4) << x0 << endl;
            continue;
        }

        if (fabs(f1) < tol)
        {
            roots.insert(x1);
            cout << "Root found at endpoint: " << fixed << setprecision(4) << x1 << endl;
            continue;
        }

        double root = secantMethod(coeffs, x0, x1, tol);
        roots.insert(root);
        cout << "Root found in the interval (" << x0 << ", " << x1 << "): " << fixed << setprecision(4) << root << endl;
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
