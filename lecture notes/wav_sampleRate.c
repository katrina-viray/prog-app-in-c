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
unsigned short int audioformat,numchannels, bitspersample;
unsigned int samplerate, byterate, blockalign;
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
offset = 14;
fseek(fpi, offset, SEEK_CUR); // fseek() from curr location (file-position)
fread(&numchannels, sizeof(short int), 1, fpi);
printf("numchannels = %d\n", numchannels);

// now let's skip to the samplerate field using fseek( )
int offset;
offset=24; // to move to the start of the samplerate field
fseek(fpi,offset,SEEK_SET); // 24 bytes past the beginning of file
fread(&samplerate,4,1,fpi);
printf("samplerate = %d\n",samplerate);

/* reading in bitspersample */
offset = 34; // moving to the start of the samplerate field.
fseek(fpi, offset, SEEK_SET); // going to 34 bytes past the beginning of the file
fread(&bitspersample, 2, 1, fpi);
printf("bitspersample = %d\n", bitspersample);

/* Now reading subchunk2id starting at byte 36 */
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

/* Now, we want to malloc() a short int array to hold the left channel samples and the right channel samples.

   How many audio samples are in the file? Well, the audio data consists of the number of bytes, which is = to
   the subchunk2size. However, since numchannels = 2, this is a stereo wav file.
   Therefore, half the bytes are left channel samples, and half the bytes are right channel samples. 

   For a stereo wav file, an audiosample consists of 1 left channle sample, and 1 right channel sample.
   This means there's 2 + 2 - 4 bytes per audiosample.
   Therefore, the total number of audio samples in the file is subchunk2size/4. 
   The left channel samples are a total of subchunk2size/2 bytes, but since each left channel
   sample is 2 bytes, the number of left channel samples is subchunk2size/4. Therefore each sample
   2 bytes.
   
   To hold the left channel data, we need a short int array with number of cells = subchunk2size/4 
   
   Let's malloc one!*/
unsigned int numAudioSamples = subchunk2size/4;

short int * leftchan;
leftchan = (short int * )malloc(numAudioSamples*sizeof(short int));
   
   /* Now we're ready to read in the left channel samples (skip over right channels).
      Using a for loop. */
for(k = 0; k < numAudioSamples; k++)
{
   /* read in the left channel sample with array syntax leftchan[] */
   fread(&leftchan[k], 2, 1, fpi);
   /* skipping over the 2 bytes of the right channel sample */
   fseek(fpi, 2, SEEK_CUR);
}

/* Now we have the left channel data in short int leftchan[]. We're going to overwrite every other sample in
   leftchan[] with noise (from pseudorandom values) */
for(k = 0; k < numAudioSamples; k++)
{
   /* making the 0th sample = to random bytes in the range of -(2^15) <= sample < +(2^15).
      ***KNOW THIS!! MUST KNOW HOW TO USE RAND
      rand()%256 is from 0 to 255, it denotes a random Byte value from 0 to 255. */
   if (k%2 == 0){
      leftchan[k] = 256*(rand()%256) + (rand()%256) - pow(2, 15);
   }
}

/* Finally, let's overwrite the left channel samples with our new values */
for(k = 0; k < numAudioSamples; k++)
{
  /* write in the left channel sample with array syntax leftchan[] */
   fwrite(&leftchan[k], 2, 1, fpi);
   /* skipping over the 2 bytes of the right channel sample */
   fseek(fpi, 2, SEEK_CUR);
}

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
