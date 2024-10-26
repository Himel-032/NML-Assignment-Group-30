Solving Non-Linear Equation:
1.	Bisection Method: It’s a method for solving non linear equation in an iterative approach. If a polynomial equation is 
     F(x)=anxn+a n-1 xn-1+…+a1x+a0=0
if f(x) is real and continuous in the interval a<x<b and f(a)f(b)<0 then their lies at least one roots lies in between a and b. Here I implemented search interval equation technique which sets the intervals and give me the roots in the interval. Here at first takes the number of polynomial size from the user, then it takes the co-efficients from the user (must be give with proper signs) .Then it finds the interval from above mentioned, then it search for roots and finally gives the output
 However it have some restrictions:
a. It works only a continuous function
b. It sometimes don’t give roots when the region is too small.
c. Any equation without backtracking value it won’t work.
2. False Position Method: Another method for solving non linear equations in an iterative process. But it’s quite different to Bisection method. Here it first checks f(a)f(b)<0 or not. If it’s >0 then there will be no root. If converse then have after that it will do a iterative process which equation is implemented inside false_position.h file. Here at first takes the number of polynomial size from the user, then it takes the co-efficients from the user (must be give with proper signs). Then it calculates the value of a and b then it will find f(a), f(b) and using these it finds value of c which will be the root and then again it will used for calculating roots.
It also have some limitations:
a. Slow rate of convergence.
b. fails to determine complex roots
c. It can not be applied over an interval where the function takes values of the same sign.

3. Newton Raphson Method: It is used to find all the real distinct roots of a non linear equation using iterative methods. But it’s quite different to bisection and false position. As those are works with an interval but doesn’t need any interval rather it works by differentiating the equation.
here it first guesses a value then it differentiates and apply the rule for estimate which is implemented at newton_raphson.h file. Here at first takes the number of polynomial size from the user, then it takes the co-efficients from the user (must be give with proper signs). It first takes a  value as initial from then it does differentiate it. Then using f(xn) and f’(xn) it tries to find Xn+1 if Xn+1 – Xn is less than 1e-6 it takes Xn+1 as roots otherwise it continues iterating.
 though it have some bindings: here division by zero problem can occur, inflection point issue may arise.

4. Secant Method: It also finds the roots of linear equation in an iterative method but it doesn’t need derivative as I need in Newton Raphson method. Here it finds root in an interval which is guessed . then it founds f(x0), f(x1) which are the endpoints, then it calculates x2 which is esmitate root after then it will also used for further calculating task. These are implemented in secant.h .here main con’s is that it’s always not guaranteed that it might gives result.

