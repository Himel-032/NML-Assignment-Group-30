#include<bits/stdc++.h>
using namespace std;

/*
bool GaussElimination(vector<vector<double>> &coefficients)
{
    int n = coefficients.size();
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        if(coefficients[i][i]==0)
        {
            int c = 1;
            while((i+c)<n && coefficients[i+c][i]==0)
                c++;
            if((i+c)==n)
            {
                flag=1;
                break;
            }
            swap(coefficients[i], coefficients[i+c]);
        }
        for(int j=i+1;j<n;j++)
        {
            double frac=coefficients[j][i]/coefficients[i][i];
            for(int k=0;k<=n;k++)
            {
                coefficients[j][k]=coefficients[j][k] - (coefficients[i][k]*frac);
            }
        }
    }
    return flag;
}

int checkConsistency(vector<vector<double>> &coefficients)
{
    int n = coefficients.size();
    double sum=0;
    int flag=3;
    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=coefficients[i][j];
        }
        if(sum==coefficients[i][n])
            flag=2;
    }
    return flag;
}

void Backsubstitution(vector<vector<double>> &coefficients)
{
    int n = coefficients.size();
    vector<double> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        ans[i]=coefficients[i][n];
        for(int j=i+1;j<n;j++)
        {
            ans[i]-=coefficients[i][j]*ans[j];
        }
        ans[i]/=coefficients[i][i];
    }
    cout<<"The solutions are(Gauss-Elimination method): ";
    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
}
*/

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
                    coefficients[j][k]=coefficients[j][k] - (coefficients[i][k]*frac);
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
    if(temp==2)
    {
        cout<<"The system of Linear equations has infinite solutions."<<endl;
        return;
    }
    if(temp==3)
    {
        cout<<"The system has no solutions."<<endl;
        return;
    }

    cout<<"Matrix after Gaussian Elimination."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            cout<<coefficients[i][j]<<" ";
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
        cout<<coefficients[i][n]/coefficients[i][i]<<' ';
    cout<<endl;
}
