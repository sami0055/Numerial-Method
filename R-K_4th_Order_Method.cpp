
#include <bits/stdc++.h>
using namespace std;

float equation(float x, float y)
{
	return 32-((y*y)/20);
}

float R_K_Method(float x0, float y0, float x, float h)
{

	// int step= int((x - x0) *(1/h));
	float k1, k2, k3, k4, k5;
	float y = y0;
	// cout<<"No of steps: "<<step<<endl;
	//for (int i=1; i<=step; i++)
	while(x0<x)
	{
		k1 = h*equation(x0, y);
		cout<<"k1= "<<k1<<", 0.2*"<<equation(x0, y)<<endl;
		  k2 = h*equation(x0 + 0.5*h, y + 0.5*k1);
         cout<<"k2= "<<k2<<" ,0.2*"<<equation(x0 + 0.5*h, y + 0.5*k1)<<endl;
		 k3 = h*equation(x0 + 0.5*h, y + 0.5*k2);
	    cout<<"k3= "<<k3<<" ,0.2*"<<equation(x0 + 0.5*h, y + 0.5*k2)<<endl;
        k4 = h*equation(x0 + h, y + k3);
		 cout<<"k4= "<<k4<<", 0.2*"<< equation(x0 + h, y + k3)<<endl;
		

	y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);
		x0 = x0 + h;
	}

	return y;
}

int main()
{
	float x0 = 0, y0 = 0, x = 1, h = 0.2;
	cout << "The value of y at x is : " <<
			R_K_Method(x0, y0, x, h);

	return 0;
}