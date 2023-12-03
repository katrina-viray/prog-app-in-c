#include<stdio.h>
#include<stdlib.h>
// change the samplerate in a WAVE audio file
/* Note- audio data is stored in the WAV file as "interlaced data". A left channel sample is sorted 1st, then
   a right channel sample, and left again and so on. 
   The left/right channel samples are either a short int or an int value.
   Audio data must be able to take in both positive and negative values.
   A stereo audiosample consist of 1 left channel sample and 1 right channel sample.
   If we're using short in data (2 bytes), then a stereo audiosample is 4 bytes!
 */
main( ){
///////////////////////////////////////////////////////
// WAV file header fields
char chunkid[4], subchunk1id[4], subchunk2id[4];
unsigned int chunksize, sbchunk1size, subchunk2size;
char format[4]; // hold WAVE
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
fpi=fopen(filename,"r+b");
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
printf("chunksize = %u\n",chunksize);

/* We've read in 8 bytes now (from chunkid and chunksize.) Now, we want to skip ahead to numchannels
   by skipping over the 1st 14 bytes. Therefore, we only have to skip 6 bytes since the file position
   is currently at byte 8. We move forward by 6 bytes to get to numchannels. */
int offset;
offset = 6;
fseek(fpi, offset, SEEK_CUR); // fseek() from curr location (file-position)
fread(&numchannels, sizeof(short int), 1, fpi);
printf("numchannels = %d\n", numchannels);

// now let's skip to the samplerate field using fseek( )
int offset;
offset=24; // to move to the start of the samplerate field
fseek(fpi,offset,SEEK_SET); // 24 bytes past the beginning of file
fread(&samplerate,4,1,fpi);
printf("samplerate = %d\n",samplerate);

/* Now reading subchunk2is starting at byte 36 */
offset = 36;
fseek(fpi, offset, SEEK_SET); // going to 36 bytes past the beginning of the file
fread(&subchunk2id[0], 4, 1, fpi);
for(k = 0; k<4; k++){
    printf("%c", subchunk2id[k]);
}
printf("\n");

/* Now reading in subchunk2size. File position is right at the start of subchunk2size, so don't need fseek() */
fread(&subchunk2size, 4, 1, fpi);
printf("subchunk2size = %d\n", subchunk2size);

/* MISC stuff; making audio file play twice as fast!
offset=-4;
fseek(fpi,offset,SEEK_CUR);// move backward 4 bytes to beginning of samplerate field
samplerate *= 2; // double the samplerate
fwrite(&samplerate,4,1,fpi); // overwrite the samplerate field with the new samplerate
printf("the samplerate is now doubled. The audio file will play twice as fast as the original\n");
*/

fclose(fpi);
system("pause");
}// end main( )
