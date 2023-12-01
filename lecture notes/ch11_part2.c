
#include<stdio.h>
#include<stdlib.h>
// opening files in binary ,mode: reading into an array
main( ){
double *pdx;
int k;
pdx=(double *)malloc(100*sizeof(double));
FILE *fpi;
fpi=fopen("C:/classes/ece3331/programs/myfile.bin","rb"); // write binary mode (unformatted)
// now we use a different ansi c function to read from the file: fread( )
for(k=0; k<100; k++){
// read 1 cell of 8 bytes (sizeof(double)) from file and store it at cell pdx+k
fread(pdx+k,sizeof(double),1,fpi);
}
//////////////////////////
// read 100 cell of 8 bytes (sizeof(double)) from file and store all cells starting at memory address pdx
fread(pdx,sizeof(double),100,fpi);
/////////////////////////
// let's check if we successfully read-in the values stored in binary form (not text form) in the file
printf("pdx[17]=%f\n",pdx[17]); // outputs 0.408 or sth, and since it's binary form, it preserves the precision!
system("pause");
}// end main( )
