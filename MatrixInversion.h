#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Function to compute the determinant of a matrix
double compute_determinant(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> B = A; // Copy of matrix A
    double det = 1.0;

    for (int i = 0; i < n; i++) {
        if (fabs(B[i][i]) < 1e-9) {
            // Check for zero pivot
            for (int k = i + 1; k < n; k++) {
                if (fabs(B[k][i]) > 1e-9) {
                    swap(B[i], B[k]); // Row swap
                    det *= -1; // Swapping rows changes the sign of determinant
                    break;
                }
            }
        }

        if (fabs(B[i][i]) < 1e-9) {
            // If pivot is still zero, determinant is zero
            return 0.0; // Singular matrix
        }

        det *= B[i][i]; // Multiply by the pivot element

        for (int j = i + 1; j < n; j++) {
            double factor = B[j][i] / B[i][i];
            for (int k = i; k < n; k++) {
                B[j][k] -= factor * B[i][k];
            }
        }
    }
    return det;
}

// Function to perform Gauss-Jordan elimination for matrix inversion
bool gauss_jordan_inversion(vector<vector<double>>& A, vector<vector<double>>& inverse) {
    int n = A.size();

    // Initialize the inverse matrix as the identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Perform Gauss-Jordan elimination on [A | I] to transform [A] into [I]
    for (int i = 0; i < n; i++) {
        // Step 1: Ensure the pivot element is non-zero by row swapping if necessary
        if (fabs(A[i][i]) < 1e-9) {
            for (int k = i + 1; k < n; k++) {
                if (fabs(A[k][i]) > 1e-9) {
                    swap(A[i], A[k]);
                    swap(inverse[i], inverse[k]); // Swap corresponding rows in inverse
                    break;
                }
            }
        }

        // If the pivot element is still zero, the matrix is singular
        if (fabs(A[i][i]) < 1e-9) {
            cout << "Matrix is singular and cannot be inverted." << endl;
            return false;
        }

        // Step 2: Normalize the pivot row (make the pivot element 1)
        double pivot = A[i][i];
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        // Step 3: Eliminate elements below the pivot in the current column
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double factor = A[j][i];
                for (int k = 0; k < n; k++) {
                    A[j][k] -= factor * A[i][k];
                    inverse[j][k] -= factor * inverse[i][k];
                }
            }
        }
    }

    return true;
}

// Function to verify A*A^-1=I and A^-1*A=I
bool verify_inverse(const vector<vector<double>>& originalA, const vector<vector<double>>& A_inv) {
    int n = originalA.size();
    vector<vector<double>> identity(n, vector<double>(n, 0.0));
    vector<vector<double>> product(n, vector<double>(n, 0.0));

    // Check originalA * A_inv
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                product[i][j] += originalA[i][k] * A_inv[k][j];
            }
        }
    }

    // Compare the result with the identity matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            identity[i][j] = (i == j) ? 1.0 : 0.0;
            if (fabs(product[i][j] - identity[i][j]) > 1e-6) {
                return false;
            }
        }
    }

    return true;
}
void MakeInverse()
{
     int n;
    cout << "Enter the size of the matrix (n*n): ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> originalA(n, vector<double>(n)); // Store a copy of original matrix
    vector<vector<double>> A_inv(n, vector<double>(n));

    // Input matrix A
    cout << "Enter the elements of matrix A row by row:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          
            cin >> A[i][j];
            originalA[i][j] = A[i][j]; // Copy the input to originalA
        }
    }

    // Check determinant to test invertibility
    double det = compute_determinant(A);
    if (fabs(det) < 1e-9) {
        cout << "Matrix is singular (determinant is 0) and cannot be inverted." << endl;
        return;
    } else {
        cout << "Matrix is invertible (determinant: " << det << ")." << endl;
    }

    // Perform Gauss-Jordan inversion
    if (gauss_jordan_inversion(A, A_inv)) {
        // Display the inverse matrix
        cout << "Inverse of the matrix A:\n";
        for (const auto& row : A_inv) {
            for (const auto& elem : row) {
                cout << setw(10) << elem << " ";
            }
            cout << endl;
        }

        // Verify the inverse using originalA
        if (verify_inverse(originalA, A_inv)) {
            cout << "Verification successful: A*A^-1 = I\n";
        } else {
            cout << "Verification failed: A*A^-1 is not equal to I\n";
        }

    } else {
        cout << "Matrix inversion failed." << endl;
    }

}