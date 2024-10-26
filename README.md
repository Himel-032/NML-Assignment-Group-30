                                     Aziz Khan
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
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

