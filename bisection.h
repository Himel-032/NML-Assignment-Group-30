#ifndef BISECTION_H
#define BISECTION_H

#include <bits/stdc++.h>
using namespace std;

const double TOLERANCE = 1e-6;

int d;
vector<double> coeffs_bisec;
double intervalStart;
double intervalEnd;

void get_inputs_false()
{
    cout << "Enter the highest power of x: ";
    cin >> d;
    coeffs_bisec.resize(d + 1);

    cout << "Enter the coefficients (from highest degree to lowest): ";
    for (int i = 0; i <= d; i++)
    {
        cin >> coeffs_bisec[i];
    }

    cout << "Enter the interval (start end): ";
    cin >> intervalStart >> intervalEnd;
}

double evaluate_bisection(double x)
{
    double result = 0.0;
    for (int i = 0; i <= d; i++)
    {
        result += coeffs_bisec[i] * pow(x, d - i);
    }
    return result;
}

bool is_root_false(double x)
{
    return abs(evaluate_bisection(x)) < TOLERANCE;
}

double bisection(double a, double b)
{
    double mid;
    while ((b - a) >= TOLERANCE)
    {
        mid = (a + b) / 2.0;
        double f_mid = evaluate_bisection(mid);

        if (is_root_false(mid))
        {
            return mid;
        }

        if (evaluate_bisection(a) * f_mid < 0)
        {
            b = mid;
        }
        else
        {
            a = mid;
        }
    }
    return mid;
}

void find_roots_false()
{
    vector<double> roots;
    double step = 0.1;

    for (double x = intervalStart; x < intervalEnd; x += step)
    {
        double a = x;
        double b = x + step;

        if (evaluate_bisection(a) * evaluate_bisection(b) < 0)
        {
            double root = bisection(a, b);

            if (roots.empty() || abs(root - roots.back()) >= TOLERANCE)
            {
                roots.push_back(root);
            }
        }
    }

    cout << "Roots found in the interval [" << intervalStart << ", " << intervalEnd << "]:\n";
    for (double root : roots)
    {
        cout << fixed << setprecision(3) << root << " ";
    }
    cout << endl;
}

void bisection()
{
    get_inputs_false();
    find_roots_false();
}

#endif // BISECTION_H