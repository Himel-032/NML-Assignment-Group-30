# Numerical Methods Laboratory Assignment -Group - 30
## contributors

## Md Himel(2107032) , Md Shahriar Aziz Khan(2107034) , Abdullah Md. Shahporan(2107056)
                                                                       
______________________________________________________________________________________                                      Md Himel
                                    Roll:2107032
_____________________________________________________________________________
# Md Himel(2107032):

## 1.Jacobi Iteration Method: 

1-> At first, the algorithm receives inputs form the user as an augmented matrix form.

2-> In this method , i set initial value of all the variables to zero(0). Then we use these values to get the new updated values of the variables .Then i changed the value of the variables using these new values. For this purpose , i have used a function(double calculateSolution(vector<vector<double>> &coefficients, vector<double> &currValues, int i, int n)) to calculate the new value of each variable.

3-> After getting all the new valuse of all variables , i changes the values of the variables. I also used a tolerance value of 1e-6 to check the convergency.If the function was not convergent , i broke the loop and showed the values of the variables.I used maximum 20000 iterations for convergency of each variable.

4-> I also checked for diagonally dominant matrix using the function (bool isDiagonallyDominant(vector<vector<double>> & coefficients,int n)).

5-> If the coefficient matrix is not diagonally dominant , i tried to make it diagonally dominant using the function (bool makeDiagonallyDominant(vector<vector<double>> & coefficients,int n)) . If it was not possible to make the coefficient matrix digonally dominant , i simply showed a message and exited from the solution method.

------------------------------------------------------------------------------------------------------------------------------------------------------------------
## 2. Gauss seidel iterative Method:

1-> In Gauss-Seidel method , i used the methods "bool isDiagonallyDominant(vector<vector<double>> & coefficients,int n),bool makeDiagonallyDominant(vector<vector<double>> & coefficients,int n),double calculateSolution(vector<vector<double>> &coefficients, vector<double> &currValues, int i, int n)" from "JacobiMethod.h" header file.All the functionallity of this method exept one is same as "Jacobi Iteration Method".

2-> In jacobi method , the algorithm changes the value of variables when the value of all variables get changed.But in Gauss-Seidel method , the algorithm immediately changes the value of each variable when it get changed. I had not waited for the change of all variables. 

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
## 3. Gauss Elimination Method:

I used this method to solve a system of linear equations using an augmented matrix form.

1-> At first , the algorithm takes the inputs from the user in the augmented matrix form. Then in "bool GaussElimination(vector<vector<double>> &coefficients)" method , at first the algorithm checks for zero elements in the diagonal. If there was a diagonal element equal to zero ,then it looks for a non zero element in the same column below the current row.If the algorithm founds a row having non zero element in the same column , it swaps the entire row with the row containing non zero element in the same column.

2-> when the matrix is in the form where all the diagonal elements are non zero , it removes the non diagonal elements below each pivot(Row echelon form).For this purpose, i used elementary row transformation formula.
The fraction "frac" represents how much of the pivot row we need to subtract from the target row to make the target element zero.For this we divide the element in the same column below the pivot by the pivot.we use it to update the entire target row (row j) by subtracting "frac" times the pivot row (row i). This operation convert the element into zero in the target row in the current column.

3-> I also check the consistency of the augmented matrix using the function (int checkConsistency(vector<vector<double>> &coefficients)). If the matrix is not consistent , then there can be no solution or infinite solutions. if the sum any entire row including the constant is zero, there are infinte solutions. or if all the elements are zero except the constant term in a same row, then there is no solution. 

4-> When it is sure that there is a unique solution, i used the method (void Backsubstitution(vector<vector<double>> &coefficients)) to get the answer.
At first , i get the solution of last variable, then i substitute this value in the upwards direction to get all the solutions.
Then the solution is printed
.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
## 4. Gauss-Jordan Elimination Method:

1-> In this method, the algorithm first convert the coefficient matrix into Row echelon form(Gaussian elimaination) using the method"bool GaussElimination(vector<vector<double>> &coefficients) " from "GaussElimination.h" header file . The operation is same as Gauss-Elimination Method.To do this , we also check the consistency using the function (int checkConsistency(vector<vector<double>> &coefficients)) from "GaussElimination.h" header file.

2-> After converting the matrix into Row echelon form,the "void JordanElimination(vector<vector<double>> &coefficients)" function takes the matrix after Gaussian Elimination and performs further row operations to convert it into reduced row echelon form. In this form, each row has a leading non zero value (a pivot), and all elements above and below each pivot are zero.

3-> After this , the matrix in reduced row echelon form is printed in the console. 

4-> If we convert the RREF matrix back into the equation form, there is only a constant term with a varible term in each row. Dividing the constant term by the coefficient of its corresponding variable , we get the solution for the corresponding variable.
For doing this , we set up a loop. which will divide the constant term by the pivot element (diagonal non zero element).
After this , we simply printed the solution of the n unknowns.
.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------
## 5. Runge - Kutta(RK4) Method:

1-> At first the "void solveDifferentialEquation()" method takes the input from the user(initial value of x, intital value of y , step size and last value of x).

2-> The "void solveDifferentialEquation()" gives 4 fixed equations to solve using RK4 method.The algorithm uses "Lamda function" to provide various form of equations.

3-> The algorithm used switch case structure to select a specific form of equations form the four.

4-> The algorithm uses the method "double rk4(double x0, double y0, double xEnd, double h, function<double(double, double)> &f)" to solve the specific equations. It calculates the value of k1,k2,k3,k4 and y using the Runge-Kutta formula. After this , it adds the step size to the value of x.When the value of x becomes greater than the termination taken from user , the loop terminated and prints the output (that is value of y).

---------------------------------------------------------------------------------------------------------------------------
## 6. LU Factorization Method:

1-> The "void LUFactorization()" method take inputs from the user.At first it take the number of unknowns(n) of the system of linear equations.Then it takes the coefficients matrix (A) from the user and the constants matrix (b) from the user.Then the algorithm call the "void LU_Factorization( vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U)" method.

2-> In the "void LU_Factorization( vector<vector<double>> &A, vector<vector<double>> &L, vector<vector<double>> &U)" method the algorithm decomposes the A vector(coefficients matrix) int two matrix L(lower triangular matrix),U (upper triangular matrix) such that LU=A. The diagonal element of L is set to 1.And others elements are calculated .

3-> Then the algorithm calls "vector<double> forward_substitution( vector<vector<double>> &L,  vector<double> &b)" method to solve for Ly=b using forward substitution technique.After finding the solutions for y, the program execution gets back to the "void LUFactorization()" method.

4-> Then the algorithm calls "vector<double> backward_substitution( vector<vector<double>> &U,  vector<double> &y)" method to solve Ux=y for the solutions of x using the backsubstitution technique.After finding the values of x , the execution gets back to "void LUFactorization()" method.

5-> After this the program prints the results.


_________________________________________________________________________________________________________________________
__________________________________________________________________________________________________________________________

                                   2)  Aziz Khan
                                     Roll: 2107034
_________________________________________________________________________________________________________________________
# Shahriar Aziz Khan (2107032)
## 1. Matrix inversion

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


