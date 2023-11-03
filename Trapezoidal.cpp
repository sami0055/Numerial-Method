#include<bits/stdc++.h>
using namespace std;
double func(double x)
{
    return pow(cos(x),2);
}

int main()
{
    double a,b,h;
    cout<<"Input integration rage from "<<endl;
    cin>>a;
    cout<<"input integration range to "<<endl;
    cin>>b;
    cout<<"Enter the value of h ";
    cin>>h;

    int p_num=(b-a)/h;

     vector<double>y(p_num+1,0);
     int j=0;
     for(double i=a; i<=b; i=i+h)
     {
        y[j++]=func(i);

     }
     double sum=0;

     for(int i=0; i<=p_num; i++)
     {
        if(i==0 || i==p_num)
        {
            sum+=y[i];
        }else{
            sum+=2*y[i];
        }
     }
     cout<<setprecision(10)<<(h/2)*sum<<endl;
}
