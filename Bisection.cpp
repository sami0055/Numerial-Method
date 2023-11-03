#include<bits/stdc++.h>
using namespace std;


long double func(long double x) {

    return x*x*x + 4*x*x - 10;
}


long double bisectionMethod(long double a, long double b, long double tol) {

     long double c=a;

    if (func(a) * func(b) >= 0) {
        cout << " Not converge for the given interval." << endl;
        return NAN;
    }

       while(abs(a-b)>=tol){

        // Calculate the midpoint c.
        c = (a + b) / 2;

        // Update the interval a and b based on the sign of func(c).
        if (func(a) * func(c)< 0) {
            b = c;

        } else {
            a = c;

        }
    }

    return c;
}

int main() {
    long double a, b, tolerance;

    cout << "Enter the interval a and b: ";
    cin >> a >> b;

    cout << "Enter the tolerance: ";
    cin >> tolerance;

   long double root = bisectionMethod(a, b, tolerance);

    if (isnan(root)==false) {
        cout << "Approximate root: " <<setprecision(10)<< root << endl;
    } else {
        cout << "Bisection Method not converge to a root." << endl;
    }

    return 0;
}
