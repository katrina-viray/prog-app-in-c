#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Write a program to approximate the 5th root of a number using the Newton-Raphson algorithm,
where we find the fifth root c0^(1/5) using the equation f(x) = x^5 - c0 = 0 */

int main() {
    double c, x, xNew, guess, f, df, maxE, e;
    int itr, i;

    // getting put for double c0
    printf("Enter a value to find its fifth root:\n");
    scanf("%lf", &c);

    // getting put for double x0 for the initial guess
    printf("Enter an initial guess of the fifth root:\n");
    scanf("%lf", &guess);

    // max error so the program stops the iterative solution when |f(x)| < maxE
    printf("Enter a maximum error:\n");
    scanf("%lf", &maxE);

    // max iterations so the program stops when the max # of iterations have been completed. 
    printf("Enter the maximum number of iterations:\n");
    scanf("%d", &itr);

    x = guess;
    for(i = 0; i < itr; i++){
        // f(x) and f'(x) functions
        f = pow(x, 5) - c;
        df = pow(x, 4)*5;

        // equation to find the new x value
        xNew = x - (f/df);

        /* fabs() takes in a single argument (double)) and returns the absolute value of that number */
        // error equation
        e = fabs((xNew - x) / xNew) * 100;

        // if error is less than the max error  print out all info
        if (e < maxE){
            printf("The current estimate of the root is %lf.\nThe current error is %lf.\nThe number of completed iterations is %d\n.", xNew, e, i);
            break;
        }
        // if error is >= the max error start loop again
        else{ 
            x = xNew;
            continue;
        }
    }
    // if the max number of iterations was reached before finding the root print message
    if(i == itr){
        printf("The number of iterations has exceeded the number of maximum number of iterations allowed\n.");
    }
}

