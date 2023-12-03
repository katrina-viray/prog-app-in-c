#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define a struct for the WAV header
struct header {
    char chunkid[4];
    unsigned int chunksize;
    char format[4];
    char subchunk1id[4];
    unsigned int subchunk1size;
    unsigned short int audioformat;
    unsigned short int numchannels;
    unsigned int samplerate;
    unsigned int byterate;
    unsigned short int blockalign;
    unsigned short int bitspersample;
    char subchunk2id[4];
    unsigned int subchunk2size;
};

int main() {
    // Define variables
    struct header HeaderOut;
    int i, j;
    double freq, t;
    short int amplitude = 32700;
    unsigned short int song[48] = {3, 3, 10, 10, 12, 12, 10, 24, 8, 8, 7, 7, 5, 5, 3, 24, 10, 10, 8, 8, 7, 7, 5, 24, 10, 10, 8, 8, 7, 7, 5, 24, 3, 3, 10, 10, 12, 12, 10, 24, 8, 8, 7, 7, 5, 5, 3, 24};
    unsigned int totalbytes = 0;
    
    // Fill in the WAV header
    HeaderOut.chunkid[0] = 'R';
    HeaderOut.chunkid[1] = 'I';
    HeaderOut.chunkid[2] = 'F';
    HeaderOut.chunkid[3] = 'F';
    HeaderOut.format[0] = 'W';
    HeaderOut.format[1] = 'A';
    HeaderOut.format[2] = 'V';
    HeaderOut.format[3] = 'E';
    HeaderOut.subchunk1id[0] = 'f';
    HeaderOut.subchunk1id[1] = 'm';
    HeaderOut.subchunk1id[2] = 't';
    HeaderOut.subchunk1id[3] = ' ';
    HeaderOut.subchunk1size = 16;
    HeaderOut.audioformat = 1;
    HeaderOut.numchannels = 1;
    HeaderOut.samplerate = 44100;
    HeaderOut.bitspersample = 16;
    HeaderOut.byterate = HeaderOut.samplerate * HeaderOut.numchannels * HeaderOut.bitspersample / 8;
    HeaderOut.blockalign = HeaderOut.numchannels * HeaderOut.bitspersample / 8;
    HeaderOut.subchunk2id[0] = 'd';
    HeaderOut.subchunk2id[1] = 'a';
    HeaderOut.subchunk2id[2] = 't';
    HeaderOut.subchunk2id[3] = 'a';
    
    // Open the output file
    FILE *fout = fopen("song.wav", "wb");
    if (fout == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }
    
    // Write the header to the output file
    fwrite(&HeaderOut, sizeof(struct header), 1, fout);
    
    // Allocate memory for the audio data
    short int **data;
    data = (short int **) malloc(sizeof(short int *) * 25);
    for (i = 0; i < 25; i++) {
        data[i] = (short int *) malloc(sizeof(short int) * 4410);
        if (data[i] == NULL) {
            printf("Error: could not allocate memory.\n");
            return 1;
        }
    }
    
    // Generate the audio data
    for (i = 0; i < 25; i++) {
        for (j = 0; j < 4410; j++) {
            freq = 440 * pow(2, (song[i]-10)/12.0);
            t = j / 44100.0;
            data[i][j] = amplitude * sin(2 * PI * freq * t);
        }
    }
    
    // Write the audio data to the output file
    for (i = 0; i < 25; i++) {
        fwrite(data[i], sizeof(short int), 4410, fout);
        totalbytes += sizeof(short int) * 4410;
    }
    
    // Update the chunksize and subchunk2size fields in the header
    HeaderOut.chunksize = totalbytes + 36;
    HeaderOut.subchunk2size = totalbytes;
    fseek(fout, 4, SEEK_SET);
    fwrite(&HeaderOut.chunksize, sizeof(unsigned int), 1, fout);
    fseek(fout, 40, SEEK_SET);
    fwrite(&HeaderOut.subchunk2size, sizeof(unsigned int), 1, fout);
    
    // Close the output file and free memory
    fclose(fout);
    for (i = 0; i < 25; i++) {
        free(data[i]);
    }
    free(data);
}




