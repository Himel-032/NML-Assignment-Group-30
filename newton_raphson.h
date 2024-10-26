#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

#include <bits/stdc++.h>
using namespace std;

double tolerance = 1e-6;
int maxIterations = 100;
int degree;
vector<double> coeffs;
double initialGuess;

void getInputs() {
    cout << "Enter the highest power of x: ";
    cin >> degree;
    coeffs.resize(degree + 1);
    cout << "Enter the coefficients (from highest degree to lowest): ";
    for (int i = 0; i <= degree; i++) {
        cin >> coeffs[i];
    }
    cout << "Enter the initial guess: ";
    cin >> initialGuess;
}

double evaluate(double x) {
    double result = 0.0;
    int currentDegree = coeffs.size() - 1;
    for (double coeff : coeffs) {
        result += coeff * pow(x, currentDegree--);
    }
    return result;
}

double numericalDerivative(double x) {
    double h = 1e-5;
    return (evaluate(x + h) - evaluate(x)) / h;
}

double newtonRaphsonMethod(double initialGuess) {
    double x = initialGuess;
    for (int i = 0; i < maxIterations; i++) {
        double f_x = evaluate(x);
        double f_prime_x = numericalDerivative(x);

        if (abs(f_prime_x) < tolerance) return x;

        double x_new = x - f_x / f_prime_x;
        if (abs(x_new - x) < tolerance) return x_new;

        x = x_new;
    }
    return x;
}

void findRoots() {
    set<double> roots;
    for (double guess = initialGuess - 1; guess <= initialGuess + 1; guess += 0.1) {
        double root = newtonRaphsonMethod(guess);

        bool isUnique = true;
        for (double r : roots) {
            if (abs(root - r) < tolerance) {
                isUnique = false;
                break;
            }
        }

        if (isUnique && abs(evaluate(root)) < tolerance) {
            roots.insert(root);
        }
    }

    cout << "Roots found:\n";
    for (double root : roots) {
        cout << fixed << setprecision(3) << root << " ";
    }
    cout << endl;
}

void newton_raphson() {
    getInputs();
    findRoots();
}

#endif
