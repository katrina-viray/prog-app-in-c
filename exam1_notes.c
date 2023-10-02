#include <stdio.h>

/* Print Statements******************************************************************* */
int x = 90;
printf("%d", x) // 90, decimal
printf("%c", x) // z, char, ASCII representation of z.
printf("%f", x) // 90, float?
printf("%e", x) // ?, exponent?

/* ASCII Representation******************************************************************* */
/* Each character is represented by a number in decimal form.
 For instance, c in decimal form is represented as 99 according to the ASCII table.
 If you want to change the values of a character, you can simply add integers to the character itself:  */
char ch = 'c';
ch += 1;
printf("%c", ch); // outputs d

if(ch == 100)
    printf("%d", ch); // outputs 100

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */

/* H******************************************************************* */