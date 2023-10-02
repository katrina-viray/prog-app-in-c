#include <stdio.h>
#include <string.h>

/* Print Statements******************************************************************* */
int x = 90;
printf("%d", x) // 90, decimal
printf("%c", x) // z, char, ASCII representation of z.
printf("%f", x) // 90, float?
printf("%e", x) // ?, exponent?

/* Getting input from the user******************************************************************* */

/* H******************************************************************* */


/* Strings******************************************************************* */
/* Given a character array, you can make sentences from manually filling the array. 
Let's say we define this array in main(): */
char sentence [201]; // can fill 200 characters + 1 for '\0' for string termination

/* Everytime you pass the 1-D array into a subroutine, it receives the memory address of the 0th cell
of the 1-D array in the main() function */
// read in sentence into character array until '\n' is reached.
void sentence(char s[201]){
    char ch;
    int i = 0;
    
    printf("Enter a sentence (up to 200 characters):\n");
    
    while ((ch = getchar()) != '\n' && i < 200) {
        s[i++] = ch;
    }
    
    s[i] = '\0';
}

// print sentence in reverse order. 
void reverse(char s[201]){
    int l = strlen(s);
    
    for(int i = l - 1; i >= 0; i--){
        if((s[i] != ' ') && (s[i] != '\t')){
            putchar(s[i]);
        }
    }
}

while((ch = getchar()) != '\n' && i < 200){
sentence[i++] = ch;
}
sentence[i] = '\0';

// to get the length of a sentence, use the strlen function
int length = strlen(sentence);

// to print, use the putchar() function
/* The putchar(int char) method in C is used to write a character,
 of unsigned char type, to stdout. This character is passed as the parameter to this method.*/

/* ASCII Representation******************************************************************* */
/* Each character is represented by a number in decimal form.
 For instance, c in decimal form is represented as 99 according to the ASCII table.
 If you want to change the values of a character, you can simply add integers to the character itself:  */
char ch = 'c';
ch += 1;
printf("%c", ch); // outputs d

if(ch == 100)
    printf("%d", ch); // outputs 100, the ASCII rep of d.

/* Arrays******************************************************************* */
// passing in arrays to "subroutines"/functions, etc. 

/* Math Library******************************************************************* */
// rand, pow, fab, etc

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */