#include <bits/stdc++.h>
using namespace std;
bool isDiagonallyDominant(vector<vector<double>> & coefficients,int n)
{
    for(int i=0;i<n;i++)
    {
        double diagonal=abs(coefficients[i][i]);
        double sum=0;
        for(int j=0;j<n;j++)
        {
            if(i != j)
            sum += abs(coefficients[i][j]);
        }
        if(diagonal<sum)
        return false; // not dominant in diagonally
    }
    return true;
}
bool makeDiagonallyDominant(vector<vector<double>> & coefficients,int n)
{
    for(int i=0;i<n;i++)
    {
        double maxDiagonal=abs(coefficients[i][i]);
        int maxRow = i;
        for(int r=i+1;r<n;r++)
        {
            if(abs(coefficients[r][i])>maxDiagonal)
            {
                maxDiagonal = abs(coefficients[r][i]);
                maxRow=r;
            }
        }
        if(maxRow != i)
        {
            swap(coefficients[i],coefficients[maxRow]);
        }
    }

    return isDiagonallyDominant(coefficients,n);
}
double calculateSolution(vector<vector<double>> &coefficients, vector<double> &currValues, int i, int n)
{
    double constant =coefficients[i][n];
    for (int j =0; j < n; j++)
    {
        if (i == j)
            continue;

        constant -= coefficients[i][j] * currValues[j];
    }
    return constant / coefficients[i][i];
}
void JacobiIterativeMethod()
{
    cout<<setprecision(5)<<fixed;
    cout << "Enter the number of unknowns:";
    int n;
    cin >> n;
    vector<vector<double>>coefficients(n, vector<double>(n + 1));
    // vector<double> constants(n);

    cout << "Enter the coefficients and constants of the equations(Form: ax + by +cz + .... = d):" << endl;
    for (int i =0; i < n; i++)
    {
        for (int j =0; j <= n; j++)
        {
            cin >>coefficients[i][j];
        }
    }

    if(isDiagonallyDominant(coefficients,n) == false)
    {
        if(makeDiagonallyDominant(coefficients,n) == false)
        {
            cout<<"Could not make the matrix Diagonally Dominant.."<<endl;
            return;
        }
    }


    double tolerance = 1e-6;
    int maxIt = 20000;
    vector<double> currValues(n, 0), newValues(n, 0);
    for (int it = 1; it <= maxIt; it++)
    {
        bool flag = true; // checking convergency
        for (int i =0; i < n; i++)
        {
            newValues[i] =calculateSolution(coefficients, currValues, i, n);
            if(abs(newValues[i]-currValues[i])>tolerance)
            flag=false;

            
        }
       // for(int i=0;i<n;i++)
        currValues =newValues;

        if(flag ==true)
        break;
    }
    cout<<"Solutions of the unknowns are(Jacobi Iteration Method): ";
    for(int i=0;i<n;i++)
    {
        cout<<currValues[i]<<' ';
    }
    cout<<endl<<endl;;
}