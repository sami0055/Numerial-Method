#include<bits/stdc++.h>
using namespace std;
double f(double t, double y, double z) {
    // Given differential equation: y'' + 4y' + 5y = 35e^(-4t)
  // double result = 35 * exp(-4 * t) - 4 * z - 5 * y;
    double result = (3+t) * exp(-2 * t) - 4 * z - 4 * y;
    return result;
}
int main()
{
    cout<<0.1*f(0.05,2.05,3.75)<<endl;
}