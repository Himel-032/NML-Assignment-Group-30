#ifndef FALSE_POSITION_FP_H
#define FALSE_POSITION_FP_H

#include <bits/stdc++.h>
using namespace std;

const double TOLERANCE_FP = 1e-6;
const int MAX_ITERATIONS_FP = 100;

int degree_fp;
vector<double> coeffs_fp;
double interval_start_fp;
double interval_end_fp;

void get_inputs_fp()
{
    cout << "Enter the highest power of x: ";
    cin >> degree_fp;
    coeffs_fp.resize(degree_fp + 1);

    cout << "Enter the coefficients (from highest degree to lowest): ";
    for (int i = 0; i <= degree_fp; i++)
    {
        cin >> coeffs_fp[i];
    }

    cout << "Enter the interval (start end): ";
    cin >> interval_start_fp >> interval_end_fp;
}

double evaluate_fp(double x)
{
    double result = 0.0;
    for (int i = 0; i <= degree_fp; i++)
    {
        result += coeffs_fp[i] * pow(x, degree_fp - i);
    }
    return result;
}

bool is_root_fp(double x)
{
    return abs(evaluate_fp(x)) < TOLERANCE_FP;
}

double false_position_fp(double a, double b)
{
    double c = a;
    for (int i = 0; i < MAX_ITERATIONS_FP; i++)
    {
        double fa = evaluate_fp(a);
        double fb = evaluate_fp(b);
        c = (a * fb - b * fa) / (fb - fa);
        double fc = evaluate_fp(c);

        if (is_root_fp(c))
        {
            return c;
        }

        if (fa * fc < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }

        if (abs(b - a) < TOLERANCE_FP)
        {
            return c;
        }
    }
    return c;
}

void find_roots_fp()
{
    vector<double> roots_fp;
    double step_fp = 0.1;

    for (double x = interval_start_fp; x < interval_end_fp; x += step_fp)
    {
        double a = x;
        double b = x + step_fp;

        if (evaluate_fp(a) * evaluate_fp(b) < 0)
        {
            double root = false_position_fp(a, b);

            if (roots_fp.empty() || abs(root - roots_fp.back()) >= TOLERANCE_FP)
            {
                roots_fp.push_back(root);
            }
        }
    }

    cout << "Roots found in the interval [" << interval_start_fp << ", " << interval_end_fp << "]:\n";
    for (double root : roots_fp)
    {
        cout << fixed << setprecision(3) << root << " ";
    }
    cout << endl;
}

void false_position()
{
    get_inputs_fp();
    find_roots_fp();
}

#endif