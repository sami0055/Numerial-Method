#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
/*
  Implementation of Inserve matrix by gaussian elimination
*/

// mat multi
vector<vector<double>> matMulti(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int N = A.size();
    vector<vector<double>> result(N, vector<double>(N, 0));

    for (int i=0; i< N; i++) {
        for (int j=0; j<N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

    return result;
}

//inverse of a matrix using Gaussian elimination
vector<vector<double>> inverseMat(const vector<vector<double>>& matrix) {
    int N = matrix.size();
    vector<vector<double>> augMat(N, vector<double>(2 * N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            augMat[i][j] = matrix[i][j];
            augMat[i][j + N] = (i == j) ? 1 : 0;
        }
    }
    
    //  Gaussian elimination ....
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                double factor = augMat[j][i] / augMat[i][i];
                for (int k = 0; k < 2 * N; k++) {
                    augMat[j][k] -= factor * augMat[i][k];
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        double divisor = augMat[i][i];
        for (int j = 0; j < 2 * N; j++) {
            augMat[i][j] /= divisor;
        }
    }
   
       vector<vector<double>> inverse(N, vector<double>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inverse[i][j] = augMat[i][j + N];
        }
    }
    
    return inverse;
}

int main() {
    int N;
    cout << "Enter the size of the square matrix (N): ";
    cin >> N;
    cout << "Enter the elements of the " << N << "x" << N << " matrix:" << endl;
    vector<vector<double>> matrix(N, vector<double>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<double>> inverse = inverseMat(matrix);

    cout << "inverse matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << inverse[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
