#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#include <bits/stdc++.h>

using namespace std;

double polynomial_newton(double x, const vector<double> &coefficients)
{
    double result = 0.0;
    int degree = coefficients.size() - 1;
    for (int i = 0; i <= degree; ++i)
    {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

double polynomialDerivative(double x, const vector<double> &coefficients)
{
    double result = 0.0;
    int degree = coefficients.size() - 1;
    for (int i = 0; i < degree; ++i)
    {
        result += coefficients[i] * (degree - i) * pow(x, degree - i - 1);
    }
    return result;
}

double newtonRaphson(double initial_guess, const vector<double> &coefficients, double epsilon, int max_iterations)
{
    double x_n = initial_guess;
    for (int iteration = 0; iteration < max_iterations; ++iteration)
    {
        double f_x_n = polynomial_newton(x_n, coefficients);
        double f_prime_x_n = polynomialDerivative(x_n, coefficients);

        if (fabs(f_prime_x_n) < epsilon)
        {
            return NAN;
        }

        double x_n_plus_1 = x_n - f_x_n / f_prime_x_n;

        if (fabs(x_n_plus_1 - x_n) < epsilon)
        {
            return x_n_plus_1;
        }

        x_n = x_n_plus_1;
    }
    return NAN;
}

void newton_raphson()
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
    set<double> uniqueRoots;

    for (double i = -10; i <= 20; i += 1)
    {
        double root = newtonRaphson(i, coefficients, epsilon, max_iterations);
        if (!isnan(root))
        {
            bool isUnique = true;
            for (const auto &uniqueRoot : uniqueRoots)
            {
                if (fabs(root - uniqueRoot) < epsilon)
                {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique)
            {
                uniqueRoots.insert(root);
            }
        }
    }

    cout << fixed << setprecision(4);
    cout << "Approximate roots of the polynomial are:\n";
    for (const auto &root : uniqueRoots)
    {
        cout << root << " ";
    }
    cout << endl;
}

#endif