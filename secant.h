#ifndef SECANT_H
#define SECANT_H

#include <bits/stdc++.h>
using namespace std;

double polynomial(double x, const vector<double> &coefficients)
{
    double result = 0.0;
    int degree = coefficients.size() - 1;
    for (int i = 0; i <= degree; ++i)
    {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

double findRootInInterval(double x0, double x1, const vector<double> &coefficients, double epsilon, int max_iterations)
{
    double f_x0 = polynomial(x0, coefficients);
    double f_x1 = polynomial(x1, coefficients);

    int iteration = 0;
    double x2;

    while (iteration < max_iterations)
    {
        if (fabs(f_x1 - f_x0) < epsilon)
        {
            return NAN;
        }

        x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);
        double f_x2 = polynomial(x2, coefficients);

        if (fabs(f_x2) < epsilon)
        {
            return x2;
        }

        x0 = x1;
        f_x0 = f_x1;
        x1 = x2;
        f_x1 = f_x2;

        iteration++;
    }

    return x2;
}

void secant()
{
    int power;
    cout << "Enter the degree (power) of the polynomial: ";
    cin >> power;

    vector<double> coefficients(power + 1);
    cout << "Enter the coefficients (highest to lowest degree): ";
    for (int i = 0; i <= power; ++i)
    {
        cin >> coefficients[i];
    }

    double epsilon = 1e-6;
    int max_iterations = 1000;
    vector<double> roots;

    double a_n = coefficients[0];
    double a_n_minus_1 = (power >= 1) ? coefficients[1] : 0;
    double x_max = abs(-a_n_minus_1 / a_n);

    double interval_limit = x_max;
    if (power >= 2)
    {
        double a_n_minus_2 = coefficients[2];
        interval_limit = sqrt(pow(a_n_minus_1 / a_n, 2) - 2 * (a_n_minus_2 / a_n));
    }

    double lower_bound = -interval_limit;
    double upper_bound = interval_limit;

    int num_subintervals = 100;
    double step = (upper_bound - lower_bound) / num_subintervals;

    for (int i = 0; i < num_subintervals; ++i)
    {
        double x0 = lower_bound + i * step;
        double x1 = x0 + step;

        double root = findRootInInterval(x0, x1, coefficients, epsilon, max_iterations);

        if (!isnan(root))
        {
            roots.push_back(root);
        }
    }

    set<double> uniqueRoots;
    for (const auto &root : roots)
    {
        bool foundClose = false;
        for (const auto &uniqueRoot : uniqueRoots)
        {
            if (fabs(root - uniqueRoot) < 0.1)
            {
                foundClose = true;
                break;
            }
        }
        if (!foundClose)
        {
            uniqueRoots.insert(root);
        }
    }

    cout << fixed << setprecision(4);
    cout << "Approximate roots of the polynomial are:\n";
    for (const auto &root : uniqueRoots)
    {
        cout << root << endl;
    }
}

#endif