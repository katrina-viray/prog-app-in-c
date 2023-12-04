#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// create a noise mono WAV file 1.0 sec long, samplerate=22050, bitspersample=4*8=32
// Note: some WAV file players require the format field to be "WAVE" not "WAV ",
// particularily when bitspersample=32
int main( ){
///////////////////////////////////////////////////////
// WAV file header fields
char chunkid[4], subchunk1id[4], subchunk2id[4],format[4],outstring[5];
outstring[4]='\0'; // so that the 1st 4 chars will be a string
unsigned int chunksize, subchunk1size, subchunk2size;
unsigned short int audioformat,numchannels,blockalign,bitspersample;
unsigned int samplerate, byterate, numaudiosamples;
char randbyte; // 0 <= char <= 255 will work to hold a rand( ) BYTE value
//////////////////////////////////////////////////////
FILE *fpi;
char filename[200];
int k,m,n;
//////////////////////////////////////
printf("Enter the path and filename for an output WAV file:\n");
scanf("%s",filename);
printf("You entered file %s\n",filename);
fpi=fopen(filename,"wb");
if(fpi==NULL){
printf("You entered an invalid path/filename.\n");
return;
}
/////////////////////////////////////
// load up chunkid with RIFF
// can't use anything like chunkid="RIFF"; since 1. chunkid is a memory address and 
// 2. RIFF is actually 5 chars (including '\0'), so it can't fit into the 4 cells of chunkid
// Therefore, when defining chunkid above, can do char chunkid[5] = "RIFF";, but below is the RIGHT way to avoid '\0'
sprintf(chunkid,"%c%c%c%c",'R','I','F','F');

for(int k=0; k<4; k++){
    outstring[k]=chunkid[k];
}
printf("chunkid[ ] = \"%s\"\n",outstring); // outstring has a string termination '\0' at the end
fwrite(chunkid,1,4,fpi); // read in RIFF

// compute chunksize
// 1 second of mono audiodata at 32-bits (4 bytes) per sample, samplerate = 22050
// = 22050*4*(1)=88,200 bytes of audiodata.
// The complete file will consist of a (44 byte WAV header + 88,200)=88,244 bytes of audiodata
// chunksize - filesize - 8 (i.e. minus 4 bytes for the chunkid and 4 bytes for the chunksize)
chunksize=88244-8;
printf("chunksize = %u\n",chunksize);
/* EX. fwrite arguments: (memory address of what we're writing from, 4 bytes/cell, 1 cell, file pointer) 
    So we're writing in 4 unformatted bytes from the chunksize variable.*/
fwrite(&chunksize,4,1,fpi); // read in chunksize unsigned int
////////////////////////////////////////

// create the format field and write it to file
// Important: some media players are now requiring the format field to hold "WAVE" not WAV "
sprintf(format,"%c%c%c%c",'W','A','V','E');
for(k=0; k<4; k++){outstring[k]=format[k];}
printf("format[ ] = \"%s\"\n",outstring);
fwrite(format,1,4,fpi);
/////////////////////////////////////////
// create the subchunk1id and write it to file
sprintf(subchunk1id,"%c%c%c%c",'f','m','t',' ');
for(k=0; k<4; k++){outstring[k]=subchunk1id[k];}
printf("subchunk1id[ ] = \"%s\"\n",outstring);
fwrite(subchunk1id,1,4,fpi);
////////////////////////////////////////////
// create subchunk1size and write to file
subchunk1size=16;
printf("subchunk1size = %u\n",subchunk1size);
fwrite(&subchunk1size,4,1,fpi);
///////////////////////////////////////////
// audioformat
audioformat=1;
printf("audioformat = %d\n",audioformat);
fwrite(&audioformat,2,1,fpi);
/////////////////////////////////////////////
// numchannels = 1 mono, &numchannels is the memory address of where numchannels is stored
numchannels = 1;
printf("numchannels = %d\n",numchannels);
fwrite(&numchannels,2,1,fpi);
//////////////////////////////////////////
// samplerate = 22050
samplerate=22050;
printf("samplerate = %d\n",samplerate);
fwrite(&samplerate,4,1,fpi);
////////////////////////////////////////////
// byterate = SampleRate * NumChannels * BitsPerSample/8
byterate=samplerate*numchannels*32/8;
printf("byterate = %d\n",byterate);
fwrite(&byterate,4,1,fpi);
//////////////////////////////////////////////
// blockalign = NumChannels * BitsPerSample/8
blockalign=numchannels*32/8;
printf("blockalign = %d\n",blockalign);
fwrite(&blockalign,2,1,fpi);
////////////////////////////////////////////////
// bitspersample=16;
bitspersample=32;
printf("bitspersample = %d\n",bitspersample);
fwrite(&bitspersample,2,1,fpi);
/////////////////////////////////////////////////////
// subchunk2id
sprintf(subchunk2id,"%c%c%c%c",'d','a','t','a');
for(k=0; k<4; k++){outstring[k]=subchunk2id[k];}
printf("subchunk2id[ ] = \"%s\"\n",outstring);
fwrite(&subchunk2id,1,4,fpi);
///////////////////////////////////////////////////////
// subchunk2size = number of bytes of audiodata = (1.0 sec)*22050*4=88,200
subchunk2size = (unsigned int)(1.0*samplerate*numchannels*bitspersample/8); // need an unsigned int number of bytes
printf("subchunk2size = %d = 44100?\n",subchunk2size);
fwrite(&subchunk2size,4,1,fpi);
////////////////////////////////////////////////
// write random audiodata bytes into the file. use rand( )%256 to generate a random byte 0-255
numaudiosamples=(unsigned int)(1.0*samplerate);
printf("numaudiosamples = %d\n",numaudiosamples);
for(m=0; m<numaudiosamples; m++){// loop over the number of audiosamples
// for each audiosample, write (bitspersample/8)*numchannels=4 random bytes into the file
for(n=0; n<bitspersample/8; n++){// loop over the 4 bytes per audiosample
randbyte=rand( )%256;
fwrite(&randbyte,1,1,fpi);
}
}
////////////////////////
fclose(fpi);
system("pause");
}// end main( )
