/*
Write a program that reads up to 100 integers from a file, 
computes the mean m, and then computes and stores in an array,
 for each integer n in the file, the difference n - m. 
 Distribute the tasks among different functions, and use pointer syntax throughout. Write this in C
*/
#include <stdio.h>
#define MAX_NUM 100

void readInts(char *filename, int *nums, int *count);
double findMean(int *nums, int count);
void computeDiff(int *nums, int count, const double mean, int *diff);

int main() {
    int nums[MAX_NUM], count;
    int diff[MAX_NUM];
    double mean;
    char fileName[100];

    printf("Enter name of file containing the integers");
    scanf("%s", fileName);
    readInts(fileName, nums, &count);

    if (count == 0) {
        printf("No valid integers found.\n");
        return 1;
    }

    double mean = findMean(nums, count);
    computeDiff(nums, count, mean, diff);

    printf("Mean is: %lf\n", mean);
    printf("Differences from the mean:\n");
    for (int i = 0; i < count; i++) {
        printf("%d", diff[i]);
    }
    return 0;
}

void readInts(char *filename, int *nums, int *count) {
    FILE* fp;
    int num;

    fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Error: File could not open.");
        return;
    }

    *count = 0;
    while (*count < MAX_NUM && fscanf(fp, "%d", &nums[*count]) == 1)
        (*count)++;

    fclose(fp);
}

double findMean(int *nums, int count) {
    double sum = 0;

    for (int i = 0; i < count; i++) {
        sum += *(nums + i);
    }
    return (double) sum / count;
}

void computeDiff(int *nums, int count, const double mean, int *diff) {
    for (int i = 0; i < count; i++) {
        *(diff + i) = *(nums + i) - mean;
    }
}
