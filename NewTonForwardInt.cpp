#include<bits/stdc++.h>
using namespace std;
int main()
{
    float x,y;
    int i,j,n,fact;
    cout<<"Enter no. of terms"<<endl;
    cin>>n;
    float a[n][n+1];
    cout<<"Enter Values of X"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i][0];
    }
     cout<<"Enter Values of Y"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i][1];
    }
    cout<<"Enter value of x for which you want y"<<endl;
    cin>>x;
    for(j=2;j<=n;j++)
    {
        for(i=0;i<=n-j;i++)
            a[i][j] = a[i+1][j-1]-a[i][j-1];
    }

    cout<<"Difference Table is: "<<endl;
    for(i=0;i<n;i++)
    {
     for(j=0;j<=n-i;j++)
       cout<<a[i][j]<<" ";
       
      cout<<endl;
    }
    
    float h=a[1][0]-a[0][0];
    float p = (x - a[0][0])/h;
    y=a[0][1]; 
    float p1=p;
    fact=1;
    for(i=2;i<=n;i++)
    {
        y=y+(p1*a[0][i])/fact;
        
        fact=fact*i; 
        p1=p1*(p-(i-1));
    }
    cout<<endl;
    cout<<"Value at "<<x<<" is = "<<y<<endl;


}