#include <stdio.h>

/* Program to read in user's first and last name along with their account balance */
int main() {
    // open output file for writing called out.txt
    FILE *fout;
    fout = fopen("out.txt","w");

    char answ = 'y', ent, c = 'a';
    int t;
    float acountBal;

    // ask user to add account until the user says no
    while(answ == 'y'){
        printf("Please enter your lastname, firstname and then hit enter:\n");

        while(c != '\n'){
            // scans in each character for the first and last name
            scanf("%c", &c);

            // if statment that checks if the loop has reached the end, where '\n' = enter
            if(c == '\n')
            {
                fputc(':',fout);
                fputc(' ', fout);
            }
            else
                fprintf(fout,"%c",c);
        }

    // enter user account balance
    printf("Please enter your account balance as a floating point number and then hit enter:\n");
    fputc('$', fout);
    scanf("%f", &acountBal);

    // print to output file with 2 digits past the decimal point. 
    fprintf(fout,"%.2f", acountBal);

    // scans in extra enter '\n' so the next scanin doesn't take in the enter
    scanf("%c", &ent);

    printf("Would you like to enter another complete name and account balance? (enter y/n)\n");
    scanf("%c", &answ);

    // scans in extra enter '\n' so the next scanin doesn't take in the enter
    scanf("%c", &ent);

    if(answ == 'y')
        fprintf(fout,"\n");
    }

    // closes file and program if user did mot want to add new account
    fclose(fout);
    return 0;
}
