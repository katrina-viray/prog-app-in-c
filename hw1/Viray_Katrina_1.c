//  main.c
//  Viray_Katrina_1.c
//  Created by Katrina Viray on 8/24/2023.
/*
Write a program to prompt the user to enter three integers from the keyboard.
Read-in the three integers using scanf( ) ( you can call scanf( ) either once or three separate times),
and print out a message to the display the sum of the three integers.
*/

#include <stdio.h>

int main()
{
    int userNum1;
    printf("Enter a number: \n");
    scanf("%d", &userNum1);

    int userNum2;
    printf("Enter a different number: \n");
    scanf("%d", &userNum2);

    int userNum3;
    printf("Enter a different number: \n");
    scanf("%d", &userNum3);

    int sum;
    sum = userNum1 + userNum2 + userNum3;
    printf("The sum of these three numbers is %d\n", sum);
}
