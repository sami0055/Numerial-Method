#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<setprecision(10)<<fixed<<endl;
    int n;
   
    cout<<"Ente the number of terms = ";
     cin>>n;

    vector<double>X(n,0.0);
    vector<double>Y(n,0.0);
    
    cout<<"Enter all the value of X: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>X[i];
    }
    cout<<"Now enter all the values of Y"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>Y[i];
    }
    double x;
    cout<<"Enter the value of x: "<<endl;
    cin>>x;
    vector<double>L(n,0);
   double sum=0;
   double term;
  for(int i=0;i<n;i++)
    {
        term=1;
        for( int j=0;j<n;j++)
        {   
            if(i!=j)
               term = term * ((x - X[j])/(X[i]-X[j]));
        }
        sum=sum + term * Y[i];    
    }
   
   cout<<sum<<endl;


}