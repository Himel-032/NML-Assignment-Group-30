// #ifndef BISECTION_H
#define BISECTION_H

#include <vector>
#include <cmath>
#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

double evaluate(const vector<double> &coeffs, double x)
{
    double result = 0.0;
    int degree = coeffs.size() - 1;
    for (int i = 0; i <= degree; ++i)
    {
        result += coeffs[i] * pow(x, degree - i);
    }
    return result;
}

double bisectionSingleRoot(const vector<double> &coeffs, double a, double b, double tol)
{
    double c = a;
    while ((b - a) >= tol)
    {
        c = (a + b) / 2;

        if (fabs(evaluate(coeffs, c)) < tol)
        {
            return c;
        }

        if (evaluate(coeffs, c) * evaluate(coeffs, a) < 0)
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

void findRootsInInterval(const vector<double> &coeffs, double a, double b, double tol, set<double> &roots)
{
    double fa = evaluate(coeffs, a);
    double fb = evaluate(coeffs, b);

    if (fabs(fa) < tol)
    {
        roots.insert(a);
    }
    if (fabs(fb) < tol)
    {
        roots.insert(b);
    }

    if (fa * fb < 0)
    {
        double root = bisectionSingleRoot(coeffs, a, b, tol);

        bool isNewRoot = true;
        for (double knownRoot : roots)
        {
            if (fabs(knownRoot - root) < tol)
            {
                isNewRoot = false;
                break;
            }
        }

        if (isNewRoot)
        {
            roots.insert(root);

            double delta = tol * 10;

            if (root - a > delta)
            {
                findRootsInInterval(coeffs, a, root - delta, tol, roots);
            }
            if (b - root > delta)
            {
                findRootsInInterval(coeffs, root + delta, b, tol, roots);
            }
        }
    }
}

void bisection()
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

        findRootsInInterval(coeffs, a, b, tol, roots);
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
