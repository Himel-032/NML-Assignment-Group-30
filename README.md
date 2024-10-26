                                     Aziz Khan
_____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
1. Matrix inversion

Initialization:

. An identity matrix is given priority over row echelon form to determine the inverse matrix since compression in the matrix linearity over the original matrix is avoided.
. The determinant will be initialized to 1 so that it is kept for later reference when it comes to judging the invertibility of the original matrix.

Gauss-Jordan elimination:
. The main objective is to coalesce(enhance) the factorization in matrix multiplication between an original matrix and the result of inverse matrix to an identity matrix when it comes to verify the inverse production of any matrix.
. The row swap concludes the echelon formation along each column, since it ensures the completion of submissive trials in zero placement as its dominance engulfs the upper triangular portion as well as the lower triangular portion of any copy of the original matrix.
. The matrix determinant lists the benchmark of any matrix property as it checks whether matrix is singular or non-invertible.
. For each row, the pivot produces a turning point along each row which can be used as reference point to generate diagonal elements of some constant which will further be terminated into a single 1. Sidewise, through each step column, the change is seen and then the reference point acts as 

Verification: 
. We have to keep in mind that determinant neither depreciates the proper transfer of original matrix to an inverse matrix, so we keep a copy of the original matrix as it is the showstopper. 
. A complete traversal in the edging portions of the original matrix creates a buffer so that we can check and compensate for any unusual behaviour in inverse matrix deviating from the usual matrix property of a determinant. For example, a 2*2 matrix produces a determinant whatsever but that doesn't mean it is invertible.

Return results:
. An inverse matrix of the original matrix is offered along with the value of determinant.
. We will get error message if not invertible.
