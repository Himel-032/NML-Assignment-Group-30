#ifndef FALSE_POSITION_METHOD_H
#define FALSE_POSITION_METHOD_H

#include <bits/stdc++.h>

using namespace std;

double TOLERANCE_false_position = 1e-6;
int degree_false_position;
vector<double> coeffs_false_position;

double evaluate_false_position(double x)
{
    double result = 0.0;
    int degree = coeffs_false_position.size() - 1;
    for (int i = 0; i <= degree; ++i)
    {
        result += coeffs_false_position[i] * pow(x, degree - i);
    }
    return result;
}

double findRootFalsePosition(double a, double b, const vector<double> &coefficients, double epsilon, int max_iterations)
{
    double f_a = evaluate_false_position(a);
    double f_b = evaluate_false_position(b);

    if (f_a * f_b > 0)
    {
        return NAN;
    }

    double c;
    int iteration = 0;
    while (fabs(b - a) > epsilon && iteration < max_iterations)
    {
        c = (a * f_b - b * f_a) / (f_b - f_a);
        double f_c = evaluate_false_position(c);

        if (fabs(f_c) < epsilon)
        {
            return c;
        }

        if (f_a * f_c < 0)
        {
            b = c;
            f_b = f_c;
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

void false_position()
{
    cout << "Enter the degree (power) of the polynomial: ";
    cin >> degree_false_position;
    coeffs_false_position.resize(degree_false_position + 1);

    cout << "Enter the coefficients (highest to lowest degree): ";
    for (int i = 0; i <= degree_false_position; i++)
    {
        cin >> coeffs_false_position[i];
    }

    double epsilon = 1e-6;
    int max_iterations = 1000;
    vector<double> roots;

    double a_n = coeffs_false_position[0];
    double a_n_minus_1 = (degree_false_position >= 1) ? coeffs_false_position[1] : 0;
    double x_max = abs(-a_n_minus_1 / a_n);

    double interval_limit = x_max;
    if (degree_false_position >= 2)
    {
        double a_n_minus_2 = coeffs_false_position[2];
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

        double root = findRootFalsePosition(a, b, coeffs_false_position, epsilon, max_iterations);
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

    cout << "Roots found using False Position Method:\n";
    for (const auto &root : roots)
    {
        cout << fixed << setprecision(6) << root << endl;
    }
}

#endif