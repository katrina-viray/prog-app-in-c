#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declare global struct for WAV header
struct wavheader{
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

// Function to open input WAV file and read its header
void open_input_wav_file(FILE **in_file, struct wavheader *header) {
    char file_name[100];
    int valid = 0;
    do {
        printf("Enter the input WAV file name: ");
        scanf("%s", file_name);
        *in_file = fopen(file_name, "rb");
        if (*in_file == NULL) {
            printf("File not found or cannot open the file. Please try again.\n");
            continue;
        }
        fread(header, sizeof(struct wavheader), 1, *in_file);
        if (header->bitspersample != 16 || header->numchannels != 1) {
            printf("Invalid WAV file. The input WAV file must be 16 bits per sample and mono.\n");
            fclose(*in_file);
            continue;
        }
        valid = 1;
    } while (!valid);
}

// Function to open output WAV file
void open_output_wav_file(FILE **out_file) {
    char file_name[100];
    printf("Enter the output WAV file name: ");
    scanf("%s", file_name);
    *out_file = fopen(file_name, "wb");
}

// Function to apply flanger effect to audio data
void apply_flanger_effect(int16_t *samples, int num_samples, float rate, float depth, float delay) {
    int i, j;
    int delay_samples = (int)(delay * 44100); // convert delay in seconds to samples
    float index;
    int16_t dry, wet;

    for (i = 0; i < num_samples; i++) {
        index = sin(2 * M_PI * i * rate / 44100.0) * depth * delay_samples;
        j = i - (int)index;
        if (j < 0) {
            j = 0;
        }
        dry = samples[i];
        wet = samples[j];
        samples[i] = (int16_t)(((1.0 - depth) * dry) + (depth * wet));
    }
}

int main() {
    // Declare variables
    FILE *in_file, *out_file;
    struct wavheader headers[2];
    int16_t *samples;
    int num_samples;
    float rate, depth, delay;
    
    // Open input WAV file and read its header
    open_input_wav_file(&in_file, &headers[0]);
    
    // Open output WAV file
    open_output_wav_file(&out_file);
    
    // Generate output stereo WAV header
    headers[1] = headers[0];
    headers[1].numchannels = 2;
    headers[1].blockalign = headers[0].blockalign * 2;
    headers[1].byterate = headers[0].byterate * 2;
    
    // Write output stereo WAV header to output file
    fwrite(&headers[1], sizeof(struct wavheader), 1, out_file);
}

