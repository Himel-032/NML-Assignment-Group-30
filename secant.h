#ifndef SECANT_SC_H
#define SECANT_SC_H

#include <bits/stdc++.h>
using namespace std;

const double TOLERANCE_SC = 1e-6;
const int MAX_ITERATIONS_SC = 100;

int degree_sc;
vector<double> coeffs_sc;
double interval_start_sc;
double interval_end_sc;

void get_inputs_sc()
{
    cout << "Enter the highest power of x: ";
    cin >> degree_sc;
    coeffs_sc.resize(degree_sc + 1);

    cout << "Enter the coefficients (from highest degree to lowest): ";
    for (int i = 0; i <= degree_sc; i++)
    {
        cin >> coeffs_sc[i];
    }

    cout << "Enter the interval (start end): ";
    cin >> interval_start_sc >> interval_end_sc;
}

double evaluate_sc(double x)
{
    double result = 0.0;
    for (int i = 0; i <= degree_sc; i++)
    {
        result += coeffs_sc[i] * pow(x, degree_sc - i);
    }
    return result;
}

bool is_root_sc(double x)
{
    return abs(evaluate_sc(x)) < TOLERANCE_SC;
}

double secant_method_sc(double x0, double x1)
{
    for (int i = 0; i < MAX_ITERATIONS_SC; i++)
    {
        double f_x0 = evaluate_sc(x0);
        double f_x1 = evaluate_sc(x1);

        if (abs(f_x1 - f_x0) < TOLERANCE_SC)
            break;

        double x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);

        if (is_root_sc(x2))
        {
            return x2;
        }

        x0 = x1;
        x1 = x2;

        if (abs(x1 - x0) < TOLERANCE_SC)
        {
            return x2;
        }
    }
    return x1;
}

void find_roots_sc()
{
    vector<double> roots_sc;
    double step_sc = 0.01;

    for (double x = interval_start_sc; x < interval_end_sc; x += step_sc)
    {
        double x0 = x;
        double x1 = x + step_sc;

        if (evaluate_sc(x0) * evaluate_sc(x1) < 0)
        {
            double root = secant_method_sc(x0, x1);

            bool isUnique = true;
            for (double r : roots_sc)
            {
                if (abs(root - r) < TOLERANCE_SC)
                {
                    isUnique = false;
                    break;
                }
            }

            if (isUnique)
            {
                roots_sc.push_back(root);
            }
        }
    }

    cout << "Roots found in the interval [" << interval_start_sc << ", " << interval_end_sc << "]:\n";
    for (double root : roots_sc)
    {
        cout << fixed << setprecision(3) << root << " ";
    }
    cout << endl;
}

void secant()
{
    get_inputs_sc();
    find_roots_sc();
}

#endif