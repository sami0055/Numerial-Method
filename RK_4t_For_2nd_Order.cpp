#include<bits/stdc++.h>
using namespace std;

float f(float t, float y, float z) {
    // Given differential equation: y'' + 4y' + 5y = 35e^(-4t)
   float result = 35 * exp(-4 * t) - 4 * z - 5 * y;
    return result;
  // Another Given diffenential equation is  y'' + 4y' + 4y = (3+t)*e^-2t 
   // float result = (3+t) * exp(-2 * t) - 4 * z - 4 * y;
   //  return result;
   
}

int main() {
    float t = 0.0;     // Initial time
    float y = -3.0;    // Initial value for y
    float z = 1.0;     // Initial value for y' (y prime)
    float h = 0.1;     // Step size
    float t_final = 0.4;  // Final time for which you want to find y
    //  float t = 0.0;     // Initial time
    // float y = 2.0;    // Initial value for y
    // float z = 5;     // Initial value for y' (y prime)
    // float h = 0.1;     // Step size
    // float t_final = 0.4;  // Final time for which you want to find y
    int count=0;
    while (t < t_final) {
        float k1y = h * z;
        float k1z = h * f(t, y, z);
        cout<<"k1y= "<<k1y<<", "<<"k1z= "<<k1z<<endl; 
        float k2y = h * (z + k1z / 2);
        float k2z = h * f(t + h / 2, y + k1y / 2, z + k1z / 2);
        cout<<"k2y= "<<k2y<<", "<<"k2z= "<<k2z<<endl; 

        float k3y = h * (z + k2z / 2);
        float k3z = h * f(t + h / 2, y + k2y / 2, z + k2z / 2);
        cout<<"k3y= "<<k3y<<", "<<"k3z= "<<k3z<<endl; 

        float k4y = h * (z + k3z);
        float k4z = h * f(t + h, y + k3y, z + k3z);
        cout<<"k4y= "<<k4y<<", "<<"k4z= "<<k4z<<endl; 

        y = y + (k1y + 2 * k2y + 2 * k3y + k4y) / 6;
        z = z + (k1z + 2 * k2z + 2 * k3z + k4z) / 6;

        cout<<"y="<<y<<" , z= "<<z<<endl;
        t += h;
    }
 

   cout << "At t = " << t_final << ", y(0.4) = " << y <<endl;

    return 0;
}
