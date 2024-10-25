#include<bits/stdc++.h>
using namespace std;

// performing gauss elimination from GaussElimination.h header file

void JordanElimination(vector<vector<double>> &coefficients)
{
    int n=coefficients.size();
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                double frac=coefficients[j][i]/coefficients[i][i];
                for(int k=0;k<=n;k++)
                {
                    coefficients[j][k]=coefficients[j][k] - (coefficients[i][k]*frac); // making non diagonal element zero
                }
            }
        }
    }
}

void GaussJordanEliminationMethod()
{
    cout<<setprecision(5)<<fixed;
    cout<<"Enter the number of unknowns:";
    int n;
    cin>>n;
    vector<vector<double>>coefficients(n, vector<double>(n+1));

    cout<<"Enter the coefficients and constants of the equations(Form: ax+by+cz+..=d):"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cin>>coefficients[i][j];
        }
    }

    int temp=0;
    bool flag=GaussElimination(coefficients);
    if(flag==true)
        temp=checkConsistency(coefficients);
    if(temp==2) // temp=2 -> infinte solutions
    {
        cout<<"The system of Linear equations has infinite solutions."<<endl;
        return;
    }
    if(temp==3) // temp=3 -> no solutions
    {
        cout<<"The system has no solutions."<<endl;
        return;
    }

    cout<<"Matrix after Gaussian Elimination."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<coefficients[i][j]<<" "; // printing matrix
        }
        cout<<endl;
    }

    JordanElimination(coefficients);
    cout<<"Matrix after Jordan Elimination:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<coefficients[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<setprecision(5)<<fixed<<endl;

    cout<<"The solutions are (Gauss-Jordan Elimination Method): ";
    for(int i=0;i<n;i++)
        cout<<coefficients[i][n]/coefficients[i][i]<<' '; // getting answer
    cout<<endl;
}
