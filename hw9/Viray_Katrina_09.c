#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

void sin_wave(short int* audio_data, float frequency, int num_samples) {
    for(int i = 0; i < num_samples; i++) {
        float t = (float)i / 44100;
        audio_data[i] = (short int)(32700.0 * sin(2 * M_PI * frequency * t));
    }
}

int main() {
    float length, frequency;
    int num_samples;

    printf("Enter a length for the audio in seconds:\n");
    scanf("%f",&length);

    printf("Enter a frequency for the audio in Hz:\n");
    scanf("%f", &frequency);

    num_samples = (int)(44100 * length);

    //create memory for audio data
    short int* audio_data = (short int*) calloc(num_samples, sizeof(short int));
    sin_wave(audio_data, frequency, num_samples);

    // Fill in the header information
    char chunkid[4] = {'R', 'I', 'F', 'F'};
    int chunksize = 36 + num_samples * sizeof(short);
    char format[4] = {'W', 'A', 'V', 'E'};
    char subchunk1id[4] = {'f', 'm', 't', ' '};
    int subchunk1size = 16;
    short audioformat = 1;
    short numchannels = 1;
    int samplerate = 44100;
    int byterate = 2 * samplerate;
    short blockalign = 2;
    short bitspersample = 16;
    char subchunk2id[4] = {'d', 'a', 't', 'a'};
    int subchunk2size = num_samples * sizeof(short);
    int filesize = chunksize + 8;

    // Open file for writing
    FILE *fp = fopen("tone1.wav", "wb");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Write header information to file
    fwrite(chunkid, sizeof(char), 4, fp);
    fwrite(&filesize, sizeof(int), 1, fp);
    fwrite(format, sizeof(char), 4, fp);
    fwrite(subchunk1id, sizeof(char), 4, fp);
    fwrite(&subchunk1size, sizeof(int), 1, fp);
    fwrite(&audioformat, sizeof(short), 1, fp);
    fwrite(&numchannels, sizeof(short), 1, fp);
    fwrite(&samplerate, sizeof(int), 1, fp);
    fwrite(&byterate, sizeof(int), 1, fp);
    fwrite(&blockalign, sizeof(short), 1, fp);
    fwrite(&bitspersample, sizeof(short), 1, fp);
    fwrite(subchunk2id, sizeof(char), 4, fp);
    fwrite(&subchunk2size, sizeof(int), 1, fp);

    // Write audio data to file
    fwrite(audio_data, sizeof(short), num_samples, fp);

    // Close file and free memory
    fclose(fp);
    free(audio_data);

return 0;
}

