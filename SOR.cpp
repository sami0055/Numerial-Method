#include<bits/stdc++.h>
using namespace std;

vector<double> SOR(const vector<vector<double>>& A, const vector<double>& b, double omega, double tolerance, int maxIterations) {
    int n = A.size();
    vector<double> x(n, 0.0); 

    for (int iter = 0; iter < maxIterations; ++iter) {
        vector<double> x_new(n, 0.0); 

        for (int i = 0; i < n; ++i) {
            double sum1 = 0.0;
            double sum2 = 0.0;

            for (int j = 0; j < i; ++j)
                sum1 += A[i][j] * x_new[j];

            for (int j = i + 1; j < n; ++j)
                sum2 += A[i][j] * x[j];

            x_new[i] = (1.0 - omega) * x[i] + (omega / A[i][i]) * (b[i] - sum1 - sum2);
        }

  
        double error = 0.0;
        for (int i = 0; i < n; ++i)
            error += abs(x_new[i] - x[i]);

        x = x_new;

        if (error < tolerance)
            break;
    }

    return x;
}

int main() {
   
    vector<vector<double>> A = {{-31/16,5/4,0},
                                {3/4,-31/16,5/4},
                                {0,3/4,-31/16}
                                
                                };

            cout<<A.size()<<endl;

    vector<double> b = {15/32,15/16,45/32};

    double omega = 1; 
    double tolerance = 1e-6;
    int maxIterations = 1000;

    vector<double> solution = SOR(A, b, omega, tolerance, maxIterations);


    cout << "Solution:" << endl;
    for (int i = 0; i < solution.size(); ++i) {
        cout << "x[" << i << "] = " << solution[i] << endl;
    }

    return 0;
}
