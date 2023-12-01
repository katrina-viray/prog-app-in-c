#include<stdio.h>
#include<stdlib.h>
// run-time allocation of 1-d arrays, versus compile-time allocation of arrays
main( ){
double dx1[100],*pdx3;
int num_cells,k;
printf("Enter how many cells of double variables that you want created:\n");
scanf("%d",&num_cells);
// The following syntax is invalid under ansi C, but it is valid under C++.
// It is the WRONG syntax for run-time allocation of 1-d arrays.
// Since your compiler is C++ compliant, it will probably compile and run this code
double dx2[num_cells];
dx2[17]=3.141592;
printf("dx2[17]=%f\n",dx2[17]);
////////////////////////////////////////////////////////
// The correct method is to use ansi c functions malloc( ) or calloc( )
pdx3=(double *)malloc(num_cells*sizeof(double)); // typecasting malloc to double*
pdx3[17]=3.141592;
printf("dx2[17]=%f\n",dx2[17]);
////////////////////////////////////////////////////////
system("pause");
}// end main( )
