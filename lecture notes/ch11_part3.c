
#include<stdio.h>
#include<stdlib.h>
// opening files in binary ,mode
main( ){
double *pdx;
int k;
pdx=(double *)malloc(100*sizeof(double));
for(k=0; k<100; k++){
pdx[k]=0.24*k; // array syntax
*(pdx+k)=0.24*k; // pointer syntax
}
FILE *fpo;
fpo=fopen("C:/classes/ece3331/programs/myfile.bin","wb"); // write binary mode (unformatted)
// now we use a different ansi c function to write to the file: fwrite( )
for(k=0; k<100; k++){
fwrite(pdx+k,sizeof(double),1,fpo); // write 1 cell of 8 bytes (sizeof(double)) to file
}
//////////////////////////
fwrite(pdx,sizeof(double),100,fpo); // write 100 cell of 8 bytes (sizeof(double)) to file
system("pause");
}// end main( )
