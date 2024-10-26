#ifndef BISECTION_H
#define BISECTION_H

#include <bits/stdc++.h>

using namespace std;

double polynomial_bs(double x, const vector<double> &coefficients)
{
    double result = 0.0;
    int degree = coefficients.size() - 1;
    for (int i = 0; i <= degree; ++i)
    {
        result += coefficients[i] * pow(x, degree - i);
    }
    return result;
}

double find_Root_InInterval(double a, double b, const vector<double> &coefficients, double epsilon, int max_iterations)
{
    double f_a = polynomial_bs(a, coefficients);
    double f_b = polynomial_bs(b, coefficients);

    if (f_a * f_b > 0)
    {
        return NAN;
    }

    int iteration = 0;
    double c;
    while (fabs(b - a) > epsilon && iteration < max_iterations)
    {
        c = (a + b) / 2;
        double f_c = polynomial_bs(c, coefficients);

        if (fabs(f_c) < epsilon)
        {
            return c;
        }

        if (f_a * f_c < 0)
        {
            b = c;
        }
        else
        {
            a = c;
            f_a = f_c;
        }
        iteration++;
    }

    return (a + b) / 2;
}

void bisection()
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

    int num_subintervals = 200;
    double step = (upper_bound - lower_bound) / num_subintervals;

    for (int i = 0; i < num_subintervals; ++i)
    {
        double a = lower_bound + i * step;
        double b = a + step;

        double root = find_Root_InInterval(a, b, coefficients, epsilon, max_iterations);
        if (!isnan(root))
        {
            bool is_repeated = false;
            for (const double &r : roots)
            {
                if (fabs(r - root) < epsilon)
                {
                    is_repeated = true;
                    break;
                }
            }
            if (!is_repeated)
            {
                roots.push_back(root);
            }
        }
    }

    cout << "Approximate roots of the polynomial are:\n";
    for (const auto &root : roots)
    {
        cout << root << endl;
    }
}

#endif