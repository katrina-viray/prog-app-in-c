/*
Write a program that prompts the user for two
integers and one of the letter codes a, s, m, or d.
The interpretation is given by the following table:

a = add, s = subtract, m = multiply, d = divide.

1. The function main issues the prompt and stores the 
user's input in the variables num1, num2, and operator.
2. Then main checks the letter code. If the letter code
is a, main invokes the function add with arguments
num1 and num2 and similary for s, m, and d. 
3. Each of the functions add, subtract, multiply, and divide invokes the funciton
print_result, which prints the result of the arithmetic operation. 
*/

#include <stdio.h>

int main() {
    float add(float a,float b);
    float subtract(float a,float b);
    float multiply(float a,float b);
    float divide(float a,float b);
    void print_result(float r);
    float num1, num2, answ=0;
    char response,s;
    
    printf("Enter your first number:\n");
    scanf("%f",&num1);
    printf("Enter your second number:\n");
    scanf("%f",&num2);
    scanf("%c",&s);
    printf("Enter operator code :\n");
    printf("a-add\n");
    printf("s-subtract\n");
    printf("m-multiply\n");
    printf("d-divide\n");
    scanf("%c",&response);
    switch(response){
        case 'a':
           answ=add(num1,num2);
            break;
        case 's':
            answ=subtract(num1,num2);
            break;
        case 'm':
            answ=multiply(num1,num2);
            break;
        case 'd':
            answ=divide(num1,num2);
            break;
    }
    result(answ);
}
float add(float a,float b){
    return a+b;
}
float subtract(float a,float b){
    return a-b;
}
float multiply(float a,float b){
    return a*b;
}
float divide(float a,float b){
    return a/b;
}
void print_result(float r){
    printf("The result is: %f\n",r);
}
