
                                                                          
                                                                    1)      Himel Hossain

                                                                          
____________________________________________________________________________________________________________________________________________________________________
-1.Jacobi Iteration Method: 

At first, the algorithm receives inputs form the user as an augmented matrix form.
In this method , i set initial value of all the variables to zero(0). Then we use these values to get the new values of the variables .Then i changed the value of the variables using these new values. For this purpose , i have used a function(double calculateSolution(vector<vector<double>> &coefficients, vector<double> &currValues, int i, int n)) to calculate the new value of each variable. After getting all the new valuse of all variables , i changes the values of the variables. I also used a tolerance value of 1e-6 to check the convergency.If the function was not convergent , i broke the loop and showed the values of the variables.I used 2000 iterations for convergency of each variable.I also checked for diagonally dominant matrix using the function (bool isDiagonallyDominant(vector<vector<double>> & coefficients,int n)). If the coefficient matrix is not diagonally dominant , i tried to make it diagonally dominant using the function (bool makeDiagonallyDominant(vector<vector<double>> & coefficients,int n)) . If it was not possible to make the coefficient matrix digonally dominant , i simply showed a message and exited from the solution method.
------------------------------------------------------------------------------------------------------------------------------------------------------------------2. Gauss seidel iterative Method:

In Gauss-Seidel method , i used the methods from "JacobiMethod.h" header file.All the functionallity of this method exept one is same as "Jacobi Iteration Method".
In jacobi method , i changed the value of variables when the value of all variables got changed.But in Gauss-Seidel method , i immediately changed the value of each variable when it got changed. I had not waited for the change of all variables. 
------------------------------------------------------------------------------------------------------------------------------------------------------------------3. Gauss Elimination Method:

I used this method to solve a system of linear equations using an augmented matrix form. At first , the algorithm takes the inputs from the user in the augmented matrix form. Then in "bool GaussElimination(vector<vector<double>> &coefficients)" method , at first the algorithm checks for zero elements in the diagonal. If there was a diagonal element equal to zero ,then it looks for a non zero element in the same column below the current row.If the algorithm founds a row having non zero element in the same column , it swaps the entire row with the row containing non zero element in the same column.
when the matrix is in the form where all the diagonal elements are non zero , it removes the non diagonal elements below each pivot.For this , i used elementary row transformation formula.
I also check the consistency of the augmented matrix using the function (int checkConsistency(vector<vector<double>> &coefficients)). If the matrix is not consistent , then there can be no solution or infinite solutions. if the sum any entire row including the constant is zero, there are infinte solutions. or if all the elements are zero except the constant term, then there is no solution. 

When it is sure that there is a unique solution, i used the method (void Backsubstitution(vector<vector<double>> &coefficients)) to get the answer.
At first , i get the solution of last variable, then i substitute this value in the upwards direction to get all the solutions.
Then the solution is printed.



_________________________________________________________________________________________________________________________

                                     Aziz Khan
_________________________________________________________________________________________________________________________
1. Matrix inversion

Initialization:

.The size of A(number of rows) is determined. An identity matrix of the same size is created to store the inverse of A as it's built through operations.
. The determinant is initialized to 1, and it will be updated as the algorithm proceeds.

Gauss-Jordan elimination:
. For each column, the algorithm tries to make the diagonal entry(pivot) equal to 1 by dividing the entire row by this pivot value.
. If the pivot is zero, the algorithm checks if row swap can be done with a row below it. This row swap ensures a non-zero pivot and if no non-zero row can be found by row swapping, the matrix is singular(non-invertible) and the algorithm terminates.
. The pivot value is multiplied into the determinant at each step. If the determinant reaches zero, the matrix is singular, and the algorithm terminates.
. Once the pivot is non-zero, the algorithm divides each element in the row(in both A and the identity matrix used for A_inv) by the pivot to make the diagonal entry 1.
. For each row, the algorithm subtracts multiples of the pivot row to amke all other entries in the current column zero, ensuring he column forms a unit vector with a single 1 in the diagonal.

Verification: 
. After transforming A into an identity matrix, the modified identity matrix A_inv should be the inverse of A.
. To verify A*A_inv, the algorithm computes A*A_inv and compares each entry to the identity matrix.

Return results:
. If successful, the inverse matrix A_inv and the determinant are returned.
. If failed, an error message is returned.

_________________________________________________________________________________________________________________________


