#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define BITS_PER_SAMPLE 16

void print_instructions_and_open_file(FILE **fp) {
    char file_name[256];
    printf("Enter the name of the output file: ");
    scanf("%s", file_name);
    *fp = fopen(file_name, "w+b");
    if (*fp == NULL) {
        printf("Error: Unable to open the file.\n");
        exit(1);
    }
}

void fill_audio_data(short int **audio_data, int num_samples) {
    int i, j;
    for (i = 0; i < num_samples; i++) {
        for (j = 0; j < 2; j++) {
            audio_data[j][i] = 256*(rand()%256)+rand()%256-32768;
        }
    }
}

void write_wave_header(FILE *fp, int num_samples) {
    int byte_rate = SAMPLE_RATE * 2 * BITS_PER_SAMPLE/8;
    int block_align = 2 * BITS_PER_SAMPLE/8;
    int data_size = num_samples * block_align;
    int file_size = 44 + data_size - 8;
    char chunk_id[4] = {'R', 'I', 'F', 'F'};
    char format[4] = {'W', 'A', 'V', 'E'};
    char sub_chunk1_id[4] = {'f', 'm', 't', ' '};
    int sub_chunk1_size = 16;
    short int audio_format = 1;
    short int num_channels = 2;
    int sample_rate = SAMPLE_RATE;
    short int bits_per_sample = BITS_PER_SAMPLE;
    char sub_chunk2_id[4] = {'d', 'a', 't', 'a'};

    fwrite(chunk_id, sizeof(char), 4, fp);
    fwrite(&file_size, sizeof(int), 1, fp);
    fwrite(format, sizeof(char), 4, fp);
    fwrite(sub_chunk1_id, sizeof(char), 4, fp);
    fwrite(&sub_chunk1_size, sizeof(int), 1, fp);
    fwrite(&audio_format, sizeof(short int), 1, fp);
    fwrite(&num_channels, sizeof(short int), 1, fp);
    fwrite(&sample_rate, sizeof(int), 1, fp);
    fwrite(&byte_rate, sizeof(int), 1, fp);
    fwrite(&block_align, sizeof(short int), 1, fp);
    fwrite(&bits_per_sample, sizeof(short int), 1, fp);
    fwrite(sub_chunk2_id, sizeof(char), 4, fp);
    fwrite(&data_size, sizeof(int), 1, fp);
}

int main() {
    int num_samples, i, j;
    short int **audio_data;
    FILE *fp;
    float audio_length;

    print_instructions_and_open_file(&fp);

    printf("Enter the length of the audio (in seconds): ");
    scanf("%f", &audio_length);

    num_samples = (int)(audio_length * SAMPLE_RATE);
    audio_data = (short int **)malloc(2 * sizeof(short int *));
    for (i = 0; i < 2; i++) {
        audio_data[i] = (short int *)malloc(num_samples * sizeof(short int));
    }

    srand(time(NULL));
    fill_audio_data(audio_data, num_samples);

    write_wave_header(fp, num_samples);

    for (i = 0; i < num_samples; i++) {
        for (j = 0; j < 2; j++) {
            fwrite(&audio_data[j][i], sizeof(short int), 1, fp);
        }
    }

    fclose(fp);

    return 0;
}
