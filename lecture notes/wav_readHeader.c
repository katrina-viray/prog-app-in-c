
#include<stdio.h>
#include<stdlib.h>
// Reading in the information in the WAV file header
main( ){
///////////////////////////////////////////////////////
// WAV file header fields
char chunkid[4], subchunk1id[4], subchunk2id[4];
// NOTE: chunksize is always going to be 36.
unsigned int chunksize, sbchunk1size, subchunk2size;
char format[4]; // holds WAVE for example
unsigned short int audioformat,numchannels;
unsigned int samplerate, byterate, blockalign, bitspersample;
//////////////////////////////////////////////////////
FILE *fpi;
char filename[200];
int k;
//////////////////////////////////////
printf("Enter the path and filename for a WAV file:\n");
scanf("%s",filename);
printf("You entered file %s\n",filename);
fpi=fopen(filename,"rb");
if(fpi==NULL){
printf("You entered an invalid path/filename.\n");
return;
}
fread(chunkid,1,4,fpi); // read in RIFF
for(k=0; k<4; k++){
printf("%c",chunkid[k]);
}
printf("\n");
fread(&chunksize,4,1,fpi); // read in chunksize unsigned int
printf("chunkize = %u\n",chunksize);
system("pause");
}// end main( )
