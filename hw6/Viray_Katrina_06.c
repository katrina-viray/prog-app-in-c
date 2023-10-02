#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fill(int a[], int n){
    for(int i = 0; i < n; i++){
        a[i] =(rand( ) % 4)*pow(2, 30) +(pow(2, 15)*rand( ) + rand( )) - 2147483648;
    }
}

// bubble sort?
void sort(int a[], int n){
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if (a[j] < a[i]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

float median(int a[], int n){
    if(n % 2 == 0)
        return (a[n/2] + a[n/2 - 1]) / 2.0;
    else
        return a[n/2];
}

int main() {
    int n;
    int vec[1000];

    printf("Enter the number of pseudo-random integers that you would like that is <= 1000:\n");
    scanf("%d", &n);

    while(n > 1000 || n < 0){
        printf("Please enter a new number of pseudo-random integers that is <= 1000:\n");
        scanf("%d", &n);
    }

    fill(vec, n);
    sort(vec, n);
    printf("The median is %f\n", median(vec, n));
}


